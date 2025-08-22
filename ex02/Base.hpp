// Base.hpp

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base {
public:
  virtual ~Base() = 0;

private:
};

class A : public Base {
public:
};

class B : public Base {
public:
};

class C : public Base {
public:
};
