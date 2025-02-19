#include "libc/x/x.h"
/* clang-format off */

static _Atomic(void *) __cp932ext_encmap_ptr;
static const unsigned char __cp932ext_encmap_rodata[] = {
  0xed, 0x5a, 0x05, 0x73, 0xdb, 0x4c, 0x10, 0xfd, 0x6b, 0x61, 0x66, 0xc6, 0x86,
  0x99, 0xa9, 0x98, 0x66, 0xe2, 0xd0, 0x86, 0xd3, 0x40, 0xdb, 0xa4, 0xcc, 0xcc,
  0xcc, 0x8c, 0x29, 0x33, 0x33, 0xc3, 0x6e, 0x19, 0xbe, 0xb6, 0x33, 0xf9, 0x34,
  0x1a, 0x8d, 0xc7, 0xb2, 0x65, 0x5b, 0x92, 0x25, 0x59, 0x72, 0x7c, 0x33, 0x8e,
  0xa3, 0xbd, 0xdd, 0xb7, 0xef, 0xbd, 0x3b, 0xdd, 0xcd, 0x64, 0xd2, 0x02, 0x13,
  0x02, 0xa3, 0x4d, 0x30, 0xaa, 0xd5, 0x48, 0x80, 0x44, 0x48, 0x82, 0x64, 0x48,
  0x81, 0x54, 0x48, 0x83, 0x74, 0xc8, 0x80, 0x4c, 0x1e, 0x9f, 0x4f, 0xf4, 0x99,
  0xbe, 0xd0, 0x57, 0xfa, 0x46, 0xdf, 0xe9, 0x07, 0xfd, 0xa4, 0x5f, 0xf4, 0x9b,
  0x46, 0x1c, 0x30, 0x1e, 0xb5, 0x98, 0xcb, 0x31, 0x59, 0xcf, 0x0e, 0xbb, 0x55,
  0xab, 0x11, 0xc6, 0x18, 0xf8, 0x80, 0x2f, 0xf8, 0x81, 0x3f, 0x04, 0x40, 0x20,
  0x04, 0x41, 0x30, 0x84, 0x40, 0x28, 0x84, 0x41, 0x38, 0x44, 0x40, 0x24, 0x44,
  0x41, 0x34, 0xc4, 0x40, 0x2c, 0xc4, 0x41, 0x3c, 0x34, 0x33, 0x5e, 0x9a, 0xa0,
  0x1b, 0x7a, 0x78, 0x9e, 0xf6, 0x7a, 0xa4, 0xc3, 0xed, 0xd0, 0x01, 0x00, 0x9d,
  0xd0, 0x05, 0x05, 0x02, 0xfa, 0x4a, 0x78, 0xb1, 0x6c, 0xee, 0x29, 0x4f, 0x20,
  0x33, 0x07, 0xca, 0xd8, 0x68, 0x29, 0xe4, 0x73, 0xb3, 0xe5, 0x82, 0x7e, 0x15,
  0x9a, 0xa3, 0x95, 0x0e, 0xfc, 0xcc, 0x82, 0x0a, 0x76, 0x36, 0x97, 0xcb, 0x29,
  0xb2, 0xc8, 0x2d, 0x56, 0x68, 0x1d, 0x9a, 0x60, 0x00, 0xfa, 0xa1, 0xcf, 0x09,
  0x5a, 0x2d, 0xd4, 0xd9, 0xcd, 0xa8, 0x82, 0x6a, 0xa8, 0x61, 0x67, 0x1b, 0x14,
  0xe1, 0x54, 0x6f, 0x83, 0xd2, 0x0a, 0x11, 0xe8, 0x7d, 0x73, 0xb5, 0x1d, 0x91,
  0xb2, 0x1c, 0x8f, 0xc2, 0x68, 0xb6, 0x2e, 0x46, 0xc3, 0xf5, 0x8a, 0x95, 0xdd,
  0x2b, 0x4e, 0x23, 0x96, 0x09, 0x56, 0x7d, 0xe2, 0x99, 0xe7, 0x24, 0x8b, 0x58,
  0xa2, 0xaa, 0x3c, 0x02, 0x39, 0xf4, 0x64, 0x0d, 0xd4, 0xa6, 0x61, 0x3a, 0xd7,
  0x25, 0xd5, 0x85, 0x6e, 0x29, 0x4c, 0xed, 0x14, 0xae, 0x3e, 0x43, 0x05, 0xd6,
  0x99, 0x0a, 0x61, 0x66, 0xe9, 0xe4, 0x54, 0xca, 0x91, 0xc9, 0x23, 0x1b, 0x73,
  0x65, 0x54, 0xe6, 0x69, 0xae, 0x3a, 0xdf, 0xe5, 0x8e, 0x05, 0x2a, 0x72, 0x2e,
  0xc4, 0x22, 0xef, 0xed, 0x64, 0x31, 0x8a, 0x05, 0xdc, 0x28, 0xb1, 0x89, 0xa5,
  0x93, 0x33, 0x9c, 0x52, 0x59, 0xae, 0x96, 0x61, 0x39, 0xaf, 0xae, 0x42, 0xf6,
  0xda, 0x54, 0xea, 0x78, 0x55, 0xab, 0x5c, 0xe6, 0x56, 0xed, 0x12, 0x42, 0x8d,
  0x2a, 0xde, 0xd4, 0x62, 0x83, 0x08, 0xdc, 0x7a, 0xbb, 0x39, 0x53, 0x0d, 0xf4,
  0x1e, 0x4e, 0xc3, 0xe9, 0x38, 0xc3, 0x0e, 0xdf, 0x99, 0xba, 0xd2, 0x31, 0x4b,
  0x16, 0x9b, 0xd9, 0xd8, 0x88, 0x26, 0x91, 0x95, 0x2d, 0xd8, 0xaa, 0xb3, 0x95,
  0x6b, 0xb3, 0xe2, 0xd3, 0xce, 0x3c, 0x77, 0x58, 0xc4, 0xc0, 0xed, 0x7c, 0x3b,
  0x25, 0x30, 0xe8, 0xc2, 0x6e, 0x0f, 0xbc, 0xa1, 0x7a, 0x24, 0x6a, 0xea, 0x13,
  0x99, 0xdf, 0x8f, 0x03, 0xde, 0xfb, 0x9c, 0x37, 0xe6, 0x88, 0xf4, 0x63, 0xd0,
  0x2d, 0xbe, 0x0d, 0xe1, 0xb0, 0xac, 0xbe, 0xf3, 0x9c, 0x56, 0x8d, 0xc8, 0xc0,
  0x9d, 0xaf, 0xcb, 0xbd, 0x33, 0x8a, 0x63, 0x92, 0x78, 0x2d, 0xc0, 0x85, 0xa2,
  0xf2, 0x17, 0x39, 0xcd, 0x0a, 0x57, 0xc0, 0x8f, 0xc5, 0x3a, 0x7f, 0x1f, 0x97,
  0x28, 0xca, 0x6f, 0x29, 0x2e, 0x53, 0x58, 0xef, 0x72, 0x33, 0xde, 0x0a, 0x5d,
  0x3a, 0xb9, 0xca, 0x86, 0xd5, 0x4a, 0x91, 0x3c, 0xd7, 0xe0, 0x5a, 0x87, 0x99,
  0xab, 0x9d, 0xe0, 0xac, 0xe7, 0xcd, 0xaf, 0x33, 0xfc, 0xb9, 0xbf, 0x01, 0x37,
  0x7a, 0xef, 0x2e, 0x11, 0x63, 0x13, 0x6e, 0xc6, 0x2d, 0x6e, 0x73, 0x6a, 0xab,
  0xea, 0x9d, 0xb7, 0xe1, 0x76, 0xdc, 0x61, 0xd3, 0x65, 0xb7, 0x9d, 0xbe, 0x3b,
  0x6d, 0xe2, 0x7b, 0x2d, 0x22, 0xfb, 0x04, 0xaa, 0xf6, 0xb0, 0xb1, 0x60, 0x81,
  0x99, 0x5d, 0x32, 0xb5, 0x1d, 0x60, 0xea, 0x0e, 0xda, 0xa9, 0xdd, 0xef, 0x00,
  0xf3, 0xb0, 0x82, 0x5e, 0x1e, 0xe1, 0x61, 0x1d, 0x15, 0x81, 0x7c, 0xcc, 0x6e,
  0xce, 0x71, 0xb7, 0xec, 0xae, 0x13, 0x18, 0x86, 0x27, 0x0d, 0x76, 0x02, 0x9c,
  0x36, 0x0c, 0xdf, 0x33, 0x66, 0xa6, 0xe7, 0xf0, 0xbc, 0x2e, 0x58, 0x8f, 0x3b,
  0x60, 0x71, 0x76, 0x12, 0xdd, 0x04, 0x21, 0x3c, 0xad, 0x17, 0xf0, 0x92, 0xca,
  0xda, 0xaf, 0xe8, 0xd0, 0xdb, 0xab, 0x78, 0x4d, 0x02, 0xab, 0x1b, 0x8a, 0x29,
  0xb8, 0x6e, 0x85, 0x74, 0x53, 0x10, 0xf9, 0x96, 0x87, 0xec, 0xc6, 0xdb, 0x8c,
  0x8e, 0x3b, 0x78, 0x17, 0xef, 0xc9, 0xd6, 0x73, 0x5f, 0x54, 0xe5, 0x43, 0x49,
  0xf8, 0x0f, 0x0c, 0xe2, 0xee, 0x23, 0x7c, 0xec, 0x91, 0xa7, 0xd2, 0x53, 0x89,
  0xaa, 0x9e, 0x38, 0xcc, 0x7f, 0x26, 0x01, 0xed, 0xb9, 0x22, 0x7e, 0xbe, 0x50,
  0x04, 0xe5, 0x95, 0x05, 0xca, 0x4b, 0xee, 0xf7, 0xd7, 0xf8, 0x4e, 0x04, 0xf6,
  0x1b, 0x36, 0xe7, 0xbd, 0x8b, 0x2c, 0xde, 0x7a, 0xc4, 0xde, 0xfa, 0x80, 0x1f,
  0x55, 0xd3, 0x81, 0x6e, 0x76, 0x88, 0xf0, 0x13, 0xc3, 0xe0, 0xb3, 0xcb, 0x2c,
  0xbe, 0x18, 0x76, 0xa5, 0xbf, 0x2a, 0xc8, 0xfc, 0x9b, 0x13, 0xac, 0x20, 0xfc,
  0x21, 0x98, 0xf1, 0x5d, 0x53, 0xf7, 0x7e, 0xe1, 0x6f, 0xd1, 0xfd, 0x7e, 0x7a,
  0xcc, 0xed, 0xf0, 0xc7, 0x6d, 0x4a, 0xfe, 0xe2, 0x3f, 0xbb, 0xbd, 0x7d, 0xc8,
  0x97, 0x8c, 0xe0, 0x9e, 0xbf, 0x8e, 0x58, 0x06, 0xd8, 0xe1, 0x12, 0x68, 0x13,
  0x0f, 0xe1, 0x22, 0x41, 0x76, 0xd9, 0x07, 0x8b, 0xd0, 0x15, 0x46, 0xa1, 0x2e,
  0xa9, 0x0f, 0x67, 0xab, 0x23, 0x29, 0x82, 0x43, 0x89, 0xd2, 0xc8, 0xcb, 0x68,
  0x45, 0xfb, 0xc4, 0x48, 0x40, 0x8b, 0xa5, 0x38, 0x15, 0x35, 0xf6, 0xba, 0xf9,
  0x4c, 0x8a, 0xa7, 0x04, 0xc9, 0xea, 0x92, 0x29, 0x91, 0xa9, 0x49, 0xb2, 0xaa,
  0x4b, 0xa1, 0x34, 0xca, 0x50, 0xcd, 0xa9, 0x4c, 0x09, 0xc8, 0x53, 0x24, 0xe4,
  0x66, 0x51, 0xb6, 0x21, 0xce, 0x2c, 0xe7, 0x23, 0x9f, 0xa7, 0xa3, 0x90, 0x8a,
  0x24, 0xe8, 0x2a, 0xe6, 0x72, 0x4b, 0xa9, 0x8c, 0x2a, 0x44, 0xd6, 0x55, 0xea,
  0xc4, 0xb7, 0x6a, 0x49, 0x3c, 0xaa, 0x5c, 0x62, 0x5d, 0x43, 0xb5, 0x1a, 0xab,
  0xf6, 0xc1, 0x3a, 0x03, 0xee, 0xcf, 0x7a, 0x9a, 0x6a, 0xf8, 0xb7, 0x6a, 0x9a,
  0x6c, 0x05, 0xd3, 0x75, 0xa6, 0x7d, 0x86, 0xaa, 0x7c, 0x66, 0xd2, 0x2c, 0x0f,
  0x39, 0x41, 0xad, 0x47, 0xa3, 0xc2, 0xba, 0x02, 0x70, 0xb6, 0x05, 0x62, 0x93,
  0x08, 0xf4, 0x66, 0xdd, 0x38, 0xdb, 0x42, 0xed, 0x1e, 0xba, 0xca, 0xde, 0x31,
  0x31, 0xd1, 0x41, 0xbe, 0x08, 0x8a, 0xad, 0x6f, 0xa7, 0x0e, 0x76, 0x4a, 0x97,
  0x8a, 0x1c, 0xba, 0x25, 0x61, 0xf7, 0xb8, 0xcc, 0xa4, 0x57, 0x12, 0x42, 0x3f,
  0x0d, 0xa8, 0xa4, 0x7d, 0x0e, 0x0d, 0x72, 0xc8, 0x43, 0x34, 0xec, 0x21, 0xa7,
  0xc1, 0x08, 0xcd, 0xa3, 0xb1, 0x49, 0x75, 0xb2, 0x2d, 0xa0, 0x45, 0x22, 0xf4,
  0x2e, 0xf6, 0x9e, 0xf6, 0xaa, 0x8e, 0xa5, 0xac, 0xbf, 0x4b, 0x38, 0x97, 0x97,
  0x59, 0xb8, 0xbd, 0x92, 0x56, 0x59, 0x79, 0xbf, 0x9c, 0x56, 0xd0, 0x6a, 0x2e,
  0xb6, 0xd6, 0x62, 0x6e, 0x8d, 0xe2, 0x6b, 0xb4, 0x85, 0xd6, 0x31, 0x98, 0x1b,
  0x38, 0xdc, 0xf5, 0x0e, 0xf0, 0x37, 0xb2, 0x73, 0x9b, 0xad, 0x32, 0x36, 0x39,
  0xa8, 0xd8, 0xea, 0x84, 0xed, 0x76, 0xda, 0xe1, 0x24, 0xc3, 0xdf, 0xa5, 0xbf,
  0x95, 0x6c, 0x53, 0xdc, 0xad, 0x3d, 0x2c, 0xe2, 0x01, 0xe6, 0xe7, 0x3e, 0xe6,
  0xb3, 0x8b, 0xf9, 0xec, 0xe6, 0xf5, 0xd8, 0xcf, 0x7b, 0xda, 0x29, 0xa2, 0x7f,
  0x28, 0xa3, 0xf0, 0x30, 0x97, 0x77, 0x8c, 0x4e, 0xc8, 0x62, 0x7c, 0x9c, 0x8e,
  0xb2, 0x75, 0x87, 0xb8, 0xea, 0x83, 0x8a, 0xe8, 0xf6, 0x73, 0xe8, 0xfd, 0x29,
  0xc9, 0x3d, 0x4e, 0x6a, 0x74, 0xbe, 0x9c, 0x56, 0xa0, 0xcf, 0x19, 0x89, 0x18,
  0x67, 0x65, 0xf4, 0x3c, 0x47, 0xe7, 0x45, 0x56, 0x8d, 0xb3, 0x79, 0x17, 0xe8,
  0x22, 0x5d, 0x11, 0x51, 0x71, 0x95, 0xae, 0x59, 0x65, 0x5d, 0xb7, 0x7a, 0xbe,
  0x21, 0x80, 0x72, 0x93, 0x89, 0xdd, 0x62, 0x3e, 0xb7, 0xb9, 0xb9, 0x3b, 0x74,
  0xd7, 0x41, 0xaf, 0x7b, 0xf4, 0x70, 0x52, 0xdd, 0x16, 0x8f, 0xe9, 0x89, 0xf7,
  0x76, 0x14, 0x18, 0x4f, 0x59, 0x57, 0x9e, 0xd1, 0x0b, 0xf6, 0xfb, 0xb9, 0x0c,
  0x8f, 0x5e, 0x2a, 0xe0, 0xeb, 0x2b, 0x01, 0x8c, 0xd7, 0xf4, 0x86, 0xde, 0x99,
  0xe3, 0x6f, 0xe9, 0x83, 0x77, 0xfd, 0x34, 0x1d, 0x1f, 0xe9, 0x94, 0xf7, 0x3f,
  0xc7, 0x35, 0x18, 0x97, 0xa8, 0x0e, 0x9b, 0xb0, 0x19, 0xe7, 0xe2, 0x21, 0xbc,
  0x88, 0x97, 0xf1, 0x3f, 0xf4, 0xa3, 0x54, 0xca, 0xa1, 0x5c, 0xca, 0xa3, 0x02,
  0x2a, 0xa1, 0x72, 0x6a, 0x20, 0x13, 0xb5, 0x52, 0x1b, 0xf5, 0xd1, 0x5c, 0x9a,
  0x4f, 0xa3, 0xb4, 0x90, 0xf6, 0xd2, 0x11, 0xba, 0x4c, 0xf7, 0xe9, 0x01, 0x3d,
  0xa2, 0xf7, 0xf4, 0xcf, 0xfc, 0x66, 0xfc, 0xb5, 0x78, 0x47, 0x1a, 0x4d, 0x6a,
  0xb2, 0xce, 0x52, 0x00, 0x3d, 0xdb, 0xe4, 0x5d, 0xfd, 0x41, 0xd3, 0x90, 0x69,
  0x9c, 0xf1, 0xe1, 0x0f, 0xfd, 0x0f,
};

optimizesize void *__cp932ext_encmap(void) {
  return xload(&__cp932ext_encmap_ptr,
               __cp932ext_encmap_rodata,
               1293, 19372); /* 6.67458% profit */
}
