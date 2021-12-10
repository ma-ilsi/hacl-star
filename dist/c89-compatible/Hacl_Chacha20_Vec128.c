/* MIT License
 *
 * Copyright (c) 2016-2020 INRIA, CMU and Microsoft Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "Hacl_Chacha20_Vec128.h"

static inline void double_round_128(Lib_IntVector_Intrinsics_vec128 *st)
{
  Lib_IntVector_Intrinsics_vec128 std0;
  Lib_IntVector_Intrinsics_vec128 std1;
  Lib_IntVector_Intrinsics_vec128 std2;
  Lib_IntVector_Intrinsics_vec128 std3;
  Lib_IntVector_Intrinsics_vec128 std4;
  Lib_IntVector_Intrinsics_vec128 std5;
  Lib_IntVector_Intrinsics_vec128 std6;
  Lib_IntVector_Intrinsics_vec128 std7;
  Lib_IntVector_Intrinsics_vec128 std8;
  Lib_IntVector_Intrinsics_vec128 std9;
  Lib_IntVector_Intrinsics_vec128 std10;
  Lib_IntVector_Intrinsics_vec128 std11;
  Lib_IntVector_Intrinsics_vec128 std12;
  Lib_IntVector_Intrinsics_vec128 std13;
  Lib_IntVector_Intrinsics_vec128 std14;
  Lib_IntVector_Intrinsics_vec128 std15;
  Lib_IntVector_Intrinsics_vec128 std16;
  Lib_IntVector_Intrinsics_vec128 std17;
  Lib_IntVector_Intrinsics_vec128 std18;
  Lib_IntVector_Intrinsics_vec128 std19;
  Lib_IntVector_Intrinsics_vec128 std20;
  Lib_IntVector_Intrinsics_vec128 std21;
  Lib_IntVector_Intrinsics_vec128 std22;
  Lib_IntVector_Intrinsics_vec128 std23;
  Lib_IntVector_Intrinsics_vec128 std24;
  Lib_IntVector_Intrinsics_vec128 std25;
  Lib_IntVector_Intrinsics_vec128 std26;
  Lib_IntVector_Intrinsics_vec128 std27;
  Lib_IntVector_Intrinsics_vec128 std28;
  Lib_IntVector_Intrinsics_vec128 std29;
  Lib_IntVector_Intrinsics_vec128 std30;
  Lib_IntVector_Intrinsics_vec128 std;
  st[0U] = Lib_IntVector_Intrinsics_vec128_add32(st[0U], st[4U]);
  std0 = Lib_IntVector_Intrinsics_vec128_xor(st[12U], st[0U]);
  st[12U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std0, (uint32_t)16U);
  st[8U] = Lib_IntVector_Intrinsics_vec128_add32(st[8U], st[12U]);
  std1 = Lib_IntVector_Intrinsics_vec128_xor(st[4U], st[8U]);
  st[4U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std1, (uint32_t)12U);
  st[0U] = Lib_IntVector_Intrinsics_vec128_add32(st[0U], st[4U]);
  std2 = Lib_IntVector_Intrinsics_vec128_xor(st[12U], st[0U]);
  st[12U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std2, (uint32_t)8U);
  st[8U] = Lib_IntVector_Intrinsics_vec128_add32(st[8U], st[12U]);
  std3 = Lib_IntVector_Intrinsics_vec128_xor(st[4U], st[8U]);
  st[4U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std3, (uint32_t)7U);
  st[1U] = Lib_IntVector_Intrinsics_vec128_add32(st[1U], st[5U]);
  std4 = Lib_IntVector_Intrinsics_vec128_xor(st[13U], st[1U]);
  st[13U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std4, (uint32_t)16U);
  st[9U] = Lib_IntVector_Intrinsics_vec128_add32(st[9U], st[13U]);
  std5 = Lib_IntVector_Intrinsics_vec128_xor(st[5U], st[9U]);
  st[5U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std5, (uint32_t)12U);
  st[1U] = Lib_IntVector_Intrinsics_vec128_add32(st[1U], st[5U]);
  std6 = Lib_IntVector_Intrinsics_vec128_xor(st[13U], st[1U]);
  st[13U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std6, (uint32_t)8U);
  st[9U] = Lib_IntVector_Intrinsics_vec128_add32(st[9U], st[13U]);
  std7 = Lib_IntVector_Intrinsics_vec128_xor(st[5U], st[9U]);
  st[5U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std7, (uint32_t)7U);
  st[2U] = Lib_IntVector_Intrinsics_vec128_add32(st[2U], st[6U]);
  std8 = Lib_IntVector_Intrinsics_vec128_xor(st[14U], st[2U]);
  st[14U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std8, (uint32_t)16U);
  st[10U] = Lib_IntVector_Intrinsics_vec128_add32(st[10U], st[14U]);
  std9 = Lib_IntVector_Intrinsics_vec128_xor(st[6U], st[10U]);
  st[6U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std9, (uint32_t)12U);
  st[2U] = Lib_IntVector_Intrinsics_vec128_add32(st[2U], st[6U]);
  std10 = Lib_IntVector_Intrinsics_vec128_xor(st[14U], st[2U]);
  st[14U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std10, (uint32_t)8U);
  st[10U] = Lib_IntVector_Intrinsics_vec128_add32(st[10U], st[14U]);
  std11 = Lib_IntVector_Intrinsics_vec128_xor(st[6U], st[10U]);
  st[6U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std11, (uint32_t)7U);
  st[3U] = Lib_IntVector_Intrinsics_vec128_add32(st[3U], st[7U]);
  std12 = Lib_IntVector_Intrinsics_vec128_xor(st[15U], st[3U]);
  st[15U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std12, (uint32_t)16U);
  st[11U] = Lib_IntVector_Intrinsics_vec128_add32(st[11U], st[15U]);
  std13 = Lib_IntVector_Intrinsics_vec128_xor(st[7U], st[11U]);
  st[7U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std13, (uint32_t)12U);
  st[3U] = Lib_IntVector_Intrinsics_vec128_add32(st[3U], st[7U]);
  std14 = Lib_IntVector_Intrinsics_vec128_xor(st[15U], st[3U]);
  st[15U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std14, (uint32_t)8U);
  st[11U] = Lib_IntVector_Intrinsics_vec128_add32(st[11U], st[15U]);
  std15 = Lib_IntVector_Intrinsics_vec128_xor(st[7U], st[11U]);
  st[7U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std15, (uint32_t)7U);
  st[0U] = Lib_IntVector_Intrinsics_vec128_add32(st[0U], st[5U]);
  std16 = Lib_IntVector_Intrinsics_vec128_xor(st[15U], st[0U]);
  st[15U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std16, (uint32_t)16U);
  st[10U] = Lib_IntVector_Intrinsics_vec128_add32(st[10U], st[15U]);
  std17 = Lib_IntVector_Intrinsics_vec128_xor(st[5U], st[10U]);
  st[5U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std17, (uint32_t)12U);
  st[0U] = Lib_IntVector_Intrinsics_vec128_add32(st[0U], st[5U]);
  std18 = Lib_IntVector_Intrinsics_vec128_xor(st[15U], st[0U]);
  st[15U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std18, (uint32_t)8U);
  st[10U] = Lib_IntVector_Intrinsics_vec128_add32(st[10U], st[15U]);
  std19 = Lib_IntVector_Intrinsics_vec128_xor(st[5U], st[10U]);
  st[5U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std19, (uint32_t)7U);
  st[1U] = Lib_IntVector_Intrinsics_vec128_add32(st[1U], st[6U]);
  std20 = Lib_IntVector_Intrinsics_vec128_xor(st[12U], st[1U]);
  st[12U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std20, (uint32_t)16U);
  st[11U] = Lib_IntVector_Intrinsics_vec128_add32(st[11U], st[12U]);
  std21 = Lib_IntVector_Intrinsics_vec128_xor(st[6U], st[11U]);
  st[6U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std21, (uint32_t)12U);
  st[1U] = Lib_IntVector_Intrinsics_vec128_add32(st[1U], st[6U]);
  std22 = Lib_IntVector_Intrinsics_vec128_xor(st[12U], st[1U]);
  st[12U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std22, (uint32_t)8U);
  st[11U] = Lib_IntVector_Intrinsics_vec128_add32(st[11U], st[12U]);
  std23 = Lib_IntVector_Intrinsics_vec128_xor(st[6U], st[11U]);
  st[6U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std23, (uint32_t)7U);
  st[2U] = Lib_IntVector_Intrinsics_vec128_add32(st[2U], st[7U]);
  std24 = Lib_IntVector_Intrinsics_vec128_xor(st[13U], st[2U]);
  st[13U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std24, (uint32_t)16U);
  st[8U] = Lib_IntVector_Intrinsics_vec128_add32(st[8U], st[13U]);
  std25 = Lib_IntVector_Intrinsics_vec128_xor(st[7U], st[8U]);
  st[7U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std25, (uint32_t)12U);
  st[2U] = Lib_IntVector_Intrinsics_vec128_add32(st[2U], st[7U]);
  std26 = Lib_IntVector_Intrinsics_vec128_xor(st[13U], st[2U]);
  st[13U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std26, (uint32_t)8U);
  st[8U] = Lib_IntVector_Intrinsics_vec128_add32(st[8U], st[13U]);
  std27 = Lib_IntVector_Intrinsics_vec128_xor(st[7U], st[8U]);
  st[7U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std27, (uint32_t)7U);
  st[3U] = Lib_IntVector_Intrinsics_vec128_add32(st[3U], st[4U]);
  std28 = Lib_IntVector_Intrinsics_vec128_xor(st[14U], st[3U]);
  st[14U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std28, (uint32_t)16U);
  st[9U] = Lib_IntVector_Intrinsics_vec128_add32(st[9U], st[14U]);
  std29 = Lib_IntVector_Intrinsics_vec128_xor(st[4U], st[9U]);
  st[4U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std29, (uint32_t)12U);
  st[3U] = Lib_IntVector_Intrinsics_vec128_add32(st[3U], st[4U]);
  std30 = Lib_IntVector_Intrinsics_vec128_xor(st[14U], st[3U]);
  st[14U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std30, (uint32_t)8U);
  st[9U] = Lib_IntVector_Intrinsics_vec128_add32(st[9U], st[14U]);
  std = Lib_IntVector_Intrinsics_vec128_xor(st[4U], st[9U]);
  st[4U] = Lib_IntVector_Intrinsics_vec128_rotate_left32(std, (uint32_t)7U);
}

static inline void
chacha20_core_128(
  Lib_IntVector_Intrinsics_vec128 *k,
  Lib_IntVector_Intrinsics_vec128 *ctx,
  uint32_t ctr
)
{
  uint32_t ctr_u32;
  Lib_IntVector_Intrinsics_vec128 cv;
  memcpy(k, ctx, (uint32_t)16U * sizeof (Lib_IntVector_Intrinsics_vec128));
  ctr_u32 = (uint32_t)4U * ctr;
  cv = Lib_IntVector_Intrinsics_vec128_load32(ctr_u32);
  k[12U] = Lib_IntVector_Intrinsics_vec128_add32(k[12U], cv);
  double_round_128(k);
  double_round_128(k);
  double_round_128(k);
  double_round_128(k);
  double_round_128(k);
  double_round_128(k);
  double_round_128(k);
  double_round_128(k);
  double_round_128(k);
  double_round_128(k);
  {
    uint32_t i;
    for (i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      Lib_IntVector_Intrinsics_vec128 *os = k;
      Lib_IntVector_Intrinsics_vec128 x = Lib_IntVector_Intrinsics_vec128_add32(k[i], ctx[i]);
      os[i] = x;
    }
  }
  k[12U] = Lib_IntVector_Intrinsics_vec128_add32(k[12U], cv);
}

static inline void
chacha20_init_128(Lib_IntVector_Intrinsics_vec128 *ctx, uint8_t *k, uint8_t *n, uint32_t ctr)
{
  uint32_t ctx1[16U] = { 0U };
  uint32_t *uu____0 = ctx1;
  uint32_t *uu____1;
  uint32_t *uu____2;
  Lib_IntVector_Intrinsics_vec128 ctr1;
  Lib_IntVector_Intrinsics_vec128 c12;
  {
    uint32_t i;
    for (i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = uu____0;
      uint32_t x = Hacl_Impl_Chacha20_Vec_chacha20_constants[i];
      os[i] = x;
    }
  }
  uu____1 = ctx1 + (uint32_t)4U;
  {
    uint32_t i;
    for (i = (uint32_t)0U; i < (uint32_t)8U; i++)
    {
      uint32_t *os = uu____1;
      uint8_t *bj = k + i * (uint32_t)4U;
      uint32_t u = load32_le(bj);
      uint32_t r = u;
      uint32_t x = r;
      os[i] = x;
    }
  }
  ctx1[12U] = ctr;
  uu____2 = ctx1 + (uint32_t)13U;
  {
    uint32_t i;
    for (i = (uint32_t)0U; i < (uint32_t)3U; i++)
    {
      uint32_t *os = uu____2;
      uint8_t *bj = n + i * (uint32_t)4U;
      uint32_t u = load32_le(bj);
      uint32_t r = u;
      uint32_t x = r;
      os[i] = x;
    }
  }
  {
    uint32_t i;
    for (i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      Lib_IntVector_Intrinsics_vec128 *os = ctx;
      uint32_t x = ctx1[i];
      Lib_IntVector_Intrinsics_vec128 x0 = Lib_IntVector_Intrinsics_vec128_load32(x);
      os[i] = x0;
    }
  }
  ctr1 =
    Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)0U,
      (uint32_t)1U,
      (uint32_t)2U,
      (uint32_t)3U);
  c12 = ctx[12U];
  ctx[12U] = Lib_IntVector_Intrinsics_vec128_add32(c12, ctr1);
}

void
Hacl_Chacha20_Vec128_chacha20_encrypt_128(
  uint32_t len,
  uint8_t *out,
  uint8_t *text,
  uint8_t *key,
  uint8_t *n,
  uint32_t ctr
)
{
  Lib_IntVector_Intrinsics_vec128 ctx[16U];
  {
    uint32_t _i;
    for (_i = 0U; _i < (uint32_t)16U; ++_i)
      ctx[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  }
  {
    uint32_t rem;
    uint32_t nb;
    uint32_t rem1;
    chacha20_init_128(ctx, key, n, ctr);
    rem = len % (uint32_t)256U;
    nb = len / (uint32_t)256U;
    rem1 = len % (uint32_t)256U;
    {
      uint32_t i;
      for (i = (uint32_t)0U; i < nb; i++)
      {
        uint8_t *uu____0 = out + i * (uint32_t)256U;
        uint8_t *uu____1 = text + i * (uint32_t)256U;
        Lib_IntVector_Intrinsics_vec128 k[16U];
        {
          uint32_t _i;
          for (_i = 0U; _i < (uint32_t)16U; ++_i)
            k[_i] = Lib_IntVector_Intrinsics_vec128_zero;
        }
        chacha20_core_128(k, ctx, i);
        {
          Lib_IntVector_Intrinsics_vec128 st0 = k[0U];
          Lib_IntVector_Intrinsics_vec128 st1 = k[1U];
          Lib_IntVector_Intrinsics_vec128 st2 = k[2U];
          Lib_IntVector_Intrinsics_vec128 st3 = k[3U];
          Lib_IntVector_Intrinsics_vec128 st4 = k[4U];
          Lib_IntVector_Intrinsics_vec128 st5 = k[5U];
          Lib_IntVector_Intrinsics_vec128 st6 = k[6U];
          Lib_IntVector_Intrinsics_vec128 st7 = k[7U];
          Lib_IntVector_Intrinsics_vec128 st8 = k[8U];
          Lib_IntVector_Intrinsics_vec128 st9 = k[9U];
          Lib_IntVector_Intrinsics_vec128 st10 = k[10U];
          Lib_IntVector_Intrinsics_vec128 st11 = k[11U];
          Lib_IntVector_Intrinsics_vec128 st12 = k[12U];
          Lib_IntVector_Intrinsics_vec128 st13 = k[13U];
          Lib_IntVector_Intrinsics_vec128 st14 = k[14U];
          Lib_IntVector_Intrinsics_vec128 st15 = k[15U];
          Lib_IntVector_Intrinsics_vec128
          v0_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(st0, st1);
          Lib_IntVector_Intrinsics_vec128
          v1_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(st0, st1);
          Lib_IntVector_Intrinsics_vec128
          v2_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(st2, st3);
          Lib_IntVector_Intrinsics_vec128
          v3_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(st2, st3);
          Lib_IntVector_Intrinsics_vec128
          v0__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_, v2_);
          Lib_IntVector_Intrinsics_vec128
          v1__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_, v2_);
          Lib_IntVector_Intrinsics_vec128
          v2__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_, v3_);
          Lib_IntVector_Intrinsics_vec128
          v3__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_, v3_);
          Lib_IntVector_Intrinsics_vec128 v0__0 = v0__;
          Lib_IntVector_Intrinsics_vec128 v2__0 = v2__;
          Lib_IntVector_Intrinsics_vec128 v1__0 = v1__;
          Lib_IntVector_Intrinsics_vec128 v3__0 = v3__;
          Lib_IntVector_Intrinsics_vec128 v0 = v0__0;
          Lib_IntVector_Intrinsics_vec128 v1 = v1__0;
          Lib_IntVector_Intrinsics_vec128 v2 = v2__0;
          Lib_IntVector_Intrinsics_vec128 v3 = v3__0;
          Lib_IntVector_Intrinsics_vec128
          v0_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st4, st5);
          Lib_IntVector_Intrinsics_vec128
          v1_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st4, st5);
          Lib_IntVector_Intrinsics_vec128
          v2_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st6, st7);
          Lib_IntVector_Intrinsics_vec128
          v3_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st6, st7);
          Lib_IntVector_Intrinsics_vec128
          v0__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_0, v2_0);
          Lib_IntVector_Intrinsics_vec128
          v1__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_0, v2_0);
          Lib_IntVector_Intrinsics_vec128
          v2__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_0, v3_0);
          Lib_IntVector_Intrinsics_vec128
          v3__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_0, v3_0);
          Lib_IntVector_Intrinsics_vec128 v0__2 = v0__1;
          Lib_IntVector_Intrinsics_vec128 v2__2 = v2__1;
          Lib_IntVector_Intrinsics_vec128 v1__2 = v1__1;
          Lib_IntVector_Intrinsics_vec128 v3__2 = v3__1;
          Lib_IntVector_Intrinsics_vec128 v4 = v0__2;
          Lib_IntVector_Intrinsics_vec128 v5 = v1__2;
          Lib_IntVector_Intrinsics_vec128 v6 = v2__2;
          Lib_IntVector_Intrinsics_vec128 v7 = v3__2;
          Lib_IntVector_Intrinsics_vec128
          v0_1 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st8, st9);
          Lib_IntVector_Intrinsics_vec128
          v1_1 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st8, st9);
          Lib_IntVector_Intrinsics_vec128
          v2_1 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st10, st11);
          Lib_IntVector_Intrinsics_vec128
          v3_1 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st10, st11);
          Lib_IntVector_Intrinsics_vec128
          v0__3 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_1, v2_1);
          Lib_IntVector_Intrinsics_vec128
          v1__3 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_1, v2_1);
          Lib_IntVector_Intrinsics_vec128
          v2__3 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_1, v3_1);
          Lib_IntVector_Intrinsics_vec128
          v3__3 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_1, v3_1);
          Lib_IntVector_Intrinsics_vec128 v0__4 = v0__3;
          Lib_IntVector_Intrinsics_vec128 v2__4 = v2__3;
          Lib_IntVector_Intrinsics_vec128 v1__4 = v1__3;
          Lib_IntVector_Intrinsics_vec128 v3__4 = v3__3;
          Lib_IntVector_Intrinsics_vec128 v8 = v0__4;
          Lib_IntVector_Intrinsics_vec128 v9 = v1__4;
          Lib_IntVector_Intrinsics_vec128 v10 = v2__4;
          Lib_IntVector_Intrinsics_vec128 v11 = v3__4;
          Lib_IntVector_Intrinsics_vec128
          v0_2 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st12, st13);
          Lib_IntVector_Intrinsics_vec128
          v1_2 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st12, st13);
          Lib_IntVector_Intrinsics_vec128
          v2_2 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st14, st15);
          Lib_IntVector_Intrinsics_vec128
          v3_2 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st14, st15);
          Lib_IntVector_Intrinsics_vec128
          v0__5 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_2, v2_2);
          Lib_IntVector_Intrinsics_vec128
          v1__5 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_2, v2_2);
          Lib_IntVector_Intrinsics_vec128
          v2__5 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_2, v3_2);
          Lib_IntVector_Intrinsics_vec128
          v3__5 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_2, v3_2);
          Lib_IntVector_Intrinsics_vec128 v0__6 = v0__5;
          Lib_IntVector_Intrinsics_vec128 v2__6 = v2__5;
          Lib_IntVector_Intrinsics_vec128 v1__6 = v1__5;
          Lib_IntVector_Intrinsics_vec128 v3__6 = v3__5;
          Lib_IntVector_Intrinsics_vec128 v12 = v0__6;
          Lib_IntVector_Intrinsics_vec128 v13 = v1__6;
          Lib_IntVector_Intrinsics_vec128 v14 = v2__6;
          Lib_IntVector_Intrinsics_vec128 v15 = v3__6;
          k[0U] = v0;
          k[1U] = v4;
          k[2U] = v8;
          k[3U] = v12;
          k[4U] = v1;
          k[5U] = v5;
          k[6U] = v9;
          k[7U] = v13;
          k[8U] = v2;
          k[9U] = v6;
          k[10U] = v10;
          k[11U] = v14;
          k[12U] = v3;
          k[13U] = v7;
          k[14U] = v11;
          k[15U] = v15;
          {
            uint32_t i0;
            for (i0 = (uint32_t)0U; i0 < (uint32_t)16U; i0++)
            {
              Lib_IntVector_Intrinsics_vec128
              x = Lib_IntVector_Intrinsics_vec128_load32_le(uu____1 + i0 * (uint32_t)16U);
              Lib_IntVector_Intrinsics_vec128 y = Lib_IntVector_Intrinsics_vec128_xor(x, k[i0]);
              Lib_IntVector_Intrinsics_vec128_store32_le(uu____0 + i0 * (uint32_t)16U, y);
            }
          }
        }
      }
    }
    if (rem1 > (uint32_t)0U)
    {
      uint8_t *uu____2 = out + nb * (uint32_t)256U;
      uint8_t *uu____3 = text + nb * (uint32_t)256U;
      uint8_t plain[256U] = { 0U };
      memcpy(plain, uu____3, rem * sizeof (uint8_t));
      {
        Lib_IntVector_Intrinsics_vec128 k[16U];
        {
          uint32_t _i;
          for (_i = 0U; _i < (uint32_t)16U; ++_i)
            k[_i] = Lib_IntVector_Intrinsics_vec128_zero;
        }
        chacha20_core_128(k, ctx, nb);
        {
          Lib_IntVector_Intrinsics_vec128 st0 = k[0U];
          Lib_IntVector_Intrinsics_vec128 st1 = k[1U];
          Lib_IntVector_Intrinsics_vec128 st2 = k[2U];
          Lib_IntVector_Intrinsics_vec128 st3 = k[3U];
          Lib_IntVector_Intrinsics_vec128 st4 = k[4U];
          Lib_IntVector_Intrinsics_vec128 st5 = k[5U];
          Lib_IntVector_Intrinsics_vec128 st6 = k[6U];
          Lib_IntVector_Intrinsics_vec128 st7 = k[7U];
          Lib_IntVector_Intrinsics_vec128 st8 = k[8U];
          Lib_IntVector_Intrinsics_vec128 st9 = k[9U];
          Lib_IntVector_Intrinsics_vec128 st10 = k[10U];
          Lib_IntVector_Intrinsics_vec128 st11 = k[11U];
          Lib_IntVector_Intrinsics_vec128 st12 = k[12U];
          Lib_IntVector_Intrinsics_vec128 st13 = k[13U];
          Lib_IntVector_Intrinsics_vec128 st14 = k[14U];
          Lib_IntVector_Intrinsics_vec128 st15 = k[15U];
          Lib_IntVector_Intrinsics_vec128
          v0_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(st0, st1);
          Lib_IntVector_Intrinsics_vec128
          v1_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(st0, st1);
          Lib_IntVector_Intrinsics_vec128
          v2_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(st2, st3);
          Lib_IntVector_Intrinsics_vec128
          v3_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(st2, st3);
          Lib_IntVector_Intrinsics_vec128
          v0__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_, v2_);
          Lib_IntVector_Intrinsics_vec128
          v1__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_, v2_);
          Lib_IntVector_Intrinsics_vec128
          v2__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_, v3_);
          Lib_IntVector_Intrinsics_vec128
          v3__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_, v3_);
          Lib_IntVector_Intrinsics_vec128 v0__0 = v0__;
          Lib_IntVector_Intrinsics_vec128 v2__0 = v2__;
          Lib_IntVector_Intrinsics_vec128 v1__0 = v1__;
          Lib_IntVector_Intrinsics_vec128 v3__0 = v3__;
          Lib_IntVector_Intrinsics_vec128 v0 = v0__0;
          Lib_IntVector_Intrinsics_vec128 v1 = v1__0;
          Lib_IntVector_Intrinsics_vec128 v2 = v2__0;
          Lib_IntVector_Intrinsics_vec128 v3 = v3__0;
          Lib_IntVector_Intrinsics_vec128
          v0_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st4, st5);
          Lib_IntVector_Intrinsics_vec128
          v1_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st4, st5);
          Lib_IntVector_Intrinsics_vec128
          v2_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st6, st7);
          Lib_IntVector_Intrinsics_vec128
          v3_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st6, st7);
          Lib_IntVector_Intrinsics_vec128
          v0__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_0, v2_0);
          Lib_IntVector_Intrinsics_vec128
          v1__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_0, v2_0);
          Lib_IntVector_Intrinsics_vec128
          v2__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_0, v3_0);
          Lib_IntVector_Intrinsics_vec128
          v3__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_0, v3_0);
          Lib_IntVector_Intrinsics_vec128 v0__2 = v0__1;
          Lib_IntVector_Intrinsics_vec128 v2__2 = v2__1;
          Lib_IntVector_Intrinsics_vec128 v1__2 = v1__1;
          Lib_IntVector_Intrinsics_vec128 v3__2 = v3__1;
          Lib_IntVector_Intrinsics_vec128 v4 = v0__2;
          Lib_IntVector_Intrinsics_vec128 v5 = v1__2;
          Lib_IntVector_Intrinsics_vec128 v6 = v2__2;
          Lib_IntVector_Intrinsics_vec128 v7 = v3__2;
          Lib_IntVector_Intrinsics_vec128
          v0_1 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st8, st9);
          Lib_IntVector_Intrinsics_vec128
          v1_1 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st8, st9);
          Lib_IntVector_Intrinsics_vec128
          v2_1 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st10, st11);
          Lib_IntVector_Intrinsics_vec128
          v3_1 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st10, st11);
          Lib_IntVector_Intrinsics_vec128
          v0__3 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_1, v2_1);
          Lib_IntVector_Intrinsics_vec128
          v1__3 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_1, v2_1);
          Lib_IntVector_Intrinsics_vec128
          v2__3 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_1, v3_1);
          Lib_IntVector_Intrinsics_vec128
          v3__3 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_1, v3_1);
          Lib_IntVector_Intrinsics_vec128 v0__4 = v0__3;
          Lib_IntVector_Intrinsics_vec128 v2__4 = v2__3;
          Lib_IntVector_Intrinsics_vec128 v1__4 = v1__3;
          Lib_IntVector_Intrinsics_vec128 v3__4 = v3__3;
          Lib_IntVector_Intrinsics_vec128 v8 = v0__4;
          Lib_IntVector_Intrinsics_vec128 v9 = v1__4;
          Lib_IntVector_Intrinsics_vec128 v10 = v2__4;
          Lib_IntVector_Intrinsics_vec128 v11 = v3__4;
          Lib_IntVector_Intrinsics_vec128
          v0_2 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st12, st13);
          Lib_IntVector_Intrinsics_vec128
          v1_2 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st12, st13);
          Lib_IntVector_Intrinsics_vec128
          v2_2 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st14, st15);
          Lib_IntVector_Intrinsics_vec128
          v3_2 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st14, st15);
          Lib_IntVector_Intrinsics_vec128
          v0__5 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_2, v2_2);
          Lib_IntVector_Intrinsics_vec128
          v1__5 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_2, v2_2);
          Lib_IntVector_Intrinsics_vec128
          v2__5 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_2, v3_2);
          Lib_IntVector_Intrinsics_vec128
          v3__5 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_2, v3_2);
          Lib_IntVector_Intrinsics_vec128 v0__6 = v0__5;
          Lib_IntVector_Intrinsics_vec128 v2__6 = v2__5;
          Lib_IntVector_Intrinsics_vec128 v1__6 = v1__5;
          Lib_IntVector_Intrinsics_vec128 v3__6 = v3__5;
          Lib_IntVector_Intrinsics_vec128 v12 = v0__6;
          Lib_IntVector_Intrinsics_vec128 v13 = v1__6;
          Lib_IntVector_Intrinsics_vec128 v14 = v2__6;
          Lib_IntVector_Intrinsics_vec128 v15 = v3__6;
          k[0U] = v0;
          k[1U] = v4;
          k[2U] = v8;
          k[3U] = v12;
          k[4U] = v1;
          k[5U] = v5;
          k[6U] = v9;
          k[7U] = v13;
          k[8U] = v2;
          k[9U] = v6;
          k[10U] = v10;
          k[11U] = v14;
          k[12U] = v3;
          k[13U] = v7;
          k[14U] = v11;
          k[15U] = v15;
          {
            uint32_t i;
            for (i = (uint32_t)0U; i < (uint32_t)16U; i++)
            {
              Lib_IntVector_Intrinsics_vec128
              x = Lib_IntVector_Intrinsics_vec128_load32_le(plain + i * (uint32_t)16U);
              Lib_IntVector_Intrinsics_vec128 y = Lib_IntVector_Intrinsics_vec128_xor(x, k[i]);
              Lib_IntVector_Intrinsics_vec128_store32_le(plain + i * (uint32_t)16U, y);
            }
          }
          memcpy(uu____2, plain, rem * sizeof (uint8_t));
        }
      }
    }
  }
}

void
Hacl_Chacha20_Vec128_chacha20_decrypt_128(
  uint32_t len,
  uint8_t *out,
  uint8_t *cipher,
  uint8_t *key,
  uint8_t *n,
  uint32_t ctr
)
{
  Lib_IntVector_Intrinsics_vec128 ctx[16U];
  {
    uint32_t _i;
    for (_i = 0U; _i < (uint32_t)16U; ++_i)
      ctx[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  }
  {
    uint32_t rem;
    uint32_t nb;
    uint32_t rem1;
    chacha20_init_128(ctx, key, n, ctr);
    rem = len % (uint32_t)256U;
    nb = len / (uint32_t)256U;
    rem1 = len % (uint32_t)256U;
    {
      uint32_t i;
      for (i = (uint32_t)0U; i < nb; i++)
      {
        uint8_t *uu____0 = out + i * (uint32_t)256U;
        uint8_t *uu____1 = cipher + i * (uint32_t)256U;
        Lib_IntVector_Intrinsics_vec128 k[16U];
        {
          uint32_t _i;
          for (_i = 0U; _i < (uint32_t)16U; ++_i)
            k[_i] = Lib_IntVector_Intrinsics_vec128_zero;
        }
        chacha20_core_128(k, ctx, i);
        {
          Lib_IntVector_Intrinsics_vec128 st0 = k[0U];
          Lib_IntVector_Intrinsics_vec128 st1 = k[1U];
          Lib_IntVector_Intrinsics_vec128 st2 = k[2U];
          Lib_IntVector_Intrinsics_vec128 st3 = k[3U];
          Lib_IntVector_Intrinsics_vec128 st4 = k[4U];
          Lib_IntVector_Intrinsics_vec128 st5 = k[5U];
          Lib_IntVector_Intrinsics_vec128 st6 = k[6U];
          Lib_IntVector_Intrinsics_vec128 st7 = k[7U];
          Lib_IntVector_Intrinsics_vec128 st8 = k[8U];
          Lib_IntVector_Intrinsics_vec128 st9 = k[9U];
          Lib_IntVector_Intrinsics_vec128 st10 = k[10U];
          Lib_IntVector_Intrinsics_vec128 st11 = k[11U];
          Lib_IntVector_Intrinsics_vec128 st12 = k[12U];
          Lib_IntVector_Intrinsics_vec128 st13 = k[13U];
          Lib_IntVector_Intrinsics_vec128 st14 = k[14U];
          Lib_IntVector_Intrinsics_vec128 st15 = k[15U];
          Lib_IntVector_Intrinsics_vec128
          v0_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(st0, st1);
          Lib_IntVector_Intrinsics_vec128
          v1_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(st0, st1);
          Lib_IntVector_Intrinsics_vec128
          v2_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(st2, st3);
          Lib_IntVector_Intrinsics_vec128
          v3_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(st2, st3);
          Lib_IntVector_Intrinsics_vec128
          v0__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_, v2_);
          Lib_IntVector_Intrinsics_vec128
          v1__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_, v2_);
          Lib_IntVector_Intrinsics_vec128
          v2__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_, v3_);
          Lib_IntVector_Intrinsics_vec128
          v3__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_, v3_);
          Lib_IntVector_Intrinsics_vec128 v0__0 = v0__;
          Lib_IntVector_Intrinsics_vec128 v2__0 = v2__;
          Lib_IntVector_Intrinsics_vec128 v1__0 = v1__;
          Lib_IntVector_Intrinsics_vec128 v3__0 = v3__;
          Lib_IntVector_Intrinsics_vec128 v0 = v0__0;
          Lib_IntVector_Intrinsics_vec128 v1 = v1__0;
          Lib_IntVector_Intrinsics_vec128 v2 = v2__0;
          Lib_IntVector_Intrinsics_vec128 v3 = v3__0;
          Lib_IntVector_Intrinsics_vec128
          v0_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st4, st5);
          Lib_IntVector_Intrinsics_vec128
          v1_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st4, st5);
          Lib_IntVector_Intrinsics_vec128
          v2_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st6, st7);
          Lib_IntVector_Intrinsics_vec128
          v3_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st6, st7);
          Lib_IntVector_Intrinsics_vec128
          v0__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_0, v2_0);
          Lib_IntVector_Intrinsics_vec128
          v1__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_0, v2_0);
          Lib_IntVector_Intrinsics_vec128
          v2__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_0, v3_0);
          Lib_IntVector_Intrinsics_vec128
          v3__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_0, v3_0);
          Lib_IntVector_Intrinsics_vec128 v0__2 = v0__1;
          Lib_IntVector_Intrinsics_vec128 v2__2 = v2__1;
          Lib_IntVector_Intrinsics_vec128 v1__2 = v1__1;
          Lib_IntVector_Intrinsics_vec128 v3__2 = v3__1;
          Lib_IntVector_Intrinsics_vec128 v4 = v0__2;
          Lib_IntVector_Intrinsics_vec128 v5 = v1__2;
          Lib_IntVector_Intrinsics_vec128 v6 = v2__2;
          Lib_IntVector_Intrinsics_vec128 v7 = v3__2;
          Lib_IntVector_Intrinsics_vec128
          v0_1 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st8, st9);
          Lib_IntVector_Intrinsics_vec128
          v1_1 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st8, st9);
          Lib_IntVector_Intrinsics_vec128
          v2_1 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st10, st11);
          Lib_IntVector_Intrinsics_vec128
          v3_1 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st10, st11);
          Lib_IntVector_Intrinsics_vec128
          v0__3 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_1, v2_1);
          Lib_IntVector_Intrinsics_vec128
          v1__3 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_1, v2_1);
          Lib_IntVector_Intrinsics_vec128
          v2__3 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_1, v3_1);
          Lib_IntVector_Intrinsics_vec128
          v3__3 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_1, v3_1);
          Lib_IntVector_Intrinsics_vec128 v0__4 = v0__3;
          Lib_IntVector_Intrinsics_vec128 v2__4 = v2__3;
          Lib_IntVector_Intrinsics_vec128 v1__4 = v1__3;
          Lib_IntVector_Intrinsics_vec128 v3__4 = v3__3;
          Lib_IntVector_Intrinsics_vec128 v8 = v0__4;
          Lib_IntVector_Intrinsics_vec128 v9 = v1__4;
          Lib_IntVector_Intrinsics_vec128 v10 = v2__4;
          Lib_IntVector_Intrinsics_vec128 v11 = v3__4;
          Lib_IntVector_Intrinsics_vec128
          v0_2 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st12, st13);
          Lib_IntVector_Intrinsics_vec128
          v1_2 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st12, st13);
          Lib_IntVector_Intrinsics_vec128
          v2_2 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st14, st15);
          Lib_IntVector_Intrinsics_vec128
          v3_2 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st14, st15);
          Lib_IntVector_Intrinsics_vec128
          v0__5 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_2, v2_2);
          Lib_IntVector_Intrinsics_vec128
          v1__5 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_2, v2_2);
          Lib_IntVector_Intrinsics_vec128
          v2__5 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_2, v3_2);
          Lib_IntVector_Intrinsics_vec128
          v3__5 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_2, v3_2);
          Lib_IntVector_Intrinsics_vec128 v0__6 = v0__5;
          Lib_IntVector_Intrinsics_vec128 v2__6 = v2__5;
          Lib_IntVector_Intrinsics_vec128 v1__6 = v1__5;
          Lib_IntVector_Intrinsics_vec128 v3__6 = v3__5;
          Lib_IntVector_Intrinsics_vec128 v12 = v0__6;
          Lib_IntVector_Intrinsics_vec128 v13 = v1__6;
          Lib_IntVector_Intrinsics_vec128 v14 = v2__6;
          Lib_IntVector_Intrinsics_vec128 v15 = v3__6;
          k[0U] = v0;
          k[1U] = v4;
          k[2U] = v8;
          k[3U] = v12;
          k[4U] = v1;
          k[5U] = v5;
          k[6U] = v9;
          k[7U] = v13;
          k[8U] = v2;
          k[9U] = v6;
          k[10U] = v10;
          k[11U] = v14;
          k[12U] = v3;
          k[13U] = v7;
          k[14U] = v11;
          k[15U] = v15;
          {
            uint32_t i0;
            for (i0 = (uint32_t)0U; i0 < (uint32_t)16U; i0++)
            {
              Lib_IntVector_Intrinsics_vec128
              x = Lib_IntVector_Intrinsics_vec128_load32_le(uu____1 + i0 * (uint32_t)16U);
              Lib_IntVector_Intrinsics_vec128 y = Lib_IntVector_Intrinsics_vec128_xor(x, k[i0]);
              Lib_IntVector_Intrinsics_vec128_store32_le(uu____0 + i0 * (uint32_t)16U, y);
            }
          }
        }
      }
    }
    if (rem1 > (uint32_t)0U)
    {
      uint8_t *uu____2 = out + nb * (uint32_t)256U;
      uint8_t *uu____3 = cipher + nb * (uint32_t)256U;
      uint8_t plain[256U] = { 0U };
      memcpy(plain, uu____3, rem * sizeof (uint8_t));
      {
        Lib_IntVector_Intrinsics_vec128 k[16U];
        {
          uint32_t _i;
          for (_i = 0U; _i < (uint32_t)16U; ++_i)
            k[_i] = Lib_IntVector_Intrinsics_vec128_zero;
        }
        chacha20_core_128(k, ctx, nb);
        {
          Lib_IntVector_Intrinsics_vec128 st0 = k[0U];
          Lib_IntVector_Intrinsics_vec128 st1 = k[1U];
          Lib_IntVector_Intrinsics_vec128 st2 = k[2U];
          Lib_IntVector_Intrinsics_vec128 st3 = k[3U];
          Lib_IntVector_Intrinsics_vec128 st4 = k[4U];
          Lib_IntVector_Intrinsics_vec128 st5 = k[5U];
          Lib_IntVector_Intrinsics_vec128 st6 = k[6U];
          Lib_IntVector_Intrinsics_vec128 st7 = k[7U];
          Lib_IntVector_Intrinsics_vec128 st8 = k[8U];
          Lib_IntVector_Intrinsics_vec128 st9 = k[9U];
          Lib_IntVector_Intrinsics_vec128 st10 = k[10U];
          Lib_IntVector_Intrinsics_vec128 st11 = k[11U];
          Lib_IntVector_Intrinsics_vec128 st12 = k[12U];
          Lib_IntVector_Intrinsics_vec128 st13 = k[13U];
          Lib_IntVector_Intrinsics_vec128 st14 = k[14U];
          Lib_IntVector_Intrinsics_vec128 st15 = k[15U];
          Lib_IntVector_Intrinsics_vec128
          v0_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(st0, st1);
          Lib_IntVector_Intrinsics_vec128
          v1_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(st0, st1);
          Lib_IntVector_Intrinsics_vec128
          v2_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(st2, st3);
          Lib_IntVector_Intrinsics_vec128
          v3_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(st2, st3);
          Lib_IntVector_Intrinsics_vec128
          v0__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_, v2_);
          Lib_IntVector_Intrinsics_vec128
          v1__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_, v2_);
          Lib_IntVector_Intrinsics_vec128
          v2__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_, v3_);
          Lib_IntVector_Intrinsics_vec128
          v3__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_, v3_);
          Lib_IntVector_Intrinsics_vec128 v0__0 = v0__;
          Lib_IntVector_Intrinsics_vec128 v2__0 = v2__;
          Lib_IntVector_Intrinsics_vec128 v1__0 = v1__;
          Lib_IntVector_Intrinsics_vec128 v3__0 = v3__;
          Lib_IntVector_Intrinsics_vec128 v0 = v0__0;
          Lib_IntVector_Intrinsics_vec128 v1 = v1__0;
          Lib_IntVector_Intrinsics_vec128 v2 = v2__0;
          Lib_IntVector_Intrinsics_vec128 v3 = v3__0;
          Lib_IntVector_Intrinsics_vec128
          v0_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st4, st5);
          Lib_IntVector_Intrinsics_vec128
          v1_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st4, st5);
          Lib_IntVector_Intrinsics_vec128
          v2_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st6, st7);
          Lib_IntVector_Intrinsics_vec128
          v3_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st6, st7);
          Lib_IntVector_Intrinsics_vec128
          v0__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_0, v2_0);
          Lib_IntVector_Intrinsics_vec128
          v1__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_0, v2_0);
          Lib_IntVector_Intrinsics_vec128
          v2__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_0, v3_0);
          Lib_IntVector_Intrinsics_vec128
          v3__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_0, v3_0);
          Lib_IntVector_Intrinsics_vec128 v0__2 = v0__1;
          Lib_IntVector_Intrinsics_vec128 v2__2 = v2__1;
          Lib_IntVector_Intrinsics_vec128 v1__2 = v1__1;
          Lib_IntVector_Intrinsics_vec128 v3__2 = v3__1;
          Lib_IntVector_Intrinsics_vec128 v4 = v0__2;
          Lib_IntVector_Intrinsics_vec128 v5 = v1__2;
          Lib_IntVector_Intrinsics_vec128 v6 = v2__2;
          Lib_IntVector_Intrinsics_vec128 v7 = v3__2;
          Lib_IntVector_Intrinsics_vec128
          v0_1 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st8, st9);
          Lib_IntVector_Intrinsics_vec128
          v1_1 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st8, st9);
          Lib_IntVector_Intrinsics_vec128
          v2_1 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st10, st11);
          Lib_IntVector_Intrinsics_vec128
          v3_1 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st10, st11);
          Lib_IntVector_Intrinsics_vec128
          v0__3 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_1, v2_1);
          Lib_IntVector_Intrinsics_vec128
          v1__3 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_1, v2_1);
          Lib_IntVector_Intrinsics_vec128
          v2__3 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_1, v3_1);
          Lib_IntVector_Intrinsics_vec128
          v3__3 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_1, v3_1);
          Lib_IntVector_Intrinsics_vec128 v0__4 = v0__3;
          Lib_IntVector_Intrinsics_vec128 v2__4 = v2__3;
          Lib_IntVector_Intrinsics_vec128 v1__4 = v1__3;
          Lib_IntVector_Intrinsics_vec128 v3__4 = v3__3;
          Lib_IntVector_Intrinsics_vec128 v8 = v0__4;
          Lib_IntVector_Intrinsics_vec128 v9 = v1__4;
          Lib_IntVector_Intrinsics_vec128 v10 = v2__4;
          Lib_IntVector_Intrinsics_vec128 v11 = v3__4;
          Lib_IntVector_Intrinsics_vec128
          v0_2 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st12, st13);
          Lib_IntVector_Intrinsics_vec128
          v1_2 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st12, st13);
          Lib_IntVector_Intrinsics_vec128
          v2_2 = Lib_IntVector_Intrinsics_vec128_interleave_low32(st14, st15);
          Lib_IntVector_Intrinsics_vec128
          v3_2 = Lib_IntVector_Intrinsics_vec128_interleave_high32(st14, st15);
          Lib_IntVector_Intrinsics_vec128
          v0__5 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_2, v2_2);
          Lib_IntVector_Intrinsics_vec128
          v1__5 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_2, v2_2);
          Lib_IntVector_Intrinsics_vec128
          v2__5 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_2, v3_2);
          Lib_IntVector_Intrinsics_vec128
          v3__5 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_2, v3_2);
          Lib_IntVector_Intrinsics_vec128 v0__6 = v0__5;
          Lib_IntVector_Intrinsics_vec128 v2__6 = v2__5;
          Lib_IntVector_Intrinsics_vec128 v1__6 = v1__5;
          Lib_IntVector_Intrinsics_vec128 v3__6 = v3__5;
          Lib_IntVector_Intrinsics_vec128 v12 = v0__6;
          Lib_IntVector_Intrinsics_vec128 v13 = v1__6;
          Lib_IntVector_Intrinsics_vec128 v14 = v2__6;
          Lib_IntVector_Intrinsics_vec128 v15 = v3__6;
          k[0U] = v0;
          k[1U] = v4;
          k[2U] = v8;
          k[3U] = v12;
          k[4U] = v1;
          k[5U] = v5;
          k[6U] = v9;
          k[7U] = v13;
          k[8U] = v2;
          k[9U] = v6;
          k[10U] = v10;
          k[11U] = v14;
          k[12U] = v3;
          k[13U] = v7;
          k[14U] = v11;
          k[15U] = v15;
          {
            uint32_t i;
            for (i = (uint32_t)0U; i < (uint32_t)16U; i++)
            {
              Lib_IntVector_Intrinsics_vec128
              x = Lib_IntVector_Intrinsics_vec128_load32_le(plain + i * (uint32_t)16U);
              Lib_IntVector_Intrinsics_vec128 y = Lib_IntVector_Intrinsics_vec128_xor(x, k[i]);
              Lib_IntVector_Intrinsics_vec128_store32_le(plain + i * (uint32_t)16U, y);
            }
          }
          memcpy(uu____2, plain, rem * sizeof (uint8_t));
        }
      }
    }
  }
}

