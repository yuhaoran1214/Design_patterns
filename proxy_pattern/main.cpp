#include <iostream>
#include <string>

class image
{
public:
    image() = default;
    image(const std::string& name) : _image_name(name) {}
    virtual ~image() = default;
    virtual void show() = 0;

protected:
    std::string _image_name;
};

class big_image : public image
{
public:
    big_image(const std::string& name) : image(name) {}
    void show() override
    {
        std::cout << "show big image: " << _image_name << std::endl;
    }
};

class big_image_proxy : public image
{
public:
    big_image_proxy(const std::string& name) : image(name) {}
    ~big_image_proxy()
    {
        delete _big_image;
    }

    void show() override
    {
        _big_image = new big_image(_image_name);
        _big_image->show();
    }
    
private:
    big_image* _big_image;
};

int main()
{
    image* img = new big_image_proxy("proxy.jpg");
    img->show();
    delete img;
    return 0;
}
