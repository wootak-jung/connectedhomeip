/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#include <app-common/zap-generated/cluster-objects.h>
#include <lib/core/CHIPError.h>

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::detail::Structs::ApplicationStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::detail::Structs::LabelStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Structs::AttributeValuePair::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Structs::ExtensionFieldSet::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Descriptor::Structs::DeviceTypeStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Binding::Structs::TargetStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::AccessControl::Structs::Target::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::AccessControl::Structs::AccessControlEntryStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::AccessControl::Structs::AccessControlExtensionStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Actions::Structs::ActionStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Actions::Structs::EndpointListStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::BasicInformation::Structs::CapabilityMinimaStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::BasicInformation::Structs::ProductAppearanceStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::OtaSoftwareUpdateRequestor::Structs::ProviderLocation::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PowerSource::Structs::BatChargeFaultChangeType::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PowerSource::Structs::BatFaultChangeType::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PowerSource::Structs::WiredFaultChangeType::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GeneralCommissioning::Structs::BasicCommissioningInfo::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::NetworkCommissioning::Structs::NetworkInfo::DecodableType & value);

static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::NetworkCommissioning::Structs::ThreadInterfaceScanResult::DecodableType & value);

static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::NetworkCommissioning::Structs::WiFiInterfaceScanResult::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GeneralDiagnostics::Structs::NetworkInterface::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::SoftwareDiagnostics::Structs::ThreadMetricsStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ThreadNetworkDiagnostics::Structs::NeighborTable::DecodableType & value);

static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::ThreadNetworkDiagnostics::Structs::OperationalDatasetComponents::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ThreadNetworkDiagnostics::Structs::RouteTable::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ThreadNetworkDiagnostics::Structs::SecurityPolicy::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::TimeSynchronization::Structs::DSTOffsetStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::TimeSynchronization::Structs::TimeZoneStruct::DecodableType & value);

static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::BridgedDeviceBasicInformation::Structs::ProductAppearanceStruct::DecodableType & value);

static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::OperationalCredentials::Structs::FabricDescriptorStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::OperationalCredentials::Structs::NOCStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GroupKeyManagement::Structs::GroupInfoMapStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GroupKeyManagement::Structs::GroupKeyMapStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GroupKeyManagement::Structs::GroupKeySetStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ModeSelect::Structs::SemanticTagStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ModeSelect::Structs::ModeOptionStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Structs::CredentialStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Thermostat::Structs::ThermostatScheduleTransition::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Channel::Structs::ChannelInfoStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Channel::Structs::LineupInfoStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::TargetNavigator::Structs::TargetInfoStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::MediaPlayback::Structs::PlaybackPositionStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::MediaInput::Structs::InputInfoStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ContentLauncher::Structs::DimensionStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ContentLauncher::Structs::AdditionalInfoStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ContentLauncher::Structs::ParameterStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ContentLauncher::Structs::ContentSearchStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ContentLauncher::Structs::StyleInformationStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ContentLauncher::Structs::BrandingInformationStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::AudioOutput::Structs::OutputInfoStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ApplicationLauncher::Structs::ApplicationEPStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ClientMonitoring::Structs::MonitoringRegistration::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Structs::SimpleStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Structs::TestFabricScoped::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Structs::NullablesAndOptionalsStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Structs::NestedStruct::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Structs::NestedStructList::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Structs::DoubleNestedStructList::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Structs::TestListStructOctet::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::AccessControl::Events::AccessControlEntryChanged::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::AccessControl::Events::AccessControlExtensionChanged::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Actions::Events::StateChanged::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Actions::Events::ActionFailed::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::BasicInformation::Events::StartUp::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::BasicInformation::Events::ShutDown::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::BasicInformation::Events::Leave::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::BasicInformation::Events::ReachableChanged::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::OtaSoftwareUpdateRequestor::Events::StateTransition::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::OtaSoftwareUpdateRequestor::Events::VersionApplied::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::OtaSoftwareUpdateRequestor::Events::DownloadError::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PowerSource::Events::WiredFaultChange::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PowerSource::Events::BatFaultChange::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PowerSource::Events::BatChargeFaultChange::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GeneralDiagnostics::Events::HardwareFaultChange::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GeneralDiagnostics::Events::RadioFaultChange::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GeneralDiagnostics::Events::NetworkFaultChange::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GeneralDiagnostics::Events::BootReason::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::SoftwareDiagnostics::Events::SoftwareFault::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ThreadNetworkDiagnostics::Events::ConnectionStatus::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ThreadNetworkDiagnostics::Events::NetworkFaultChange::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::WiFiNetworkDiagnostics::Events::Disconnection::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::WiFiNetworkDiagnostics::Events::AssociationFailure::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::WiFiNetworkDiagnostics::Events::ConnectionStatus::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::BridgedDeviceBasicInformation::Events::StartUp::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::BridgedDeviceBasicInformation::Events::ShutDown::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::BridgedDeviceBasicInformation::Events::Leave::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::BridgedDeviceBasicInformation::Events::ReachableChanged::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Switch::Events::SwitchLatched::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Switch::Events::InitialPress::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Switch::Events::LongPress::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Switch::Events::ShortRelease::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Switch::Events::LongRelease::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Switch::Events::MultiPressOngoing::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Switch::Events::MultiPressComplete::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::BooleanState::Events::StateChange::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Events::DoorLockAlarm::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Events::DoorStateChange::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Events::LockOperation::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Events::LockOperationError::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Events::LockUserChange::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PumpConfigurationAndControl::Events::SupplyVoltageLow::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::PumpConfigurationAndControl::Events::SupplyVoltageHigh::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::PumpConfigurationAndControl::Events::PowerMissingPhase::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::PumpConfigurationAndControl::Events::SystemPressureLow::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::PumpConfigurationAndControl::Events::SystemPressureHigh::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PumpConfigurationAndControl::Events::DryRunning::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::PumpConfigurationAndControl::Events::MotorTemperatureHigh::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::PumpConfigurationAndControl::Events::PumpMotorFatalFailure::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::PumpConfigurationAndControl::Events::ElectronicTemperatureHigh::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PumpConfigurationAndControl::Events::PumpBlocked::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PumpConfigurationAndControl::Events::SensorFailure::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::PumpConfigurationAndControl::Events::ElectronicNonFatalFailure::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::PumpConfigurationAndControl::Events::ElectronicFatalFailure::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PumpConfigurationAndControl::Events::GeneralFault::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PumpConfigurationAndControl::Events::Leakage::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PumpConfigurationAndControl::Events::AirDetection::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::PumpConfigurationAndControl::Events::TurbineOperation::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Events::TestEvent::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Events::TestFabricScopedEvent::DecodableType & value);

