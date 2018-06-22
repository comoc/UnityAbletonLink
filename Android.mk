include $(CLEAR_VARS)

LOCAL_ARM_MODE  := arm
LOCAL_PATH      := $(NDK_PROJECT_PATH)
LOCAL_MODULE    := libUnityAbletonLink
LOCAL_CFLAGS    := -DLINK_PLATFORM_LINUX=1
LOCAL_C_INCLUDES := link/include link/modules/asio-standalone/asio/include abl_link/external/android-ifaddrs
LOCAL_SRC_FILES := MyAbletonLink.cpp Plugin.cpp abl_link/external/android-ifaddrs/ifaddrs.cpp
LOCAL_LDLIBS    := -llog

include $(BUILD_SHARED_LIBRARY)
