#include <iostream>
#include "StringTokenizer.h"

using namespace std;
using NewHome::StringUtil::StringTokenizer;

void PrintTokens(string, StringTokenizer);

int main()
{
    cout << "Hello world!" << endl;

    string test = "hello world";
    string test1 = "hello,world";
    string test2 = "hello|world,my;name|is";

    StringTokenizer strTok(test);
    StringTokenizer strTok1(test1, vector<string>(1, ","));
    StringTokenizer strTok2(test2, "|,;");

    PrintTokens(test, strTok);
    PrintTokens(test1,strTok1);
    PrintTokens(test2, strTok2);

    return 0;
}

void PrintTokens(string original, StringTokenizer st)
{
    cout << "Original : " << original << endl;
    cout << "coutn = " << st.CountTokens() << endl;


    int i = 0;
    while(st.HasNextToken())
    {
        cout << st.NextToken() << endl;
        i++;
    }
}