static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Groups::Commands::AddGroupResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Groups::Commands::ViewGroupResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Groups::Commands::GetGroupMembershipResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Groups::Commands::RemoveGroupResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Commands::AddSceneResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Commands::ViewSceneResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Commands::RemoveSceneResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Commands::RemoveAllScenesResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Commands::StoreSceneResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Commands::GetSceneMembershipResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Commands::EnhancedAddSceneResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Commands::EnhancedViewSceneResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Scenes::Commands::CopySceneResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::OtaSoftwareUpdateProvider::Commands::QueryImageResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::OtaSoftwareUpdateProvider::Commands::ApplyUpdateResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GeneralCommissioning::Commands::ArmFailSafeResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::GeneralCommissioning::Commands::SetRegulatoryConfigResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::GeneralCommissioning::Commands::CommissioningCompleteResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::NetworkCommissioning::Commands::ScanNetworksResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::NetworkCommissioning::Commands::NetworkConfigResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::NetworkCommissioning::Commands::ConnectNetworkResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DiagnosticLogs::Commands::RetrieveLogsResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::OperationalCredentials::Commands::AttestationResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::OperationalCredentials::Commands::CertificateChainResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::OperationalCredentials::Commands::CSRResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::OperationalCredentials::Commands::NOCResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::GroupKeyManagement::Commands::KeySetReadResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::GroupKeyManagement::Commands::KeySetReadAllIndicesResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Commands::GetWeekDayScheduleResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Commands::GetYearDayScheduleResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Commands::GetHolidayScheduleResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Commands::GetUserResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Commands::SetCredentialResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::DoorLock::Commands::GetCredentialStatusResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Thermostat::Commands::GetWeeklyScheduleResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::Channel::Commands::ChangeChannelResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::TargetNavigator::Commands::NavigateTargetResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::MediaPlayback::Commands::PlaybackResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::KeypadInput::Commands::SendKeyResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ContentLauncher::Commands::LauncherResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::ApplicationLauncher::Commands::LauncherResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::AccountLogin::Commands::GetSetupPINResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::ElectricalMeasurement::Commands::GetProfileInfoResponseCommand::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::ElectricalMeasurement::Commands::GetMeasurementProfileResponseCommand::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Commands::TestSpecificResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Commands::TestAddArgumentsResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Commands::TestSimpleArgumentResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::UnitTesting::Commands::TestStructArrayArgumentResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Commands::TestListInt8UReverseResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Commands::TestEnumsResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Commands::TestNullableOptionalResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::UnitTesting::Commands::TestComplexNullableOptionalResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Commands::BooleanResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Commands::SimpleStructResponse::DecodableType & value);
static CHIP_ERROR LogValue(const char * label, size_t indent,
                           const chip::app::Clusters::UnitTesting::Commands::TestEmitTestEventResponse::DecodableType & value);
static CHIP_ERROR
LogValue(const char * label, size_t indent,
         const chip::app::Clusters::UnitTesting::Commands::TestEmitTestFabricScopedEventResponse::DecodableType & value);
