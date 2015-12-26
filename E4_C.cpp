#include <iostream>
#include<fstream>
#include <string.h>
#include <stack>
#define in cin
#define FIN "date.in"
#define out cout
#define MAXN 1000001
using namespace std;

ifstream f(FIN);

int n;
char s[MAXN];
stack <char> st;

bool open(char c)
{
    if (c == '[')
     return true;

    if (c == '{')
     return true;

    if (c == '<')
        return true;

    if (c == '(')
         return true;

    return false;
}

bool same(char c, char d)
{
    if (c == '[' && d == ']')
     return true;
    if (c == '{' && d == '}')
     return true;
    if (c == '<' && d == '>')
        return true;
    if (c == '(' && d == ')')
     return true;

    return false;
}

int solve()
{

    char c;
    int sol = 0;

    for (int i = 0; i < n; i++)
    {
        if (open(s[i]) == true)
        {
            st.push(s[i]);
            continue;
        }

        if (st.empty() == true)
        {
            cout << "Impossible\n";
            return 0;
        }

        c = st.top();

        st.pop();

        sol = sol + (!same(c, s[i]));
    }

    if (!st.empty())
    {
        cout << "Impossible\n";
        return 0;
    }

    cout << sol << '\n';

    return 0;
}

int main()
{
    in >> s;
    n = strlen(s);
    solve();

    return 0;
}
