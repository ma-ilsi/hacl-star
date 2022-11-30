module Hacl.Hash.Blake2

// This module contains low-level implementations that implement the
// "update_multi" API, found in Spec.Agile.Hash.
//
// This is just a lightweight wrapper around the actual implementation in
// code/blake2; by re-exporting the correct type signatures, this makes
// instantiating the HMAC implementation trivial (which is defined in terms of
// update_multi).
//
// Final remark: this module is completely noextract, so it generates no code at run-time.

open Spec.Hash.Definitions
open Hacl.Hash.Definitions
open Hacl.Impl.Blake2.Core

// Blake2B_32

inline_for_extraction noextract
val init_256: init_st (|Blake2B, M32|)

inline_for_extraction noextract
val update_multi_256: update_multi_st (|Blake2B, M32|)

inline_for_extraction noextract
val update_last_256: update_last_st (|Blake2B, M32|)

inline_for_extraction noextract
val finish_256: finish_st (|Blake2B, M32|)

// Blake2S_32 (TODO)

// As mentioned above, this module generates no code at run-time, so we can
// safely put vectorized versions in a file that does not contain a _128 or _256
// suffix: these combinators will be inlined in their respective files, e.g.
// Hacl_HMAC_Blake2s_128.c

// Blake2S_128 (TODO)
// Blake2B_256 (TODO)
