#include <cmath>
#include <iostream>

class Coordinates {
public:
    Coordinates() = default;
    Coordinates(size_t posX, size_t posY)
        : posX_(posX)
        , posY_(posY)
    {
    }
    static size_t distance(const Coordinates& lhs, const Coordinates& rhs)
    {
        return std::sqrt(std::pow((int)lhs.posX_ - (int)rhs.posX_, 2) + std::pow((int)lhs.posY_ - (int)rhs.posY_, 2));
    }
    bool operator==(const Coordinates& lhs) const
    {
        return this->posX_ == lhs.posX_ && this->posY_ == lhs.posY_;
    }

private:
    const size_t posX_{0};
    const size_t posY_{0};
};