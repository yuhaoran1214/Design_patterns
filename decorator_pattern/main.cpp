#include <iostream>
#include <string>

class tank
{
public:
    virtual ~tank() = default;
    virtual void shot() = 0;
    virtual void run() = 0;
};

class t50 : public tank
{
public:
    void shot() override
    {
        std::cout << "tank t50 shot" << std::endl;
    }

    void run() override
    {
        std::cout << "tank t50 run" << std::endl;
    }
};

class t75 : public tank
{
public:
    void shot() override
    {
        std::cout << "tank t75 shot" << std::endl;
    }

    void run() override
    {
        std::cout << "tank t75 run" << std::endl;
    }
};

class decorator : public tank
{
public:
    decorator(tank* t) : _tank(t) {}

    void shot() override
    {
        _tank->shot();
    }

    void run() override
    {
        _tank->run();
    }

protected:
    tank* _tank;
};

class infrared_decorator : public decorator
{
public:
    infrared_decorator(tank* t) : decorator(t) {}

    void run() override
    {
        _tank->run();
        set_infrared("+Infrared");
        std::cout << get_infrared() << std::endl;
    }

    void shot() override
    {
        _tank->shot();
    }

    void set_infrared(const std::string& infrared)
    {
        _infrared = infrared;
    }

    std::string get_infrared() const
    {
        return _infrared;
    }

private:
    std::string _infrared;
};

class amphibian_decorator : public decorator
{
public:
    amphibian_decorator(tank* t) : decorator(t) {}

    void run() override
    {
        _tank->run();
        set_amphibian("+Amphibian");
        std::cout << get_amphibian() << std::endl;
    }

    void shot() override
    {
        _tank->shot();        
    }

    void set_amphibian(const std::string& amphibian)
    {
        _amphibian = amphibian;
    }

    std::string get_amphibian() const
    {
        return _amphibian;
    }

private:
    std::string _amphibian;
};

int main()
{
    tank* t1 = new t50();
    tank* t2 = new infrared_decorator(t1);
    t2->shot();
    t2->run();

    delete t1;
    delete t2;

    return 0;
}

