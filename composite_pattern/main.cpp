#include <iostream>
#include <string>
#include <vector>

class menu
{
public:
    virtual ~menu() = default;
    virtual void add(menu*) {}
    virtual menu* get_child(int) { return nullptr; }
    virtual void display()= 0;

protected:
    menu() = default;
    menu(const std::string& name) : _name(name) {}

    std::string _name;
};

class sub_menu : public menu
{
public:
    sub_menu() = default;
    sub_menu(const std::string& name) : menu(name) {}

    void display() override
    {
        std::cout << _name << std::endl;
    }
};

class composit_menu : public menu
{
public:
    composit_menu() = default;
    composit_menu(const std::string& name) : menu(name) {} 
    ~composit_menu()
    {
        for (auto& m : _menu_vec)
        {
            delete m;
        }
    }

    void add(menu* m) override
    {
        _menu_vec.emplace_back(m); 
    }

    menu* get_child(int index) override
    {
        return _menu_vec[index];
    }

    void display() override
    {
        std::cout << "+" << _name << std::endl;
        for (auto& m : _menu_vec)
        {
            std::cout << "|-";
            m->display();
        }
    }

private:
    std::vector<menu*> _menu_vec;
};

int main()
{
    menu* m1 = new composit_menu("国内新闻");
    m1->add(new sub_menu("时事新闻"));
    m1->add(new sub_menu("社会新闻"));
    m1->display();

    menu* m2 = new composit_menu("国际新闻");
    m2->add(new sub_menu("国际要闻"));
    m2->add(new sub_menu("环球视野"));
    m2->display();

    delete m1;
    delete m2;
    return 0;
}

