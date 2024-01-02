/*
  Keyboard.h

  Copyright (c) 2015, Arduino LLC
  Original code (pre-library): Copyright (c) 2011, Peter Barrett

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once
#include <stdint.h>

typedef union {
    struct {
            uint8_t numlock:1;
            uint8_t capslock:1;
            uint8_t scrolllock:1;
            uint8_t compose:1;
            uint8_t kana:1;
            uint8_t reserved:3;
    };
    uint8_t leds;
} arduino_usb_hid_keyboard_event_data_t;

// Power Control
#define CONSUMER_CONTROL_POWER                             0x0030
#define CONSUMER_CONTROL_RESET                             0x0031
#define CONSUMER_CONTROL_SLEEP                             0x0032

// Screen Brightness
#define CONSUMER_CONTROL_BRIGHTNESS_INCREMENT              0x006F
#define CONSUMER_CONTROL_BRIGHTNESS_DECREMENT              0x0070

// These HID usages operate only on mobile systems (battery powered) and
// require Windows 8 (build 8302 or greater).
#define CONSUMER_CONTROL_WIRELESS_RADIO_CONTROLS           0x000C
#define CONSUMER_CONTROL_WIRELESS_RADIO_BUTTONS            0x00C6
#define CONSUMER_CONTROL_WIRELESS_RADIO_LED                0x00C7
#define CONSUMER_CONTROL_WIRELESS_RADIO_SLIDER_SWITCH      0x00C8

// Media Control
#define CONSUMER_CONTROL_PLAY_PAUSE                        0x00CD
#define CONSUMER_CONTROL_SCAN_NEXT                         0x00B5
#define CONSUMER_CONTROL_SCAN_PREVIOUS                     0x00B6
#define CONSUMER_CONTROL_STOP                              0x00B7
#define CONSUMER_CONTROL_VOLUME                            0x00E0
#define CONSUMER_CONTROL_MUTE                              0x00E2
#define CONSUMER_CONTROL_BASS                              0x00E3
#define CONSUMER_CONTROL_TREBLE                            0x00E4
#define CONSUMER_CONTROL_BASS_BOOST                        0x00E5
#define CONSUMER_CONTROL_VOLUME_INCREMENT                  0x00E9
#define CONSUMER_CONTROL_VOLUME_DECREMENT                  0x00EA
#define CONSUMER_CONTROL_BASS_INCREMENT                    0x0152
#define CONSUMER_CONTROL_BASS_DECREMENT                    0x0153
#define CONSUMER_CONTROL_TREBLE_INCREMENT                  0x0154
#define CONSUMER_CONTROL_TREBLE_DECREMENT                  0x0155

// Application Launcher
#define CONSUMER_CONTROL_CONFIGURATION                     0x0183
#define CONSUMER_CONTROL_EMAIL_READER                      0x018A
#define CONSUMER_CONTROL_CALCULATOR                        0x0192
#define CONSUMER_CONTROL_LOCAL_BROWSER                     0x0194

// Browser/Explorer Specific
#define CONSUMER_CONTROL_SEARCH                            0x0221
#define CONSUMER_CONTROL_HOME                              0x0223
#define CONSUMER_CONTROL_BACK                              0x0224
#define CONSUMER_CONTROL_FORWARD                           0x0225
#define CONSUMER_CONTROL_BR_STOP                           0x0226
#define CONSUMER_CONTROL_REFRESH                           0x0227
#define CONSUMER_CONTROL_BOOKMARKS                         0x022A

// Mouse Horizontal scroll
#define CONSUMER_CONTROL_PAN                               0x0238

#define CC_BIT_0 CONSUMER_CONTROL_SCAN_NEXT
#define CC_BIT_1 CONSUMER_CONTROL_SCAN_PREVIOUS
#define CC_BIT_2 CONSUMER_CONTROL_STOP
#define CC_BIT_3 CONSUMER_CONTROL_PLAY_PAUSE
#define CC_BIT_4 CONSUMER_CONTROL_MUTE
#define CC_BIT_5 CONSUMER_CONTROL_VOLUME_INCREMENT
#define CC_BIT_6 CONSUMER_CONTROL_VOLUME_DECREMENT
#define CC_BIT_7 CONSUMER_CONTROL_HOME
#define CC_BIT_8 CONSUMER_CONTROL_LOCAL_BROWSER
#define CC_BIT_9 CONSUMER_CONTROL_CALCULATOR
#define CC_BIT_A CONSUMER_CONTROL_BRIGHTNESS_DECREMENT
#define CC_BIT_B CONSUMER_CONTROL_BRIGHTNESS_INCREMENT
#define CC_BIT_C CONSUMER_CONTROL_BR_STOP
#define CC_BIT_D CONSUMER_CONTROL_BACK
#define CC_BIT_E CONSUMER_CONTROL_CONFIGURATION
#define CC_BIT_F CONSUMER_CONTROL_EMAIL_READER

#define M_KEY_TYPE_MASK        ((uint32_t)0xffff0000UL)
#define M_KEY_TARGET_MASK      ((uint32_t)0xC0000000UL)

#define M_KEY_TARGET_KB       ((uint32_t)0x40000000UL)
#define M_KEY_TARGET_CC       ((uint32_t)0x80000000UL)

#define M_KEY_TYPE_MODIF      (M_KEY_TARGET_KB | (uint32_t)0x01000000UL)
#define M_KEY_TYPE_NONPRINT   (M_KEY_TARGET_KB | (uint32_t)0x02000000UL)
#define M_KEY_TYPE_KEYPAD     (M_KEY_TARGET_KB | (uint32_t)0x04000000UL)
#define SHIFT               (M_KEY_TARGET_KB | (uint32_t)0x08000000UL)

#define M_KEY_LEFT_CTRL       (M_KEY_TYPE_MODIF | (uint32_t)0x01UL)
#define M_KEY_LEFT_SHIFT      (M_KEY_TYPE_MODIF | (uint32_t)0x02UL)
#define M_KEY_LEFT_ALT        (M_KEY_TYPE_MODIF | (uint32_t)0x04UL)
#define M_KEY_LEFT_GUI        (M_KEY_TYPE_MODIF | (uint32_t)0x08UL)
#define M_KEY_RIGHT_CTRL      (M_KEY_TYPE_MODIF | (uint32_t)0x10UL)
#define M_KEY_RIGHT_SHIFT     (M_KEY_TYPE_MODIF | (uint32_t)0x20UL)
#define M_KEY_RIGHT_ALT       (M_KEY_TYPE_MODIF | (uint32_t)0x40UL)
#define M_KEY_RIGHT_GUI       (M_KEY_TYPE_MODIF | (uint32_t)0x80UL)

#define M_KEY_UP_ARROW        (M_KEY_TYPE_NONPRINT | (uint32_t)0x0052UL)
#define M_KEY_DOWN_ARROW      (M_KEY_TYPE_NONPRINT | (uint32_t)0x0051UL)
#define M_KEY_LEFT_ARROW      (M_KEY_TYPE_NONPRINT | (uint32_t)0x0050UL)
#define M_KEY_RIGHT_ARROW     (M_KEY_TYPE_NONPRINT | (uint32_t)0x004fUL)
#define M_KEY_BACKSPACE       (M_KEY_TYPE_NONPRINT | (uint32_t)0x002aUL)
#define M_KEY_TAB             (M_KEY_TYPE_NONPRINT | (uint32_t)0x002bUL)
#define M_KEY_RETURN          (M_KEY_TYPE_NONPRINT | (uint32_t)0x0028UL)
#define M_KEY_ESC             (M_KEY_TYPE_NONPRINT | (uint32_t)0x0029UL)
#define M_KEY_INSERT          (M_KEY_TYPE_NONPRINT | (uint32_t)0x0049UL)
#define M_KEY_PRTSC           (M_KEY_TYPE_NONPRINT | (uint32_t)0x0046UL)
#define M_KEY_DELETE          (M_KEY_TYPE_NONPRINT | (uint32_t)0x004cUL)
#define M_KEY_PAGE_UP         (M_KEY_TYPE_NONPRINT | (uint32_t)0x004bUL)
#define M_KEY_PAGE_DOWN       (M_KEY_TYPE_NONPRINT | (uint32_t)0x004eUL)
#define M_KEY_HOME            (M_KEY_TYPE_NONPRINT | (uint32_t)0x004aUL)
#define M_KEY_END             (M_KEY_TYPE_NONPRINT | (uint32_t)0x004dUL)
#define M_KEY_CAPS_LOCK       (M_KEY_TYPE_NONPRINT | (uint32_t)0x0039UL)
#define M_KEY_NUM_LOCK        (M_KEY_TYPE_NONPRINT | (uint32_t)0x0053UL)

#define M_KEY_F1              (M_KEY_TYPE_NONPRINT | (uint32_t)0x003aUL)
#define M_KEY_F2              (M_KEY_TYPE_NONPRINT | (uint32_t)0x003bUL)
#define M_KEY_F3              (M_KEY_TYPE_NONPRINT | (uint32_t)0x003cUL)
#define M_KEY_F4              (M_KEY_TYPE_NONPRINT | (uint32_t)0x003dUL)
#define M_KEY_F5              (M_KEY_TYPE_NONPRINT | (uint32_t)0x003eUL)
#define M_KEY_F6              (M_KEY_TYPE_NONPRINT | (uint32_t)0x003fUL)
#define M_KEY_F7              (M_KEY_TYPE_NONPRINT | (uint32_t)0x0040UL)
#define M_KEY_F8              (M_KEY_TYPE_NONPRINT | (uint32_t)0x0041UL)
#define M_KEY_F9              (M_KEY_TYPE_NONPRINT | (uint32_t)0x0042UL)
#define M_KEY_F10             (M_KEY_TYPE_NONPRINT | (uint32_t)0x0043UL)
#define M_KEY_F11             (M_KEY_TYPE_NONPRINT | (uint32_t)0x0044UL)
#define M_KEY_F12             (M_KEY_TYPE_NONPRINT | (uint32_t)0x0045UL)
#define M_KEY_PRTSC           (M_KEY_TYPE_NONPRINT | (uint32_t)0x0046UL)
#define M_KEY_F13             (M_KEY_TYPE_NONPRINT | (uint32_t)0x0068UL)
#define M_KEY_F14             (M_KEY_TYPE_NONPRINT | (uint32_t)0x0069UL)
#define M_KEY_F15             (M_KEY_TYPE_NONPRINT | (uint32_t)0x006aUL)
#define M_KEY_F16             (M_KEY_TYPE_NONPRINT | (uint32_t)0x006bUL)
#define M_KEY_F17             (M_KEY_TYPE_NONPRINT | (uint32_t)0x006cUL)
#define M_KEY_F18             (M_KEY_TYPE_NONPRINT | (uint32_t)0x006dUL)
#define M_KEY_F19             (M_KEY_TYPE_NONPRINT | (uint32_t)0x006eUL)
#define M_KEY_F20             (M_KEY_TYPE_NONPRINT | (uint32_t)0x006fUL)
#define M_KEY_F21             (M_KEY_TYPE_NONPRINT | (uint32_t)0x0070UL)
#define M_KEY_F22             (M_KEY_TYPE_NONPRINT | (uint32_t)0x0071UL)
#define M_KEY_F23             (M_KEY_TYPE_NONPRINT | (uint32_t)0x0072UL)
#define M_KEY_F24             (M_KEY_TYPE_NONPRINT | (uint32_t)0x0073UL)

#define M_KEY_NUM_0           (M_KEY_TYPE_KEYPAD | (uint32_t)0x0062UL)
#define M_KEY_NUM_1           (M_KEY_TYPE_KEYPAD | (uint32_t)0x0059UL)
#define M_KEY_NUM_2           (M_KEY_TYPE_KEYPAD | (uint32_t)0x005aUL)
#define M_KEY_NUM_3           (M_KEY_TYPE_KEYPAD | (uint32_t)0x005bUL)
#define M_KEY_NUM_4           (M_KEY_TYPE_KEYPAD | (uint32_t)0x005cUL)
#define M_KEY_NUM_5           (M_KEY_TYPE_KEYPAD | (uint32_t)0x005dUL)
#define M_KEY_NUM_6           (M_KEY_TYPE_KEYPAD | (uint32_t)0x005eUL)
#define M_KEY_NUM_7           (M_KEY_TYPE_KEYPAD | (uint32_t)0x005fUL)
#define M_KEY_NUM_8           (M_KEY_TYPE_KEYPAD | (uint32_t)0x0060UL)
#define M_KEY_NUM_9           (M_KEY_TYPE_KEYPAD | (uint32_t)0x0061UL)
#define M_KEY_NUM_SLASH       (M_KEY_TYPE_KEYPAD | (uint32_t)0x0054UL)
#define M_KEY_NUM_ASTERISK    (M_KEY_TYPE_KEYPAD | (uint32_t)0x0055UL)
#define M_KEY_NUM_MINUS       (M_KEY_TYPE_KEYPAD | (uint32_t)0x0056UL)
#define M_KEY_NUM_PLUS        (M_KEY_TYPE_KEYPAD | (uint32_t)0x0057UL)
#define M_KEY_NUM_ENTER       (M_KEY_TYPE_KEYPAD | (uint32_t)0x0058UL)
#define M_KEY_NUM_PERIOD      (M_KEY_TYPE_KEYPAD | (uint32_t)0x0063UL)
#define M_KEY_NUM_EQUAL       (M_KEY_TYPE_KEYPAD | (uint32_t)0x0067UL)


typedef uint32_t MediaKeyReport;

#define M_KEY_MEDIA_NEXT              (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0x0U))
#define M_KEY_MEDIA_PREV              (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0x1U))
#define M_KEY_MEDIA_STOP              (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0x2U))
#define M_KEY_MEDIA_PAUSE             (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0x3U))
#define M_KEY_MEDIA_MUTE              (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0x4U))
#define M_KEY_MEDIA_VOLUP             (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0x5U))
#define M_KEY_MEDIA_VOLDN             (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0x6U))
#define M_KEY_MEDIA_WWW_HOME          (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0x7U))

#define M_KEY_FILE_EXPLORER           (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0x8U))
#define M_KEY_MEDIA_CALC              (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0x9U))
#define M_KEY_MEDIA_BRIGHTNESS_D      (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0xAU))
#define M_KEY_MEDIA_BRIGHTNESS_I      (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0xBU))
#define M_KEY_MEDIA_WWW_STOP          (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0xCU))
#define M_KEY_MEDIA_WWW_BACK          (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0xDU))
#define M_KEY_CONSUMER_CTL            (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0xEU))
#define M_KEY_MEDIA_EMAIL             (M_KEY_TARGET_CC | (MediaKeyReport) (1UL << 0xFU))

#define STR_LEFT_CTRL "\x80"
#define STR_LEFT_SHIFT "\x81"
#define STR_LEFT_ALT "\x82"
#define STR_LEFT_GUI "\x83"
#define STR_RIGHT_CTRL "\x84"
#define STR_RIGHT_SHIFT "\x85"
#define STR_RIGHT_ALT "\x86"
#define STR_RIGHT_GUI "\x87"
#define STR_UP_ARROW "\x88"
#define STR_DOWN_ARROW "\x89"
#define STR_LEFT_ARROW "\x8a"
#define STR_RIGHT_ARROW "\x8b"
#define STR_BACKSPACE "\x8c"
#define STR_TAB "\x8d"
#define STR_RETURN "\x8e"
#define STR_ESC "\x8f"
#define STR_INSERT "\x90"
#define STR_PRTSC "\x91"
#define STR_DELETE "\x92"
#define STR_PAGE_UP "\x93"
#define STR_PAGE_DOWN "\x94"
#define STR_HOME "\x95"
#define STR_END "\x96"
#define STR_CAPS_LOCK "\x97"
#define STR_NUM_LOCK "\x98"
#define STR_F1 "\x99"
#define STR_F2 "\x9a"
#define STR_F3 "\x9b"
#define STR_F4 "\x9c"
#define STR_F5 "\x9d"
#define STR_F6 "\x9e"
#define STR_F7 "\x9f"
#define STR_F8 "\xa0"
#define STR_F9 "\xa1"
#define STR_F10 "\xa2"
#define STR_F11 "\xa3"
#define STR_F12 "\xa4"
#define STR_F13 "\xa5"
#define STR_F14 "\xa6"
#define STR_F15 "\xa7"
#define STR_F16 "\xa8"
#define STR_F17 "\xa9"
#define STR_F18 "\xaa"
#define STR_F19 "\xab"
#define STR_F20 "\xac"
#define STR_F21 "\xad"
#define STR_F22 "\xae"
#define STR_F23 "\xaf"
#define STR_F24 "\xb0"
#define STR_NUM_0 "\xb1"
#define STR_NUM_1 "\xb2"
#define STR_NUM_2 "\xb3"
#define STR_NUM_3 "\xb4"
#define STR_NUM_4 "\xb5"
#define STR_NUM_5 "\xb6"
#define STR_NUM_6 "\xb7"
#define STR_NUM_7 "\xb8"
#define STR_NUM_8 "\xb9"
#define STR_NUM_9 "\xba"
#define STR_NUM_SLASH "\xbb"
#define STR_NUM_ASTERISK "\xbc"
#define STR_NUM_MINUS "\xbd"
#define STR_NUM_PLUS "\xbe"
#define STR_NUM_ENTER "\xbf"
#define STR_NUM_PERIOD "\xc0"
#define STR_NUM_EQUAL "\xc1"
#define STR_MEDIA_NEXT "\xc2"
#define STR_MEDIA_PREV "\xc3"
#define STR_MEDIA_STOP "\xc4"
#define STR_MEDIA_PAUSE "\xc5"
#define STR_MEDIA_MUTE "\xc6"
#define STR_MEDIA_VOLUP "\xc7"
#define STR_MEDIA_VOLDN "\xc8"
#define STR_MEDIA_WWW_HOME "\xc9"
#define STR_FILE_EXPLORER "\xca"
#define STR_MEDIA_CALC "\xcb"
#define STR_MEDIA_BRIGHTNESS_D "\xcc"
#define STR_MEDIA_BRIGHTNESS_I "\xcd"
#define STR_MEDIA_WWW_STOP "\xce"
#define STR_MEDIA_WWW_BACK "\xcf"
#define STR_CONSUMER_CTL "\xd0"
#define STR_MEDIA_EMAIL "\xd1"

#define LED_NUMLOCK     0x01
#define LED_CAPSLOCK    0x02
#define LED_SCROLLLOCK  0x04
#define LED_COMPOSE     0x08
#define LED_KANA        0x10

//  Low level key report: up to 6 keys and shift, ctrl etc at once
typedef struct
{
  uint8_t modifiers;
  uint8_t reserved;
  uint8_t keys[62];
} KeyReport;

const uint32_t _asciimap[] =
{
    0x00U, // NUL
    0x00U, // SOH
    0x00U, // STX
    0x00U, // ETX
    0x00U, // EOT
    0x00U, // ENQ
    0x00U, // ACK
    0x00U, // BEL
    0x2aU, // BS    Backspace
    0x2bU, // TAB   Tab
    0x28U, // LF    Enter
    0x00U, // VT
    0x00U, // FF
    0x00U, // CR
    0x00U, // SO
    0x00U, // SI
    0x00U, // DEL
    0x00U, // DC1
    0x00U, // DC2
    0x00U, // DC3
    0x00U, // DC4
    0x00U, // NAK
    0x00U, // SYN
    0x00U, // ETB
    0x00U, // CAN
    0x00U, // EM
    0x00U, // SUB
    0x00U, // ESC
    0x00U, // FS
    0x00U, // GS
    0x00U, // RS
    0x00U, // US
    0x2cU,         //  ' '
    0x1eU | SHIFT, // !
    0x34U | SHIFT, // "
    0x20U | SHIFT, // #
    0x21U | SHIFT, // $
    0x22U | SHIFT, // %
    0x24U | SHIFT, // &
    0x34U,         // '
    0x26U | SHIFT, // (
    0x27U | SHIFT, // )
    0x25U | SHIFT, // *
    0x2eU | SHIFT, // +
    0x36U,         // ,
    0x2dU,         // -
    0x37U,         // .
    0x38U,         // /
    0x27U,         // 0
    0x1eU,         // 1
    0x1fU,         // 2
    0x20U,         // 3
    0x21U,         // 4
    0x22U,         // 5
    0x23U,         // 6
    0x24U,         // 7
    0x25U,         // 8
    0x26U,         // 9
    0x33U | SHIFT, // :
    0x33U,         // ;
    0x36U | SHIFT, // <
    0x2eU,         // =
    0x37U | SHIFT, // >
    0x38U | SHIFT, // ?
    0x1fU | SHIFT, // @
    0x04U | SHIFT, // A
    0x05U | SHIFT, // B
    0x06U | SHIFT, // C
    0x07U | SHIFT, // D
    0x08U | SHIFT, // E
    0x09U | SHIFT, // F
    0x0aU | SHIFT, // G
    0x0bU | SHIFT, // H
    0x0cU | SHIFT, // I
    0x0dU | SHIFT, // J
    0x0eU | SHIFT, // K
    0x0fU | SHIFT, // L
    0x10U | SHIFT, // M
    0x11U | SHIFT, // N
    0x12U | SHIFT, // O
    0x13U | SHIFT, // P
    0x14U | SHIFT, // Q
    0x15U | SHIFT, // R
    0x16U | SHIFT, // S
    0x17U | SHIFT, // T
    0x18U | SHIFT, // U
    0x19U | SHIFT, // V
    0x1aU | SHIFT, // W
    0x1bU | SHIFT, // X
    0x1cU | SHIFT, // Y
    0x1dU | SHIFT, // Z
    0x2fU,         // [
    0x31U,         // bslash
    0x30U,         // ]
    0x23U | SHIFT, // ^
    0x2dU | SHIFT, // _
    0x35U,         // `
    0x04U,         // a
    0x05U,         // b
    0x06U,         // c
    0x07U,         // d
    0x08U,         // e
    0x09U,         // f
    0x0aU,         // g
    0x0bU,         // h
    0x0cU,         // i
    0x0dU,         // j
    0x0eU,         // k
    0x0fU,         // l
    0x10U,         // m
    0x11U,         // n
    0x12U,         // o
    0x13U,         // p
    0x14U,         // q
    0x15U,         // r
    0x16U,         // s
    0x17U,         // t
    0x18U,         // u
    0x19U,         // v
    0x1aU,         // w
    0x1bU,         // x
    0x1cU,         // y
    0x1dU,         // z
    0x2fU | SHIFT, // {
    0x31U | SHIFT, // |
    0x30U | SHIFT, // }
    0x35U | SHIFT, // ~
    0x00U,         // DEL
    // MODIFIER
    M_KEY_LEFT_CTRL,
    M_KEY_LEFT_SHIFT,
    M_KEY_LEFT_ALT, 
    M_KEY_LEFT_GUI, 
    M_KEY_RIGHT_CTRL, 
    M_KEY_RIGHT_SHIFT, 
    M_KEY_RIGHT_ALT, 
    M_KEY_RIGHT_GUI, 
    // NONPRINT
    M_KEY_UP_ARROW,
    M_KEY_DOWN_ARROW,
    M_KEY_LEFT_ARROW,
    M_KEY_RIGHT_ARROW,
    M_KEY_BACKSPACE,
    M_KEY_TAB,
    M_KEY_RETURN,
    M_KEY_ESC,
    M_KEY_INSERT,
    M_KEY_PRTSC,
    M_KEY_DELETE,
    M_KEY_PAGE_UP,
    M_KEY_PAGE_DOWN,
    M_KEY_HOME,
    M_KEY_END,
    M_KEY_CAPS_LOCK,
    M_KEY_NUM_LOCK,

    // F Keys
    M_KEY_F1, 
    M_KEY_F2, 
    M_KEY_F3, 
    M_KEY_F4, 
    M_KEY_F5, 
    M_KEY_F6, 
    M_KEY_F7, 
    M_KEY_F8, 
    M_KEY_F9, 
    M_KEY_F10, 
    M_KEY_F11, 
    M_KEY_F12, 
    M_KEY_F13, 
    M_KEY_F14, 
    M_KEY_F15, 
    M_KEY_F16, 
    M_KEY_F17, 
    M_KEY_F18, 
    M_KEY_F19, 
    M_KEY_F20, 
    M_KEY_F21, 
    M_KEY_F22, 
    M_KEY_F23, 
    M_KEY_F24, 

    // KEYPAD
    M_KEY_NUM_0,
    M_KEY_NUM_1,
    M_KEY_NUM_2,
    M_KEY_NUM_3,
    M_KEY_NUM_4,
    M_KEY_NUM_5,
    M_KEY_NUM_6,
    M_KEY_NUM_7,
    M_KEY_NUM_8,
    M_KEY_NUM_9,
    M_KEY_NUM_SLASH,
    M_KEY_NUM_ASTERISK,
    M_KEY_NUM_MINUS,
    M_KEY_NUM_PLUS,
    M_KEY_NUM_ENTER,
    M_KEY_NUM_PERIOD,
    M_KEY_NUM_EQUAL,

    // // MEDIA 1
    // M_KEY_MEDIA_NEXT,
    // M_KEY_MEDIA_PREV, 
    // M_KEY_MEDIA_STOP, 
    // M_KEY_MEDIA_PAUSE, 
    // M_KEY_MEDIA_MUTE, 
    // M_KEY_MEDIA_VOLUP, 
    // M_KEY_MEDIA_VOLDN, 
    // M_KEY_MEDIA_WWW_HOME, 
    
    // // MEDIA 2
    // M_KEY_FILE_EXPLORER, 
    // M_KEY_MEDIA_CALC, 
    // M_KEY_MEDIA_BRIGHTNESS_D, 
    // M_KEY_MEDIA_BRIGHTNESS_I, 
    // M_KEY_MEDIA_WWW_STOP, 
    // M_KEY_MEDIA_WWW_BACK, 
    // M_KEY_CONSUMER_CTL, 
    // M_KEY_MEDIA_EMAIL, 
};

#include <stdio.h>

int main() {
    // char ch[] = STR_F5 STR_F6 STR_F7 STR_F10 STR_F11 STR_F12 "aezakmi" "hesoyam" "cvwkxam" "uzumymw" "vkypqcf" "worshipme" "helloladies" "toodamnhot" "fullclip" STR_ESC;
    char ch[] = \
    STR_CAPS_LOCK "Hello World\n" ;
    FILE* fp = fopen("new.txt", "wb");
    fwrite(ch, sizeof(ch), 1, fp);
}