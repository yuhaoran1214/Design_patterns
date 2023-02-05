#include <iostream>
#include <string>
#include <vector>

class colleage
{
public:
    colleage(const std::string& name) : _name(name) {};
    virtual ~colleage() = default;

    void set_name(const std::string& name) { _name = name; }
    std::string get_name() const { return _name; }

    void set_content(const std::string& content) { _content = content; }
    std::string get_content() const { return _content; }

    virtual void talk() = 0;

private:
    std::string _name;
    std::string _content;
};

class monitor : public colleage
{
public:
    monitor(const std::string& name) : colleage(name) {}
    void talk() override
    {
        std::cout << "班长 " << get_name() << " 说：" << get_content() << std::endl;
    }
};

class secretary : public colleage
{
public:
    secretary(const std::string& name) : colleage(name) {}
    void talk() override
    {
        std::cout << "团支书 " << get_name() << " 说：" << get_content() << std::endl;
    }
};

class student_a : public colleage
{
public:
    student_a(const std::string& name) : colleage(name) {}
    void talk() override
    {
        std::cout << "学生A " << get_name() << " 说：" << get_content() << std::endl;
    }
};

class student_b : public colleage
{
public:
    student_b(const std::string& name) : colleage(name) {}
    void talk() override
    {
        std::cout << "学生B " << get_name() << " 说：" << get_content() << std::endl;
    }
};

class mediator
{
public:
    std::vector<colleage*> _colleage_vec;
    virtual ~mediator() = default;
    virtual void add_student(colleage* c)
    {
        _colleage_vec.emplace_back(c); 
    }
    virtual void notiry(colleage*) = 0;
};

class qq_mediator : public mediator
{
public:
    virtual void notiry(colleage* c) override
    {
        c->talk();
        for (std::size_t i = 0; i < _colleage_vec.size(); ++i)
        {
            if (c != _colleage_vec[i])
            {
                _colleage_vec[i]->talk();
            }
        }
    }
};

int main()
{
    qq_mediator qq;
    monitor* m = new monitor("Jack");
    secretary* s = new secretary("Tom");
    student_a* a = new student_a("Frank");
    student_b* b = new student_b("Tim");

    qq.add_student(m);
    qq.add_student(s);
    qq.add_student(a);
    qq.add_student(b);

    m->set_content("明天开始放假！");
    qq.notiry(m);

    delete m;
    delete s;
    delete a;
    delete b;

    return 0;
}
