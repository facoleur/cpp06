// main.cpp

#include "Base.hpp"

Base *generate(void) {
  int choice = 1 + std::rand() % 3;

  switch (choice) {
  case 1:
    return new A();

  case 2:
    return new B();

  default:
    return new C();
  }
}

void identify(Base *p) {
  std::cout << "identify type by ptr: ";

  if (dynamic_cast<A *>(p)) {
    std::cout << "A" << std::endl;
    return;
  }

  if (dynamic_cast<B *>(p)) {
    std::cout << "B" << std::endl;
    return;
  }

  if (dynamic_cast<C *>(p)) {
    std::cout << "C" << std::endl;
    return;
  }

  std::cout << "unknown" << std::endl;
}

void identify(Base &p) {
  std::cout << "identify type by ref: ";

  try {
    dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (const std::exception &) {
  }

  try {
    dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (const std::exception &) {
  }

  try {
    dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (const std::exception &) {
  }

  std::cout << "unknown" << std::endl;
}

int main() {
  std::srand(std::time(NULL));

  Base *b = generate();

  identify(b);
  identify(*b);

  delete b;

  // Base *c = new Base();

  // identify(c);
  // identify(*c);

  // delete c;

  return 0;
}
