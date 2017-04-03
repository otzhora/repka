#ifndef PROJ_CLASSES_H
#define PROJ_CLASSES_H

#include <string>
#include <vector>
class Text
{
public:
    Text() {
        data.resize(1);
    };

    Text(const std::vector< std::vector<std::string> > _data);

    ~Text();

    //  number of strings
    unsigned long size() const;

    // number of tokens in n string (Number Of TOKENS)
    unsigned long notokens(int n);

    // return n string  (Get STRing)
    std::vector<std::string> gstr(int n) const;

    // return i token of n string
    std::string gtoken(int n, int i) const;

    void operator=(Text& a);

    bool operator==(const Text &rhs) const;

    bool operator!=(const Text &rhs) const;


    void out();
    protected:
    std::vector< std::vector<std::string> > data;
};


class EditableText : public Text
{
public:
    EditableText() : Text() {}

    EditableText(const std::vector<std::vector<std::string> > _data) : Text(_data) {};

    //CHange STRing
    void chstr(std::vector<std::string> str, unsigned long n);

    //CHange TOKEN
    void chtoken(std::string str, unsigned long n, unsigned long i);

    //Find TOKEN (if found return true and pos in result)
    bool ftoken(std::string token, std::pair<unsigned long, unsigned long>& pos);

};

#endif //PROJ_CLASSES_H
