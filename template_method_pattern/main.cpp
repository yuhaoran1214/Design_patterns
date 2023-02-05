#include <iostream>

template<typename T>
class caffeine_beverage
{
public:
    virtual ~caffeine_beverage() = default;

    void prepare_recipe()
    {
        boil_water();
        brew();
        pour_in_cup();
        add_condiments();
    }

    void boil_water()
    {
        std::cout << "把水煮沸" << std::endl;
    }

    void brew()
    {
        static_cast<T*>(this)->brew();
    }

    void pour_in_cup()
    {
        std::cout << "把咖啡倒进杯子" << std::endl;
    }

    void add_condiments()
    {
        static_cast<T*>(this)->add_condiments();
    }
};

class coffee : public caffeine_beverage<coffee>
{
public:
    void brew()
    {
        std::cout << "用沸水冲泡咖啡" << std::endl;
    }

    void add_condiments()
    {
        std::cout << "加糖和牛奶" << std::endl;
    }
};

class tea : public caffeine_beverage<tea>
{
public:
    void brew()
    {
        std::cout << "用沸水冲泡茶叶" << std::endl;
    }

    void add_condiments()
    {
        std::cout << "加柠檬" << std::endl;
    }
};

int main()
{
    std::cout << "冲杯咖啡" << std::endl;
    coffee c;
    c.prepare_recipe();
    std::cout << std::endl;
    std::cout << "冲杯茶" << std::endl;
    tea t;
    t.prepare_recipe();

    return 0;
}
