#include<iostream>
#include<fstream>
#define MAXN 10001
#define in cin
#define FIN "takeout.in"
#include<stack>
#include<vector>
using namespace std;

ifstream f(FIN);

stack<int> s;
int n, k;
char c;
int v[MAXN];

int main()
{
    in >> n;
    in >> k;

    for(int i = 1; i <= n; i++)
    {
        in >> c;

        if(c == 'b')
        {
            v[i] = v[i-1] + 1;
            s.push(i);
        }
        else
        {
            v[i] = v[i-1];
            s.push(i);
        }

        if(s.size() > k)
        {
            if(v[i] - v[i - k - 1] == k)
            {
                vector<int> sol;
                for(int i = 1; i <= k + 1; i++)
                {
                    sol.push_back(s.top());
                    s.pop();
                }

                for(vector<int>::reverse_iterator it = sol.rbegin(); it != sol.rend(); it++ )
                {
                    cout << *it << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
