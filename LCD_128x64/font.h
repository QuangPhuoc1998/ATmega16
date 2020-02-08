//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// Author : Ho Thanh Tam	                                                         ;
// Email:   thanhtam.h@gmail.com													 ;		
// Date :   2009, Oct., 15                                                           ;
// Version: 0.1                                                                      ;
// Title:   Font                                                                     ;
// website: www.hocavr.com                                                           ;
// Description: Bang Font cho Graphic LCD 128x64            .                        ;
//                                                                                   ; 
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

#include <avr/pgmspace.h>
static char font5x7[] PROGMEM= {///////ASCII	
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 32
	  0x00, 0x00, 0x7d, 0x00, 0x00  ,// 33
	  0x00, 0x70, 0x00, 0x70, 0x00  ,// 34
	  0x14, 0x7f, 0x14, 0x7f, 0x14  ,// 35
	  0x12, 0x2a, 0x7f, 0x2a, 0x24  ,// 36
	  0x62, 0x64, 0x08, 0x13, 0x23  ,// 37
	  0x36, 0x49, 0x55, 0x22, 0x05  ,// 38
	  0x00, 0x50, 0x60, 0x00, 0x00  ,// 39
	  0x00, 0x1c, 0x22, 0x41, 0x00  ,// 40
	  0x00, 0x41, 0x22, 0x1c, 0x00  ,// 41
	  0x14, 0x08, 0x3e, 0x08, 0x14  ,// 42
	  0x08, 0x08, 0x3e, 0x08, 0x08  ,// 43
	  0x00, 0x05, 0x06, 0x00, 0x00  ,// 44
	  0x08, 0x08, 0x08, 0x08, 0x08  ,// 45
	  0x00, 0x03, 0x03, 0x00, 0x00  ,// 46
	  0x02, 0x04, 0x08, 0x10, 0x20  ,// 47
	  0x3e, 0x45, 0x49, 0x51, 0x3e  ,// 48: 0
	  0x00, 0x21, 0x7f, 0x01, 0x00  ,// 49: 1
	  0x21, 0x43, 0x45, 0x49, 0x31  ,// 50: 2
	  0x42, 0x41, 0x51, 0x69, 0x46  ,// 51:	 3
	  0x0c, 0x14, 0x24, 0x7f, 0x04  ,// 52
	  0x72, 0x51, 0x51, 0x51, 0x4e  ,// 53
	  0x1e, 0x29, 0x49, 0x49, 0x06  ,// 54
	  0x40, 0x47, 0x48, 0x50, 0x60  ,// 55
	  0x36, 0x49, 0x49, 0x49, 0x36  ,// 56
	  0x30, 0x49, 0x49, 0x4a, 0x3c  ,// 57
	  0x00, 0x36, 0x36, 0x00, 0x00  ,// 58
	  0x00, 0x35, 0x36, 0x00, 0x00  ,// 59
	  0x08, 0x14, 0x22, 0x41, 0x00  ,// 60
	  0x14, 0x14, 0x14, 0x14, 0x14  ,// 61
	  0x41, 0x22, 0x14, 0x08, 0x00  ,// 62
	  0x20, 0x40, 0x45, 0x48, 0x30  ,// 63
	  0x26, 0x49, 0x4f, 0x41, 0x3e  ,// 64
	  0x3f, 0x44, 0x44, 0x44, 0x3f  ,// 65
	  0x7f, 0x49, 0x49, 0x49, 0x36  ,// 66
	  0x3e, 0x41, 0x41, 0x41, 0x22  ,// 67
	  0x7f, 0x41, 0x41, 0x41, 0x3e  ,// 68
	  0x7f, 0x49, 0x49, 0x49, 0x41  ,// 69
	  0x7f, 0x48, 0x48, 0x48, 0x40  ,// 70
	  0x3e, 0x41, 0x49, 0x49, 0x2f  ,// 71
	  0x7f, 0x08, 0x08, 0x08, 0x7f  ,// 72
	  0x00, 0x41, 0x7f, 0x41, 0x00  ,// 73
	  0x02, 0x01, 0x41, 0x7e, 0x40  ,// 74
	  0x7f, 0x08, 0x14, 0x22, 0x41  ,// 75
	  0x7f, 0x01, 0x01, 0x01, 0x01  ,// 76
	  0x7f, 0x40, 0x20, 0x40, 0x7f  ,// 77
	  0x7f, 0x10, 0x08, 0x04, 0x7f  ,// 78
	  0x3e, 0x41, 0x41, 0x41, 0x3e  ,// 79
	  0x7f, 0x48, 0x48, 0x48, 0x30  ,// 80
	  0x3e, 0x41, 0x45, 0x42, 0x3d  ,// 81
	  0x7f, 0x48, 0x4c, 0x4a, 0x31  ,// 82
	  0x31, 0x49, 0x49, 0x49, 0x46  ,// 83
	  0x40, 0x40, 0x7f, 0x40, 0x40  ,// 84
	  0x7e, 0x01, 0x01, 0x01, 0x7e  ,// 85
	  0x7c, 0x02, 0x01, 0x02, 0x7c  ,// 86
	  0x7e, 0x01, 0x0e, 0x01, 0x7e  ,// 87
	  0x63, 0x14, 0x08, 0x14, 0x63  ,// 88
	  0x70, 0x08, 0x07, 0x08, 0x70  ,// 89
	  0x43, 0x45, 0x49, 0x51, 0x61  ,// 90
	  0x00, 0x7f, 0x41, 0x41, 0x00  ,// 91
	  0x54, 0x34, 0x1f, 0x34, 0x54  ,// 92
	  0x00, 0x41, 0x41, 0x7f, 0x00  ,// 93
	  0x10, 0x20, 0x40, 0x20, 0x10  ,// 94
	  0x01, 0x01, 0x01, 0x01, 0x01  ,// 95
	  0x00, 0x40, 0x20, 0x10, 0x00  ,// 96
	  0x02, 0x15, 0x15, 0x15, 0x0f  ,// 97
	  0x7f, 0x09, 0x11, 0x11, 0x0e  ,// 98
	  0x0e, 0x11, 0x11, 0x11, 0x02  ,// 99
	  0x0e, 0x11, 0x11, 0x09, 0x7f  ,// 100
	  0x0e, 0x15, 0x15, 0x15, 0x0c  ,// 101
	  0x08, 0x3f, 0x48, 0x40, 0x20  ,// 102
	  0x30, 0x49, 0x49, 0x49, 0x7e  ,// 103
	  0x7f, 0x08, 0x10, 0x10, 0x0f  ,// 104
	  0x00, 0x11, 0x5f, 0x01, 0x00  ,// 105
	  0x02, 0x01, 0x21, 0x7e, 0x00  ,// 106
	  0x7f, 0x04, 0x0a, 0x11, 0x00  ,// 107
	  0x00, 0x41, 0x7f, 0x01, 0x00  ,// 108
	  0x1f, 0x10, 0x0c, 0x10, 0x0f  ,// 109
	  0x1f, 0x08, 0x10, 0x10, 0x0f  ,// 110
	  0x0e, 0x11, 0x11, 0x11, 0x0e  ,// 111
	  0x1f, 0x14, 0x14, 0x14, 0x08  ,// 112
	  0x08, 0x14, 0x14, 0x0c, 0x1f  ,// 113
	  0x1f, 0x08, 0x10, 0x10, 0x08  ,// 114
	  0x09, 0x15, 0x15, 0x15, 0x12  ,// 115
	  0x20, 0x7e, 0x21, 0x01, 0x02  ,// 116
	  0x1e, 0x01, 0x01, 0x02, 0x1f  ,// 117
	  0x1c, 0x02, 0x01, 0x02, 0x1c  ,// 118
	  0x1e, 0x01, 0x06, 0x01, 0x1e  ,// 119
	  0x11, 0x0a, 0x04, 0x0a, 0x11  ,// 120
	  0x18, 0x05, 0x05, 0x05, 0x1e  ,// 121
	  0x11, 0x13, 0x15, 0x19, 0x11  ,// 122
	  0x00, 0x08, 0x36, 0x41, 0x00  ,// 123
	  0x00, 0x00, 0x7f, 0x00, 0x00  ,// 124
	  0x00, 0x41, 0x36, 0x08, 0x00  ,// 125
	  0x08, 0x08, 0x2a, 0x1c, 0x08  ,// 126
	  0x08, 0x1c, 0x2a, 0x08, 0x08  ,// 127
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 128
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 129
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 130
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 131
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 132
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 133
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 134
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 135
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 136
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 137
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 138
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 139
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 140
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 141
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 142
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 143
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 144
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 145
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 146
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 147
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 148
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 149
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 150
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 151
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 152
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 153
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 154
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 155
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 156
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 157
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 158
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 159
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 160
	  0x07, 0x05, 0x07, 0x00, 0x00  ,// 161
	  0x00, 0x00, 0x78, 0x40, 0x40  ,// 162
	  0x01, 0x01, 0x0f, 0x00, 0x00  ,// 163
	  0x04, 0x02, 0x01, 0x00, 0x00  ,// 164
	  0x00, 0x0c, 0x0c, 0x00, 0x00  ,// 165
	  0x28, 0x28, 0x29, 0x2a, 0x3c  ,// 166
	  0x10, 0x11, 0x16, 0x14, 0x18  ,// 167
	  0x02, 0x04, 0x0f, 0x10, 0x00  ,// 168
	  0x0c, 0x08, 0x19, 0x09, 0x0e  ,// 169
	  0x09, 0x09, 0x0f, 0x09, 0x09  ,// 170
	  0x09, 0x0a, 0x0c, 0x1f, 0x08  ,// 171
	  0x08, 0x1f, 0x08, 0x0a, 0x0c  ,// 172
	  0x01, 0x09, 0x09, 0x0f, 0x01  ,// 173
	  0x15, 0x15, 0x15, 0x1f, 0x00  ,// 174
	  0x0c, 0x00, 0x0d, 0x01, 0x0e  ,// 175
	  0x04, 0x04, 0x04, 0x04, 0x04  ,// 176
	  0x40, 0x41, 0x5e, 0x48, 0x70  ,// 177
	  0x04, 0x08, 0x1f, 0x20, 0x40  ,// 178
	  0x38, 0x20, 0x61, 0x22, 0x3c  ,// 179
	  0x11, 0x11, 0x1f, 0x11, 0x11  ,// 180
	  0x22, 0x24, 0x28, 0x7f, 0x20  ,// 181
	  0x21, 0x7e, 0x20, 0x21, 0x3e  ,// 182
	  0x28, 0x28, 0x7f, 0x28, 0x28  ,// 183
	  0x08, 0x31, 0x21, 0x22, 0x3c  ,// 184
	  0x10, 0x60, 0x21, 0x3e, 0x20  ,// 185
	  0x21, 0x21, 0x21, 0x21, 0x3f  ,// 186
	  0x20, 0x79, 0x22, 0x7c, 0x20  ,// 187
	  0x29, 0x29, 0x01, 0x02, 0x1c  ,// 188
	  0x21, 0x22, 0x24, 0x2a, 0x31  ,// 189
	  0x20, 0x7e, 0x21, 0x29, 0x31  ,// 190
	  0x30, 0x09, 0x01, 0x02, 0x3c  ,// 191
	  0x08, 0x31, 0x29, 0x26, 0x3c  ,// 192
	  0x28, 0x29, 0x3e, 0x48, 0x08  ,// 193
	  0x30, 0x00, 0x31, 0x02, 0x3c  ,// 194
	  0x10, 0x51, 0x5e, 0x50, 0x10  ,// 195
	  0x00, 0x7f, 0x08, 0x04, 0x00  ,// 196
	  0x11, 0x12, 0x7c, 0x10, 0x10  ,// 197
	  0x01, 0x21, 0x21, 0x21, 0x01  ,// 198
	  0x21, 0x2a, 0x24, 0x2a, 0x30  ,// 199
	  0x22, 0x24, 0x6f, 0x34, 0x22  ,// 200
	  0x00, 0x01, 0x02, 0x7c, 0x00  ,// 201
	  0x0f, 0x00, 0x20, 0x10, 0x0f  ,// 202
	  0x7e, 0x11, 0x11, 0x11, 0x11  ,// 203
	  0x20, 0x21, 0x21, 0x22, 0x3c  ,// 204
	  0x10, 0x20, 0x10, 0x08, 0x06  ,// 205
	  0x26, 0x20, 0x7f, 0x20, 0x26  ,// 206
	  0x20, 0x24, 0x22, 0x25, 0x38  ,// 207
	  0x00, 0x2a, 0x2a, 0x2a, 0x01  ,// 208
	  0x0e, 0x12, 0x22, 0x02, 0x07  ,// 209
	  0x01, 0x0a, 0x04, 0x0a, 0x30  ,// 210
	  0x28, 0x3e, 0x29, 0x29, 0x29  ,// 211
	  0x10, 0x7f, 0x10, 0x14, 0x18  ,// 212
	  0x01, 0x21, 0x21, 0x3f, 0x01  ,// 213
	  0x29, 0x29, 0x29, 0x29, 0x3f  ,// 214
	  0x10, 0x50, 0x51, 0x52, 0x1c  ,// 215
	  0x78, 0x01, 0x02, 0x7c, 0x00  ,// 216
	  0x1f, 0x00, 0x3f, 0x01, 0x06  ,// 217
	  0x3f, 0x01, 0x02, 0x04, 0x08  ,// 218
	  0x3f, 0x21, 0x21, 0x21, 0x3f  ,// 219
	  0x38, 0x20, 0x21, 0x22, 0x3c  ,// 220
	  0x21, 0x21, 0x01, 0x02, 0x0c  ,// 221
	  0x20, 0x10, 0x40, 0x20, 0x00  ,// 222
	  0x70, 0x50, 0x70, 0x00, 0x00  ,// 223
	  0x0e, 0x11, 0x09, 0x06, 0x19  ,// 224
	  0x02, 0x55, 0x15, 0x55, 0x0f  ,// 225
	  0x1f, 0x2a, 0x2a, 0x2a, 0x14  ,// 226
	  0x0a, 0x15, 0x15, 0x11, 0x02  ,// 227
	  0x3f, 0x02, 0x02, 0x04, 0x3e  ,// 228
	  0x0e, 0x11, 0x19, 0x15, 0x12  ,// 229
	  0x0f, 0x12, 0x22, 0x22, 0x1c  ,// 230
	  0x1c, 0x22, 0x22, 0x22, 0x3f  ,// 231
	  0x02, 0x01, 0x1e, 0x10, 0x10  ,// 232
	  0x20, 0x20, 0x00, 0x70, 0x00  ,// 233
	  0x00, 0x00, 0x10, 0x5f, 0x00  ,// 234
	  0x28, 0x10, 0x28, 0x00, 0x00  ,// 235
	  0x18, 0x24, 0x7e, 0x24, 0x08  ,// 236
	  0x14, 0x7f, 0x15, 0x01, 0x01  ,// 237
	  0x1f, 0x48, 0x50, 0x50, 0x0f  ,// 238
	  0x0e, 0x51, 0x11, 0x51, 0x0e  ,// 239
	  0x3f, 0x12, 0x22, 0x22, 0x1c  ,// 240
	  0x1c, 0x22, 0x22, 0x12, 0x3f  ,// 241
	  0x3c, 0x52, 0x52, 0x52, 0x3c  ,// 242
	  0x03, 0x05, 0x02, 0x05, 0x06  ,// 243
	  0x1a, 0x26, 0x20, 0x26, 0x1a  ,// 244
	  0x1e, 0x41, 0x01, 0x42, 0x1f  ,// 245
	  0x63, 0x55, 0x49, 0x41, 0x41  ,// 246
	  0x22, 0x3c, 0x20, 0x3e, 0x22  ,// 247
	  0x51, 0x4a, 0x44, 0x4a, 0x51  ,// 248
	  0x3c, 0x02, 0x02, 0x02, 0x3f  ,// 249
	  0x28, 0x28, 0x3e, 0x28, 0x48  ,// 250
	  0x22, 0x3c, 0x28, 0x28, 0x2e  ,// 251
	  0x3e, 0x28, 0x38, 0x28, 0x3e  ,// 252
	  0x04, 0x04, 0x15, 0x04, 0x04  ,// 253
	  0x00, 0x00, 0x00, 0x00, 0x00  ,// 254
	  0x7f, 0x7f, 0x7f, 0x7f, 0x7f   // 255
};

