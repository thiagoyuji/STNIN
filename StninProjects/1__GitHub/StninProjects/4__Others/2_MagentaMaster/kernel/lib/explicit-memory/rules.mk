# Copyright 2017 The Fuchsia Authors
#
# Use of this source code is governed by a MIT-style
# license that can be found in the LICENSE file or at
# https://opensource.org/licenses/MIT

SRC_DIR := system/ulib/explicit-memory
LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

KERNEL_INCLUDES += $(SRC_DIR)/include

MODULE_SRCS += \
    $(SRC_DIR)/bytes.c \

include make/module.mk
