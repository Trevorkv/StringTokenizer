#ifndef STRINGTOKENIZER_H
#define STRINGTOKENIZER_H

#include<string>
#include<vector>
#include<iostream>

namespace NewHome::StringUtil
{
    using std::string;
    using std::vector;

    class StringTokenizer
    {
        public:
            StringTokenizer(string, string = " \r\t");
            StringTokenizer(string, vector<string>);
            virtual ~StringTokenizer();

            int CountTokens(int = 0);

            string NextToken();
            string NextToken(string);
            string NextToken(vector<string>);

            string PeekNextDelim(int = 0);

            bool HasNextToken();
            bool HasNextDelim();



        protected:

        private:
            string _str = "";
            vector<string> _delim;

            void AssignDelim(string);
            void AssignDelim(vector<string>);

    };

}

#endif // STRINGTOKENIZER_H
