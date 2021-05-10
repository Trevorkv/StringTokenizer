#include <iostream>
#include "StringTokenizer.h"

using namespace std;
using NewHome::StringUtil::StringTokenizer;

void TestTokenizer(string, StringTokenizer);

int main()
{
    cout << "Hello world!" << endl;

    string test = "hello world";
    string test1 = "hello,world";
    string test2 = "hello|world,my;name|is";

    StringTokenizer strTok(test);
    StringTokenizer strTok1(test1, vector<string>(1, ","));
    StringTokenizer strTok2(test2, "|,;");

    TestTokenizer(test, strTok);
    TestTokenizer(test1,strTok1);
    TestTokenizer(test2, strTok2);

    return 0;
}

void TestTokenizer(string original, StringTokenizer st)
{
    cout << "Original : " << original << endl;
    cout << "Token Counts = " << st.CountTokens() << endl;

    while(st.HasNextToken())
    {
        cout << "Next Delimiter = " << st.PeekNextDelim() << endl;
        cout << "Token = " << st.NextToken() << endl;
    }
}
