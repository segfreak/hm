#pragma once

#include <chrono>
#include <functional>
#include <iostream>

namespace hm
{

template <std::size_t iterations = 1'000'000, typename Fn,
          typename... Args>
void
benchmark (const char *name, Fn &&fn, Args &&...args)
{
  using namespace std::chrono;
  auto start = high_resolution_clock::now ();

  for (std::size_t i = 0; i < iterations; ++i)
    std::invoke (std::forward<Fn> (fn), std::forward<Args> (args)...);

  auto end = high_resolution_clock::now ();
  auto dur = duration_cast<duration<double, std::micro>> (end - start);
  std::cout << name << ": " << dur.count () / iterations
            << " us per call\n";
}

extern "C" void benchmark_hasher_1cycle_concept ();

extern "C" void benchmark_hasher_1cycle_abstract ();

}
