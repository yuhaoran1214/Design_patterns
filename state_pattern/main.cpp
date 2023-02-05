#include <iostream>
#include <string>

class war;

class state
{
public:
    virtual ~state() = default;
    virtual void get_current_state(war*) = 0;
};

class war
{
public:
    war(state* s) : _state(s) {}
    ~war() { delete _state; }
    int get_days() const { return _days; }
    void set_days(int days) { _days = days; }
    void get_state() { _state->get_current_state(this); }
    void set_state(state* s) { delete _state; _state = s; }

private:
    state* _state;
    int _days = 0;
};

class end_state : public state
{
public:
    void get_current_state(war*) override
    {
        std::cout << "战争结束" << std::endl;
    }
};

class anaphase_state : public state
{
public:
    void get_current_state(war* w) override
    {
        if (w->get_days() < 30)
        {
            std::cout << w->get_days() << ", 后期" << std::endl; 
        }
        else
        {
            w->set_state(new end_state());
            w->get_state();
        }
    }
};

class metaphase_state : public state
{
public:
    void get_current_state(war* w) override
    {
        if (w->get_days() < 20)
        {
            std::cout << w->get_days() << ", 中期" << std::endl; 
        }
        else
        {
            w->set_state(new anaphase_state());
            w->get_state();
        }
    }
};

class prophase_state : public state
{
public:
    void get_current_state(war* w)
    {
        if (w->get_days() < 10)
        {
            std::cout << w->get_days() << ", 前期" << std::endl; 
        }
        else
        {
            w->set_state(new metaphase_state());
            w->get_state();
        }
    }
};

int main()
{
    war* w = new war(new prophase_state());
    for (int i = 1; i < 40; ++i)
    {
        w->set_days(i);
        w->get_state();
    }

    delete w;
    return 0;
}
