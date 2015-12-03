#include<fstream>
#define FIN "trompeta.in"
#define FOUT "trompeta.out"
#define MAXN 1000001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

char st[MAXN];
int top;

int n, k;
int i;
char c;

int main()
{
    f >> n;
    f >> k;

    for(i = 1; i <= n; ++i)
    {
        f >> c;

        while(top > 0 && st[top] < c && top + n - i >= k)
        {
            --top;
        }

        ++top;
        st[top] = c;
    }

    for(i = 1; i <= k; ++i)
       g << st[i];
    g << "\n";
    return 0;
}
