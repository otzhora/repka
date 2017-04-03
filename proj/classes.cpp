#include <iostream>
#include "classes.h"


Text::Text(const std::vector< std::vector<std::string> > _data){
    data.resize(_data.size());

    for(int i = 0; i < _data.size(); i++)
    {
        data[i].resize(_data[i].size());
    }

    for(int i = 0; i < _data.size(); i++)
    {
        for(int j = 0; j < _data[i].size(); j++)
            data[i][j] = _data[i][j];
    }
}

Text::~Text() {
    for(int i = 0; i < data.size(); i++)
    {
        data[i].clear();
    }
    data.clear();
}

unsigned long Text::size() const
{
    return data.size();
}

unsigned long Text::notokens(int n) {
    if(n < data.size())
        return data[n].size();
    else return 0;
}

std::vector<std::string> Text::gstr(int n) const {
    if(n < data.size())
        return data[n];
    else return std::vector<std::string>(0);
}

std::string Text::gtoken(int n, int i) const {
    if(n < data.size() && i < data[n].size())
        return data[n][i];
    else return "";
}

bool Text::operator==(const Text &rhs) const {
    return data == rhs.data;
}

bool Text::operator!=(const Text &rhs) const {
    return !(rhs == *this);
}

void Text::operator=(Text &a) {

    for(int i = 0; i < a.data.size(); i++)
    {
        data[i].clear();
    }
    data.clear();

    data.resize(a.size());

    for(int i = 0; i < a.data.size(); i++)
    {
        data[i].resize(a.data[i].size());
    }

    for(int i = 0; i < a.data.size(); i++)
    {
        for(int j = 0; j < a.data[i].size(); j++)
            data[i][j] = a.data[i][j];
    }
}

void EditableText::chstr(std::vector<std::string> str, unsigned long n) {
    if(n < data.size()){
        data[n].clear();
        data[n] = str;
    }
    else
    {
        data.resize(n + 1);
        data[n] = str;
    }

}

void EditableText::chtoken(std::string str, unsigned long n, unsigned long i) {
    if(n < data.size() && i < data[n].size())
        data[n][i] = str;
    else if(n < data.size())
    {
        data[n].resize(i+1);
        data[n][i] = str;
    }
    else
    {
        data.resize(n + 1);
        data[n].resize(i + 1);
        data[n][i] = str;
    }
}

bool EditableText::ftoken(std::string token, std::pair<unsigned long, unsigned long> &pos) {
    for(unsigned long i = 0; i < data.size(); i ++)
        for(unsigned long j = 0; j < data[i].size(); j++)
        {
            if(data[i][j] == token)
            {
                pos = std::make_pair(i, j);
                return true;
            }
        }
    return false;
}

void Text::out() {
    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < data[i].size(); j++)
            std::cout << data[i][j] << " ";
        std::cout << std::endl;
    }
}