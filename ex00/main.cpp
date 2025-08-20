// main.cpp

#include "ScalarConverter.hpp"
#include <cassert>

void test_getType() {
  // ---- CHAR ----
  assert(getType("a") == CHAR);
  assert(getType("!") == CHAR);
  assert(getType("Z") == CHAR);
  assert(getType(" ") == CHAR);

  // ---- INT ----
  assert(getType("123") == INT);
  assert(getType("  234324 ") == INT);
  assert(getType("-345879456") == INT);
  assert(getType("+42") == INT);
  assert(getType("0") == INT);

  // ---- FLOAT ----
  assert(getType("123.2f") == FLOAT);
  assert(getType(".11f") == FLOAT);
  assert(getType("42.f") == FLOAT);
  assert(getType("1e3f") == FLOAT);
  assert(getType("  -0.5f  ") == FLOAT);
  assert(getType("nanf") == FLOAT);
  assert(getType("-inff") == FLOAT);
  assert(getType("+inff") == FLOAT);

  // ---- DOUBLE ----
  assert(getType("42.42") == DOUBLE);
  assert(getType("-0.001") == DOUBLE);
  assert(getType("1e10") == DOUBLE);
  assert(getType("0.") == DOUBLE);
  assert(getType(".5") == DOUBLE);

  assert(getType("  3.14159  ") == DOUBLE);
  assert(getType("nan") == DOUBLE);
  assert(getType("+inf") == DOUBLE);
  assert(getType("-inf") == DOUBLE);

  // ---- SPECIAL  ----
  assert(getType("nan") == SPECIAL || getType("nan") == DOUBLE);
  assert(getType("nanf") == SPECIAL || getType("nanf") == FLOAT);
  assert(getType("+inf") == SPECIAL || getType("+inf") == DOUBLE);
  assert(getType("-inff") == SPECIAL || getType("-inff") == FLOAT);

  // ---- INVALID ----
  assert(getType("") == INVALID);
  assert(getType("   ") == INVALID);
  assert(getType("abc") == INVALID);
  assert(getType("12a") == INVALID);
  assert(getType("3.2ff") == INVALID);
  assert(getType("..") == INVALID);
  assert(getType("1e") == INVALID);
  assert(getType("1.2f3") == INVALID);
  assert(getType("f123") == INVALID);
}

void printFloat(float f);

int main(const int ac, const char *av[]) {
  // std::cout << std::setprecision(17);

  if (ac != 2) {
    std::cout << "usage: " << av[0] << " <literal>" << std::endl;
    return 1;
  }

  std::string s = av[1];

  ScalarConverter::convert(s);
  return 0;
}
