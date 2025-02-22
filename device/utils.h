/*
 * Copyright (C) 2023 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <aidl/android/hardware/camera/common/Status.h>
#include <android/binder_auto_utils.h>
#include <cutils/sched_policy.h>
#include <aidl/android/hardware/camera/device/StreamBuffer.h>
#include <aidl/android/hardware/common/NativeHandle.h>
using aidl::android::hardware::camera::device::StreamBuffer;
using aidl::android::hardware::common::NativeHandle;

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace implementation {
namespace {
ndk::ScopedAStatus toScopedAStatus(const aidl::android::hardware::camera::common::Status s) {
    return ndk::ScopedAStatus::fromServiceSpecificError(static_cast<int32_t>(s));
}

} // namespace
StreamBuffer newStreamBuffer(StreamBuffer&& src);

bool setThreadPriority(SchedPolicy policy, int prio);

}  // namespace implementation
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android
