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

    /****************************************************************************************************
    *Function: StringUtil::TrimSpaces
    *Param: string s
    *Description: Removes all empty spaces in s and returns the value of its result.
    *Return: string
    ****************************************************************************************************/
    string TrimSpaces(string s)
    {
        StringTokenizer tk(s);
        s = "";

        while(tk.HasNextToken())
        {
            s += tk.NextToken();
        }

        return s;
    }

    /***************************************************************************************************
    *Function: StringUtil::TrimLeadingSpaces
    *Param: string s
    *Description: Removes all leading spaces in s and return the value of the result.
    *Return: string
    ***************************************************************************************************/
    string TrimrimLeadingSpaces(string s)
    {
        int i = s.find_first_not_of(" \r\t");

        if(i != string::npos)
            s = s.substr(i, s.size());

        return s;
    }

    /***************************************************************************************************
    *Function: StringUtil::TrimTrailingSpaces
    *Param: string s
    *Description: Removes all trailing spaces in s and returning the value of the result.
    *Return: string
    ***************************************************************************************************/
    string TrimTrailingSpaces(string s)
    {
        int i = s.find_last_not_of(" \r\t");

        if(i != string::npos)
            s = s.substr(i, s.size());

        return s;
    }

    /***************************************************************************************************
    *Function: StringUtil::TrimExessiveSpaces
    *Param: string s
    *Description: Removes all extra empty spaces in s and return the results. This removes leading,
    *   trailing, and extra spaces in s.
    *Return: string s
    ***************************************************************************************************/
    string TrimExessiveSpaces(string s)
    {
        StringTokenizer tk(s);
        s = "";

        while(tk.HasNextToken())
        {
            if(s != "")
                s += " ";
            s += tk.NextToken();
        }

        return s;
    }
}
