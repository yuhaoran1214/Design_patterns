#include <iostream>
#include <string>
#include <map>

class context
{
public:
    void add_value(const std::string& key, int value)
    {
        _value_map.emplace(key, value);
    }

    int get_value(const std::string& key)
    {
        return _value_map[key];
    }

private:
    std::map<std::string, int> _value_map;
};

class expression
{
public:
    virtual ~expression() = default;
    virtual int interpreter(const context&) = 0;
};

class add_nonterminal_expression : public expression
{
public:
    add_nonterminal_expression(expression* left, expression* right) 
        : _left(left), _right(right) {}

    int interpreter(const context& c) override
    {
        return _left->interpreter(c) + _right->interpreter(c);
    }

private:
    expression* _left;
    expression* _right;
};

class subtract_nonterminal_expression : public expression
{
public:
    subtract_nonterminal_expression(expression* left, expression* right) 
        : _left(left), _right(right) {}

    int interpreter(const context& c) override
    {
        return _left->interpreter(c) - _right->interpreter(c);
    }

private:
    expression* _left;
    expression* _right;
};

class terminal_expression : public expression
{
public:
    terminal_expression(int i) : _i(i) {}

    int interpreter(const context&) override
    {
        return _i;
    }

private:
    int _i;
};

int main()
{
    context c;
    c.add_value("a", 7);
    c.add_value("b", 8);
    c.add_value("c", 2);

    terminal_expression* t1 = new terminal_expression(c.get_value("a"));
    terminal_expression* t2 = new terminal_expression(c.get_value("b"));
    subtract_nonterminal_expression *sub = new subtract_nonterminal_expression(t1, t2);

    terminal_expression* t3 = new terminal_expression(c.get_value("c"));
    add_nonterminal_expression* add = new add_nonterminal_expression(sub, t3);

    std::cout << "a - b + c = " << add->interpreter(c) << std::endl;

    delete t1;
    delete t2;
    delete t3;

    return 0;
}

