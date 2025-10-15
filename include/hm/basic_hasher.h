#pragma once

#include "types.h"

#include <span>
#include <vector>

namespace hm
{

class basic_hasher
{
public:
  virtual ~basic_hasher ()              = default;

  virtual void                  init () = 0;
  virtual void                  update (std::span<hm::byte> data)  = 0;
  virtual void                  final (std::vector<hm::byte> &out) = 0;
  virtual std::vector<hm::byte> final ()                           = 0;
};

inline void
hasher_init (basic_hasher *h)
{
  h->init ();
}

inline void
hasher_update (basic_hasher *h, std::span<hm::byte> data)
{
  h->update (data);
}

inline void
hasher_final (basic_hasher *h, std::vector<hm::byte> &out)
{
  h->final (out);
}

inline std::vector<hm::byte>
hasher_final (basic_hasher *h)
{
  return h->final ();
}

}