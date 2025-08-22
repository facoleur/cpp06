// converters.cpp

#include "ScalarConverter.hpp"

bool isSpecial(double value) { return std::isnan(value) || std::isinf(value); }

void printFloat(float f) {
  std::cout << "float: ";
  if (f == static_cast<long long>(f))
    std::cout << f << ".0f" << std::endl;
  else
    std::cout << f << "f" << std::endl;
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
  printFloat(static_cast<float>(value));
  std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void convertFloat(const std::string &literal) {
  std::string sDouble = literal.substr(0, literal.length() - 1);
  const char *p = sDouble.c_str();

  char *endp = 0;
  const double value = strtod(p, &endp);

  std::string impossible = "impossible";

  handlePrintChar(value);
  handlePrintInt(value);
  printFloat(static_cast<float>(value));
  std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void convertDouble(const std::string &literal) {
  const char *p = literal.c_str();
  char *endp = 0;

  double value = std::strtod(p, &endp);

  handlePrintChar(value);
  handlePrintInt(value);
  printFloat(static_cast<float>(value));
  std::cout << "double: " << value << std::endl;
}

void convertChar(const std::string &literal) {
  const char c = literal[0];

  std::cout << "char: "
            << "'" << c << "'" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  printFloat(static_cast<float>(c));
  std::cout << "double: " << static_cast<double>(c) << std::endl;
}
