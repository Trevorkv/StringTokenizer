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


    string StringTokenizer::NextToken(string delim)
    {
        AssignDelim(delim);

        string ret = NextToken();

        return ret;
    }


    string StringTokenizer::NextToken(vector<string> delim)
    {
        AssignDelim(delim);
        string ret = NextToken();

        return ret;
    }



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


    string StringTokenizer::ToString()
    {
        return _str;
    }



    bool StringTokenizer::HasNextToken()
    {
        return !_str.empty();
    }


    bool StringTokenizer::HasNextDelim()
    {
        string nextDelim = PeekNextDelim();

        return !nextDelim.empty();
    }


    void StringTokenizer::AssignDelim(string s)
    {
        _delim.clear();

        for(int i = 0; i < s.size(); i++)
        {
            _delim.insert(_delim.end(), string(1, s.at(i)));
        }
    }


    void StringTokenizer::AssignDelim(vector<string> s)
    {
        _delim.clear();

        _delim = s;
    }

}


