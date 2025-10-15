#pragma once

#include "../basic_hasher.h"
#include "../types.h"

#include <iostream>

#include <span>
#include <vector>

namespace hm
{
class trace_hasher : public basic_hasher
{
  std::vector<hm::byte> ctx;

public:
  void
  init ()
  {
    std::cout << "trace : void                      "
                 "myhasher->init(void)\n";
  }

  void
  update (std::span<hm::byte> data)
  {
    std::cout << "trace : void                      "
                 "myhasher->update(std::span<hm::byte>)\n";
  }

  void
  final (std::vector<hm::byte> &out)
  {
    std::cout << "trace : void                      "
                 "myhasher->final(std::vector<hm::byte> &)\n";
  }

  std::vector<hm::byte>
  final ()
  {
    std::cout << "trace : std::vector<hm::byte> myhasher->final()\n";
    return {};
  }
};
}