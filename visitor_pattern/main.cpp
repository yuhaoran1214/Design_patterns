#include <iostream>

class visitor;

class element
{
public:
    virtual ~element() = default;
    virtual void accept(visitor* v) = 0;
    virtual void do_something() = 0;
};

class visitor
{
public:
    virtual ~visitor() = default;
    virtual void visit(element* e) = 0;
};

class element_a : public element
{
public:
    virtual void accept(visitor* v) override final
    {
        v->visit(this);
    }

    virtual void do_something() override final
    {
        std::cout << "do something" << std::endl;
    }
};

class visitor_a : public visitor
{
public:
    virtual void visit(element* e) override final
    {
        e->do_something();
    }
};

int main()
{
    element* e = new element_a();
    visitor* v = new visitor_a();
    e->accept(v);

    delete e;
    delete v;

    return 0;
}
