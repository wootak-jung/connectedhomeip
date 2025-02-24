#
#    Copyright (c) 2020 Project CHIP Authors
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
#
cmake_minimum_required(VERSION 3.13.1)

get_filename_component(CHIP_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/third_party/connectedhomeip REALPATH)
get_filename_component(NLIO_ROOT ${CHIP_ROOT}/third_party/nlio/repo/include REALPATH)
get_filename_component(NRFCONNECT_COMMON ${CHIP_ROOT}/examples/platform/nrfconnect REALPATH)
get_filename_component(GEN_DIR ${CHIP_ROOT}/zzz_generated/ REALPATH)

include(${CHIP_ROOT}/config/nrfconnect/app/check-nrfconnect-version.cmake)

# Load NCS/Zephyr build system
set(CONF_FILE ${CHIP_ROOT}/config/nrfconnect/app/sample-defaults.conf prj.conf)

if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/boards/${BOARD}.conf)
  list(APPEND CONF_FILE boards/${BOARD}.conf)
endif()

set(BUILD_WITH_DFU "MATTER" CACHE STRING "Build target with Device Firmware Upgrade support")

if(NOT BUILD_WITH_DFU STREQUAL "OFF")
    if(BUILD_WITH_DFU STREQUAL "BLE")
        if(BOARD STREQUAL "nrf5340dk_nrf5340_cpuapp")
        list(INSERT OVERLAY_CONFIG 0 ${CHIP_ROOT}/config/nrfconnect/app/overlay-multi_image_smp_dfu_support.conf)
        else()
            list(INSERT OVERLAY_CONFIG 0 ${CHIP_ROOT}/config/nrfconnect/app/overlay-single_image_smp_dfu_support.conf)
        endif()
    elseif(NOT BUILD_WITH_DFU STREQUAL "MATTER")
        message(FATAL_ERROR "Selected invalid BUILD_WITH_DFU value: ${BUILD_WITH_DFU}")
    endif()

    list(INSERT OVERLAY_CONFIG 0 ${CHIP_ROOT}/config/nrfconnect/app/overlay-mcuboot_qspi_nor_support.conf)
    list(INSERT OVERLAY_CONFIG 0 ${CHIP_ROOT}/config/nrfconnect/app/overlay-ota_requestor.conf)

    if(BOARD STREQUAL "nrf5340dk_nrf5340_cpuapp")
        # DFU over Matter doesn't support multi-image update yet, but using this configs should not harm it anyway.
        set(mcuboot_OVERLAY_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/configuration/mcuboot_multi_image_dfu.conf CACHE INTERNAL "")
    else()
        set(mcuboot_OVERLAY_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/configuration/mcuboot_single_image_dfu.conf CACHE INTERNAL "")
    endif()

    set(PM_STATIC_YML_FILE ${CMAKE_CURRENT_SOURCE_DIR}/configuration/${BOARD}/pm_static.yml)
endif()

list(APPEND ZEPHYR_EXTRA_MODULES ${CHIP_ROOT}/config/nrfconnect/chip-module)
find_package(Zephyr HINTS $ENV{ZEPHYR_BASE})

# -Wmaybe-uninitialized has too many false positives, including on std::optional
# and chip::Optional.  Make it nonfatal.
#
# See https://gcc.gnu.org/bugzilla/show_bug.cgi?id=80635
target_compile_options(app PRIVATE -Werror -Wno-error=maybe-uninitialized)

project(chip-nrfconnect-pump-controller-example)

include(${CHIP_ROOT}/config/nrfconnect/app/enable-gnu-std.cmake)
include(${CHIP_ROOT}/config/nrfconnect/app/flashing.cmake)
include(${CHIP_ROOT}/src/app/chip_data_model.cmake)

target_include_directories(app PRIVATE
                           main/include
                           ${GEN_DIR}/app-common
                           ${GEN_DIR}/pump-controller-app
                           ${NLIO_ROOT}
                           ${NRFCONNECT_COMMON}/util/include
                           ${NRFCONNECT_COMMON}/app/include)

target_sources(app PRIVATE
               main/AppTask.cpp
               main/PumpManager.cpp
               main/main.cpp
               main/ZclCallbacks.cpp
               ${GEN_DIR}/pump-controller-app/zap-generated/callback-stub.cpp
               ${GEN_DIR}/pump-controller-app/zap-generated/IMClusterCommandHandler.cpp
               ${NRFCONNECT_COMMON}/util/LEDWidget.cpp
               ${NRFCONNECT_COMMON}/util/ThreadUtil.cpp)

chip_configure_data_model(app
    INCLUDE_SERVER
    ZAP_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../pump-controller-common/pump-controller-app.zap
)

if(BUILD_WITH_DFU STREQUAL "BLE")
    target_sources(app PRIVATE ${NRFCONNECT_COMMON}/util/DFUOverSMP.cpp)
endif()
