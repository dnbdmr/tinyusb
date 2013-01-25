/*
 * usbd_host.h
 *
 *  Created on: Jan 19, 2013
 *      Author: hathach
 */

/*
 * Software License Agreement (BSD License)
 * Copyright (c) 2012, hathach (tinyusb.net)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the tiny usb stack.
 */

/** \file
 *  \brief TBD
 *
 *  \note TBD
 */

/** \ingroup TBD
 *  \defgroup TBD
 *  \brief TBD
 *
 *  @{
 */

#ifndef _TUSB_USBD_HOST_H_
#define _TUSB_USBD_HOST_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "hcd.h"

enum {
  TUSB_FLAGS_CLASS_UNSPECIFIED          = BIT_(0)    , ///< 0
  TUSB_FLAGS_CLASS_AUDIO                = BIT_(1)    , ///< 1
  TUSB_FLAGS_CLASS_CDC                  = BIT_(2)    , ///< 2
  TUSB_FLAGS_CLASS_HID_GENERIC          = BIT_(3)    , ///< 3
  TUSB_FLAGS_CLASS_RESERVED_4           = BIT_(4)    , ///< 4
  TUSB_FLAGS_CLASS_PHYSICAL             = BIT_(5)    , ///< 5
  TUSB_FLAGS_CLASS_IMAGE                = BIT_(6)    , ///< 6
  TUSB_FLAGS_CLASS_PRINTER              = BIT_(7)    ,  ///< 7
  TUSB_FLAGS_CLASS_MSC                  = BIT_(8)    ,  ///< 8
  TUSB_FLAGS_CLASS_HUB                  = BIT_(9)    ,  ///< 9
  TUSB_FLAGS_CLASS_CDC_DATA             = BIT_(10)   ,  ///< 10
  TUSB_FLAGS_CLASS_SMART_CARD           = BIT_(11)   ,  ///< 11
  TUSB_FLAGS_CLASS_RESERVED_12          = BIT_(12)   , ///< 12
  TUSB_FLAGS_CLASS_CONTENT_SECURITY     = BIT_(13)   ,  ///< 13
  TUSB_FLAGS_CLASS_VIDEO                = BIT_(14)   ,  ///< 14
  TUSB_FLAGS_CLASS_PERSONAL_HEALTHCARE  = BIT_(15)   ,  ///< 15
  TUSB_FLAGS_CLASS_AUDIO_VIDEO          = BIT_(16)   ,  ///< 16
  // reserved from 17 to 20
  TUSB_FLAGS_CLASS_RESERVED_20          = BIT_(20)    , ///< 3

  TUSB_FLAGS_CLASS_HID_KEYBOARD         = BIT_(21)    , ///< 3
  TUSB_FLAGS_CLASS_HID_MOUSE            = BIT_(22)    , ///< 3

  // reserved from 25 to 26
  TUSB_FLAGS_CLASS_RESERVED_25          = BIT_(25)    , ///< 3
  TUSB_FLAGS_CLASS_RESERVED_26          = BIT_(26)    , ///< 3

  TUSB_FLAGS_CLASS_DIAGNOSTIC           = BIT_(27),
  TUSB_FLAGS_CLASS_WIRELESS_CONTROLLER  = BIT_(28),
  TUSB_FLAGS_CLASS_MISC                 = BIT_(29),
  TUSB_FLAGS_CLASS_APPLICATION_SPECIFIC = BIT_(30),
  TUSB_FLAGS_CLASS_VENDOR_SPECIFIC      = BIT_(31)
};

typedef uint32_t tusbh_flag_class_t;

typedef struct {
  uint8_t interface_count;
  uint8_t attributes;
} usbh_configure_info_t;

typedef struct {
  uint8_t core_id;
  pipe_handle_t pipe_control;
  uint8_t configure_count;

#if 0 // TODO allow configure for vendor/product
  uint16_t vendor_id;
  uint16_t product_id;
#endif

  usbh_configure_info_t configuration;
} usbh_device_info_t;

typedef enum {
  PIPE_STATUS_AVAILABLE = 0,
  PIPE_STATUS_BUSY,
  PIPE_STATUS_COMPLETE
} pipe_status_t;
//--------------------------------------------------------------------+
// Structures & Types
//--------------------------------------------------------------------+
typedef uint32_t tusb_handle_device_t;

//--------------------------------------------------------------------+
// APPLICATION API
//--------------------------------------------------------------------+
void         tusbh_device_mounting_cb (tusb_error_t error, tusb_handle_device_t device_hdl, uint32_t *configure_flags, uint8_t number_of_configure);
void         tusbh_device_mounted_cb (tusb_error_t error, tusb_handle_device_t device_hdl, uint32_t *configure_flags, uint8_t number_of_configure);
tusb_error_t tusbh_configuration_set     (tusb_handle_device_t const device_hdl, uint8_t const configure_number);


// TODO hiding from application include
//--------------------------------------------------------------------+
// CLASS API
//--------------------------------------------------------------------+
usbh_device_info_t*   usbh_device_info_get(tusb_handle_device_t device_hdl);
pipe_status_t         usbh_pipe_status_get(pipe_handle_t pipe_hdl);

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_USBD_HOST_H_ */

/** @} */