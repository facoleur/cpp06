// ScalarConverter.cpp

#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
  return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string literal) {

  type type = getType(literal);

  switch (type) {
  case INVALID:
    std::cout << "invalid input" << std::endl;
    break;
  case INT:
    convertInt(literal);
    break;
  case FLOAT:
    convertFloat(literal);
    break;
  case DOUBLE:
    convertDouble(literal);
    break;
  case CHAR:
    convertChar(literal);
    break;

  default:
    break;
  }
}
