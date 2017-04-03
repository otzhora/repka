#include <iostream>
#include "classes.h"
#include "func.h"
using namespace std;

int main() {

    int n, m;
    vector< vector<string> > arr;
    cout << "enter n (number of strings)" << endl;
    cin >> n;

    arr.resize((unsigned long)n);
    string buf;
    getline(cin , buf);
    for(int i = 0; i < n; i++)
    {
        getline(cin , buf);
        arr[i] = parse(buf);
    }

    Text txt(arr);

    cout << "number of string: " << txt.size() << endl;
    txt.out();
    cout << "enter n: ";
    cin >> n;
    n--;
    cout << "number of tkent in n str: " << txt.notokens(n) << endl;
    cout << "enter n: ";
    cin >> n;
    n--;
    cout << "n'th string: ";
    for(int i = 0; i < txt.gstr(n).size(); i++)
        cout << txt.gstr(n)[i] << " ";
    cout << endl;
    cout << "enter n and i: ";
    int i;
    cin >> n >> i;
    n--, i--;
    cout << "i'th token of n'th string: " << txt.gtoken(n, i) << endl;
    EditableText etxt(arr);
    cout << "now text is editable" << endl;
    cout << "enter string and n: ";
    cin >> n;
    n--;
    cout << endl;
    {
        vector<string> buf_str;
        string buf;
        getline(cin, buf);
        buf_str = parse(buf);
        etxt.chstr(buf_str, n);
    }
    cout << endl;
    cout << "enter n and i: ";
    cin >> n >> i;
    n--, i--;
    cout << "enter string: ";
    {
        string buf;
        cin >> buf;
        etxt.chtoken(buf, n, i);
    }
    cout <<  "enter string to find: ";
    {
        string buf;
        cin >> buf;
        pair<unsigned long, unsigned long> pos;
        if(etxt.ftoken(buf, pos))
            cout << ++pos.first << " " << ++pos.second << endl;
        else
            cout << "this is not in text" << endl;
    }
    etxt.out();
    return 0;
}