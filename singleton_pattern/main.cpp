#include <iostream>

class single
{
public:
    single() = default;
    single(const single&) = delete;
    single& operator=(const single&) = delete;

    static single& get_instance()
    {
        static single s;
        return s;
    }

    void print()
    {
        std::cout << "Hello world" << std::endl;
    }
};

int main()
{
    single::get_instance().print();
    single::get_instance().print();
    return 0;
}

