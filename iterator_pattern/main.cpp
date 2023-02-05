#include <iostream>
#include <vector>

template<typename Item>
class iterator_base
{
public:
    virtual ~iterator_base() = default;
    virtual void first() = 0;
    virtual void next() = 0;
    virtual Item* current_item() = 0;
    virtual bool is_done() = 0;
};

template<typename Item>
class concrete_aggregate;

template<typename Item>
class concrete_iterator : public iterator_base<Item>
{
public:
    concrete_iterator(concrete_aggregate<Item>* a) : _aggr(a) {}

    void first() override
    {
        _current = 0;
    }

    void next() override
    {
        if (_current < _aggr->len())
        {
            ++_current;
        }
    }

    Item* current_item() override
    {
        if (_current < _aggr->len())
        {
            return &(*_aggr)[_current];
        }
        return nullptr;
    }

    bool is_done() override
    {
        return _current == _aggr->len();
    }

private:
    concrete_aggregate<Item>* _aggr;
    int _current = 0;
};

template<typename Item>
class aggergate
{
public:
    virtual ~aggergate() = default;
    virtual iterator_base<Item>* create_iterator() = 0;
};

template<typename Item>
class concrete_aggregate : public aggergate<Item>
{
public:
    iterator_base<Item>* create_iterator() override
    {
        return new concrete_iterator<Item>(this);
    }

    Item& operator[](int index)
    {
        return _item_vec[index];
    }

    int len() const
    {
        return _item_vec.size();
    }

private:
    std::vector<Item> _item_vec {1, 2, 3};
};

int main()
{
    aggergate<int>* aggr = new concrete_aggregate<int>();
    iterator_base<int>* iter = aggr->create_iterator();
    for (iter->first(); !iter->is_done(); iter->next())
    {
        std::cout << *(iter->current_item()) << std::endl;
    }

    delete iter;
    delete aggr;

    return 0;
}
