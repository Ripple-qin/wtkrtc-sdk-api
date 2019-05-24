/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "modules/video_render/external/video_render_external_impl.h"

namespace webrtc {

VideoRenderExternalImpl::VideoRenderExternalImpl(
                                                 const int32_t id,
                                                 const VideoRenderType videoRenderType,
                                                 void* window,
                                                 const bool fullscreen) :
    _fullscreen(fullscreen)
{
}

VideoRenderExternalImpl::~VideoRenderExternalImpl()
{
}

int32_t VideoRenderExternalImpl::Init()
{
    return 0;
}

int32_t VideoRenderExternalImpl::ChangeWindow(void* window)
{
	rtc::CritScope lock(&_critSect);
    return 0;
}

rtc::VideoSinkInterface<VideoFrame>*
VideoRenderExternalImpl::AddIncomingRenderStream(const uint32_t streamId,
                                                 const uint32_t zOrder,
                                                 const float left,
                                                 const float top,
                                                 const float right,
                                                 const float bottom)
{
    rtc::CritScope lock(&_critSect);
    return this;
}

int32_t VideoRenderExternalImpl::DeleteIncomingRenderStream(
                                                                  const uint32_t streamId)
{
    rtc::CritScope lock(&_critSect);
    return 0;
}

int32_t VideoRenderExternalImpl::GetIncomingRenderStreamProperties(
                                                                         const uint32_t streamId,
                                                                         uint32_t& zOrder,
                                                                         float& left,
                                                                         float& top,
                                                                         float& right,
                                                                         float& bottom) const
{
    rtc::CritScope lock(&_critSect);

    zOrder = 0;
    left = 0;
    top = 0;
    right = 0;
    bottom = 0;

    return 0;
}

int32_t VideoRenderExternalImpl::StartRender()
{
    rtc::CritScope lock(&_critSect);
    return 0;
}

int32_t VideoRenderExternalImpl::StopRender()
{
    rtc::CritScope lock(&_critSect);
    return 0;
}

VideoRenderType VideoRenderExternalImpl::RenderType()
{
    return kRenderExternal;
}

VideoType VideoRenderExternalImpl::PerferedVideoType()
{
    return VideoType::kI420;
}

bool VideoRenderExternalImpl::FullScreen()
{
    rtc::CritScope lock(&_critSect);
    return _fullscreen;
}

int32_t VideoRenderExternalImpl::GetGraphicsMemory(
                                                         uint64_t& totalGraphicsMemory,
                                                         uint64_t& availableGraphicsMemory) const
{
    totalGraphicsMemory = 0;
    availableGraphicsMemory = 0;
    return -1;
}

int32_t VideoRenderExternalImpl::GetScreenResolution(
                                                           uint32_t& screenWidth,
                                                           uint32_t& screenHeight) const
{
    rtc::CritScope lock(&_critSect);
    screenWidth = 0;
    screenHeight = 0;
    return 0;
}

uint32_t VideoRenderExternalImpl::RenderFrameRate(
                                                        const uint32_t streamId)
{
    rtc::CritScope lock(&_critSect);
    return 0;
}

int32_t VideoRenderExternalImpl::SetStreamCropping(
                                                         const uint32_t streamId,
                                                         const float left,
                                                         const float top,
                                                         const float right,
                                                         const float bottom)
{
    rtc::CritScope lock(&_critSect);
    return 0;
}

int32_t VideoRenderExternalImpl::ConfigureRenderer(
                                                         const uint32_t streamId,
                                                         const unsigned int zOrder,
                                                         const float left,
                                                         const float top,
                                                         const float right,
                                                         const float bottom)
{
    rtc::CritScope lock(&_critSect);
    return 0;
}

int32_t VideoRenderExternalImpl::SetTransparentBackground(
                                                                const bool enable)
{
    rtc::CritScope lock(&_critSect);
    return 0;
}

int32_t VideoRenderExternalImpl::SetText(
                                               const uint8_t textId,
                                               const uint8_t* text,
                                               const int32_t textLength,
                                               const uint32_t textColorRef,
                                               const uint32_t backgroundColorRef,
                                               const float left,
                                               const float top,
                                               const float right,
                                               const float bottom)
{
    rtc::CritScope lock(&_critSect);
    return 0;
}

int32_t VideoRenderExternalImpl::SetBitmap(const void* bitMap,
                                           const uint8_t pictureId,
                                           const void* colorKey,
                                           const float left,
                                           const float top,
                                           const float right,
                                           const float bottom)
{
    rtc::CritScope lock(&_critSect);
    return 0;
}

void VideoRenderExternalImpl::OnFrame(const VideoFrame& videoFrame) {}

}  // namespace webrtc
