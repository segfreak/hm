#pragma once

#include "basic_hasher.h"
#include "concept_hasher.h"

#include "types.h"

#include <span>
#include <vector>

namespace hm
{

template <typename Hasher>
std::vector<hm::byte>
hash (Hasher &hasher, std::span<byte> data)
{
  hasher_init (hasher);
  hasher_update (hasher, data);
  return hasher_final (hasher);
}

inline std::vector<hm::byte>
dyn_hash (basic_hasher *hasher, std::span<byte> data)
{
  hasher_init (hasher);
  hasher_update (hasher, data);
  return hasher_final (hasher);
}

}