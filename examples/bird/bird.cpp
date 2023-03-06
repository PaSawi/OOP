#include <iostream>
#include <memory>
#include <vector>

class Bird {
public:
    virtual void sing() { std::cout << "tweet, tweet\n"; }
};

class Sparrow : public Bird {
public:
    void sing() { std::cout << "chirp, chirp\n"; }
};

void sing(Bird& b)
{
    b.sing();
}
//*********************************************************************************

class Soundable {
public:
    virtual void makeSound() = 0;
};

class Goose : public Soundable {
public:
    void makeSound() override { std::cout << "Honk! Honk!\n"; }
};

class Hen : public Soundable {
public:
    void makeSound() override { std::cout << "Cluck! Cluck!\n"; }
};

class Duck : public Soundable {
public:
    void makeSound() override { std::cout << "Quack! Quack!\n"; }
};

int main()
{
    std::cout << "-------------------------------------------------------\n";
    std::vector<std::shared_ptr<Soundable>> birds_;
    birds_.emplace_back(std::make_shared<Goose>());
    birds_.emplace_back(std::make_shared<Hen>());
    birds_.emplace_back(std::make_shared<Duck>());

    birds_[0]->makeSound();
    birds_[1]->makeSound();
    birds_[2]->makeSound();

    std::cout << "-------------------------------------------------------\n";

    Sparrow sparrow;
    Bird& bird = sparrow;
    Bird hen;
    sing(bird);
    sing(sparrow);

    std::vector<Bird*> birds;
    birds.emplace_back(&sparrow);
    birds.emplace_back(&hen);

    birds[0]->sing();
    birds[1]->sing();
    std::cout << "--------------------------------------------END VOICES--\n\n";

    return 0;
}