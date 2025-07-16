/*
 * Copyright 2025 BlissLabs
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef C2FFMPEG_VIDEO_UTILS_H
#define C2FFMPEG_VIDEO_UTILS_H

#include <string>
extern "C" {
#include <config.h>
#include <libavutil/pixdesc.h>
}
#ifdef CONFIG_VAAPI
#include <va/va.h>
#endif

namespace android {

enum class PixelFormatType {
    YUV_420,
    RGB_565,
    RGBX_8888,
    BGRA_8888,
    UNKNOWN
};

class C2FFMPEGVideoUtils {
public:
    explicit C2FFMPEGVideoUtils();
    virtual ~C2FFMPEGVideoUtils() = default;

    uint32_t getPixelFormat(bool flexible) const;
#ifdef CONFIG_VAAPI
    uint32_t getVAFormat() const;
    uint32_t getVAFOURCCFormat() const;
#endif
    enum AVPixelFormat getAVFormat() const;
    bool mSwapVAColorRGB;

private:
    std::string mOverridePixelFormat;
    PixelFormatType getPixelFormatType() const;
};

} // namespace android

#endif // C2FFMPEG_VIDEO_UTILS_H
