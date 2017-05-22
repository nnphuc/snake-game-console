#include "utility.h"




wchar_t *toWchar_t(const char *c)
{

    const size_t cSize = strlen(c)+1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, c, cSize);

    return wc;

}

namespace std{
    string to_string(int x)
    {
        char s[100];
        sprintf(s,"%d",x);
        return string(s);
    }
}


