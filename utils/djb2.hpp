#ifndef __DJB2_HPP__
#define __DJB2_HPP__

unsigned int djb2(const void *key)
{
    unsigned int hash = 5381;

    const char *ptr;
    ptr = (char *)key;

    int c;
    while ((c = *ptr++))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

class DJB2
{
public:
    unsigned int operator()(const void *key)
    {
        return djb2(key);
    }
};

#endif