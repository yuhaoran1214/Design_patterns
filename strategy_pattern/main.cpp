#include <iostream>

class weapon_behavior
{
public:
    virtual ~weapon_behavior() = default;
    virtual void use_weapon() = 0;
};

class ak47 : public weapon_behavior
{
public:
    void use_weapon() override
    {
        std::cout << "use ak47 to shoot!" << std::endl;
    }
};

class knife : public weapon_behavior
{
public:
    void use_weapon() override
    {
        std::cout << "use knife to kill!" << std::endl;
    }
};

class character
{
public:
    virtual ~character() = default;

    void set_weapon(weapon_behavior* weapon)
    {
        weapon_ = weapon;
    }

    virtual void fight() = 0;

protected:
    weapon_behavior* weapon_ = nullptr;
};

class king : public character
{
public:
    void fight() override
    {
        std::cout << "the king:";
        if (weapon_ == nullptr)
        {
            std::cout << "You do not have a weapon! please set weapon!" << std::endl;
        }
        else
        {
            weapon_->use_weapon();
        }
    }
};

int main()
{
    weapon_behavior* a = new ak47();
    weapon_behavior* k = new knife();

    character* c = new king();
    c->fight();

    c->set_weapon(a);
    c->fight();

    c->set_weapon(k);
    c->fight();

    delete a;
    delete k;
    delete c;

    return 0;
}
