/**
 * @file custom_hash.cpp
 * @author Kiwon Song (songkwwwwwww@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>

namespace std {
template <> struct hash<pair<std::string, int>> {
  auto operator()(const pair<std::string, int> &p) const -> size_t {
    return hash<std::string>{}(p.first) ^ hash<int>{}(p.second);
  }
};
} // namespace std

int main() {
  std::unordered_set<std::pair<std::string, int>> names{
      {"Ian", 5}, {"Y.E.", 4}, {"Pan", 3}}; // good
  for (const auto &[key, value] : names) {
    std::cout << key << ", " << value << std::endl;
  }
}