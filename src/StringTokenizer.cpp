#include "StringTokenizer.h"

namespace NewHome::StringUtil
{

    StringTokenizer::StringTokenizer(string str, string delim)
    {
        _str = str;

        AssignDelim(delim);
    }

    StringTokenizer::StringTokenizer(string str, vector<string> delim)
    {
        _str = str;
        AssignDelim(delim);
    }

    StringTokenizer::~StringTokenizer()
    {
        //dtor
    }

    /************************************************************************
    *Function: StringTokenizer::CountTokens
    *Param: int i
    *Description: Returns the number of tokens in the given string starting
    *   from the given index i.
    *Return: int
    ************************************************************************/
    int StringTokenizer::CountTokens(int i)
    {
        int ret = 0;
        int index = 0;

        for(int j = 0; j < _delim.size(); j++)
        {
            index = 0;

            do{
                index = _str.find(_delim[j], index);

                if(index != string::npos)
                {
                    index++;
                    ret++;
                }
            }while(index != string::npos);
        }

        return ret+1;
    }

    /*****************************************************************************
    *Function: StringTokenizer::NextToken
    *Param: void
    *Description: Extracts the next token as a string and return it.
    *Return: string
    *****************************************************************************/
    string StringTokenizer::NextToken()
    {
        string ret = "";

        int index = _str.size();
        int temp = _str.size();

        for(int i = 0; i < _delim.size(); i++)
        {
            temp = _str.find(_delim[i]);

            if(temp != string::npos && temp < index)
                index = temp;
        }

        ret = _str.substr(0, index);
        _str = _str.substr(index == _str.size() ? index : index+1);

        return ret;
    }

    /**********************************************************************************
    *Function: StringTokenizer::NextToken
    *Param: string delim
    *Description: Extracts the next token from the given string using delim to provide
    *   a list of delimiters. Each charactrer in delim overrides the objects
    *   instantiated delimiters if applicable.
    *Return: string
    **********************************************************************************/
    string StringTokenizer::NextToken(string delim)
    {
        AssignDelim(delim);

        string ret = NextToken();

        return ret;
    }

    /**********************************************************************************
    *Function: StringTokenizer::NextToken
    *Param: vector<string> delim
    *Description: Extracts the next token from the given string using delim to provide
    *   a list of delimiters. delim overrides the objects instantiated delimiters if
    *   applicable.
    *Return: string
    **********************************************************************************/
    string StringTokenizer::NextToken(vector<string> delim)
    {
        AssignDelim(delim);
        string ret = NextToken();

        return ret;
    }


    /***************************************************************************************
    *Function: StringTokenizer::PeekNextDelim
    *Param: int i = 0
    *Description: Returns a copy of the next delimiter in the given string starting from the
    *   index i. Default value of i is 0. Returns the empty string if nothing is found.
    *Return: string
    ***************************************************************************************/
    string StringTokenizer::PeekNextDelim(int i)
    {
        string strTemp = _str.substr(i, _str.size());

        string ret = "";

        int index = strTemp.size();
        int temp = strTemp.size();

        for(int i = 0; i < _delim.size(); i++)
        {
            temp = strTemp.find(_delim[i]);

            if(temp != string::npos && temp < index)
            {
                index = temp;
                ret = strTemp.substr(index, _delim[i].size());
            }
        }

        return ret;
    }

    /***************************************************************************************
    *Function: StringYTokenizer::ToString
    *Param: void
    *Description: Returns the value of the remaining string being tokenized by the current
    *   object.
    *Return: string
    ***************************************************************************************/
    string StringTokenizer::ToString()
    {
        return _str;
    }


    /*************************************************************************************
    *Function: StringATokenizer::HasNextToken
    *Param: void
    *Description: Returns true if there is another token, else return false.
    *Return: bool
    *************************************************************************************/
    bool StringTokenizer::HasNextToken()
    {
        return !_str.empty();
    }

    /************************************************************************************
    *Function: StringATokenizer::HasNextDelim
    *Param: void
    *Description: Returns true if there is another delimiter, else false.
    *Return: bool
    ************************************************************************************/
    bool StringTokenizer::HasNextDelim()
    {
        string nextDelim = PeekNextDelim();

        return !nextDelim.empty();
    }

    /***********************************************************************************
    *Function: StringTokenizer::AssignDelim
    *Param: string s
    *Description: Assigns the characters of s as values of the delimiters used in the
    *   StringTokenizer object.
    *Return: void
    ***********************************************************************************/
    void StringTokenizer::AssignDelim(string s)
    {
        _delim.clear();

        for(int i = 0; i < s.size(); i++)
        {
            _delim.insert(_delim.end(), string(1, s.at(i)));
        }
    }

    /***********************************************************************************
    *Function: StringTokenizer::AssignDelim
    *Param: string s
    *Description: Assigns the value of s as the delimiters used in the
    *   StringTokenizer object.
    *Return: void
    ***********************************************************************************/
    void StringTokenizer::AssignDelim(vector<string> s)
    {
        _delim.clear();

        _delim = s;
    }

}


