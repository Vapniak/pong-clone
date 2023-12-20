#pragma once

#include <iostream>

namespace debug {

template <typename... T>
inline void log(T... args) {
  std::cout << "[LOG] ";

  auto _ = {(std::cout << args, 0)...};

  std::cout << std::endl;
}

template <typename... T>
inline void warning(T... args) {
  std::cerr << "[WARNING] ";

  auto _ = {(std::cerr << args, 0)...};

  std::cerr << std::endl;
}

template <typename... T>
inline void error(T... args) {
  std::cerr << "[ERROR] ";

  auto _ = {(std::cerr << args, 0)...};

  std::cerr << std::endl;
}

}  // namespace debug