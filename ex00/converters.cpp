// converters.cpp

#include "ScalarConverter.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>

bool isSpecial(double value) { return std::isnan(value) || std::isinf(value); }

int countDecimals(const std::string &s) {
  std::string::size_type pos = s.find('.');
  if (pos == std::string::npos)
    return 0;

  if (s.find('f') == std::string::npos && s.find('F') == std::string::npos) {
    return s.size() - pos;
  }

  return s.size() - pos - 1;
}

void handlePrintFloat(float f, int decimals) {
  std::cout << "float: ";
  if (decimals == 0) {
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
  } else {
    std::cout << std::fixed
              << std::setprecision(decimals > 1 ? decimals - 1 : decimals) << f
              << "f" << std::endl;
  }
}

void handlePrintDouble(double d, int decimals) {
  std::cout << "double: ";
  if (decimals == 0)
    std::cout << std::fixed << std::setprecision(1) << d << std::endl;
  else
    std::cout << std::fixed
              << std::setprecision(decimals > 1 ? decimals - 1 : decimals) << d
              << std::endl;
}

void handlePrintChar(const double value) {

  if (value > 127 || value < 0 || isSpecial(value)) {
    std::cout << "char: impossible" << std::endl;
    return;
  }

  if (!isprint(static_cast<unsigned char>(value))) {
    std::cout << "char: non displayable" << std::endl;
    return;
  }

  std::cout << "char: "
            << "'" << static_cast<char>(value) << "'" << std::endl;
}

void handlePrintInt(const double value) {
  if (isSpecial(value) || (value > INT_MAX || value < INT_MIN))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void convertInt(const std::string &literal) {
  const char *p = literal.c_str();
  char *endp = 0;
  errno = 0;

  long int value = std::strtol(p, &endp, 10);

  if (value > INT_MAX || value < INT_MIN) {
    std::cout << "Int Out of range" << std::endl;
    return;
  }

  handlePrintChar(static_cast<double>(value));
  std::cout << "int: " << static_cast<int>(value) << std::endl;
  handlePrintFloat(static_cast<float>(value), 0);
  handlePrintDouble(static_cast<double>(value), 0);
}

void convertFloat(const std::string &literal) {
  std::string sDouble = literal.substr(0, literal.length() - 1);
  const char *p = sDouble.c_str();

  char *endp = 0;
  const double value = strtod(p, &endp);
  int decimals = countDecimals(literal);

  std::string impossible = "impossible";

  handlePrintChar(value);
  handlePrintInt(value);
  handlePrintFloat(static_cast<float>(value), decimals);
  handlePrintDouble(value, decimals);
}

void convertDouble(const std::string &literal) {
  const char *p = literal.c_str();
  char *endp = 0;

  double value = std::strtod(p, &endp);
  int decimals = countDecimals(literal);

  handlePrintChar(value);
  handlePrintInt(value);
  handlePrintFloat(static_cast<float>(value), decimals);
  handlePrintDouble(value, decimals);
}

void convertChar(const std::string &literal) {
  const char c = literal[0];

  std::cout << "char: "
            << "'" << c << "'" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  handlePrintFloat(static_cast<float>(c), 0);
  handlePrintDouble(static_cast<double>(c), 0);
}
