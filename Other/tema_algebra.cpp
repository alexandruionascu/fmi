#include<iostream>
using namespace std;


int n;
int st[20];
int sigma[] = {0, 3, 2, 1, 11, 5, 8, 13, 10, 9, 12, 4, 6, 7};
int back(int k, int masca)
{
    if(k == n+1)
    {
        //verific daca e permutarea buna
        int v[20];
        for(int i = 1; i <= n; i++)
        {
            v[i] = st[i];
        }

        for(int i = 1; i <= n; i++)
        {
            v[i] = st[v[i]];
        }

        for(int i = 1; i <= n; i++)
        {
            v[i] = st[v[i]];
        }

        for(int i = 1; i <= n; i++)
        {
            if(v[i] != sigma[i])
            {
                return 0;
            }
        }

        for(int i=1;i<=n;i++)
            cout << st[i] << " ";
        cout << "\n";
    }
    else
    {
        st[k] = 0;
        while(st[k] < n)
        {
            st[k]++;

            if((masca | (1 << st[k])) != masca)
                back(k+1, masca | (1 << st[k]));
        }

    }
}

int main()
{
    cout << "n = ";
    cin >> n;
    back(1, 0);
    return 0;
}
