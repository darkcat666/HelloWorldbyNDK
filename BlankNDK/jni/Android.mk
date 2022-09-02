LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := amount-values   # モジュール名
LOCAL_SRC_FILES := amount-values.c  # ソースファイル名

include $(BUILD_SHARED_LIBRARY)