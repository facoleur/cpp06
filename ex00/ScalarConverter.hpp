// ScalarConverter.hpp

#pragma once

#include <cctype>
#include <climits>
#include <cstdlib>
#include <errno.h>
#include <iomanip>
#include <iostream>
#include <math.h>

enum type {
  CHAR = 1,
  INT = 2,
  FLOAT = 3,
  DOUBLE = 4,
  INVALID = 5,
  SPECIAL = 6,
};

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();

public:
  static void convert(const std::string literal);
};

type getType(const std::string literal);
void convertInt(const std::string &literal);
void convertFloat(const std::string &literal);
void convertDouble(const std::string &literal);
void convertChar(const std::string &literal);
void handlePrintFloat(float f);
