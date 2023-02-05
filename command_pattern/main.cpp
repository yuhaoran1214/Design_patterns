#include <iostream>
#include <vector>

// 烤肉师傅.
class roast_cook
{
public:
    void make_mutton()
    {
        std::cout << "make mutton" << std::endl;
    }

    void make_chickenwing()
    {
        std::cout << "make chickenwing" << std::endl;
    }
};

// 抽象命令类.
class command
{
public:
    command(roast_cook* cook) : _roast_cook(cook) {}
    virtual ~command() {}
    virtual void execute() = 0;

protected:
    roast_cook* _roast_cook;
};

// 烤羊肉命令.
class make_mutton_command : public command
{
public:
    make_mutton_command(roast_cook* cook) : command(cook) {}
    virtual void execute()
    {
        _roast_cook->make_mutton();
    }
};

// 烤鸡翅命令.
class make_chickenwing_command : public command
{
public:
    make_chickenwing_command(roast_cook* cook) : command(cook) {}
    virtual void execute()
    {
        _roast_cook->make_chickenwing();
    }
};

// 服务员类.
class waiter
{
public:
    void set_command(command* cmd)
    {
        std::cout << "set command" << std::endl;
        _command_vec.emplace_back(cmd);
    }

    void notify()
    {
        for (auto& cmd : _command_vec)
        {
            cmd->execute();
        }
    }

private:
    std::vector<command*> _command_vec;
};

int main()
{
    roast_cook* cook = new roast_cook();
    command* cmd1 = new make_mutton_command(cook);
    command* cmd2 = new make_chickenwing_command(cook);
    waiter* girl = new waiter();

    // 点菜.
    girl->set_command(cmd1);
    girl->set_command(cmd2);

    // 服务员通知厨师做菜.
    girl->notify();

    delete girl;
    delete cmd1;
    delete cmd2;
    delete cook;

    return 0;
}
