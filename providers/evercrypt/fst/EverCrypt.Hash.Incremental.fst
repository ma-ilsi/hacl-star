module EverCrypt.Hash.Incremental

open FStar.Mul

// Watch out: keep the module declarations in sync between fsti and fst
// (otherwise interleaving issues may bite).
module B = LowStar.Buffer
module S = FStar.Seq
module ST = FStar.HyperStack.ST
module HS = FStar.HyperStack
module G = FStar.Ghost
module U32 = FStar.UInt32
module U64 = FStar.UInt64
module F = Hacl.Streaming.Functor

module Hash = EverCrypt.Hash

open FStar.HyperStack.ST
open Spec.Hash.Definitions
open Hacl.Streaming.Interface

include Spec.Hash.Definitions
include Hacl.Hash.Definitions

#set-options "--z3rlimit 200 --max_fuel 0 --max_ifuel 0"

inline_for_extraction noextract
let agile_state: stateful hash_alg =
  Stateful
    EverCrypt.Hash.state

    (fun #i h s -> EverCrypt.Hash.footprint s h)
    EverCrypt.Hash.freeable
    (fun #i h s -> EverCrypt.Hash.invariant s h)

    Spec.Hash.Definitions.words_state'
    (fun i h s -> EverCrypt.Hash.repr s h)

    (fun #i h s -> EverCrypt.Hash.invariant_loc_in_footprint s h)
    (fun #i l s h0 h1 ->
      EverCrypt.Hash.frame_invariant l s h0 h1;
      EverCrypt.Hash.frame_invariant_implies_footprint_preservation l s h0 h1)
    (fun #i l s h0 h1 -> ())
    EverCrypt.Hash.alloca
    EverCrypt.Hash.create_in
    (fun i -> EverCrypt.Hash.free #i)
    (fun i -> EverCrypt.Hash.copy #i)

#push-options "--ifuel 1"
let mk_words_state (#a : hash_alg) (s : words_state' a)
                   (counter : nat{is_blake a ==> counter <= max_extra_state a}) :
 Tot (words_state a) =
 if is_blake a then
   (s, nat_to_extra_state a counter)
 else (s, ())
#pop-options    

inline_for_extraction noextract
let evercrypt_hash //: block hash_alg =
  =
  Block
    Erased
    agile_state
    (stateful_unused hash_alg)

    Hacl.Streaming.SHA2_256.max_input_length64
    Hacl.Hash.Definitions.hash_len
    Hacl.Hash.Definitions.block_len

    (fun a _ -> fst (Spec.Agile.Hash.init a))
    (fun a s prevlen input -> fst (Spec.Agile.Hash.update_multi a (mk_words_state s prevlen) input))
    (fun a s prevlen input -> fst (Spec.Hash.Incremental.update_last a (mk_words_state s prevlen) prevlen input))
    (fun a _ s -> Spec.Hash.PadFinish.finish a (mk_words_state s 0))

    (fun a _ -> Spec.Agile.Hash.hash a)

    (fun a s prevlen -> Spec.Hash.Lemmas.update_multi_zero a (mk_words_state s prevlen))
    (fun a s prevlen1 prevlen2 input1 input2 -> admit()) // relying on the pattern in Hacl.Streaming.SHA256 here
    (fun a _ input -> admit())// Spec.Hash.Incremental.hash_is_hash_incremental a input)

    EverCrypt.Hash.alg_of_state
    (fun i _ -> EverCrypt.Hash.init #i)
    (fun i s prevlen blocks len -> EverCrypt.Hash.update_multi #i s prevlen blocks len)
    (fun i s prevlen last last_len -> admit())// EverCrypt.Hash.update_last #i s prevlen last last_len) (**)
    (fun i _ -> EverCrypt.Hash.finish #i)


let create_in a = F.create_in evercrypt_hash a (EverCrypt.Hash.state a) (G.erased unit) ()

let init (a: G.erased hash_alg) = F.init evercrypt_hash a (EverCrypt.Hash.state a) (G.erased unit) ()

let update (i: G.erased hash_alg) =
  let _ = allow_inversion Spec.Agile.Hash.hash_alg in
  assert_norm (pow2 61 - 1 < pow2 64);
  assert_norm (pow2 64 < pow2 125 - 1);
  F.update evercrypt_hash i (EverCrypt.Hash.state i) (G.erased unit)

inline_for_extraction noextract
let finish_st a = F.finish_st evercrypt_hash a (EverCrypt.Hash.state a) (G.erased unit)

/// The wrapper pattern, to ensure that the stack-allocated state is properly
/// monomorphized.
let finish_md5: finish_st MD5 = F.mk_finish evercrypt_hash MD5 (EverCrypt.Hash.state MD5) (G.erased unit)
let finish_sha1: finish_st SHA1 = F.mk_finish evercrypt_hash SHA1 (EverCrypt.Hash.state SHA1) (G.erased unit)
let finish_sha224: finish_st SHA2_224 = F.mk_finish evercrypt_hash SHA2_224 (EverCrypt.Hash.state SHA2_224) (G.erased unit)
let finish_sha256: finish_st SHA2_256 = F.mk_finish evercrypt_hash SHA2_256 (EverCrypt.Hash.state SHA2_256) (G.erased unit)
let finish_sha384: finish_st SHA2_384 = F.mk_finish evercrypt_hash SHA2_384 (EverCrypt.Hash.state SHA2_384) (G.erased unit)
let finish_sha512: finish_st SHA2_512 = F.mk_finish evercrypt_hash SHA2_512 (EverCrypt.Hash.state SHA2_512) (G.erased unit)
let finish_blake2s: finish_st Blake2S = F.mk_finish evercrypt_hash Blake2S (EverCrypt.Hash.state Blake2S) (G.erased unit)
let finish_blake2b: finish_st Blake2B = F.mk_finish evercrypt_hash Blake2B (EverCrypt.Hash.state Blake2B) (G.erased unit)

let alg_of_state (a: G.erased hash_alg) = F.index_of_state evercrypt_hash a (EverCrypt.Hash.state a) (G.erased unit)

val finish: a:G.erased hash_alg -> finish_st a
let finish a s dst =
  let a = alg_of_state a s in
  match a with
  | MD5 -> finish_md5 s dst
  | SHA1 -> finish_sha1 s dst
  | SHA2_224 -> finish_sha224 s dst
  | SHA2_256 -> finish_sha256 s dst
  | SHA2_384 -> finish_sha384 s dst
  | SHA2_512 -> finish_sha512 s dst
  | Blake2S -> finish_blake2s s dst
  | Blake2B -> finish_blake2b s dst

let free (i: G.erased hash_alg) = F.free evercrypt_hash i (EverCrypt.Hash.state i) (G.erased unit)

/// Finally, a few helpers predicates to make things easier for clients...

let state (a: hash_alg) = F.state evercrypt_hash a (EverCrypt.Hash.state a) (G.erased unit)

let hashed #a (h: HS.mem) (s: state a) =
  F.seen evercrypt_hash a h s
