// main.cpp

#include "ScalarConverter.hpp"
#include <cassert>


int main(const int ac, const char *av[]) {
  // std::cout << std::setprecision(20);

  if (ac != 2) {
    std::cout << "usage: " << av[0] << " <literal>" << std::endl;
    return 1;
  }

  std::string s = av[1];

  ScalarConverter::convert(s);

  return 0;
}
