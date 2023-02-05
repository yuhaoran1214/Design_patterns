#include <iostream>
#include <string>

struct request
{
    int num;
};

// 管理者.
class manager
{
public:
    manager(const std::string& name) : _name(name) {}
    virtual ~manager() = default;

    void set_successor(manager* m) 
    {
        _manager = m;
    }

    virtual void get_request(const request& req) = 0;

protected:
    manager* _manager;
    std::string _name;
};

// 经理.
class common_manager : public manager
{
public:
    common_manager(const std::string& name) : manager(name) {}
    void get_request(const request& req) override
    {
        if (req.num >= 0 && req.num < 1000)
        {
            std::cout << _name << " 处理了请求：" << req.num << std::endl;
        }
        else
        {
            _manager->get_request(req);
        }
    }
};

// 总监.
class majordomo : public manager
{
public:
    majordomo(const std::string& name) : manager(name) {}
    void get_request(const request& req) override
    {
        if (req.num <= 5000)
        {
            std::cout << _name << " 处理了请求：" << req.num << std::endl;
        }
        else
        {
            _manager->get_request(req);
        }
    }
};

class general_manager : public manager
{
public:
    general_manager(const std::string& name) : manager(name) {}
    void get_request(const request& req) override
    {
        std::cout << _name << " 处理了请求：" << req.num << std::endl;
    }
};

int main()
{
    manager* common = new common_manager("张经理");
    manager* major = new majordomo("李总监");
    general_manager* general = new general_manager("赵总");
    common->set_successor(major);
    major->set_successor(general);
    
    request req {999};
    common->get_request(req);

    req.num = 4999;
    common->get_request(req);

    req.num = 6999;
    common->get_request(req);

    delete general;
    delete major;
    delete common;

    return 0;
}
