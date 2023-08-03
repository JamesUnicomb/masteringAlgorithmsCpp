#ifndef __SORT_HPP__
#define __SORT_HPP__

template <typename T>
class CompareT
{
public:
    inline bool operator()(T a, T b)
    {
        return a > b ? true : false;
    }
};

#endif