static char font7x8[] PROGMEM= {
	 0,   0,   0,   0,   0,   0,   0, //' ' 32
	 0,   6,  95,  95,   6,   0,   0, //'!'
	 0,   7,   7,   0,   7,   7,   0, //'"'
	 20, 127, 127,  20, 127, 127,  20, //'#'
	 36,  46, 107, 107,  58,  18,   0, //'$'
	 70, 102,  48,  24,  12, 102,  98, //'%'
	 48, 122,  79,  93,  55, 122,  72, //'&'
	 4,   7,   3,   0,   0,   0,   0, //'''
	 0,  28,  62,  99,  65,   0,   0, //'('
	 0,  65,  99,  62,  28,   0,   0, //')'
	 8,  42,  62,  28,  28,  62,  42, //'*'
	 8,   8,  62,  62,   8,   8,   0, //'+'
	 0, 128, 224,  96,   0,   0,   0, //','
	 8,   8,   8,   8,   8,   8,   0, //'-'
	 0,   0,  96,  96,   0,   0,   0, //'.'
	96,  48,  24,  12,   6,   3,   1, //'/'
	62, 127, 113,  89,  77, 127,  62, //'0'
	64,  66, 127, 127,  64,  64,   0, //'1'
	98, 115,  89,  73, 111, 102,   0, //'2'
	34,  99,  73,  73, 127,  54,   0, //'3'
	24,  28,  22,  83, 127, 127,  80, //'4'
	39, 103,  69,  69, 125,  57,   0, //'5'
	60, 126,  75,  73, 121,  48,   0, //'6'
	 3,   3, 113, 121,  15,   7,   0, //'7'
	54, 127,  73,  73, 127,  54,   0, //'8'
	 6,  79,  73, 105,  63,  30,   0, //'9'
	 0,   0, 102, 102,   0,   0,   0, //':'
	 0, 128, 230, 102,   0,   0,   0, //';'
	 8,  28,  54,  99,  65,   0,   0, //'<'
	36,  36,  36,  36,  36,  36,   0, //'='
	 0,  65,  99,  54,  28,   8,   0, //'>'
	 2,   3,  81,  89,  15,   6,   0, //'?'
	62, 127,  65,  93,  93,  31,  30, //'@'
	124, 126,  19,  19, 126, 124,   0, //'A'
	65, 127, 127,  73,  73, 127,  54, //'B'
	28,  62,  99,  65,  65,  99,  34, //'C'
	65, 127, 127,  65,  99,  62,  28, //'D'
	65, 127, 127,  73,  93,  65,  99, //'E'
	65, 127, 127,  73,  29,   1,   3, //'F'
	28,  62,  99,  65,  81, 115, 114, //'G'
	127, 127,   8,   8, 127, 127,   0, //'H'
	 0,  65, 127, 127,  65,   0,   0, //'I'
	48, 112,  64,  65, 127,  63,   1, //'J'
	65, 127, 127,   8,  28, 119,  99, //'K'
	65, 127, 127,  65,  64,  96, 112, //'L'
	127, 127,  14,  28,  14, 127, 127, //'M'
	127, 127,   6,  12,  24, 127, 127, //'N'
	28,  62,  99,  65,  99,  62,  28, //'O'
	65, 127, 127,  73,   9,  15,   6, //'P'
	30,  63,  33, 113, 127,  94,   0, //'Q'
	65, 127, 127,   9,  25, 127, 102, //'R'
	38, 111,  77,  89, 115,  50,   0, //'S'
	 3,  65, 127, 127,  65,   3,   0, //'T'
	127, 127,  64,  64, 127, 127,   0, //'U'
	31,  63,  96,  96,  63,  31,   0, //'V'
	127, 127,  48,  24,  48, 127, 127, //'W'
	67, 103,  60,  24,  60, 103,  67, //'X'
	 7,  79, 120, 120,  79,   7,   0, //'Y'
	71,  99, 113,  89,  77, 103, 115, //'Z'
	 0, 127, 127,  65,  65,   0,   0, //'['
	 1,   3,   6,  12,  24,  48,  96, //'\'
	 0,  65,  65, 127, 127,   0,   0, //']'
	 8,  12,   6,   3,   6,  12,   8, //'^'
	128, 128, 128, 128, 128, 128, 128, //'_'
	 0,   0,   3,   7,   4,   0,   0, //'`'
	32, 116,  84,  84,  60, 120,  64, //'a'
	65, 127,  63,  72,  72, 120,  48, //'b'
	56, 124,  68,  68, 108,  40,   0, //'c'
	48, 120,  72,  73,  63, 127,  64, //'d'
	56, 124,  84,  84,  92,  24,   0, //'e'
	72, 126, 127,  73,   3,   2,   0, //'f'
	56, 188, 164, 164, 252, 120,   0, //'g'
	65, 127, 127,   8,   4, 124, 120, //'h'
	 0,  68, 125, 125,  64,   0,   0, //'i'
	96, 224, 128, 128, 253, 125,   0, //'j'
	65, 127, 127,  16,  56, 108,  68, //'k'
	 0,  65, 127, 127,  64,   0,   0, //'l'
	120, 124,  28,  56,  28, 124, 120, //'m'
	124, 124,   4,   4, 124, 120,   0, //'n'
	56, 124,  68,  68, 124,  56,   0, //'o'
	0, 252, 252, 164,  36,  60,  24, //'p'
	24,  60,  36, 164, 248, 252, 132, //'q'
	68, 124, 120,  76,   4,  28,  24, //'r'
	72,  92,  84,  84, 116,  36,   0, //'s'
	 0,   4,  62, 127,  68,  36,   0, //'t'
	60, 124,  64,  64,  60, 124,  64, //'u'
	28,  60,  96,  96,  60,  28,   0, //'v'
	60, 124, 112,  56, 112, 124,  60, //'w'
	68, 108,  56,  16,  56, 108,  68, //'x'
	60, 188, 160, 160, 252, 124,   0, //'y'
	76, 100, 116,  92,  76, 100,   0, //'z'
	 8,   8,  62, 119,  65,  65,   0, //'{'
	 0,   0,   0, 119, 119,   0,   0, //'|'
	65,  65, 119,  62,   8,   8,   0, //'}'
	 2,   3,   1,   3,   2,   3,   1, //'~'
	255, 129,  129,  129,  129, 129, 255, //''
	14, 159, 145, 177, 251,  74,   0 //'?
};
 
