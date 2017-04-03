#include "func.h"

std::vector<std::string> parse(std::string str)
{
    std::vector<std::string> buf;
    unsigned long pos = 0;
    for(unsigned long i = 0; i < str.size(); i ++)
    {
        if(str[i] == ' ')
        {
            buf.push_back(str.substr(pos, i-pos));
            pos = i + 1;
        }
    }
    buf.push_back(str.substr(pos, str.size()-pos));
    return buf;
}