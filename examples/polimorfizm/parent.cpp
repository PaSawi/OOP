#include <iostream>
#include <memory>
#include <string>

class Parent {
public:
    Parent() { std::cout << "PARENT C'tor called\n"; }
    virtual ~Parent() { std::cout << "PARENT D'tor caller\n\n"; }
};

class Child : public Parent {
public:
    Child() { std::cout << "CHILD C'tor called\n"; }
    ~Child() override { std::cout << "CHILD D'tor caller\n"; }
};

//**********************************************************************************
class Doppler {
public:
    virtual std::string sayHello() { return "I'm Doppler!"; }
};

class Dwarf : public Doppler {
public:
    std::string sayHello() override { return "I'm Dwarf!"; }
};

class Elf : public Doppler {
public:
    std::string sayHello() override { return "I'm Elf!"; }
};

class Human : public Doppler {
public:
    std::string sayHello() override { return "I'm Human!"; }
};

int main()
{

    std::cout << "\n";
    Child child; // ok, object on stack, not a pointer
    std::unique_ptr<Parent> child2 = std::make_unique<Child>();
    std::cout << '\n';
    std::shared_ptr<Parent> child3 = std::make_shared<Child>();
    Parent* ptr = new Child {};
    delete ptr;
    std::cout << '\n';

    std::shared_ptr<Doppler> doppler1 = std::make_shared<Dwarf>();
    std::shared_ptr<Doppler> doppler2 = std::make_shared<Elf>();
    std::shared_ptr<Doppler> doppler3 = std::make_shared<Human>();
    std::cout << "\n";
    std::cout << doppler1->sayHello() << "\n";
    std::cout << doppler2->sayHello() << '\n';
    std::cout << doppler3->sayHello() << '\n';
    std::cout << "\n";
}