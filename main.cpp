#include <iostream>
#include "StringTokenizer.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

using NewHome::StringUtil::StringTokenizer;

void TestStringTokenizer();
void TestTokenizer(string, StringTokenizer);

void TestStringUtilFunctions();

int main()
{
    cout << "\tTesting members of namespace NewHome::StringUtil" << endl << endl;
    TestStringTokenizer();

    return 0;
}

void TestStringTokenizer()
{
    cout << "\t<Testing StringTokenizer>" << endl;

    string test = "hello world";
    string test1 = "hello,world";
    string test2 = "hello|world,my;name|is";

    StringTokenizer strTok(test);
    StringTokenizer strTok1(test1, vector<string>(1, ","));
    StringTokenizer strTok2(test2, "|,;");

    TestTokenizer(test, strTok);
    TestTokenizer(test1,strTok1);
    TestTokenizer(test2, strTok2);
}

void TestTokenizer(string original, StringTokenizer st)
{
    cout << "Original : " << original << endl;
    cout << "Token Counts = " << st.CountTokens() << endl << endl;

    while(st.HasNextToken())
    {
        cout << "Next Delimiter = " << st.PeekNextDelim() << endl;
        cout << "Token = " << st.NextToken() << endl;
        cout << "Resulting String = " << st.ToString() << endl;
    }

    cout << "End Test of " << original << endl << endl;
}

void TestStringUtilFunctions()
{

}
