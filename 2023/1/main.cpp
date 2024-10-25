#include <cstdint>
#include <cstring>
#include <iostream>
#include <stdio.h>

bool check_l(uint16_t k[], uint16_t k_copy[], uint16_t l, uint8_t m);

int main() {
  uint8_t m;
  uint16_t n;

  scanf("%hu %hhu", &n, &m);

  char opis[n][n];

  for (uint16_t i = 0; i < n; i++) {
    for (uint16_t j = 0; j < n; j++) {
      std::cin >> opis[i][j];
    }
  }

  uint16_t k[m];
  uint16_t k_copy[m - 1];
  std::memset(k, 0, m * sizeof(uint16_t));

  uint16_t l;

  for (uint16_t i = 0; i < n; i++) {
    for (uint16_t j = 0; j < n; j++) {
      l = 0;
      // idz po wierszu
      while (opis[i][j + l++] == '.' && l <= n)
        ;
      l--;
      if (check_l(k, k_copy, l, m)) {
        for (uint16_t jj = j; jj < j + l; jj++) {
          opis[i][jj] = 'X';
        }
      }

      l = 0;
      // idz po kolumnie
      while (opis[j + l++][i] == '.' && l <= n)
        ;
      l--;
      if (check_l(k, k_copy, l, m)) {
        for (uint16_t jj = j; jj < j + l; jj++) {
          if (opis[jj][i] == 'X') {
            std::cout << "AAA\n";
          }

          opis[jj][i] = 'X';
          std::cout << "KOLUMNA: " << jj << ", " << i << std::endl;
        }
      }
    }
  }

  std::cout << std::endl;

  std::cout << "Grid:\n";
  for (uint16_t i = 0; i < n; i++) {
    for (uint16_t j = 0; j < n; j++) {
      std::cout << opis[i][j];
    }
    std::cout << std::endl;
  }

  std::cout << "K:\n";
  for (uint8_t i = 0; i < m; i++) {
    std::cout << k[i] << std::endl;
  }

  std::cout << "Kcopy:\n";
  for (uint8_t i = 0; i < m - 1; i++) {
    std::cout << k[i] << std::endl;
  }

  if (k[0] / m > k[m - 1]) {
    std::cout << k[0] / m;
  } else {
    std::cout << k[m - 1];
  }
}

bool check_l(uint16_t k[], uint16_t k_copy[], uint16_t l, uint8_t m) {
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
