/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *    All rights reserved.
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

#include "AppMain.h"
#include "app/clusters/ota-requestor/BDXDownloader.h"
#include "app/clusters/ota-requestor/OTARequestor.h"
#include "platform/GenericOTARequestorDriver.h"
#include "platform/Linux/OTAImageProcessorImpl.h"

using chip::BDXDownloader;
using chip::ByteSpan;
using chip::CharSpan;
using chip::EndpointId;
using chip::FabricIndex;
using chip::GetRequestorInstance;
using chip::NodeId;
using chip::OnDeviceConnected;
using chip::OnDeviceConnectionFailure;
using chip::OTADownloader;
using chip::OTAImageProcessorImpl;
using chip::OTAImageProcessorParams;
using chip::OTARequestor;
using chip::PeerId;
using chip::Server;
using chip::VendorId;
using chip::Callback::Callback;
using chip::System::Layer;
using chip::Transport::PeerAddress;
using namespace chip;
using namespace chip::ArgParser;
using namespace chip::Messaging;
using namespace chip::app::Clusters::OtaSoftwareUpdateProvider::Commands;

OTARequestor gRequestorCore;
DeviceLayer::GenericOTARequestorDriver gRequestorUser;
BDXDownloader gDownloader;
OTAImageProcessorImpl gImageProcessor;

bool HandleOptions(const char * aProgram, OptionSet * aOptions, int aIdentifier, const char * aName, const char * aValue);
void OnStartDelayTimerHandler(Layer * systemLayer, void * appState);

constexpr uint16_t kOptionDelayQuery          = 'q';
constexpr uint16_t kOptionRequestorCanConsent = 'c';
constexpr uint16_t kOptionOtaDownloadPath     = 'f';
constexpr size_t kMaxFilePathSize             = 256;

uint16_t delayQueryTimeInSec = 0;
chip::Optional<bool> gRequestorCanConsent;
static char gOtaDownloadPath[kMaxFilePathSize] = "/tmp/test.bin";

OptionDef cmdLineOptionsDef[] = {
    { "delayQuery", chip::ArgParser::kArgumentRequired, kOptionDelayQuery },
    { "requestorCanConsent", chip::ArgParser::kNoArgument, kOptionRequestorCanConsent },
    { "otaDownloadPath", chip::ArgParser::kArgumentRequired, kOptionOtaDownloadPath },
    {},
};

OptionSet cmdLineOptions = { HandleOptions, cmdLineOptionsDef, "PROGRAM OPTIONS",
                             "  -q/--delayQuery <Time in seconds>\n"
                             "        From boot up, the amount of time to wait before triggering the QueryImage\n"
                             "        command. If none or zero is supplied, QueryImage will not be triggered automatically. At "
                             "least one provider location must be written to the DefaultOTAProviders attribute.\n"
                             "  -c/--requestorCanConsent\n"
                             "        If supplied, the RequestorCanConsent field of the QueryImage command is set to true.\n"
                             "        Otherwise, the value is determined by the driver.\n "
                             "  -f/--otaDownloadPath <file path>\n"
                             "        If supplied, the OTA image is downloaded to the given fully-qualified file-path.\n"
                             "        Otherwise, the value defaults to /tmp/test.bin.\n " };

OptionSet * allOptions[] = { &cmdLineOptions, nullptr };

static void InitOTARequestor(void)
{
    // Set the global instance of the OTA requestor core component
    SetRequestorInstance(&gRequestorCore);

    gRequestorCore.Init(&(chip::Server::GetInstance()), &gRequestorUser, &gDownloader);
    gRequestorUser.Init(&gRequestorCore, &gImageProcessor);

    // WARNING: this is probably not realistic to know such details of the image or to even have an OTADownloader instantiated at
    // the beginning of program execution. We're using hardcoded values here for now since this is a reference application.
    OTAImageProcessorParams ipParams;
    ipParams.imageFile = CharSpan::fromCharString(gOtaDownloadPath);
    gImageProcessor.SetOTAImageProcessorParams(ipParams);
    gImageProcessor.SetOTADownloader(&gDownloader);

    // Set the image processor instance used for handling image being downloaded
    gDownloader.SetImageProcessorDelegate(&gImageProcessor);
}

bool HandleOptions(const char * aProgram, OptionSet * aOptions, int aIdentifier, const char * aName, const char * aValue)
{
    bool retval = true;

    switch (aIdentifier)
    {
    case kOptionDelayQuery:
        delayQueryTimeInSec = static_cast<uint16_t>(strtol(aValue, NULL, 0));
        break;
    case kOptionRequestorCanConsent:
        gRequestorCanConsent.SetValue(true);
        break;
    case kOptionOtaDownloadPath:
        chip::Platform::CopyString(gOtaDownloadPath, aValue);
        break;
    default:
        PrintArgError("%s: INTERNAL ERROR: Unhandled option: %s\n", aProgram, aName);
        retval = false;
        break;
    }

    return (retval);
}

void ApplicationInit()
{
    chip::Dnssd::Resolver::Instance().Init(chip::DeviceLayer::UDPEndPointManager());

    if (gRequestorCanConsent.HasValue())
    {
        gRequestorCore.SetRequestorCanConsent(gRequestorCanConsent.Value());
    }

    // Initialize all OTA download components
    InitOTARequestor();

    // If a delay is provided, after the timer expires, QueryImage from default OTA provider
    if (delayQueryTimeInSec > 0)
    {
        chip::DeviceLayer::SystemLayer().StartTimer(chip::System::Clock::Milliseconds32(delayQueryTimeInSec * 1000),
                                                    OnStartDelayTimerHandler, nullptr);
    }
}

int main(int argc, char * argv[])
{
    VerifyOrDie(ChipLinuxAppInit(argc, argv, &cmdLineOptions) == 0);
    ChipLinuxAppMainLoop();
    return 0;
}

// Test mode operation
void OnStartDelayTimerHandler(Layer * systemLayer, void * appState)
{
    static_cast<OTARequestor *>(GetRequestorInstance())->TriggerImmediateQuery();
}
