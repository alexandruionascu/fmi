#include<fstream>
#include<iostream>
using namespace std;
#define FIN "editor.in"
#define FOUT "editor.out"
#define MAXN 60001

char s[MAXN];
char st[MAXN];
ifstream f(FIN);
ofstream g(FOUT);


int solve(char* s, int length)
{

    int top = 0;
    for(int i=0; i < length - 1; i++)
    {
        if(top == 0)
        {
            if(s[i] == ')' || s[i] == ']')
            {
                g << ":(" << endl;
                return 0;
            }
        }

        if(s[i] == '(' || s[i] == '[')
        {
            top++;
            st[top] = s[i];
        }
        else if(s[i] == ')')
        {
            if(st[top] == '(')
            {
                top--;
            }
            else
            {
                g << ":(" << endl;
                return 0;
            }
        }
        else if(st[top] == '[')
        {
            top--;
        }
        else
        {
            g << ":(" << endl;
            return 0;
        }

    }


    if(top == 0)
    {
        g << ":)" << endl;
    }
    else
    {
        g << ":(" << endl;
    }

    return 0;
}

int main()
{
    int k;
    f >> k;

    for(int i=1; i<=k; i++)
    {
        char c = '0';
        int index = 0;
        while(c != 'E')
        {
            f >> c;
            if(c == '*')
            {
                if(index > 0)
                {
                    index-- ;
                }

            }
            else
            {
                s[index] = c;
                index++;
            }

        }

        solve(s, index);

    }



    return 0;
}
