#ifndef __HASHPJW_HPP__
#define __HASHPJW_HPP__

unsigned int hashpjw(const void *key)
{
    const char *ptr;
    unsigned int val;

    val = 0;
    ptr = (char *)key;

    while (*ptr != '\0')
    {
        unsigned int tmp;

        val = (val << 4) + (*ptr);

        if ((tmp = (val & 0xf0000000)))
        {
            val = val ^ (tmp >> 24);
            val = val ^ tmp;
        }
        ptr++;
    }

    return val;
}

class HashPJW
{
public:
    unsigned int operator()(const void *key)
    {
        return hashpjw(key);
    }
};

#endif