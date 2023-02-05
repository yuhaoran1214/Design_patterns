#include <iostream>
#include <string>
#include <list>

class observer
{
public:
    virtual ~observer() = default;
    virtual void update() = 0;
};

class blog
{
public:
    virtual ~blog() = default;

    void attach(observer* o)
    {
        _observer_list.emplace_back(o); 
    }

    void remove(observer* o)
    {
        _observer_list.remove(o);
    }

    void notify()
    {
        for (auto& iter : _observer_list)
        {
            iter->update();
        }
    }

    virtual void set_status(const std::string& status) = 0;
    virtual std::string get_status() const = 0;

protected:
    std::string _status;

private:
    std::list<observer*> _observer_list;
};

class blog_csdn : public blog
{
public:
    blog_csdn(const std::string& title) : _title(title) {}

    void set_status(const std::string& status) override
    {
        _status = "CSDN通知：" + _title + status;
    }

    std::string get_status() const override
    {
        return _status;
    }

private:
    std::string _title;
};

class observer_blog : public observer
{
public:
    observer_blog(const std::string& name, blog* b) : _name(name), _blog(b) {}

    void update() override
    {
        std::cout << _name << "------------" << _blog->get_status() << std::endl;
    }

private:
    std::string _name;
    blog* _blog;
};

int main()
{
    blog* b = new blog_csdn("chxuan");
    observer* o = new observer_blog("cx", b);
    b->attach(o);
    b->set_status("C++");
    b->notify();
    delete b;
    delete o;
    return 0;
}

