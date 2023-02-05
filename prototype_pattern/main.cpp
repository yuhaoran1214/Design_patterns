#include <string.h>
#include <iostream>
#include <string>
#include <vector>

class resume
{
public:
    resume() {}
    virtual ~resume() {}
    virtual resume* clone() { return nullptr; }
    virtual void set(char*) {}
    virtual void show() {}

protected:
    char* _name = nullptr;
};

class resume_a : public resume
{
public:
    resume_a(const char* str)
    {
        if (str == nullptr)
        {
            _name = new char[1];
            _name[0] = '\0';
        }
        else
        {
            _name = new char[strlen(str) + 1];
            strcpy(_name, str);
        }
    }

    ~resume_a()
    {
        if (_name != nullptr)
        {
            delete [] _name;
            _name = nullptr;
        }
    }

    resume_a(const resume_a& other)
    {
        if (_name != nullptr)
        {
            delete [] _name;
            _name = nullptr;
        }
        _name = new char[strlen(other._name) + 1];
        strcpy(_name, other._name);
    }

    virtual resume_a* clone()
    {
        return new resume_a(*this);
    }

    virtual void show()
    {
        std::cout << "resume_a name: " << _name << std::endl;
    }
};

int main()
{
    resume* r1 = new resume_a("A");
    resume* r2 = r1->clone();
    r1->show();
    delete r1;
    r2->show();
    delete r2;
    return 0;
}

