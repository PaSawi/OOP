#include <iostream>
#include <memory>
#include <string>

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
    std::shared_ptr<Doppler> doppler1 = std::make_shared<Dwarf>();
    std::shared_ptr<Doppler> doppler2 = std::make_shared<Elf>();
    std::shared_ptr<Doppler> doppler3 = std::make_shared<Human>();

    std::cout << doppler1->sayHello() << "\n";
    std::cout << doppler2->sayHello() << '\n';
    std::cout << doppler3->sayHello() << '\n';
}