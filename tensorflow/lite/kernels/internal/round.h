/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_LITE_KERNELS_INTERNAL_ROUND_H_
#define TENSORFLOW_LITE_KERNELS_INTERNAL_ROUND_H_

#include <cmath>

namespace tflite {

// TODO(aselle): See if we can do this only on jdk. Also mikecase, check
// if you need this for java host build.
#if defined(__ANDROID__) && !defined(__NDK_MAJOR__)
template <class T>
inline float TfLiteRound(const float x) {
  return ::round(x);
}
inline double TfLiteRound(const double x) { return ::round(x); }
#else
template <class T>
inline T TfLiteRound(const T x) {
#ifdef TF_LITE_RISCV_MCU
  return ::round(x);
#else
  return std::round(x);
#endif
}
#endif

}  // namespace tflite

#endif  // TENSORFLOW_LITE_KERNELS_INTERNAL_ROUND_H_
