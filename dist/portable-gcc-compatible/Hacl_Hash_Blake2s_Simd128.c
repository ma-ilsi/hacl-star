/* MIT License
 *
 * Copyright (c) 2016-2022 INRIA, CMU and Microsoft Corporation
 * Copyright (c) 2022-2023 HACL* Contributors
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


#include "internal/Hacl_Hash_Blake2s_Simd128.h"

#include "internal/Hacl_Impl_Blake2_Constants.h"

/* SNIPPET_START: update_block */

static inline void
update_block(
  Lib_IntVector_Intrinsics_vec128 *wv,
  Lib_IntVector_Intrinsics_vec128 *hash,
  bool flag,
  uint64_t totlen,
  uint8_t *d
)
{
  uint32_t m_w[16U] = { 0U };
  KRML_MAYBE_FOR16(i,
    (uint32_t)0U,
    (uint32_t)16U,
    (uint32_t)1U,
    uint32_t *os = m_w;
    uint8_t *bj = d + i * (uint32_t)4U;
    uint32_t u = load32_le(bj);
    uint32_t r = u;
    uint32_t x = r;
    os[i] = x;);
  Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
  uint32_t wv_14;
  if (flag)
  {
    wv_14 = (uint32_t)0xFFFFFFFFU;
  }
  else
  {
    wv_14 = (uint32_t)0U;
  }
  uint32_t wv_15 = (uint32_t)0U;
  mask =
    Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
      (uint32_t)(totlen >> (uint32_t)32U),
      wv_14,
      wv_15);
  memcpy(wv, hash, (uint32_t)4U * sizeof (Lib_IntVector_Intrinsics_vec128));
  Lib_IntVector_Intrinsics_vec128 *wv3 = wv + (uint32_t)3U;
  wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
  KRML_MAYBE_FOR10(i,
    (uint32_t)0U,
    (uint32_t)10U,
    (uint32_t)1U,
    uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
    KRML_PRE_ALIGN(16) Lib_IntVector_Intrinsics_vec128 m_st[4U] KRML_POST_ALIGN(16) = { 0U };
    Lib_IntVector_Intrinsics_vec128 *r0 = m_st;
    Lib_IntVector_Intrinsics_vec128 *r1 = m_st + (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U;
    Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U;
    uint32_t s0 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)0U];
    uint32_t s1 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)1U];
    uint32_t s2 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)2U];
    uint32_t s3 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)3U];
    uint32_t s4 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)4U];
    uint32_t s5 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)5U];
    uint32_t s6 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)6U];
    uint32_t s7 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)7U];
    uint32_t s8 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)8U];
    uint32_t s9 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)9U];
    uint32_t s10 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)10U];
    uint32_t s11 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)11U];
    uint32_t s12 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)12U];
    uint32_t s13 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)13U];
    uint32_t s14 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)14U];
    uint32_t s15 = Hacl_Hash_Blake2s_sigmaTable[start_idx + (uint32_t)15U];
    r0[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s2], m_w[s4], m_w[s6]);
    r1[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s1], m_w[s3], m_w[s5], m_w[s7]);
    r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
    r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s11], m_w[s13], m_w[s15]);
    Lib_IntVector_Intrinsics_vec128 *x = m_st;
    Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U;
    Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U;
    uint32_t a = (uint32_t)0U;
    uint32_t b0 = (uint32_t)1U;
    uint32_t c0 = (uint32_t)2U;
    uint32_t d10 = (uint32_t)3U;
    Lib_IntVector_Intrinsics_vec128 *wv_a0 = wv + a * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b0 = wv + b0 * (uint32_t)1U;
    wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
    wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a1 = wv + d10 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b1 = wv + a * (uint32_t)1U;
    wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
    wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], (uint32_t)16U);
    Lib_IntVector_Intrinsics_vec128 *wv_a2 = wv + c0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b2 = wv + d10 * (uint32_t)1U;
    wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a3 = wv + b0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b3 = wv + c0 * (uint32_t)1U;
    wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
    wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], (uint32_t)12U);
    Lib_IntVector_Intrinsics_vec128 *wv_a4 = wv + a * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b4 = wv + b0 * (uint32_t)1U;
    wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
    wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a5 = wv + d10 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b5 = wv + a * (uint32_t)1U;
    wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
    wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], (uint32_t)8U);
    Lib_IntVector_Intrinsics_vec128 *wv_a6 = wv + c0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b6 = wv + d10 * (uint32_t)1U;
    wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a7 = wv + b0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b7 = wv + c0 * (uint32_t)1U;
    wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
    wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], (uint32_t)7U);
    Lib_IntVector_Intrinsics_vec128 *r10 = wv + (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r21 = wv + (uint32_t)2U;
    Lib_IntVector_Intrinsics_vec128 *r31 = wv + (uint32_t)3U;
    Lib_IntVector_Intrinsics_vec128 v00 = r10[0U];
    Lib_IntVector_Intrinsics_vec128
    v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
    r10[0U] = v1;
    Lib_IntVector_Intrinsics_vec128 v01 = r21[0U];
    Lib_IntVector_Intrinsics_vec128
    v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
    r21[0U] = v10;
    Lib_IntVector_Intrinsics_vec128 v02 = r31[0U];
    Lib_IntVector_Intrinsics_vec128
    v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
    r31[0U] = v11;
    uint32_t a0 = (uint32_t)0U;
    uint32_t b = (uint32_t)1U;
    uint32_t c = (uint32_t)2U;
    uint32_t d1 = (uint32_t)3U;
    Lib_IntVector_Intrinsics_vec128 *wv_a = wv + a0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b8 = wv + b * (uint32_t)1U;
    wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
    wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a8 = wv + d1 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b9 = wv + a0 * (uint32_t)1U;
    wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
    wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], (uint32_t)16U);
    Lib_IntVector_Intrinsics_vec128 *wv_a9 = wv + c * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b10 = wv + d1 * (uint32_t)1U;
    wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a10 = wv + b * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b11 = wv + c * (uint32_t)1U;
    wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
    wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], (uint32_t)12U);
    Lib_IntVector_Intrinsics_vec128 *wv_a11 = wv + a0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b12 = wv + b * (uint32_t)1U;
    wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
    wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a12 = wv + d1 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b13 = wv + a0 * (uint32_t)1U;
    wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
    wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], (uint32_t)8U);
    Lib_IntVector_Intrinsics_vec128 *wv_a13 = wv + c * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b14 = wv + d1 * (uint32_t)1U;
    wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a14 = wv + b * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b = wv + c * (uint32_t)1U;
    wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
    wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], (uint32_t)7U);
    Lib_IntVector_Intrinsics_vec128 *r11 = wv + (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r2 = wv + (uint32_t)2U;
    Lib_IntVector_Intrinsics_vec128 *r3 = wv + (uint32_t)3U;
    Lib_IntVector_Intrinsics_vec128 v0 = r11[0U];
    Lib_IntVector_Intrinsics_vec128
    v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
    r11[0U] = v12;
    Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
    Lib_IntVector_Intrinsics_vec128
    v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
    r2[0U] = v13;
    Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
    Lib_IntVector_Intrinsics_vec128
    v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
    r3[0U] = v14;);
  Lib_IntVector_Intrinsics_vec128 *s0 = hash;
  Lib_IntVector_Intrinsics_vec128 *s1 = hash + (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r0 = wv;
  Lib_IntVector_Intrinsics_vec128 *r1 = wv + (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r2 = wv + (uint32_t)2U;
  Lib_IntVector_Intrinsics_vec128 *r3 = wv + (uint32_t)3U;
  s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
  s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
  s1[0U] = Lib_IntVector_Intrinsics_vec128_xor(s1[0U], r1[0U]);
  s1[0U] = Lib_IntVector_Intrinsics_vec128_xor(s1[0U], r3[0U]);
}

/* SNIPPET_END: update_block */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_init */

void
Hacl_Hash_Blake2s_Simd128_init(Lib_IntVector_Intrinsics_vec128 *hash, uint32_t kk, uint32_t nn)
{
  Lib_IntVector_Intrinsics_vec128 *r0 = hash;
  Lib_IntVector_Intrinsics_vec128 *r1 = hash + (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r2 = hash + (uint32_t)2U;
  Lib_IntVector_Intrinsics_vec128 *r3 = hash + (uint32_t)3U;
  uint32_t iv0 = Hacl_Hash_Blake2s_ivTable_S[0U];
  uint32_t iv1 = Hacl_Hash_Blake2s_ivTable_S[1U];
  uint32_t iv2 = Hacl_Hash_Blake2s_ivTable_S[2U];
  uint32_t iv3 = Hacl_Hash_Blake2s_ivTable_S[3U];
  uint32_t iv4 = Hacl_Hash_Blake2s_ivTable_S[4U];
  uint32_t iv5 = Hacl_Hash_Blake2s_ivTable_S[5U];
  uint32_t iv6 = Hacl_Hash_Blake2s_ivTable_S[6U];
  uint32_t iv7 = Hacl_Hash_Blake2s_ivTable_S[7U];
  r2[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv0, iv1, iv2, iv3);
  r3[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv4, iv5, iv6, iv7);
  uint32_t kk_shift_8 = kk << (uint32_t)8U;
  uint32_t iv0_ = iv0 ^ ((uint32_t)0x01010000U ^ (kk_shift_8 ^ nn));
  r0[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv0_, iv1, iv2, iv3);
  r1[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv4, iv5, iv6, iv7);
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_init */

/* SNIPPET_START: update_key */

static void
update_key(
  Lib_IntVector_Intrinsics_vec128 *wv,
  Lib_IntVector_Intrinsics_vec128 *hash,
  uint32_t kk,
  uint8_t *k,
  uint32_t ll
)
{
  uint64_t lb = (uint64_t)(uint32_t)64U;
  uint8_t b[64U] = { 0U };
  memcpy(b, k, kk * sizeof (uint8_t));
  if (ll == (uint32_t)0U)
  {
    update_block(wv, hash, true, lb, b);
  }
  else
  {
    update_block(wv, hash, false, lb, b);
  }
  Lib_Memzero0_memzero(b, (uint32_t)64U * sizeof (b[0U]));
}

/* SNIPPET_END: update_key */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_update_multi */

void
Hacl_Hash_Blake2s_Simd128_update_multi(
  uint32_t len,
  Lib_IntVector_Intrinsics_vec128 *wv,
  Lib_IntVector_Intrinsics_vec128 *hash,
  uint64_t prev,
  uint8_t *blocks,
  uint32_t nb
)
{
  for (uint32_t i = (uint32_t)0U; i < nb; i++)
  {
    uint64_t totlen = prev + (uint64_t)((i + (uint32_t)1U) * (uint32_t)64U);
    uint8_t *b = blocks + i * (uint32_t)64U;
    update_block(wv, hash, false, totlen, b);
  }
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_update_multi */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_update_last */

void
Hacl_Hash_Blake2s_Simd128_update_last(
  uint32_t len,
  Lib_IntVector_Intrinsics_vec128 *wv,
  Lib_IntVector_Intrinsics_vec128 *hash,
  uint64_t prev,
  uint32_t rem,
  uint8_t *d
)
{
  uint8_t b[64U] = { 0U };
  uint8_t *last = d + len - rem;
  memcpy(b, last, rem * sizeof (uint8_t));
  uint64_t totlen = prev + (uint64_t)len;
  update_block(wv, hash, true, totlen, b);
  Lib_Memzero0_memzero(b, (uint32_t)64U * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_update_last */

/* SNIPPET_START: update_blocks */

static inline void
update_blocks(
  uint32_t len,
  Lib_IntVector_Intrinsics_vec128 *wv,
  Lib_IntVector_Intrinsics_vec128 *hash,
  uint64_t prev,
  uint8_t *blocks
)
{
  uint32_t nb0 = len / (uint32_t)64U;
  uint32_t rem0 = len % (uint32_t)64U;
  uint32_t nb;
  if (rem0 == (uint32_t)0U && nb0 > (uint32_t)0U)
  {
    nb = nb0 - (uint32_t)1U;
  }
  else
  {
    nb = nb0;
  }
  uint32_t rem;
  if (rem0 == (uint32_t)0U && nb0 > (uint32_t)0U)
  {
    rem = (uint32_t)64U;
  }
  else
  {
    rem = rem0;
  }
  Hacl_Hash_Blake2s_Simd128_update_multi(len, wv, hash, prev, blocks, nb);
  Hacl_Hash_Blake2s_Simd128_update_last(len, wv, hash, prev, rem, blocks);
}

/* SNIPPET_END: update_blocks */

/* SNIPPET_START: update */

static inline void
update(
  Lib_IntVector_Intrinsics_vec128 *wv,
  Lib_IntVector_Intrinsics_vec128 *hash,
  uint32_t kk,
  uint8_t *k,
  uint32_t ll,
  uint8_t *d
)
{
  uint64_t lb = (uint64_t)(uint32_t)64U;
  if (kk > (uint32_t)0U)
  {
    update_key(wv, hash, kk, k, ll);
    if (!(ll == (uint32_t)0U))
    {
      update_blocks(ll, wv, hash, lb, d);
      return;
    }
    return;
  }
  update_blocks(ll, wv, hash, (uint64_t)(uint32_t)0U, d);
}

/* SNIPPET_END: update */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_finish */

void
Hacl_Hash_Blake2s_Simd128_finish(
  uint32_t nn,
  uint8_t *output,
  Lib_IntVector_Intrinsics_vec128 *hash
)
{
  uint32_t double_row = (uint32_t)32U;
  KRML_CHECK_SIZE(sizeof (uint8_t), double_row);
  uint8_t b[double_row];
  memset(b, 0U, double_row * sizeof (uint8_t));
  uint8_t *first = b;
  uint8_t *second = b + (uint32_t)16U;
  Lib_IntVector_Intrinsics_vec128 *row0 = hash;
  Lib_IntVector_Intrinsics_vec128 *row1 = hash + (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128_store32_le(first, row0[0U]);
  Lib_IntVector_Intrinsics_vec128_store32_le(second, row1[0U]);
  uint8_t *final = b;
  memcpy(output, final, nn * sizeof (uint8_t));
  Lib_Memzero0_memzero(b, double_row * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_finish */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_store_state128s_to_state32 */

void
Hacl_Hash_Blake2s_Simd128_store_state128s_to_state32(
  uint32_t *st32,
  Lib_IntVector_Intrinsics_vec128 *st
)
{
  Lib_IntVector_Intrinsics_vec128 *r0 = st;
  Lib_IntVector_Intrinsics_vec128 *r1 = st + (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r2 = st + (uint32_t)2U;
  Lib_IntVector_Intrinsics_vec128 *r3 = st + (uint32_t)3U;
  uint32_t *b0 = st32;
  uint32_t *b1 = st32 + (uint32_t)4U;
  uint32_t *b2 = st32 + (uint32_t)8U;
  uint32_t *b3 = st32 + (uint32_t)12U;
  uint8_t b8[16U] = { 0U };
  Lib_IntVector_Intrinsics_vec128_store32_le(b8, r0[0U]);
  KRML_MAYBE_FOR4(i,
    (uint32_t)0U,
    (uint32_t)4U,
    (uint32_t)1U,
    uint32_t *os = b0;
    uint8_t *bj = b8 + i * (uint32_t)4U;
    uint32_t u = load32_le(bj);
    uint32_t r = u;
    uint32_t x = r;
    os[i] = x;);
  uint8_t b80[16U] = { 0U };
  Lib_IntVector_Intrinsics_vec128_store32_le(b80, r1[0U]);
  KRML_MAYBE_FOR4(i,
    (uint32_t)0U,
    (uint32_t)4U,
    (uint32_t)1U,
    uint32_t *os = b1;
    uint8_t *bj = b80 + i * (uint32_t)4U;
    uint32_t u = load32_le(bj);
    uint32_t r = u;
    uint32_t x = r;
    os[i] = x;);
  uint8_t b81[16U] = { 0U };
  Lib_IntVector_Intrinsics_vec128_store32_le(b81, r2[0U]);
  KRML_MAYBE_FOR4(i,
    (uint32_t)0U,
    (uint32_t)4U,
    (uint32_t)1U,
    uint32_t *os = b2;
    uint8_t *bj = b81 + i * (uint32_t)4U;
    uint32_t u = load32_le(bj);
    uint32_t r = u;
    uint32_t x = r;
    os[i] = x;);
  uint8_t b82[16U] = { 0U };
  Lib_IntVector_Intrinsics_vec128_store32_le(b82, r3[0U]);
  KRML_MAYBE_FOR4(i,
    (uint32_t)0U,
    (uint32_t)4U,
    (uint32_t)1U,
    uint32_t *os = b3;
    uint8_t *bj = b82 + i * (uint32_t)4U;
    uint32_t u = load32_le(bj);
    uint32_t r = u;
    uint32_t x = r;
    os[i] = x;);
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_store_state128s_to_state32 */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_load_state128s_from_state32 */

void
Hacl_Hash_Blake2s_Simd128_load_state128s_from_state32(
  Lib_IntVector_Intrinsics_vec128 *st,
  uint32_t *st32
)
{
  Lib_IntVector_Intrinsics_vec128 *r0 = st;
  Lib_IntVector_Intrinsics_vec128 *r1 = st + (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r2 = st + (uint32_t)2U;
  Lib_IntVector_Intrinsics_vec128 *r3 = st + (uint32_t)3U;
  uint32_t *b0 = st32;
  uint32_t *b1 = st32 + (uint32_t)4U;
  uint32_t *b2 = st32 + (uint32_t)8U;
  uint32_t *b3 = st32 + (uint32_t)12U;
  r0[0U] = Lib_IntVector_Intrinsics_vec128_load32s(b0[0U], b0[1U], b0[2U], b0[3U]);
  r1[0U] = Lib_IntVector_Intrinsics_vec128_load32s(b1[0U], b1[1U], b1[2U], b1[3U]);
  r2[0U] = Lib_IntVector_Intrinsics_vec128_load32s(b2[0U], b2[1U], b2[2U], b2[3U]);
  r3[0U] = Lib_IntVector_Intrinsics_vec128_load32s(b3[0U], b3[1U], b3[2U], b3[3U]);
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_load_state128s_from_state32 */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_malloc_with_key */

Lib_IntVector_Intrinsics_vec128 *Hacl_Hash_Blake2s_Simd128_malloc_with_key(void)
{
  Lib_IntVector_Intrinsics_vec128
  *buf =
    (Lib_IntVector_Intrinsics_vec128 *)KRML_ALIGNED_MALLOC(16,
      sizeof (Lib_IntVector_Intrinsics_vec128) * (uint32_t)4U);
  memset(buf, 0U, (uint32_t)4U * sizeof (Lib_IntVector_Intrinsics_vec128));
  return buf;
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_malloc_with_key */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_malloc */

/**
  State allocation function when there is no key
*/
Hacl_Hash_Blake2s_Simd128_state_t *Hacl_Hash_Blake2s_Simd128_malloc(void)
{
  uint8_t *buf = (uint8_t *)KRML_HOST_CALLOC((uint32_t)64U, sizeof (uint8_t));
  Lib_IntVector_Intrinsics_vec128
  *wv =
    (Lib_IntVector_Intrinsics_vec128 *)KRML_ALIGNED_MALLOC(16,
      sizeof (Lib_IntVector_Intrinsics_vec128) * (uint32_t)4U);
  memset(wv, 0U, (uint32_t)4U * sizeof (Lib_IntVector_Intrinsics_vec128));
  Lib_IntVector_Intrinsics_vec128
  *b =
    (Lib_IntVector_Intrinsics_vec128 *)KRML_ALIGNED_MALLOC(16,
      sizeof (Lib_IntVector_Intrinsics_vec128) * (uint32_t)4U);
  memset(b, 0U, (uint32_t)4U * sizeof (Lib_IntVector_Intrinsics_vec128));
  Hacl_Hash_Blake2s_Simd128_block_state_t block_state = { .fst = wv, .snd = b };
  Hacl_Hash_Blake2s_Simd128_state_t
  s = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)(uint32_t)0U };
  Hacl_Hash_Blake2s_Simd128_state_t
  *p =
    (Hacl_Hash_Blake2s_Simd128_state_t *)KRML_HOST_MALLOC(sizeof (
        Hacl_Hash_Blake2s_Simd128_state_t
      ));
  p[0U] = s;
  Hacl_Hash_Blake2s_Simd128_init(block_state.snd, (uint32_t)0U, (uint32_t)32U);
  return p;
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_malloc */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_reset */

/**
  Re-initialization function when there is no key
*/
void Hacl_Hash_Blake2s_Simd128_reset(Hacl_Hash_Blake2s_Simd128_state_t *state)
{
  Hacl_Hash_Blake2s_Simd128_state_t scrut = *state;
  uint8_t *buf = scrut.buf;
  Hacl_Hash_Blake2s_Simd128_block_state_t block_state = scrut.block_state;
  Hacl_Hash_Blake2s_Simd128_init(block_state.snd, (uint32_t)0U, (uint32_t)32U);
  Hacl_Hash_Blake2s_Simd128_state_t
  tmp = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)(uint32_t)0U };
  state[0U] = tmp;
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_reset */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_update */

/**
  Update function when there is no key; 0 = success, 1 = max length exceeded
*/
uint32_t
Hacl_Hash_Blake2s_Simd128_update(
  Hacl_Hash_Blake2s_Simd128_state_t *state,
  uint8_t *chunk,
  uint32_t chunk_len
)
{
  Hacl_Hash_Blake2s_Simd128_state_t s = *state;
  uint64_t total_len = s.total_len;
  if ((uint64_t)chunk_len > (uint64_t)0xffffffffffffffffU - total_len)
  {
    return (uint32_t)1U;
  }
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)64U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  if (chunk_len <= (uint32_t)64U - sz)
  {
    Hacl_Hash_Blake2s_Simd128_state_t s1 = *state;
    Hacl_Hash_Blake2s_Simd128_block_state_t block_state1 = s1.block_state;
    uint8_t *buf = s1.buf;
    uint64_t total_len1 = s1.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, chunk, chunk_len * sizeof (uint8_t));
    uint64_t total_len2 = total_len1 + (uint64_t)chunk_len;
    *state
    =
      (
        (Hacl_Hash_Blake2s_Simd128_state_t){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
  }
  else if (sz == (uint32_t)0U)
  {
    Hacl_Hash_Blake2s_Simd128_state_t s1 = *state;
    Hacl_Hash_Blake2s_Simd128_block_state_t block_state1 = s1.block_state;
    uint8_t *buf = s1.buf;
    uint64_t total_len1 = s1.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      Lib_IntVector_Intrinsics_vec128 *wv = block_state1.fst;
      Lib_IntVector_Intrinsics_vec128 *hash = block_state1.snd;
      uint32_t nb = (uint32_t)1U;
      Hacl_Hash_Blake2s_Simd128_update_multi((uint32_t)64U, wv, hash, prevlen, buf, nb);
    }
    uint32_t ite;
    if
    (
      (uint64_t)chunk_len
      % (uint64_t)(uint32_t)64U
      == (uint64_t)0U
      && (uint64_t)chunk_len > (uint64_t)0U
    )
    {
      ite = (uint32_t)64U;
    }
    else
    {
      ite = (uint32_t)((uint64_t)chunk_len % (uint64_t)(uint32_t)64U);
    }
    uint32_t n_blocks = (chunk_len - ite) / (uint32_t)64U;
    uint32_t data1_len = n_blocks * (uint32_t)64U;
    uint32_t data2_len = chunk_len - data1_len;
    uint8_t *data1 = chunk;
    uint8_t *data2 = chunk + data1_len;
    Lib_IntVector_Intrinsics_vec128 *wv = block_state1.fst;
    Lib_IntVector_Intrinsics_vec128 *hash = block_state1.snd;
    uint32_t nb = data1_len / (uint32_t)64U;
    Hacl_Hash_Blake2s_Simd128_update_multi(data1_len, wv, hash, total_len1, data1, nb);
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (uint8_t));
    *state
    =
      (
        (Hacl_Hash_Blake2s_Simd128_state_t){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)chunk_len
        }
      );
  }
  else
  {
    uint32_t diff = (uint32_t)64U - sz;
    uint8_t *chunk1 = chunk;
    uint8_t *chunk2 = chunk + diff;
    Hacl_Hash_Blake2s_Simd128_state_t s1 = *state;
    Hacl_Hash_Blake2s_Simd128_block_state_t block_state10 = s1.block_state;
    uint8_t *buf0 = s1.buf;
    uint64_t total_len10 = s1.total_len;
    uint32_t sz10;
    if (total_len10 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len10 > (uint64_t)0U)
    {
      sz10 = (uint32_t)64U;
    }
    else
    {
      sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)64U);
    }
    uint8_t *buf2 = buf0 + sz10;
    memcpy(buf2, chunk1, diff * sizeof (uint8_t));
    uint64_t total_len2 = total_len10 + (uint64_t)diff;
    *state
    =
      (
        (Hacl_Hash_Blake2s_Simd128_state_t){
          .block_state = block_state10,
          .buf = buf0,
          .total_len = total_len2
        }
      );
    Hacl_Hash_Blake2s_Simd128_state_t s10 = *state;
    Hacl_Hash_Blake2s_Simd128_block_state_t block_state1 = s10.block_state;
    uint8_t *buf = s10.buf;
    uint64_t total_len1 = s10.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      Lib_IntVector_Intrinsics_vec128 *wv = block_state1.fst;
      Lib_IntVector_Intrinsics_vec128 *hash = block_state1.snd;
      uint32_t nb = (uint32_t)1U;
      Hacl_Hash_Blake2s_Simd128_update_multi((uint32_t)64U, wv, hash, prevlen, buf, nb);
    }
    uint32_t ite;
    if
    (
      (uint64_t)(chunk_len - diff)
      % (uint64_t)(uint32_t)64U
      == (uint64_t)0U
      && (uint64_t)(chunk_len - diff) > (uint64_t)0U
    )
    {
      ite = (uint32_t)64U;
    }
    else
    {
      ite = (uint32_t)((uint64_t)(chunk_len - diff) % (uint64_t)(uint32_t)64U);
    }
    uint32_t n_blocks = (chunk_len - diff - ite) / (uint32_t)64U;
    uint32_t data1_len = n_blocks * (uint32_t)64U;
    uint32_t data2_len = chunk_len - diff - data1_len;
    uint8_t *data1 = chunk2;
    uint8_t *data2 = chunk2 + data1_len;
    Lib_IntVector_Intrinsics_vec128 *wv = block_state1.fst;
    Lib_IntVector_Intrinsics_vec128 *hash = block_state1.snd;
    uint32_t nb = data1_len / (uint32_t)64U;
    Hacl_Hash_Blake2s_Simd128_update_multi(data1_len, wv, hash, total_len1, data1, nb);
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (uint8_t));
    *state
    =
      (
        (Hacl_Hash_Blake2s_Simd128_state_t){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)(chunk_len - diff)
        }
      );
  }
  return (uint32_t)0U;
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_update */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_digest */

/**
  Finish function when there is no key
*/
void
Hacl_Hash_Blake2s_Simd128_digest(Hacl_Hash_Blake2s_Simd128_state_t *state, uint8_t *output)
{
  Hacl_Hash_Blake2s_Simd128_state_t scrut = *state;
  Hacl_Hash_Blake2s_Simd128_block_state_t block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)64U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf_1 = buf_;
  KRML_PRE_ALIGN(16) Lib_IntVector_Intrinsics_vec128 wv0[4U] KRML_POST_ALIGN(16) = { 0U };
  KRML_PRE_ALIGN(16) Lib_IntVector_Intrinsics_vec128 b[4U] KRML_POST_ALIGN(16) = { 0U };
  Hacl_Hash_Blake2s_Simd128_block_state_t tmp_block_state = { .fst = wv0, .snd = b };
  Lib_IntVector_Intrinsics_vec128 *src_b = block_state.snd;
  Lib_IntVector_Intrinsics_vec128 *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)4U * sizeof (Lib_IntVector_Intrinsics_vec128));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint32_t ite;
  if (r % (uint32_t)64U == (uint32_t)0U && r > (uint32_t)0U)
  {
    ite = (uint32_t)64U;
  }
  else
  {
    ite = r % (uint32_t)64U;
  }
  uint8_t *buf_last = buf_1 + r - ite;
  uint8_t *buf_multi = buf_1;
  Lib_IntVector_Intrinsics_vec128 *wv1 = tmp_block_state.fst;
  Lib_IntVector_Intrinsics_vec128 *hash0 = tmp_block_state.snd;
  uint32_t nb = (uint32_t)0U;
  Hacl_Hash_Blake2s_Simd128_update_multi((uint32_t)0U, wv1, hash0, prev_len, buf_multi, nb);
  uint64_t prev_len_last = total_len - (uint64_t)r;
  Lib_IntVector_Intrinsics_vec128 *wv = tmp_block_state.fst;
  Lib_IntVector_Intrinsics_vec128 *hash = tmp_block_state.snd;
  Hacl_Hash_Blake2s_Simd128_update_last(r, wv, hash, prev_len_last, r, buf_last);
  Hacl_Hash_Blake2s_Simd128_finish((uint32_t)32U, output, tmp_block_state.snd);
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_digest */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_free */

/**
  Free state function when there is no key
*/
void Hacl_Hash_Blake2s_Simd128_free(Hacl_Hash_Blake2s_Simd128_state_t *state)
{
  Hacl_Hash_Blake2s_Simd128_state_t scrut = *state;
  uint8_t *buf = scrut.buf;
  Hacl_Hash_Blake2s_Simd128_block_state_t block_state = scrut.block_state;
  Lib_IntVector_Intrinsics_vec128 *wv = block_state.fst;
  Lib_IntVector_Intrinsics_vec128 *b = block_state.snd;
  KRML_ALIGNED_FREE(wv);
  KRML_ALIGNED_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(state);
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_free */

/* SNIPPET_START: Hacl_Hash_Blake2s_Simd128_hash_with_key */

/**
Write the BLAKE2s digest of message `input` using key `key` into `output`.

@param output Pointer to `output_len` bytes of memory where the digest is written to.
@param output_len Length of the to-be-generated digest with 1 <= `output_len` <= 32.
@param input Pointer to `input_len` bytes of memory where the input message is read from.
@param input_len Length of the input message.
@param key Pointer to `key_len` bytes of memory where the key is read from.
@param key_len Length of the key. Can be 0.
*/
void
Hacl_Hash_Blake2s_Simd128_hash_with_key(
  uint8_t *output,
  uint32_t output_len,
  uint8_t *input,
  uint32_t input_len,
  uint8_t *key,
  uint32_t key_len
)
{
  KRML_PRE_ALIGN(16) Lib_IntVector_Intrinsics_vec128 b[4U] KRML_POST_ALIGN(16) = { 0U };
  KRML_PRE_ALIGN(16) Lib_IntVector_Intrinsics_vec128 b1[4U] KRML_POST_ALIGN(16) = { 0U };
  Hacl_Hash_Blake2s_Simd128_init(b, key_len, output_len);
  update(b1, b, key_len, key, input_len, input);
  Hacl_Hash_Blake2s_Simd128_finish(output_len, output, b);
  Lib_Memzero0_memzero(b1, (uint32_t)4U * sizeof (b1[0U]));
  Lib_Memzero0_memzero(b, (uint32_t)4U * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Hash_Blake2s_Simd128_hash_with_key */

