#!/bin/sh

if [[ `uname -m` = "arm64" ]]; then
    arch -x86_64 $SHELL -c "NDK_PROJECT_PATH=. $ANDROID_NDK_ROOT/ndk-build NDK_APPLICATION_MK=Application.mk $*"
else
    NDK_PROJECT_PATH=. $ANDROID_NDK_ROOT/ndk-build NDK_APPLICATION_MK=Application.mk $*
fi

# rm -rf libs
# rm -rf obj

