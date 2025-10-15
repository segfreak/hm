
#include "hm/hasher_collection/benchmark_hasher.h"
#include <hm/concept_hasher.h>
#include <memory>

namespace hm
{

extern "C" void
benchmark_hasher_1cycle_concept ()
{
  hm::benchmark_hasher  hasher;

  std::vector<hm::byte> data{ 0x00, 0x01 };

  hm::hasher_init (hasher);
  hm::hasher_update (hasher, data);
  hm::hasher_final (hasher);
}

extern "C" void
benchmark_hasher_1cycle_abstract ()
{
  std::unique_ptr<hm::basic_hasher> hasher
      = std::make_unique<hm::benchmark_hasher> ();

  std::vector<hm::byte> data{ 0x00, 0x01 };

  hm::hasher_init (hasher.get ());
  hm::hasher_update (hasher.get (), data);
  hm::hasher_final (hasher.get ());
}

}
