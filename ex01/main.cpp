// main.cpp

#include "Serializer.hpp"

int main() {
  Data object;

  object.c = 'a';
  object.i = 1;

  Data *ptr = &object;

  uintptr_t sptr = Serializer::serialize(ptr);

  Data *sObject = Serializer::deserialize(sptr);

  if (!(reinterpret_cast<uintptr_t>(ptr) == sptr)) {
    std::cout << "wrong conversion!" << std::endl;
  }

  bool arePtrEq = reinterpret_cast<uintptr_t>(ptr) == sptr;

  std::cout << "ptrs are equal: " << std::boolalpha << arePtrEq << std::endl;

  std::cout << "objs data equal: " << std::boolalpha << (object.c == sObject->c)
            << std::endl;

  std::cout << "original ptr: " << ptr << std::endl;
  std::cout << "sptr: " << sptr << std::endl;
  std::cout << "sptr formatted: "
            << "0x" << std::hex << sptr << std::dec << std::endl;

  std::cout << "Data char: " << object.c << std::endl;
  std::cout << "Data int: " << object.i << std::endl;

  std::cout << "new Data char: " << sObject->c << std::endl;
  std::cout << "new Data int: " << sObject->i << std::endl;

  return 0;
}
