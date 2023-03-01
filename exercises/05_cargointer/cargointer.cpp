#include <iostream>
#include <string>

class Cargo {
public:
    Cargo() = default;
    Cargo(std::string name, size_t amount, size_t basePrice);
    virtual ~Cargo() = default;

    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;

    virtual Cargo& operator+=(size_t amount) = 0;
    virtual Cargo& operator-=(size_t amount) = 0;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};

class Fruit : public Cargo {
public:
    Fruit(std::string name, size_t amount, size_t basePrice, size_t expiryDate, size_t spoilByTime);
    ~Fruit() override;

    size_t getPrice() const override
    {
        if (spoilByTime_ >= expiryDate_)
            return 0;
        return static_cast<size_t>(basePrice_ * ((float)(expiryDate_ - spoilByTime_)) / expiryDate_);
    }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

    Fruit& operator--()
    {
        --spoilByTime_;
        return *this;
    };

    Cargo& operator+=(size_t amount)
    {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(size_t amount)
    {
        amount_ -= amount;
        return *this;
    }

private:
    size_t spoilByTime_;
    size_t expiryDate_;
};

class Alcohol : Cargo {

    size_t getPrice() const override
    {
        return basePrice_ + (baseAlcoholPrice - alcoholPercentage_);
    }

private:
    size_t alcoholPercentage_;
    size_t baseAlcoholPrice_;
};

class Item : Cargo {
};