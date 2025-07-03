module mod;

import std;

namespace mod {

int add(int a, int b) {
  return std::plus<int> {}(a, b);
}

} // namespace mod
