/*
 * This file is part of the KeepKey project.
 *
 * Copyright (C) 2018 KeepKey LLC
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keepkey/firmware/app_resources.h"

#include "keepkey/board/keepkey_board.h"
#include "keepkey/board/resources.h"

#include <string.h>
#include <stdint.h>

static void screensaver_1(uint8_t *data)
{
    const uint8_t image_data[3820] =
    {
        0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x0b, 0x00, 0xfb, 0x56, 0x93, 0x9f, 0x6f, 0x14, 0x7f, 0x00, 0x7c, 0x00, 0xff, 0xd1, 0x03, 0xde, 0xff, 0xd8, 0x7f, 0x00, 0x7c, 0x00, 0xff, 0xd0, 0x04, 0xde, 0xff, 0x45, 0x7f, 0x00, 0x7b, 0x00, 0xfe, 0xbd, 0xdc, 0x03, 0xde, 0xff, 0x52, 0x7f, 0x00, 0x7b, 0x00, 0xfe, 0x02, 0x69, 0x03, 0xde, 0xff, 0x52, 0x7f, 0x00, 0x7c, 0x00, 0xff, 0x44, 0x03, 0xde, 0xff, 0x52, 0x7f, 0x00, 0x7c, 0x00, 0xff, 0x46, 0x03, 0xde, 0xff, 0x52, 0x7f, 0x00, 0x7c, 0x00, 0xff, 0x46, 0x03, 0xde, 0xff, 0x52, 0x7f, 0x00, 0x7c, 0x00, 0xff, 0x46, 0x03, 0xde, 0xff, 0x52, 0x08, 0x00, 0x02, 0x02, 0xff, 0x03, 0x06, 0x00, 0xfb, 0x05, 0x11, 0x16, 0x13, 0x07, 0x0d, 0x00, 0xff, 0x0d, 0x02, 0x16, 0xff, 0x0d, 0x06, 0x00, 0xff, 0x06, 0x02, 0x1a, 0xff, 0x03, 0x05, 0x00, 0xfc, 0x11, 0x1c, 0x1a, 0x09, 0x7f, 0x00, 0x42, 0x00, 0xff, 0x46, 0x03, 0xde, 0xff, 0x52, 0x06, 0x00, 0xfe, 0x01, 0xc7, 0x02, 0xcd, 0xfe, 0xc6, 0x06, 0x03, 0x00, 0xf7, 0x1c, 0xa0, 0xd2, 0xd5, 0xd7, 0xd6, 0xd3, 0x9e, 0x12, 0x08, 0x00, 0xfc, 0x01, 0x6f, 0xc7, 0xd4, 0x02, 0xd7, 0xfd, 0xd4, 0xc3, 0x4e, 0x04, 0x00, 0xff, 0x99, 0x02, 0xd8, 0xfe, 0xc2, 0x0d, 0x02, 0x00, 0xf8, 0x61, 0xc9, 0xd5, 0xd9, 0xd8, 0xd4, 0x94, 0x03, 0x7f, 0x00, 0x40, 0x00, 0xff, 0x46, 0x03, 0xde, 0xff, 0x52, 0x06, 0x00, 0xff, 0xb0, 0x03, 0xde, 0xfe, 0xd7, 0x06, 0x02, 0x00, 0xff, 0x8d, 0x09, 0xde, 0xff, 0x69, 0x06, 0x00, 0xfe, 0x4c, 0xcf, 0x08, 0xde, 0xfe, 0xaf, 0x11, 0x02, 0x00, 0xff, 0x9f, 0x03, 0xde, 0xfd, 0xbd, 0x21, 0xc2, 0x07, 0xde, 0xfe, 0xda, 0x36, 0x7f, 0x00, 0x3f, 0x00, 0xff, 0x46, 0x03, 0xde, 0xff, 0x52, 0x05, 0x00, 0xff, 0xa3, 0x04, 0xde, 0xfc, 0xd6, 0x06, 0x02, 0xb8, 0x0b, 0xde, 0xff, 0x62, 0x04, 0x00, 0xff, 0x3d, 0x0b, 0xde, 0xff, 0xb4, 0x02, 0x00, 0xff, 0xa0, 0x03, 0xde, 0xfe, 0xdb, 0xd1, 0x0a, 0xde, 0xff, 0x06, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x47, 0x03, 0xde, 0xff, 0x52, 0x04, 0x00, 0xff, 0x82, 0x03, 0xde, 0xfb, 0xd8, 0x29, 0x28, 0x00, 0x59, 0x04, 0xde, 0xfb, 0xb8, 0x52, 0x30, 0x3c, 0x89, 0x03, 0xde, 0xfe, 0xd2, 0x0d, 0x02, 0x00, 0xff, 0x0c, 0x04, 0xde, 0xfa, 0xdd, 0x73, 0x38, 0x30, 0x5d, 0xd4, 0x03, 0xde, 0xfc, 0x71, 0x00, 0x27, 0xc0, 0x05, 0xde, 0xfb, 0xab, 0x4d, 0x2d, 0x3f, 0x95, 0x04, 0xde, 0xff, 0x95, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x44, 0x03, 0xde, 0xff, 0x52, 0x03, 0x00, 0xff, 0x6a, 0x03, 0xde, 0xfe, 0xd6, 0x19, 0x03, 0x00, 0xff, 0xd9, 0x03, 0xde, 0xff, 0x63, 0x05, 0x00, 0xff, 0x44, 0x03, 0xde, 0xff, 0x4e, 0x02, 0x00, 0xff, 0x88, 0x03, 0xde, 0xfe, 0xb5, 0x09, 0x05, 0x00, 0xff, 0xbd, 0x02, 0xde, 0xfc, 0xc9, 0x07, 0x00, 0x25, 0x03, 0xde, 0xfe, 0xda, 0x4e, 0x05, 0x00, 0xff, 0x68, 0x03, 0xde, 0xff, 0xd3, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x52, 0x02, 0x00, 0xff, 0x3c, 0x04, 0xde, 0xff, 0x35, 0x03, 0x00, 0xff, 0x4b, 0x03, 0xde, 0xff, 0x94, 0x07, 0x00, 0xff, 0xbf, 0x02, 0xde, 0xfc, 0xb1, 0x00, 0x03, 0xbe, 0x02, 0xde, 0xff, 0xd0, 0x07, 0x00, 0xff, 0x41, 0x02, 0xde, 0xfc, 0xd9, 0x16, 0x00, 0x20, 0x03, 0xde, 0xff, 0x80, 0x07, 0x00, 0xff, 0xca, 0x02, 0xde, 0xff, 0xdb, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x03, 0xde, 0xfd, 0xc1, 0xb0, 0xae, 0x04, 0xde, 0xff, 0x4f, 0x04, 0x00, 0xff, 0x8e, 0x02, 0xde, 0xff, 0xdd, 0x08, 0x00, 0xff, 0x7f, 0x02, 0xde, 0xfc, 0xdc, 0x00, 0x06, 0xda, 0x02, 0xde, 0xff, 0x6a, 0x07, 0x00, 0xfe, 0x1d, 0xdd, 0x02, 0xde, 0xfd, 0x2f, 0x00, 0x20, 0x03, 0xde, 0xff, 0x5f, 0x07, 0x00, 0xff, 0xb1, 0x02, 0xde, 0xff, 0xdc, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x09, 0xde, 0xff, 0x7c, 0x04, 0x00, 0xfe, 0x01, 0xab, 0x02, 0xde, 0xfe, 0xd1, 0x89, 0x06, 0x8d, 0xfe, 0x8a, 0xbd, 0x03, 0xde, 0xfe, 0x06, 0x22, 0x03, 0xde, 0xff, 0xa4, 0x07, 0x8d, 0xff, 0x9a, 0x03, 0xde, 0xfd, 0x44, 0x00, 0x20, 0x03, 0xde, 0xff, 0x5f, 0x07, 0x00, 0xff, 0xb1, 0x02, 0xde, 0xff, 0xdc, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x08, 0xde, 0xff, 0xc5, 0x05, 0x00, 0xfe, 0x02, 0xb2, 0x0f, 0xde, 0xfe, 0x07, 0x38, 0x0f, 0xde, 0xfd, 0x48, 0x00, 0x20, 0x03, 0xde, 0xff, 0x5f, 0x07, 0x00, 0xff, 0xb1, 0x02, 0xde, 0xff, 0xdc, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x09, 0xde, 0xff, 0x9c, 0x04, 0x00, 0xfe, 0x02, 0xb1, 0x02, 0xde, 0xff, 0xdd, 0x0b, 0xda, 0xfd, 0xde, 0x00, 0x36, 0x03, 0xde, 0x0b, 0xda, 0xfc, 0xdd, 0x3a, 0x00, 0x20, 0x03, 0xde, 0xff, 0x5f, 0x07, 0x00, 0xff, 0xb1, 0x02, 0xde, 0xff, 0xdc, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x03, 0xde, 0xfc, 0x8b, 0x5d, 0x57, 0xc8, 0x03, 0xde, 0xff, 0x59, 0x03, 0x00, 0xfe, 0x01, 0xa9, 0x02, 0xde, 0xff, 0xcd, 0x0d, 0x00, 0xff, 0x1f, 0x03, 0xde, 0xff, 0x52, 0x0d, 0x00, 0xff, 0x1f, 0x03, 0xde, 0xff, 0x5f, 0x07, 0x00, 0xff, 0xb1, 0x02, 0xde, 0xff, 0xdc, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x50, 0x02, 0x00, 0xfe, 0x19, 0xd7, 0x03, 0xde, 0xff, 0x35, 0x03, 0x00, 0xff, 0x89, 0x03, 0xde, 0xff, 0x27, 0x0c, 0x00, 0xfe, 0x07, 0xd9, 0x02, 0xde, 0xff, 0x91, 0x0d, 0x00, 0xff, 0x22, 0x03, 0xde, 0xff, 0x63, 0x07, 0x00, 0xff, 0xb5, 0x02, 0xde, 0xff, 0xdc, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x52, 0x03, 0x00, 0xff, 0x4d, 0x03, 0xde, 0xfe, 0xcf, 0x0d, 0x02, 0x00, 0xff, 0x43, 0x03, 0xde, 0xfe, 0xc5, 0x08, 0x06, 0x00, 0xfe, 0x09, 0x46, 0x03, 0x00, 0xfe, 0x03, 0xbc, 0x03, 0xde, 0xff, 0x38, 0x07, 0x00, 0xfe, 0x36, 0x1a, 0x03, 0x00, 0xff, 0x23, 0x03, 0xde, 0xff, 0xaf, 0x06, 0x00, 0xff, 0x0e, 0x03, 0xde, 0xff, 0xd6, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x52, 0x04, 0x00, 0xff, 0x6d, 0x03, 0xde, 0xff, 0xb6, 0x03, 0x00, 0xff, 0xd2, 0x03, 0xde, 0xfe, 0xcb, 0x27, 0x04, 0x00, 0xfc, 0x52, 0xd8, 0xde, 0x42, 0x03, 0x00, 0xff, 0x7c, 0x03, 0xde, 0xfe, 0xdb, 0x6c, 0x04, 0x00, 0xfc, 0x1c, 0xac, 0xdd, 0x9b, 0x03, 0x00, 0xff, 0x23, 0x04, 0xde, 0xfe, 0xc5, 0x1d, 0x03, 0x00, 0xfe, 0x15, 0xc7, 0x03, 0xde, 0xff, 0xad, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x52, 0x04, 0x00, 0xfe, 0x01, 0xab, 0x03, 0xde, 0xfc, 0xbd, 0xaf, 0x03, 0x45, 0x05, 0xde, 0xfc, 0xc6, 0xb4, 0xbc, 0xd8, 0x03, 0xde, 0xfe, 0xcf, 0x0e, 0x02, 0x00, 0xfe, 0x03, 0xd1, 0x04, 0xde, 0xfc, 0xd7, 0xb7, 0xb6, 0xca, 0x04, 0xde, 0xff, 0x61, 0x02, 0x00, 0xff, 0x23, 0x06, 0xde, 0xfd, 0xc6, 0xb4, 0xc1, 0x05, 0xde, 0xff, 0x22, 0x7f, 0x00, 0x3e, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x52, 0x06, 0x00, 0xff, 0xc9, 0x03, 0xde, 0xfc, 0xd7, 0x06, 0x00, 0x98, 0x0a, 0xde, 0xfd, 0xd9, 0xa2, 0x0b, 0x03, 0x00, 0xfe, 0x27, 0xd5, 0x0a, 0xde, 0xfe, 0xc7, 0x47, 0x02, 0x00, 0xff, 0x23, 0x03, 0xde, 0xff, 0xbb, 0x09, 0xde, 0xff, 0x66, 0x07, 0x00, 0xfd, 0x12, 0xe5, 0x49, 0x1e, 0x00, 0xfd, 0x12, 0xe5, 0x49, 0x39, 0x00, 0xfd, 0x0f, 0xd4, 0x33, 0x12, 0x00, 0xfe, 0x02, 0x25, 0x11, 0x00, 0xfe, 0x02, 0x25, 0x12, 0x00, 0xfe, 0x02, 0x25, 0x11, 0x00, 0xfe, 0x7b, 0xb6, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x52, 0x06, 0x00, 0xff, 0x29, 0x03, 0xde, 0xfe, 0xdc, 0x07, 0x02, 0x00, 0xff, 0x55, 0x08, 0xde, 0xfe, 0x82, 0x1a, 0x06, 0x00, 0xfe, 0x17, 0xb7, 0x07, 0xde, 0xfd, 0xb6, 0x37, 0x05, 0x03, 0x00, 0xff, 0x23, 0x03, 0xde, 0xfd, 0x5e, 0x35, 0xd4, 0x05, 0xde, 0xfe, 0xd3, 0x35, 0x08, 0x00, 0xfd, 0x24, 0xff, 0x68, 0x1e, 0x00, 0xfd, 0x24, 0xff, 0x68, 0x39, 0x00, 0xfd, 0x66, 0xfd, 0x1b, 0x12, 0x00, 0xfd, 0x48, 0xff, 0x2b, 0x10, 0x00, 0xfd, 0x48, 0xff, 0x2b, 0x11, 0x00, 0xfd, 0x48, 0xff, 0x2b, 0x10, 0x00, 0xfe, 0xa4, 0xe0, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x52, 0x07, 0x00, 0xff, 0x28, 0x03, 0x3b, 0xff, 0x02, 0x03, 0x00, 0xf8, 0x04, 0x4c, 0x76, 0x87, 0x7e, 0x63, 0x37, 0x02, 0x0a, 0x00, 0xf9, 0x30, 0x68, 0x83, 0x85, 0x70, 0x4d, 0x16, 0x06, 0x00, 0xff, 0x23, 0x03, 0xde, 0xff, 0x5f, 0x02, 0x00, 0xfb, 0x3b, 0x68, 0x77, 0x68, 0x3b, 0x0a, 0x00, 0xfd, 0x24, 0xff, 0x68, 0x1e, 0x00, 0xfd, 0x24, 0xff, 0x68, 0x39, 0x00, 0xfe, 0xc8, 0xb5, 0x13, 0x00, 0xfd, 0x54, 0xff, 0x38, 0x10, 0x00, 0xfd, 0x54, 0xff, 0x38, 0x11, 0x00, 0xfd, 0x54, 0xff, 0x38, 0x10, 0x00, 0xfe, 0xa4, 0xe0, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x52, 0x2e, 0x00, 0xff, 0x23, 0x03, 0xde, 0xff, 0x5f, 0x11, 0x00, 0xf9, 0x24, 0xff, 0x68, 0x00, 0x06, 0xa5, 0xb2, 0x02, 0x00, 0xfa, 0x09, 0x8e, 0xdd, 0xed, 0xad, 0x1d, 0x02, 0x00, 0xe9, 0x09, 0x8e, 0xdd, 0xed, 0xad, 0x1d, 0x00, 0x13, 0xe4, 0x49, 0xad, 0xf3, 0xda, 0x79, 0x02, 0x00, 0x24, 0xff, 0x68, 0x00, 0x06, 0xa5, 0xb2, 0x02, 0x00, 0xf7, 0x09, 0x8e, 0xdd, 0xed, 0xad, 0x1d, 0x00, 0x97, 0xa9, 0x03, 0x00, 0xfd, 0x16, 0xd8, 0x4a, 0x05, 0x00, 0xfa, 0x08, 0x8d, 0xdc, 0xf1, 0xb4, 0x25, 0x02, 0x00, 0xee, 0x07, 0x86, 0xda, 0xf0, 0xbb, 0x31, 0x00, 0x13, 0xe3, 0x60, 0xc5, 0xf6, 0xc0, 0x1c, 0x8e, 0xed, 0xe8, 0x7a, 0x04, 0x00, 0xfd, 0x2a, 0xff, 0x53, 0x02, 0x00, 0xf9, 0x0b, 0x96, 0xe3, 0xec, 0x81, 0x8e, 0x9c, 0x02, 0x00, 0xf8, 0x09, 0x8e, 0xdd, 0xed, 0xad, 0x1d, 0x00, 0xc0, 0x04, 0xff, 0xff, 0x5c, 0x07, 0x00, 0xf9, 0x4e, 0xcd, 0xf6, 0xe1, 0x81, 0x04, 0xc0, 0x04, 0xff, 0xf8, 0x5c, 0x00, 0x22, 0xb0, 0xea, 0xf3, 0xbe, 0x2d, 0x02, 0x00, 0xfa, 0xc8, 0x7b, 0xa8, 0xf5, 0xcb, 0xc0, 0x04, 0xff, 0xf8, 0x5c, 0x00, 0x09, 0x8e, 0xdd, 0xed, 0xad, 0x1d, 0x02, 0x00, 0xf9, 0x0e, 0x9b, 0xe7, 0xeb, 0x83, 0xa4, 0xe0, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x52, 0x2e, 0x00, 0xff, 0x23, 0x03, 0xde, 0xff, 0x5f, 0x11, 0x00, 0xcc, 0x24, 0xff, 0x68, 0x08, 0xb3, 0xff, 0x6e, 0x00, 0x01, 0xb8, 0xe3, 0x6d, 0x5f, 0xc9, 0xe1, 0x0e, 0x01, 0xb8, 0xe3, 0x6d, 0x5f, 0xc9, 0xe1, 0x0e, 0x28, 0xff, 0xfc, 0xb0, 0x6d, 0x9d, 0xff, 0x81, 0x00, 0x24, 0xff, 0x68, 0x08, 0xb3, 0xff, 0x6e, 0x00, 0x01, 0xb8, 0xe3, 0x6d, 0x5f, 0xc9, 0xe1, 0x0e, 0x86, 0xff, 0x28, 0x02, 0x00, 0xfd, 0x73, 0xff, 0x31, 0x05, 0x00, 0xf0, 0xb5, 0xf6, 0x87, 0x76, 0xd9, 0xe3, 0x0e, 0x00, 0xaf, 0xf6, 0x88, 0x6b, 0xc4, 0xf9, 0x2a, 0x28, 0x02, 0xff, 0xf7, 0x9f, 0x7e, 0xf8, 0xee, 0xe2, 0x7d, 0xb5, 0xff, 0x35, 0x03, 0x00, 0xe5, 0x8b, 0xec, 0x06, 0x00, 0x01, 0xba, 0xf4, 0x80, 0x6a, 0xcf, 0xff, 0xc8, 0x00, 0x01, 0xb8, 0xe3, 0x6d, 0x5f, 0xc9, 0xe1, 0x0e, 0x3e, 0x98, 0xff, 0x87, 0x63, 0x16, 0x06, 0x00, 0xec, 0x2b, 0xfc, 0xb6, 0x66, 0x8a, 0xff, 0x86, 0x3e, 0x98, 0xff, 0x87, 0x63, 0x16, 0x07, 0xd2, 0xec, 0x76, 0x6f, 0xdc, 0xd5, 0x02, 0x00, 0xe5, 0xf4, 0xff, 0xd9, 0x89, 0x67, 0x3e, 0x98, 0xff, 0x87, 0x63, 0x16, 0x01, 0xb8, 0xe3, 0x6d, 0x5f, 0xc9, 0xe1, 0x0e, 0x01, 0xc1, 0xf3, 0x84, 0x74, 0xd4, 0xfd, 0xe0, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x52, 0x2e, 0x00, 0xff, 0x23, 0x03, 0xde, 0xff, 0x5f, 0x11, 0x00, 0xfa, 0x24, 0xff, 0x71, 0xb8, 0xfc, 0x5e, 0x02, 0x00, 0xfd, 0x3e, 0xff, 0x41, 0x02, 0x00, 0xfa, 0x21, 0xfc, 0x6f, 0x3e, 0xff, 0x41, 0x02, 0x00, 0xf9, 0x21, 0xfc, 0x6f, 0x28, 0xff, 0xb2, 0x01, 0x02, 0x00, 0xf7, 0xa3, 0xf5, 0x05, 0x24, 0xff, 0x71, 0xb8, 0xfc, 0x5e, 0x02, 0x00, 0xfd, 0x3e, 0xff, 0x41, 0x02, 0x00, 0xf6, 0x21, 0xfc, 0x6f, 0x21, 0xfe, 0x87, 0x00, 0x01, 0xd2, 0xcb, 0x05, 0x00, 0xfd, 0x3a, 0xff, 0x62, 0x02, 0x00, 0xfa, 0x27, 0xbc, 0x1f, 0x39, 0xff, 0x61, 0x02, 0x00, 0xfa, 0x08, 0xe8, 0xaa, 0x28, 0xff, 0xa8, 0x02, 0x00, 0xf9, 0xbf, 0xff, 0x31, 0x00, 0x32, 0xff, 0x6c, 0x02, 0x00, 0xfd, 0x05, 0xe9, 0x90, 0x02, 0x00, 0xfd, 0x3b, 0xff, 0x61, 0x02, 0x00, 0xf9, 0x10, 0xf2, 0xc8, 0x00, 0x3e, 0xff, 0x41, 0x02, 0x00, 0xf9, 0x21, 0xfc, 0x6f, 0x00, 0x54, 0xff, 0x38, 0x08, 0x00, 0xf5, 0x50, 0xff, 0x5b, 0x01, 0x00, 0x5c, 0x43, 0x00, 0x54, 0xff, 0x38, 0x02, 0x00, 0xf4, 0x04, 0x93, 0x48, 0x2d, 0x49, 0xae, 0xff, 0x0b, 0x00, 0xf4, 0xea, 0x12, 0x03, 0x00, 0xfd, 0x54, 0xff, 0x38, 0x02, 0x00, 0xfd, 0x3e, 0xff, 0x41, 0x02, 0x00, 0xfa, 0x21, 0xfc, 0x6f, 0x41, 0xff, 0x5b, 0x02, 0x00, 0xfd, 0x0f, 0xf0, 0xe0, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x54, 0x2e, 0x00, 0xff, 0x23, 0x03, 0xde, 0xff, 0x5f, 0x11, 0x00, 0xfb, 0x24, 0xff, 0xfd, 0xff, 0xa3, 0x03, 0x00, 0xff, 0x71, 0x06, 0xff, 0xfe, 0x8f, 0x71, 0x06, 0xff, 0xfc, 0x8f, 0x28, 0xff, 0x68, 0x03, 0x00, 0xf8, 0x66, 0xff, 0x26, 0x24, 0xff, 0xfd, 0xff, 0xa3, 0x03, 0x00, 0xff, 0x71, 0x06, 0xff, 0xf8, 0x8f, 0x00, 0xb6, 0xe4, 0x03, 0x31, 0xff, 0x66, 0x05, 0x00, 0xfd, 0x6f, 0xff, 0x1e, 0x05, 0x00, 0xfd, 0x6f, 0xff, 0x1b, 0x03, 0x00, 0xfb, 0xaf, 0xdf, 0x28, 0xff, 0x6b, 0x02, 0x00, 0xf9, 0xa5, 0xea, 0x01, 0x00, 0x19, 0xff, 0x78, 0x02, 0x00, 0xfd, 0x4e, 0xff, 0x2f, 0x02, 0x00, 0xfd, 0x6e, 0xff, 0x1c, 0x03, 0x00, 0xfc, 0xbc, 0xc8, 0x00, 0x71, 0x06, 0xff, 0xfb, 0x8f, 0x00, 0x54, 0xff, 0x38, 0x02, 0x00, 0xfe, 0x53, 0xfe, 0x03, 0xff, 0xf4, 0x80, 0x0a, 0xc4, 0xff, 0xdf, 0xa4, 0x59, 0x03, 0x00, 0x54, 0xff, 0x38, 0x03, 0x00, 0xf6, 0x73, 0xf3, 0xff, 0xf1, 0xef, 0xff, 0x10, 0x00, 0xf4, 0xa5, 0x04, 0x00, 0xfd, 0x54, 0xff, 0x38, 0x02, 0x00, 0xff, 0x71, 0x06, 0xff, 0xfc, 0x8f, 0x72, 0xff, 0x1a, 0x03, 0x00, 0xfe, 0xb3, 0xe0, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x54, 0x07, 0x00, 0xff, 0x45, 0x02, 0x53, 0xfe, 0x51, 0x03, 0x05, 0x00, 0xfa, 0x23, 0x4b, 0x5a, 0x59, 0x42, 0x0f, 0x04, 0x00, 0xff, 0x0c, 0x04, 0x44, 0xfe, 0x48, 0x0d, 0x04, 0x00, 0xfe, 0x01, 0x39, 0x04, 0x44, 0xfd, 0x2b, 0x00, 0x23, 0x03, 0xde, 0xff, 0x5f, 0x11, 0x00, 0xfa, 0x24, 0xff, 0xea, 0xa9, 0xff, 0x4b, 0x02, 0x00, 0xfd, 0x6e, 0xff, 0x5b, 0x03, 0x50, 0xfb, 0x4e, 0x0e, 0x6e, 0xff, 0x5b, 0x03, 0x50, 0xfb, 0x4e, 0x0e, 0x28, 0xff, 0x69, 0x03, 0x00, 0xf7, 0x68, 0xff, 0x22, 0x24, 0xff, 0xea, 0xa9, 0xff, 0x4b, 0x02, 0x00, 0xfd, 0x6e, 0xff, 0x5b, 0x03, 0x50, 0xf7, 0x4e, 0x0e, 0x00, 0x4f, 0xff, 0x46, 0x90, 0xf4, 0x0d, 0x05, 0x00, 0xfd, 0x71, 0xff, 0x1e, 0x05, 0x00, 0xfd, 0x6f, 0xff, 0x1b, 0x03, 0x00, 0xfb, 0xb0, 0xdd, 0x28, 0xff, 0x64, 0x02, 0x00, 0xfe, 0xa4, 0xe4, 0x02, 0x00, 0xfd, 0x18, 0xff, 0x78, 0x02, 0x00, 0xfe, 0xb0, 0xcd, 0x03, 0x00, 0xfd, 0x72, 0xff, 0x1a, 0x03, 0x00, 0xfa, 0xbd, 0xc8, 0x00, 0x6e, 0xff, 0x5b, 0x03, 0x50, 0xfa, 0x4e, 0x0e, 0x00, 0x54, 0xff, 0x38, 0x02, 0x00, 0xfe, 0x1f, 0x86, 0x03, 0x88, 0xf4, 0x36, 0x00, 0x02, 0x3d, 0x7a, 0xba, 0xfc, 0xa9, 0x00, 0x54, 0xff, 0x38, 0x02, 0x00, 0xf5, 0x42, 0xff, 0x98, 0x19, 0x00, 0x71, 0xff, 0x10, 0x00, 0xf4, 0x9c, 0x04, 0x00, 0xfd, 0x54, 0xff, 0x38, 0x02, 0x00, 0xfd, 0x6e, 0xff, 0x5b, 0x03, 0x50, 0xfb, 0x4e, 0x0e, 0x6f, 0xff, 0x1a, 0x03, 0x00, 0xfe, 0xb0, 0xe0, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x54, 0x06, 0x00, 0xff, 0x57, 0x03, 0xde, 0xfe, 0xda, 0x08, 0x02, 0x00, 0xfd, 0x03, 0x47, 0xd0, 0x06, 0xde, 0xfe, 0x96, 0x12, 0x02, 0x00, 0xff, 0x28, 0x05, 0xde, 0xff, 0x29, 0x04, 0x00, 0xfe, 0x02, 0xc1, 0x04, 0xde, 0xfd, 0x92, 0x00, 0x23, 0x03, 0xde, 0xff, 0x5f, 0x11, 0x00, 0xf5, 0x24, 0xff, 0x6b, 0x07, 0xcd, 0xef, 0x21, 0x00, 0x3a, 0xff, 0x49, 0x02, 0x00, 0xfa, 0x0e, 0xb0, 0x4a, 0x3a, 0xff, 0x49, 0x02, 0x00, 0xf9, 0x0e, 0xb0, 0x4a, 0x28, 0xff, 0xb5, 0x01, 0x02, 0x00, 0xf2, 0xaa, 0xee, 0x03, 0x24, 0xff, 0x6b, 0x07, 0xcd, 0xef, 0x21, 0x00, 0x3a, 0xff, 0x49, 0x02, 0x00, 0xf7, 0x0e, 0xb0, 0x4a, 0x00, 0x04, 0xe4, 0xa3, 0xe9, 0x9c, 0x03, 0x00, 0xfa, 0x09, 0x10, 0x00, 0x3e, 0xff, 0x5b, 0x02, 0x00, 0xfa, 0x23, 0xc6, 0x36, 0x3a, 0xff, 0x5d, 0x02, 0x00, 0xfa, 0x08, 0xe8, 0xa7, 0x28, 0xff, 0x64, 0x02, 0x00, 0xfe, 0xa4, 0xe4, 0x02, 0x00, 0xf9, 0x18, 0xff, 0x78, 0x00, 0x17, 0xfc, 0x6b, 0x03, 0x00, 0xfd, 0x41, 0xff, 0x5a, 0x02, 0x00, 0xf9, 0x0f, 0xf1, 0xc8, 0x00, 0x3a, 0xff, 0x49, 0x02, 0x00, 0xf9, 0x0e, 0xb0, 0x4a, 0x00, 0x54, 0xff, 0x3a, 0x08, 0x00, 0xfd, 0x54, 0xa8, 0x0d, 0x02, 0x00, 0xfa, 0x9a, 0xf9, 0x02, 0x54, 0xff, 0x3a, 0x02, 0x00, 0xf5, 0x7d, 0xff, 0x1c, 0x00, 0x01, 0xb6, 0xff, 0x10, 0x00, 0xf4, 0x9c, 0x04, 0x00, 0xfd, 0x54, 0xff, 0x3a, 0x02, 0x00, 0xfd, 0x3a, 0xff, 0x49, 0x02, 0x00, 0xfa, 0x0e, 0xb0, 0x4a, 0x3e, 0xff, 0x5c, 0x02, 0x00, 0xfd, 0x0e, 0xec, 0xe0, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x54, 0x05, 0x00, 0xff, 0x34, 0x04, 0xde, 0xfe, 0xd7, 0x08, 0x02, 0x00, 0xff, 0xac, 0x09, 0xde, 0xfc, 0xd8, 0x29, 0x00, 0x26, 0x05, 0xde, 0xff, 0x28, 0x04, 0x00, 0xfe, 0x02, 0xbc, 0x04, 0xde, 0xfd, 0x8e, 0x00, 0x23, 0x03, 0xde, 0xff, 0x5f, 0x11, 0x00, 0xe7, 0x24, 0xff, 0x68, 0x00, 0x25, 0xf3, 0xcd, 0x07, 0x00, 0xb2, 0xeb, 0x75, 0x62, 0xc0, 0xf2, 0x2c, 0x00, 0xb2, 0xeb, 0x75, 0x62, 0xc0, 0xf2, 0x2c, 0x28, 0x02, 0xff, 0xea, 0xb0, 0x6d, 0xa0, 0xff, 0x70, 0x00, 0x24, 0xff, 0x68, 0x00, 0x25, 0xf3, 0xcd, 0x07, 0x00, 0xb2, 0xeb, 0x75, 0x62, 0xc0, 0xf2, 0x2c, 0x02, 0x00, 0xff, 0x7f, 0x02, 0xff, 0xff, 0x37, 0x02, 0x00, 0xed, 0x01, 0xd5, 0xee, 0x0f, 0x01, 0xb8, 0xf2, 0x80, 0x71, 0xd3, 0xec, 0x16, 0x00, 0xb1, 0xf3, 0x7e, 0x68, 0xc4, 0xf8, 0x02, 0x28, 0xfe, 0xff, 0x64, 0x02, 0x00, 0xfe, 0xa4, 0xe4, 0x02, 0x00, 0xf9, 0x18, 0xff, 0x78, 0x00, 0x73, 0xf9, 0x12, 0x03, 0x00, 0xf8, 0x01, 0xbd, 0xef, 0x72, 0x5e, 0xc7, 0xff, 0xc8, 0x02, 0x00, 0xf3, 0xb2, 0xeb, 0x75, 0x62, 0xc0, 0xf2, 0x2c, 0x00, 0x35, 0xff, 0xab, 0x9a, 0x47, 0x06, 0x00, 0xee, 0x47, 0xff, 0xbf, 0x6f, 0x83, 0xe7, 0xbc, 0x00, 0x35, 0xff, 0xab, 0x9a, 0x47, 0x4d, 0xff, 0xa9, 0x6a, 0xb7, 0x02, 0xff, 0xfc, 0x1d, 0x00, 0xf4, 0x9c, 0x04, 0x00, 0xeb, 0x35, 0xff, 0xab, 0x9a, 0x47, 0x00, 0xb2, 0xeb, 0x75, 0x62, 0xc0, 0xf2, 0x2c, 0x01, 0xbe, 0xf2, 0x7f, 0x6f, 0xd0, 0xff, 0xe0, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x54, 0x04, 0x00, 0xff, 0x28, 0x04, 0xde, 0xfb, 0xab, 0xa2, 0x06, 0x02, 0xab, 0x05, 0xde, 0xfe, 0xd0, 0xcf, 0x04, 0xde, 0xfb, 0xcf, 0x09, 0x20, 0xaf, 0xc7, 0x03, 0xde, 0xff, 0x28, 0x04, 0x00, 0xfd, 0x02, 0x94, 0xb4, 0x03, 0xde, 0xf9, 0x8e, 0x00, 0x1b, 0xb1, 0xab, 0xac, 0x4b, 0x11, 0x00, 0xfd, 0x12, 0xe6, 0x46, 0x02, 0x00, 0xf6, 0x58, 0xe9, 0x1b, 0x00, 0x08, 0x89, 0xdb, 0xf5, 0xc6, 0x3c, 0x02, 0x00, 0xed, 0x08, 0x89, 0xdb, 0xf5, 0xc6, 0x3c, 0x00, 0x28, 0xff, 0x73, 0xb3, 0xf5, 0xd6, 0x6d, 0x01, 0x00, 0x12, 0xe6, 0x46, 0x02, 0x00, 0xf6, 0x58, 0xe9, 0x1b, 0x00, 0x08, 0x89, 0xdb, 0xf5, 0xc6, 0x3c, 0x03, 0x00, 0xfc, 0x1c, 0xfd, 0xd2, 0x01, 0x03, 0x00, 0xf6, 0xa9, 0xca, 0x06, 0x00, 0x0a, 0x90, 0xde, 0xf3, 0xbb, 0x2e, 0x02, 0x00, 0xf6, 0x08, 0x88, 0xdb, 0xf1, 0xbd, 0x30, 0x00, 0x1c, 0xff, 0x55, 0x02, 0x00, 0xfe, 0x7f, 0xbc, 0x02, 0x00, 0xfa, 0x0b, 0xe2, 0x54, 0x01, 0xd5, 0xa8, 0x05, 0x00, 0xf9, 0x0c, 0x97, 0xe6, 0xef, 0x8c, 0xc0, 0xb8, 0x02, 0x00, 0xfa, 0x08, 0x89, 0xdb, 0xf5, 0xc6, 0x3c, 0x02, 0x00, 0xfb, 0x01, 0x8c, 0xf3, 0xd5, 0x56, 0x07, 0x00, 0xe9, 0x53, 0xcd, 0xf6, 0xe6, 0x9c, 0x15, 0x00, 0x01, 0x8c, 0xf3, 0xd5, 0x56, 0x01, 0x7d, 0xe8, 0xea, 0xb0, 0x5a, 0xee, 0x25, 0x00, 0xca, 0x75, 0x04, 0x00, 0xf4, 0x01, 0x8c, 0xf3, 0xd5, 0x56, 0x00, 0x08, 0x89, 0xdb, 0xf5, 0xc6, 0x3c, 0x02, 0x00, 0xf9, 0x0d, 0x9c, 0xe8, 0xed, 0x87, 0x7b, 0xb8, 0x09, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x54, 0x03, 0x00, 0xfe, 0x09, 0xd9, 0x03, 0xde, 0xff, 0x75, 0x03, 0x00, 0xff, 0x3e, 0x04, 0xde, 0xfe, 0x96, 0x0b, 0x02, 0x00, 0xfe, 0x0d, 0xa3, 0x03, 0xde, 0xff, 0x5a, 0x02, 0x00, 0xff, 0x75, 0x03, 0xde, 0xff, 0x24, 0x06, 0x00, 0xfe, 0x1e, 0xdd, 0x02, 0xde, 0xff, 0x8e, 0x2f, 0x00, 0xfd, 0x28, 0xff, 0x60, 0x18, 0x00, 0xfd, 0x21, 0xff, 0x6d, 0x18, 0x00, 0xfe, 0x1e, 0x02, 0x09, 0x00, 0xfd, 0x36, 0xff, 0x47, 0x05, 0x00, 0xff, 0x0f, 0x03, 0x00, 0xfd, 0x01, 0xe0, 0x91, 0x4f, 0x00, 0xff, 0x43, 0x03, 0xde, 0xff, 0x53, 0x02, 0x00, 0xfe, 0x07, 0xc5, 0x03, 0xde, 0xff, 0x9a, 0x04, 0x00, 0xff, 0xb7, 0x02, 0xde, 0xfe, 0xdd, 0x4e, 0x06, 0x00, 0xff, 0xb8, 0x02, 0xde, 0xff, 0xd1, 0x02, 0x00, 0xff, 0x76, 0x03, 0xde, 0xff, 0x25, 0x06, 0x00, 0xfe, 0x20, 0xdd, 0x02, 0xde, 0xff, 0x8e, 0x2f, 0x00, 0xfd, 0x28, 0xff, 0x60, 0x16, 0x00, 0xfb, 0x18, 0x15, 0x9d, 0xea, 0x10, 0x23, 0x00, 0xfd, 0x98, 0xe3, 0x03, 0x04, 0x00, 0xf8, 0x12, 0xf9, 0x9d, 0x1c, 0x11, 0x77, 0xff, 0x41, 0x4f, 0x00, 0xff, 0x43, 0x03, 0xde, 0xfc, 0x76, 0x3a, 0x33, 0xae, 0x03, 0xde, 0xff, 0xb2, 0x04, 0x00, 0xff, 0x14, 0x03, 0xde, 0xff, 0xae, 0x07, 0x00, 0xff, 0x3e, 0x03, 0xde, 0xfd, 0x1a, 0x00, 0x76, 0x03, 0xde, 0xff, 0x24, 0x06, 0x00, 0xfe, 0x20, 0xdd, 0x02, 0xde, 0xff, 0x8e, 0x2f, 0x00, 0xfd, 0x14, 0xe5, 0x3f, 0x16, 0x00, 0xff, 0xe3, 0x02, 0xff, 0xff, 0x5a, 0x24, 0x00, 0xfe, 0x60, 0x52, 0x05, 0x00, 0xfd, 0x02, 0x7d, 0xfc, 0x02, 0xff, 0xfe, 0xfa, 0x7d, 0x50, 0x00, 0xff, 0x41, 0x09, 0xde, 0xfe, 0xd5, 0x0a, 0x04, 0x00, 0xff, 0x4f, 0x03, 0xde, 0xff, 0x23, 0x07, 0x00, 0xff, 0x12, 0x03, 0xde, 0xfd, 0x3a, 0x00, 0x76, 0x03, 0xde, 0xff, 0x23, 0x06, 0x00, 0xfe, 0x20, 0xdd, 0x02, 0xde, 0xff, 0x8f, 0x48, 0x00, 0xfd, 0x32, 0x69, 0x36, 0x2e, 0x00, 0xfc, 0x0c, 0x39, 0x46, 0x1a, 0x51, 0x00, 0xff, 0x41, 0x08, 0xde, 0xfe, 0xcc, 0x10, 0x05, 0x00, 0xff, 0x70, 0x03, 0xde, 0xff, 0xcf, 0x07, 0xd2, 0xff, 0xd3, 0x03, 0xde, 0xfd, 0x4a, 0x00, 0x76, 0x03, 0xde, 0xff, 0x23, 0x06, 0x00, 0xfe, 0x20, 0xdd, 0x02, 0xde, 0xff, 0x91, 0x7f, 0x00, 0x4f, 0x00, 0xff, 0x41, 0x09, 0xde, 0xff, 0x35, 0x05, 0x00, 0xff, 0x7c, 0x0f, 0xde, 0xfd, 0x47, 0x00, 0x76, 0x03, 0xde, 0xff, 0x1f, 0x06, 0x00, 0xfe, 0x20, 0xdd, 0x02, 0xde, 0xff, 0x91, 0x7f, 0x00, 0x4f, 0x00, 0xff, 0x41, 0x03, 0xde, 0xfd, 0xd8, 0xd3, 0xd2, 0x03, 0xde, 0xfe, 0xda, 0x1e, 0x04, 0x00, 0xff, 0x73, 0x03, 0xde, 0xff, 0xa7, 0x0a, 0xa0, 0xfc, 0xa5, 0x27, 0x00, 0x76, 0x03, 0xde, 0xff, 0x1f, 0x06, 0x00, 0xfe, 0x20, 0xdd, 0x02, 0xde, 0xff, 0x91, 0x7f, 0x00, 0x4f, 0x00, 0xff, 0x41, 0x03, 0xde, 0xff, 0x48, 0x02, 0x00, 0xff, 0x5e, 0x03, 0xde, 0xff, 0xb7, 0x04, 0x00, 0xff, 0x5b, 0x03, 0xde, 0xff, 0x35, 0x0d, 0x00, 0xff, 0x76, 0x03, 0xde, 0xff, 0x1e, 0x06, 0x00, 0xfe, 0x1f, 0xdd, 0x02, 0xde, 0xff, 0x91, 0x7f, 0x00, 0x4f, 0x00, 0xff, 0x41, 0x03, 0xde, 0xff, 0x52, 0x03, 0x00, 0xff, 0xa8, 0x03, 0xde, 0xff, 0xa1, 0x03, 0x00, 0xff, 0x23, 0x03, 0xde, 0xff, 0xb4, 0x0d, 0x00, 0xff, 0x6f, 0x03, 0xde, 0xff, 0x49, 0x06, 0x00, 0xff, 0x3c, 0x03, 0xde, 0xff, 0x91, 0x7f, 0x00, 0x4f, 0x00, 0xff, 0x41, 0x03, 0xde, 0xff, 0x52, 0x03, 0x00, 0xfe, 0x01, 0xb8, 0x03, 0xde, 0xff, 0x56, 0x03, 0x00, 0xff, 0xcb, 0x03, 0xde, 0xff, 0x69, 0x06, 0x00, 0xfd, 0x15, 0xa3, 0x25, 0x03, 0x00, 0xff, 0x46, 0x03, 0xde, 0xfe, 0xcc, 0x12, 0x04, 0x00, 0xfe, 0x34, 0xcc, 0x03, 0xde, 0xff, 0x94, 0x7f, 0x00, 0x4f, 0x00, 0xff, 0x41, 0x03, 0xde, 0xff, 0x52, 0x04, 0x00, 0xfe, 0x21, 0xda, 0x03, 0xde, 0xfc, 0x4c, 0x3a, 0x00, 0x55, 0x04, 0xde, 0xfa, 0xad, 0x36, 0x1f, 0x20, 0x32, 0x87, 0x02, 0xde, 0xfe, 0xbf, 0x03, 0x03, 0x00, 0x05, 0xde, 0xfc, 0x88, 0x59, 0x66, 0xaf, 0x05, 0xde, 0xff, 0x95, 0x7f, 0x00, 0x4f, 0x00, 0xff, 0x41, 0x03, 0xde, 0xff, 0x52, 0x05, 0x00, 0xff, 0x33, 0x04, 0xde, 0xfc, 0xd8, 0x08, 0x05, 0xcd, 0x05, 0xde, 0x02, 0xda, 0x05, 0xde, 0xff, 0x5d, 0x03, 0x00, 0xff, 0x4f, 0x0d, 0xde, 0xff, 0x95, 0x7f, 0x00, 0x4f, 0x00, 0xff, 0x41, 0x03, 0xde, 0xff, 0x52, 0x06, 0x00, 0xff, 0x7d, 0x03, 0xde, 0xfb, 0xd8, 0x08, 0x00, 0x10, 0xbd, 0x09, 0xde, 0xfd, 0xcb, 0x68, 0x06, 0x04, 0x00, 0xff, 0x72, 0x07, 0xde, 0xfd, 0xa8, 0x3e, 0xdd, 0x02, 0xde, 0xff, 0x95, 0x7f, 0x00, 0x4f, 0x00, 0xfb, 0x3a, 0xc6, 0xbe, 0xc4, 0x49, 0x07, 0x00, 0xff, 0xa2, 0x02, 0xbe, 0xfe, 0xb9, 0x07, 0x03, 0x00, 0xfd, 0x7c, 0xd3, 0xda, 0x02, 0xdb, 0xfc, 0xda, 0xd5, 0xb9, 0x4a, 0x08, 0x00, 0xf6, 0x16, 0x94, 0xcd, 0xd3, 0xc9, 0x94, 0x23, 0x00, 0x1c, 0xdd, 0x02, 0xde, 0xff, 0x95, 0x7f, 0x00, 0x64, 0x00, 0xfe, 0x09, 0x1e, 0x02, 0x26, 0xfe, 0x1e, 0x0d, 0x0c, 0x00, 0xfe, 0x02, 0x06, 0x04, 0x00, 0xfe, 0x1a, 0xdd, 0x02, 0xde, 0xff, 0x95, 0x7f, 0x00, 0x7c, 0x00, 0xfe, 0x18, 0xdd, 0x02, 0xde, 0xff, 0x99, 0x7f, 0x00, 0x7c, 0x00, 0xfe, 0x16, 0xdd, 0x02, 0xde, 0xff, 0x99, 0x7f, 0x00, 0x7c, 0x00, 0xfe, 0x14, 0xdd, 0x02, 0xde, 0xff, 0x99, 0x7f, 0x00, 0x7b, 0x00, 0xfd, 0x01, 0x2a, 0xdd, 0x02, 0xde, 0xff, 0x99, 0x7f, 0x00, 0x7b, 0x00, 0xfe, 0x95, 0xd5, 0x03, 0xde, 0xff, 0x99, 0x7f, 0x00, 0x7b, 0x00, 0xff, 0xa4, 0x04, 0xde, 0xff, 0x8a, 0x7f, 0x00, 0x7b, 0x00, 0xff, 0xa4, 0x03, 0xde, 0xfe, 0xdd, 0x2a, 0x7f, 0x00, 0x7b, 0x00, 0xfb, 0x39, 0x83, 0xa3, 0x86, 0x33, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x50, 0x00
    };
    memcpy(data, image_data, sizeof(image_data));
}
static const Image screensaver_1_image = {&screensaver_1, 256, 64};

static const AnimationFrame screensaver_array[] = { {&screensaver_1_image, 1000} };

static const ImageAnimation screensaver = { 1, screensaver_array};

const ImageAnimation *variant_getScreensaverAnimation(void)
{
    return(&screensaver);
}

const char *variant_name(void) {
    return "MFR";
}

uint32_t variant_getScreensaverTimeout(void) {
    return 1; // Immediately
}

bool variant_isMFR(void) {
    return true;
}

void variant_mfr_softReset(void) {
    board_reset();
}

