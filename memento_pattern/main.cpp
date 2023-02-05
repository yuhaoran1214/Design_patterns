#include <iostream>
#include <vector>

struct memento
{
    int vitality;
    int attack;
    int defense;
};

class game_role
{
public:
    memento save()
    {
        return _memento;
    }

    void load(memento m)
    {
        _memento = m;
    }

    void show()
    {
        std::cout << "vitality: " << _memento.vitality << std::endl;
        std::cout << "attack: " << _memento.attack << std::endl;
        std::cout << "defense: " << _memento.defense << std::endl;
    }

    void attack()
    {
        _memento.vitality -= 10;
        _memento.attack -= 10;
        _memento.defense -= 10;
    }

private:
    memento _memento {100, 100, 100};
};

class caretake
{
public:
    void save(memento m)
    {
        _memento_vec.emplace_back(m);
    }

    memento load(int state)
    {
        return _memento_vec[state];
    }

private:
    std::vector<memento> _memento_vec;
};

int main()
{
    caretake c;
    game_role role;
    role.show();
    c.save(role.save());
    role.attack();
    role.show();
    role.load(c.load(0));
    role.show();

    return 0;
}