prog_char hiGLCD[] = {
	252, 186, 6, 32, 128, 0, 0, 0, 0, 0, 0, 128, 192, 64, 32, 48, 16, 16, 24, 8, 8, 12, 4, 4, 4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 12, 8, 8, 8, 24, 16, 16, 32, 32, 96, 64, 192, 128, 0, 0, 1, 255, 255, 48, 16, 240, 224, 0, 0, 224, 240, 16, 16, 240, 224, 0, 0, 224, 240, 16, 48, 48, 0, 0, 32, 176, 144, 144, 240, 224, 0, 16, 48, 240, 208, 0, 208, 48, 16, 16, 240, 240, 32, 16, 48, 0, 0, 0, 0, 0, 224, 240, 16, 48, 48, 0, 0, 224, 240, 16, 16, 240, 224, 0, 16, 240, 240, 32, 16, 240, 224, 32, 16, 240, 224,
	63, 255, 252, 248, 249, 224, 24, 24, 12, 130, 193, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 224, 224, 224, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 6, 7, 15, 28, 48, 103, 199, 132, 0, 3, 7, 4, 4, 7, 3, 0, 0, 3, 7, 4, 4, 2, 0, 0, 3, 7, 4, 4, 7, 7, 4, 0, 0, 1, 7, 6, 1, 0, 0, 4, 7, 7, 4, 0, 0, 0, 6, 6, 0, 0, 3, 7, 4, 4, 2, 0, 0, 3, 7, 4, 4, 7, 3, 0, 4, 7, 7, 4, 0, 7, 7, 4, 0, 7, 7,
	0, 1, 7, 255, 255, 255, 255, 248, 227, 31, 239, 32, 0, 0, 0, 0, 0, 0, 0, 0, 128, 192, 224, 248, 254, 255, 159, 143, 7, 1, 0, 0, 0, 0, 128, 224, 248, 252, 252, 62, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 1, 3, 14, 56, 240, 192, 0, 0, 0, 0, 192, 240, 48, 24, 8, 8, 24, 48, 120, 0, 0, 128, 128, 128, 0, 128, 128, 0, 0, 128, 128, 128, 128, 0, 0, 128, 128, 128, 128, 128, 128, 0, 0, 8, 248, 248, 128, 128, 128, 0, 0, 128, 152, 152, 0, 0, 0, 128, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 63, 255, 195, 15, 127, 255, 255, 252, 231, 60, 224, 128, 0, 0, 0, 224, 252, 255, 255, 95, 7, 3, 3, 3, 7, 135, 199, 247, 254, 126, 63, 31, 7, 3, 1, 0, 0, 24, 60, 60, 60, 28, 12, 0, 0, 0, 192, 248, 252, 255, 127, 63, 15, 7, 1, 0, 0, 0, 0, 0, 0, 0, 15, 255, 248, 240, 0, 7, 31, 24, 48, 32, 32, 34, 62, 30, 2, 0, 32, 63, 63, 33, 0, 1, 0, 25, 61, 36, 36, 63, 63, 32, 0, 255, 255, 32, 32, 63, 31, 0, 32, 63, 63, 33, 0, 63, 63, 32, 32, 63, 63, 32, 0, 31, 63, 32, 33, 17, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 3, 15, 62, 248, 227, 223, 255, 255, 255, 252, 231, 127, 199, 2, 1, 1, 0, 0, 0, 0, 0, 48, 60, 30, 15, 7, 3, 0, 0, 24, 28, 124, 254, 254, 254, 140, 128, 128, 0, 0, 64, 240, 120, 62, 31, 15, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 128, 248, 248, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 64, 192, 192, 64, 64, 0, 0, 0, 0, 0, 0, 128, 128, 193, 65, 65, 193, 128, 192, 0, 64, 64, 192, 192, 64, 64, 64, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 15, 31, 127, 255, 255, 255, 255, 254, 240, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 7, 14, 15, 7, 0, 0, 0, 192, 192, 192, 192, 192, 192, 192, 192, 128, 224, 240, 252, 255, 255, 255, 255, 255, 63, 31, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 0, 0, 0, 0, 192, 0, 0, 62, 255, 193, 128, 0, 0, 0, 129, 67, 0, 0, 0, 255, 255, 0, 0, 0, 128, 193, 127, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 15, 63, 63, 255, 255, 199, 6, 254, 28, 28, 24, 56, 176, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 128, 128, 192, 199, 223, 223, 239, 239, 239, 119, 119, 59, 59, 29, 31, 15, 7, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 127, 127, 240, 216, 204, 198, 195, 192, 192, 192, 192, 192, 192, 224, 96, 112, 56, 28, 14, 7, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 
}; 