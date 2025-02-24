/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
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

#include <app-common/zap-generated/cluster-objects.h>
#include <app/data-model/Decode.h>
#include <app/data-model/Encode.h>
#include <lib/support/UnitTestRegistration.h>
#include <lib/support/jsontlv/TlvJson.h>
#include <nlunit-test.h>
#include <system/SystemPacketBuffer.h>
#include <system/TLVPacketBufferBackingStore.h>

namespace {

using namespace chip::Encoding;
using namespace chip;
using namespace chip::app;

System::TLVPacketBufferBackingStore gStore;
TLV::TLVWriter gWriter;
TLV::TLVReader gReader;
nlTestSuite * gSuite;

void SetupBuf()
{
    System::PacketBufferHandle buf;

    buf = System::PacketBufferHandle::New(1024);
    gStore.Init(std::move(buf));

    gWriter.Init(gStore);
    gReader.Init(gStore);
}

CHIP_ERROR SetupReader()
{
    gReader.Init(gStore);
    return gReader.Next();
}

bool Matches(const char * referenceString, Json::Value & generatedValue)
{
    Json::StyledWriter writer;
    auto generatedStr = JsonToString(generatedValue);

    auto matches = (generatedStr == std::string(referenceString));

    if (!matches)
    {
        printf("Didn't match!\n");
        printf("Reference:\n");
        printf("%s\n", referenceString);

        printf("Generated:\n");
        printf("%s\n", generatedStr.c_str());
    }

    return matches;

#if 0
    //
    // Converting the reference string to a JSON representation and comparing
    // that against the generated JSON object would have been preferable. This avoids
    // the need to have reference strings expressed precisely to match the generated string
    // from the JSON converter, right down to the number of spaces,etc. This would have made
    // the reference string less britle and coupled to the jsoncpp converter implementation.
    //
    // However, jsoncpp converter converts positive values in the JSON to a signed
    // integer C type. This results in a mis-match with the generated JSON objects
    // that are created from spec-compliant TLV that correctly represents them as unsigned
    // integers in the JSON object.
    //
    // This mismatch nullifies this approach unfortunately.
    //
    // TODO: Investigate a way to compare using JSON objects.
    //
    Json::Reader reader;
    Json::Value referenceValue;

    bool ret = reader.parse(referenceString, referenceValue);
    if (ret != true) {
        return ret;
    }

    std::cout << generatedValue << "\n";
    std::cout << referenceValue << "\n";

    int rett = generatedValue.compare(referenceValue);
    printf("%d\n", rett);
    return (rett == 0);
#endif
}

template <typename T>
void EncodeAndValidate(T val, const char * expectedJsonString)
{
    CHIP_ERROR err;

    SetupBuf();

    err = DataModel::Encode(gWriter, TLV::AnonymousTag(), val);
    NL_TEST_ASSERT(gSuite, err == CHIP_NO_ERROR);

    err = gWriter.Finalize();
    NL_TEST_ASSERT(gSuite, err == CHIP_NO_ERROR);

    err = SetupReader();
    NL_TEST_ASSERT(gSuite, err == CHIP_NO_ERROR);

    Json::Value d;
    err = TlvToJson(gReader, d);
    NL_TEST_ASSERT(gSuite, err == CHIP_NO_ERROR);

    bool matches = Matches(expectedJsonString, d);
    NL_TEST_ASSERT(gSuite, matches);
}

void TestConverter(nlTestSuite * inSuite, void * inContext)
{
    gSuite = inSuite;

    EncodeAndValidate(static_cast<uint32_t>(30),
                      "{\n"
                      "   \"value\" : 30\n"
                      "}\n");

    EncodeAndValidate(static_cast<int32_t>(-30),
                      "{\n"
                      "   \"value\" : -30\n"
                      "}\n");

    EncodeAndValidate(false,
                      "{\n"
                      "   \"value\" : false\n"
                      "}\n");

    EncodeAndValidate(true,
                      "{\n"
                      "   \"value\" : true\n"
                      "}\n");

    EncodeAndValidate(1.0,
                      "{\n"
                      "   \"value\" : 1.0\n"
                      "}\n");

    const char charBuf[] = "hello";
    CharSpan charSpan(charBuf);
    EncodeAndValidate(charSpan,
                      "{\n"
                      "   \"value\" : \"hello\"\n"
                      "}\n");

    //
    // Validated using https://base64.guru/converter/encode/hex
    //
    const uint8_t byteBuf[] = { 0x01, 0x02, 0x03, 0x04, 0xff, 0xfe, 0x99, 0x88, 0xdd, 0xcd };
    ByteSpan byteSpan(byteBuf);
    EncodeAndValidate(byteSpan,
                      "{\n"
                      "   \"value\" : \"AQIDBP/+mYjdzQ==\"\n"
                      "}\n");

    DataModel::Nullable<uint8_t> nullValue;
    EncodeAndValidate(nullValue,
                      "{\n"
                      "   \"value\" : null\n"
                      "}\n");

    Clusters::TestCluster::Structs::SimpleStruct::Type structVal;
    structVal.a = 20;
    structVal.b = true;
    structVal.d = byteBuf;
    structVal.e = charSpan;
    structVal.g = 1.0;
    structVal.h = 1.0;

    EncodeAndValidate(structVal,
                      "{\n"
                      "   \"value\" : {\n"
                      "      \"0\" : 20,\n"
                      "      \"1\" : true,\n"
                      "      \"2\" : 0,\n"
                      "      \"3\" : \"AQIDBP/+mYjdzQ==\",\n"
                      "      \"4\" : \"hello\",\n"
                      "      \"5\" : 0,\n"
                      "      \"6\" : 1.0,\n"
                      "      \"7\" : 1.0\n"
                      "   }\n"
                      "}\n");

    uint8_t int8uListData[] = { 1, 2, 3, 4 };
    DataModel::List<uint8_t> int8uList;

    int8uList = int8uListData;

    EncodeAndValidate(int8uList,
                      "{\n"
                      "   \"value\" : [ 1, 2, 3, 4 ]\n"
                      "}\n");

    Clusters::TestCluster::Structs::SimpleStruct::Type structListData[2] = { structVal, structVal };
    DataModel::List<Clusters::TestCluster::Structs::SimpleStruct::Type> structList;

    structList = structListData;

    EncodeAndValidate(structList,
                      "{\n"
                      "   \"value\" : [\n"
                      "      {\n"
                      "         \"0\" : 20,\n"
                      "         \"1\" : true,\n"
                      "         \"2\" : 0,\n"
                      "         \"3\" : \"AQIDBP/+mYjdzQ==\",\n"
                      "         \"4\" : \"hello\",\n"
                      "         \"5\" : 0,\n"
                      "         \"6\" : 1.0,\n"
                      "         \"7\" : 1.0\n"
                      "      },\n"
                      "      {\n"
                      "         \"0\" : 20,\n"
                      "         \"1\" : true,\n"
                      "         \"2\" : 0,\n"
                      "         \"3\" : \"AQIDBP/+mYjdzQ==\",\n"
                      "         \"4\" : \"hello\",\n"
                      "         \"5\" : 0,\n"
                      "         \"6\" : 1.0,\n"
                      "         \"7\" : 1.0\n"
                      "      }\n"
                      "   ]\n"
                      "}\n");
}

int Initialize(void * apSuite)
{
    VerifyOrReturnError(chip::Platform::MemoryInit() == CHIP_NO_ERROR, FAILURE);
    return SUCCESS;
}

int Finalize(void * aContext)
{
    (void) gStore.Release();
    chip::Platform::MemoryShutdown();
    return SUCCESS;
}

const nlTest sTests[] = { NL_TEST_DEF("TestConverter", TestConverter), NL_TEST_SENTINEL() };

} // namespace

nlTestSuite theSuite = { "TlvJson", sTests, Initialize, Finalize };

int TestTlvJson(void)
{
    nlTestRunner(&theSuite, nullptr);
    return nlTestRunnerStats(&theSuite);
}

CHIP_REGISTER_TEST_SUITE(TestTlvJson)
