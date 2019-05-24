/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

#include "modules/video_render/ios/video_render_ios_channel.h"
#include "rtc_base/logging.h"

using namespace webrtc;

VideoRenderIosChannel::VideoRenderIosChannel(VideoRenderIosView* view)
    : view_(view), current_frame_( webrtc::VideoFrame(I420Buffer::Create(640, 480),webrtc::kVideoRotation_0, 0)), buffer_is_updated_(false) {
}

VideoRenderIosChannel::~VideoRenderIosChannel() { /*delete current_frame_;*/ }

void VideoRenderIosChannel::OnFrame(const VideoFrame& video_frame) {

  current_frame_ = video_frame;
  current_frame_.set_timestamp_us(0);
  //RTC_LOG(LS_ERROR) << __FUNCTION__ << ",current_frame_ rotation = " << current_frame_.rotation();
  //current_frame_.set_rotation(webrtc::kVideoRotation_180);
  //RTC_LOG(LS_ERROR) << __FUNCTION__ << ",current_frame_ rotation = " << current_frame_.rotation();
  buffer_is_updated_ = true;
}

bool VideoRenderIosChannel::RenderOffScreenBuffer() {
  if (![view_ renderFrame:&current_frame_]) {
    return false;
  }

  buffer_is_updated_ = false;

  return true;
}

bool VideoRenderIosChannel::IsUpdated() { return buffer_is_updated_; }

int VideoRenderIosChannel::SetStreamSettings(const float z_order,
                                             const float left,
                                             const float top,
                                             const float right,
                                             const float bottom) {
  if (![view_ setCoordinatesForZOrder:z_order
                                 Left:left
                                  Top:bottom
                                Right:right
                               Bottom:top]) {

    return -1;
  }

  return 0;
}
