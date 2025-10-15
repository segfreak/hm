#pragma once

#include "types.h"

#include <span>
#include <vector>

namespace hm
{
template <typename T>
concept hasher = requires (T t, std::span<hm::byte> data,
                           std::vector<hm::byte> &out) {
  { t.init () } -> std::same_as<void>;
  { t.update (data) } -> std::same_as<void>;
  { t.final (out) } -> std::same_as<void>;
  { t.final () } -> std::same_as<std::vector<hm::byte>>;
};

template <hasher H>
void
hasher_init (H &h)
{
  h.init ();
}

template <hasher H>
void
hasher_update (H &h, std::span<hm::byte> data)
{
  h.update (data);
}

template <hasher H>
void
hasher_final (H &h, std::vector<hm::byte> &out)
{
  h.final (out);
}

template <hasher H>
std::vector<hm::byte>
hasher_final (H &h)
{
  return h.final ();
}

}