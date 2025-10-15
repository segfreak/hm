#include "hm/types.h"
#include <gtest/gtest.h>

#include <hm/basic_hasher.h>
#include <hm/concept_hasher.h>

#include <hm/benchmark.h>
#include <hm/hash.h>

#include <hm/hasher_collection/trace_hasher.h>
#include <span>

TEST (ConceptTest, Test)
{
  hm::trace_hasher      hasher;

  std::vector<hm::byte> data;
  data.push_back (0x00);
  data.push_back (0x01);

  hm::hasher_init (hasher);
  hm::hasher_update (hasher, data);
  hm::hasher_final (hasher);
}

TEST (AbstractTest, Test)
{
  hm::trace_hasher      hasher;

  std::vector<hm::byte> data;
  data.push_back (0x00);
  data.push_back (0x01);

  hm::hasher_init (&hasher);
  hm::hasher_update (&hasher, data);
  hm::hasher_final (&hasher);
}

TEST (Benchmark, Test)
{
  std::cout << "Benchmarking concept vs abstract...\n\n";

  hm::benchmark ("concept", hm::benchmark_hasher_1cycle_concept);
  hm::benchmark ("abstract", hm::benchmark_hasher_1cycle_abstract);
}

//
// Suit main
//
int
main (int argc, char **argv)
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}