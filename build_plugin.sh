#!/bin/sh
$ANDROID_NDK_ROOT/ndk-build NDK_PROJECT_PATH=. NDK_APPLICATION_MK=Application.mk $*
rm -rf libs
rm -rf obj
