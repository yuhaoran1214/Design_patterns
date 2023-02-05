#include <iostream>
#include <string>

class product
{
public:
    virtual ~product() {}
};

class phone : public product
{
public:
    phone()
    {
        std::cout << "make phone" << std::endl;
    }
};

class tv : public product
{
public:
    tv()
    {
        std::cout << "make tv" << std::endl;
    }
};

class simple_factory
{
public:
    static product* create(const std::string& product_name)
    {
        if (product_name == "phone")
        {
            return new phone();
        }
        else if (product_name == "tv")
        {
            return new tv();
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    product* product1 = simple_factory::create("phone");
    product* product2 = simple_factory::create("tv");
    delete product1;
    delete product2;
    return 0;
}

