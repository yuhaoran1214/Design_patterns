#include <iostream>
#include <string>
#include <map>

class character
{
public:
    virtual ~character() = default;
    virtual void set_size(int, int) = 0;
    virtual void display() = 0;

protected:
    std::string _symbol;
    int _weight = 0;
    int _height = 0;
};

class character_a : public character
{
public:
    character_a()
    {
        _symbol = "A";
        _weight = 100;
        _height = 200;
    }

    void set_size(int w, int h) override
    {
        _weight = w;
        _height = h;
    }

    void display() override
    {
        std::cout << "character_a: " << _symbol << "(" << _weight << "," << _height << ")" << std::endl;
    }
};

class character_b : public character
{
public:
    character_b()
    {
        _symbol = "B";
        _weight = 100;
        _height = 200;
    }

    void set_size(int w, int h) override
    {
        _weight = w;
        _height = h;
    }

    void display() override
    {
        std::cout << "character_b: " << _symbol << "(" << _weight << "," << _height << ")" << std::endl;
    }
};

class character_factory
{
public:
    character_factory()
    {
        _character_map.emplace("A", new character_a());
        _character_map.emplace("B", new character_b());
    }

    ~character_factory()
    {
        for (auto& iter : _character_map)
        {
            delete iter.second;
        }
    }

    character* get_character(const std::string& key)
    {
        auto iter = _character_map.find(key);
        if (iter != _character_map.end())
        {
            return iter->second;
        }
        return nullptr;
    }

private:
    std::map<std::string, character*> _character_map;
};

int main()
{
    character_factory* f1 = new character_factory();
    character* c1 = f1->get_character("A");
    c1->display();

    character* c2 = f1->get_character("B");
    c2->set_size(500, 800);
    c2->display();

    delete f1;

    return 0;
}
