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

            /************************************************************************
            *Function: StringTokenizer::CountTokens
            *Param: int i = 0
            *Description: Returns the number of tokens in the given string starting
            *   from index i.
            *Return: int
            ************************************************************************/
            int CountTokens(int i = 0);

            /*****************************************************************************
            *Function: StringTokenizer::NextToken
            *Param: void
            *Description: Extracts the next token as a string and return it.
            *Return: string
            *****************************************************************************/
            string NextToken();

            /**********************************************************************************
            *Function: StringTokenizer::NextToken
            *Param: string delim
            *Description: Extracts the next token from the given string using delim to provide
            *   a list of delimiters. Each charactrer in delim overrides the objects
            *   instantiated delimiters if applicable.
            *Return: string
            **********************************************************************************/
            string NextToken(string delim);

            /**********************************************************************************
            *Function: StringTokenizer::NextToken
            *Param: vector<string> delim
            *Description: Extracts the next token from the given string using delim to provide
            *   a list of delimiters. delim overrides the objects instantiated delimiters if
            *   applicable.
            *Return: string
            **********************************************************************************/
            string NextToken(vector<string>);

            /***************************************************************************************
            *Function: StringTokenizer::PeekNextDelim
            *Param: int i = 0
            *Description: Returns a copy of the next delimiter in the given string starting from the
            *   index i. Default value of i is 0. Returns the empty string if nothing is found.
            *Return: string
            ***************************************************************************************/
            string PeekNextDelim(int = 0);

            /***************************************************************************************
            *Function: StringYTokenizer::ToString
            *Param: void
            *Description: Returns the value of the remaining string being tokenized by the current
            *   object.
            *Return: string
            ***************************************************************************************/
            string ToString();

            /*************************************************************************************
            *Function: StringATokenizer::HasNextToken
            *Param: void
            *Description: Returns true if there is another token, else return false.
            *Return: bool
            *************************************************************************************/
            bool HasNextToken();

            /************************************************************************************
            *Function: StringATokenizer::HasNextDelim
            *Param: void
            *Description: Returns true if there is another delimiter, else false.
            *Return: bool
            ************************************************************************************/
            bool HasNextDelim();

        protected:

        private:
            string _str = "";
            vector<string> _delim;

            /***********************************************************************************
            *Function: StringTokenizer::AssignDelim
            *Param: string s
            *Description: Assigns the characters of s as values of the delimiters used in the
            *   StringTokenizer object.
            *Return: void
            ***********************************************************************************/
            void AssignDelim(string);

            /***********************************************************************************
            *Function: StringTokenizer::AssignDelim
            *Param: string s
            *Description: Assigns the value of s as the delimiters used in the
            *   StringTokenizer object.
            *Return: void
            ***********************************************************************************/
            void AssignDelim(vector<string>);

    };

}

#endif // STRINGTOKENIZER_H
