// getType.cpp

#include "ScalarConverter.hpp"

std::string trim(const std::string &s) {
  if (s.empty())
    return s;

  size_t start = s.find_first_not_of(" \t\n\r\f\v");
  if (start == std::string::npos)
    return "";

  size_t end = s.find_last_not_of(" \t\n\r\f\v");

  return s.substr(start, end - start + 1);
}

bool hasDotOrExp(const std::string &literal) {
  for (unsigned int i = 0; i < literal.length(); i++) {
    if (literal[i] == 'e' || literal[i] == 'E' || literal[i] == '.')
      return true;
  }
  return false;
}

bool isSpecialFloat(const std::string &literal) {
  std::string s = trim(literal);

  for (size_t i = 0; i < s.length(); ++i)
    s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));

  return (s == "+inff" || s == "-inff" || s == "nanf");
}

bool isSpecialDouble(const std::string &literal) {
  std::string s = trim(literal);

  for (size_t i = 0; i < s.length(); ++i)
    s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));

  return (s == "nan" || s == "+inf" || s == "-inf");
}

bool isInt(const std::string literal) {
  std::string s = trim(literal);

  if (s.empty())
    return false;

  const char *p = s.c_str();
  char *endp = 0;

  const long value = strtol(p, &endp, 10);

  if (*endp != '\0')
    return false;

  if (value < INT_MIN || value > INT_MAX)
    return false;

  return true;
}

bool isChar(const std::string &literal) {
  return literal.length() == 1 &&
         !isdigit(static_cast<unsigned char>(literal[0]));
}

bool isFloat(const std::string &literal) {
  std::string s = trim(literal);

  if (s.empty())
    return false;

  if (isSpecialFloat(s))
    return true;

  if (!hasDotOrExp(s))
    return false;

  const char *p = s.c_str();
  char *endp = 0;

  (void)std::strtod(p, &endp);
  if (endp == p)
    return false;

  if (*endp != 'f' && *endp != 'F')
    return false;
  ++endp;

  return *endp == '\0';
}

bool isDouble(const std::string &literal) {
  std::string s = trim(literal);

  if (isSpecialDouble(s))
    return true;

  if (!hasDotOrExp(s))
    return false;

  const char *p = s.c_str();
  char *endp = 0;

  (void)std::strtod(p, &endp);
  if (endp == p)
    return false;

  if (*endp == 'f' || *endp == 'F')
    return false;

  return *endp == '\0';
}

type getType(const std::string literal) {
  if (isInt(literal))
    return INT;
  if (isFloat(literal))
    return FLOAT;
  if (isDouble(literal))
    return DOUBLE;
  if (isChar(literal))
    return CHAR;
  return INVALID;
}
