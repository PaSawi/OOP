#include <iostream>
#include <string>
class Person {
    const std::string name_;
    unsigned age_;

public:
    Person(const std::string& name, unsigned age)
        : name_(name)
        , age_(age)
    {
    }

    std::string getName() const { return name_; }

    unsigned getAge() const { return age_; }
    void setAge(unsigned age) { age_ = age; }
};

void printPerson(const Person& p)
{
    std::cout << "Name: " << p.getName() << ", age: " << p.getAge() << '\n';
    // p.setAge(-1);
    // impossible, p passed as const & - read only
}

int main()
{
    Person adam { "Adam", 25 };
    std::cout << "Hello " << adam.getName() << '\n';

    adam.setAge(50);
    std::cout << "Adam has " << adam.getAge() << " years old" << '\n';

    const Person eva { "Eva", 30 };
    // eva.setAge(40);
    // not possible, eva is const
    std::cout << eva.getAge() << 'n';

    printPerson(adam);
    printPerson(eva);
}
