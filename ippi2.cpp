#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int Count(const std::string& num) {
  int n = num.size();
  int mult = 1;
  int res = 0;
  for (int i = n - 1; i >= 0; --i) {

    if (num[i] == '1') {
      res += mult;
    }
    mult *= 2;
  }
  return res;
}

int S(const std::string& num) {
  int len = num.size();
  int res = 0;
  if (num[0] == '0') {
    res += Count(num);
  }
  int delta = 0;
  for (int i = 1; i < len; ++i) {
    if (num[i] == '0') {
      delta = Count(num.substr(i, len - i) + num.substr(0, i));
      res += delta;
    }
  }
  return res;
}

int Pow(int n, int deg) {
  int res = 1;
  while (deg > 0) {
    res *= n;
    --deg;
  }
  return res;
}

std::string Modify(int n, int p) {
  std::string ans = "\0";
  while (n > 0 && ans.size() != p) {
    ans = (n % 2 == 0 ? "0" : "1") + ans;
    n /= 2;
  }
  while (ans.size() != p) {
    ans = "0" + ans;
  }
  return ans;
}

int main() {
  int n = 0;
  int p = 0;
  std::cin >> p;
  for (int j = 1; j < p + 1; j += 2) {
    n = 1 << j;
    int max = 0;
    int x = 0;
    std::string ans = "\0";
    for (int i = 1; i < n; ++i) {
      std::string binary = Modify(i, j);
      int sum = S(binary);
      if (sum > max) {
        max = sum;
        x = i;
        ans = binary;
      }
    }
    if (p % 2 == 0) {
      std::cout << "\n p = " << j << " максимум: " << max << ", x = " << x << " = " << ans << " theory: " << (Pow(2, j) - 1) * j / 6 << "\n";
    } else {
      std::cout << "p = " << j << " максимум: " << max << ", x = " << x << " = " << ans << " theory: " << j * (Pow(4, j / 2) - 1) / 3  + (3 * (j / 2 - 1) - (Pow(4, j / 2) - 4)) / 9 << "\n";
    }
  }
}