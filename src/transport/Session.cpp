/*
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

#include <transport/GroupSession.h>
#include <transport/SecureSession.h>
#include <transport/Session.h>
#include <transport/UnauthenticatedSessionTable.h>

namespace chip {
namespace Transport {

SecureSession * Session::AsSecureSession()
{
    VerifyOrDie(GetSessionType() == SessionType::kSecure);
    return static_cast<SecureSession *>(this);
}

UnauthenticatedSession * Session::AsUnauthenticatedSession()
{
    VerifyOrDie(GetSessionType() == SessionType::kUnauthenticated);
    return static_cast<UnauthenticatedSession *>(this);
}

GroupSession * Session::AsGroupSession()
{
    VerifyOrDie(GetSessionType() == SessionType::kGroup);
    return static_cast<GroupSession *>(this);
}

} // namespace Transport
} // namespace chip
