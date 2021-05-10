#include"StringUtilFunctions.h"

namespace NewHome::StringUtil
{
    /*****************************************************************************
    *Function: IsNumeral
    *Param: string s
    *Description: Returns true if the given string can be expressed as a number,
    *   else false.
    *Return: bool
    *****************************************************************************/
    bool IsNumeral(string s)
    {
        bool ret = true;
        bool hasDecimal = false;

        for(int i = 0; i < s.size(); i++)
        {
            if((s[i] == '.' && hasDecimal) || !std::isdigit(s[i])
               || (s[i] == '-' && i > 0) )
            {
                ret = false;
                break;
            }
        }

        return ret;
    }
}
