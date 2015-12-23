#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#define FIN "loto.in"
#define FOUT "loto.out"
#define in f
#define out cout
#define MAXN 101
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int v[MAXN];
int n, s;

typedef struct
{
    int x;
    int y;
    int z;
} Sum;

vector< pair <int, Sum*> > sums;

int read()
{
    in >> n;
    in >> s;
    out << s;
    for(int i = 1; i <= n; i++)
        in >> v[i];
    return 0;
}

int write(int i, int j)
{
    out << sums[i].second->x << " " << sums[i].second->y << " " << sums[i].second->z << " ";
    out << sums[j].second->x << " " << sums[j].second->y << " " << sums[j].second->z;

    return 0;
}

int solve()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                int value = v[i] + v[j] + v[k];
                Sum* sum = new Sum();
                sum->x = i;
                sum->y = j;
                sum->z = k;
                sums.push_back(make_pair(value,sum));
            }
        }
    }

    sort(sums.begin(), sums.end());

    for(int i = 0; i < sums.size(); i++)
        cout << sums[i].first << " ";
    cout << "\n";
    int left = 0;
    int right = sums.size() - 1;

    while(left <= right)
    {
        if(sums[left].first + sums[right].first < s)
        {
            left++;
        }
        else if(sums[left].first + sums[right].first > s)
        {
            right--;
        }
        else
        {
            write(left, right);
            return 0;
        }
    }

    out << -1;
    return 0;
}



int main()
{
    read();
    solve();


    return 0;
}
