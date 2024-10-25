#include <cstdint>
#include <iostream>

constexpr inline std::uint64_t usu(std::uint64_t a, std::uint64_t b) {
  return (((b - a + 2) / 4) * 2) + (((b - a + 1) / 4) * 2);
}

int main() {
  std::uint64_t a, b;
  std::cin >> a >> b;
  std::cout << usu(a, b);
  return 0;
}
