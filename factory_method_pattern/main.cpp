#include <iostream>

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

class factory
{
public:
    virtual ~factory() {}
    virtual product* make_product() = 0; 
};

class phone_factory : public factory
{
public:
    virtual product* make_product()
    {
        return new phone();
    }
};

class tv_factory : public factory
{
public:
    virtual product* make_product()
    {
        return new tv();
    }
};

int main()
{
    factory* factory1 = new phone_factory();
    product* product1 = factory1->make_product();

    factory* factory2 = new tv_factory();
    product* product2 = factory2->make_product();

    delete factory1;
    delete product1;
    delete factory2;
    delete product2;
    
    return 0;
}
