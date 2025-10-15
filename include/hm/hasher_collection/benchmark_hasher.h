#pragma once

#include "../basic_hasher.h"
#include "../types.h"

#include <cstring>

#include <span>
#include <vector>

namespace hm
{
class benchmark_hasher : public basic_hasher
{
  std::vector<hm::byte> ctx;
  std::uint64_t         acc = 0;

public:
  void
  init ()
  {
    acc = 0;
    ctx.clear ();
  }

  void
  update (std::span<hm::byte> data)
  {
    for (auto b : data)
    {
      acc ^= (static_cast<std::uint64_t> (b) + 0x9E3779B97F4A7C15ull);
      acc  = (acc << 7) | (acc >> (64 - 7));
    }

    ctx.insert (ctx.end (), data.begin (), data.end ());
  }

  void
  final (std::vector<hm::byte> &out)
  {
    out.clear ();
    out.resize (8);
    std::uint64_t tmp = acc ^ (acc >> 33) ^ 0xA5A5A5A5A5A5A5A5ull;
    std::memcpy (out.data (), &tmp, 8);
  }

  std::vector<hm::byte>
  final ()
  {
    std::vector<hm::byte> out;
    final (out);
    return out;
  }
};
}