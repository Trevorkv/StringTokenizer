#ifndef STRINGUTILFUNCTIONS_H_INCLUDED
#define STRINGUTILFUNCTIONS_H_INCLUDED

#include<string>
#include"StringTokenizer.h"

namespace NewHome::StringUtil
{
    using std::string;

    bool IsNumeral(string);
    string TrimSpaces(string);
    string TrimTrailingSpaces(string);
    string TrimrimLeadingSpaces(string);
    string TrimExessiveSpaces(string);

    string ToString(vector<string>);
}

#endif // STRINGUTILFUNCTIONS_H_INCLUDED
