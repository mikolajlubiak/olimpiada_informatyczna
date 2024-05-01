#include <cstdint>
#include <cstring>
#include <iostream>
#include <stdio.h>

uint8_t m;
uint16_t n;
uint16_t l;

bool check_l(uint16_t k[], uint16_t k_copy[]);

int main() {
  scanf("%hu %hhu", &n, &m);

  char opis[n * n];

  for (uint16_t i = 0; i < n; i++) {
    for (uint16_t j = 0; j < n; j++) {
      std::cin >> opis[i * n + j];
    }
  }

  uint16_t k[m];
  uint16_t k_copy[m - 1];
  std::memset(k, 0, m * sizeof(uint16_t));

  for (uint16_t i = 0; i < n; i++) {
    for (uint16_t j = 0; j < n; j++) {
      l = 0;
      while (opis[i * n + j + l++] == '.' && l <= n)
        ;
      l--;
      if (check_l(k, k_copy)) {
        for (uint16_t jj = j; jj < j + l; jj++) {
          opis[i * n + jj] = 'X';
        }
      }

      l = 0;
      while (opis[(j + l++) * n + i] == '.' && l <= n)
        ;
      l--;
      if (check_l(k, k_copy)) {
        for (uint16_t jj = j; jj < j + l; jj++) {
          opis[jj * n + i] = 'X';
        }
      }
    }
  }

  if (k[0] / m > k[m - 1]) {
    std::cout << k[0] / m;
  } else {
    std::cout << k[m - 1];
  }
}

bool check_l(uint16_t k[], uint16_t k_copy[]) {
  for (int8_t o = 0; o < m; o++) {
    if (l > k[o]) {
      std::memcpy(k_copy, k, (m - o) * sizeof(uint16_t));

      for (int8_t u = o; u < m; u++) {
        k[u] = k_copy[u - 1];
      }

      k[o] = l;

      return true;
    }
  }
  return false;
}
