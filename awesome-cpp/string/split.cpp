#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string s, std::string delimiter) {
  size_t pos_start = 0;
  size_t pos_end = 0;
  size_t delim_len = delimiter.length();
  std::string token;
  std::vector<std::string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

int main() {
  std::string s = "Hello, World, C++";
  auto strs = split(s, ",");
  for (const auto str : strs) {
    std::cout << str << std::endl;
  }
}