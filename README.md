# WebRTC API
This WebRTC API based M67 release, will update&record code from time to time, include video/audio test. The Android/iOS platform use IAX2.

Feature:
1.Audio/Video call with media relay server, codec is opus/vp8/vp9/h264(both SW & HW coder);
2.Audio/Video conference with conference server;
3.APP call Web H5 client;
4.Signal protocal is IAX2(Asterisk server);
Note:
1. Current supported & tested platform are macOS/Linux/Android.
2. iOS will add it later.

Linux/macOS platform Setup:
1. Get the WebRTC source code, please refer webrtc.org, or
    https://webrtc.org/native-code/android/ for add Android build tools, and
    https://webrtc.org/native-code/ios/ for add iOS build tools.
    *NOTE: For Linux platform loopback test, need gen project like: gn gen out/Linux --args='is_debug=false' or set RTC_DCHECK_IS_ON macro define to 0 at src/rtc_base/checks.h, about the side effect will check later.*
2. Compile the source code according the web site above.
3. Add this api code dircotry to WebRTC src/ dictory.
4. Modify src/BUILD.gn file for add compile the api code. eg. add this line deps += [ "webrtc_api_linux_mac:wtk_rtc_api" ] on some useful place.
5. Compile it, the bin file will gen at out/Linux/ dirctory, just run it
6. Have fun.

Android platform Setup:
1. Mostly same as Linux/macOS platform.
2. Because mobile APP use IAX2 as signal protocal, so you need setup a IAX2 server, like asterisk, then enter app, sign in with asterisk server's config.
