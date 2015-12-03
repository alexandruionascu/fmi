#include<iostream>
#include<fstream>
#include<queue>
#define MAXN 10001
using namespace std;

ifstream f("iepurasi.in");
ofstream g("iepurasi.out");

int n;
int v[MAXN];
queue<long long> q;
int taps;

int flip(int start, int finish)
{
    int aux;
    while(start < finish)
    {
        aux = v[start];
        v[start] = v[finish];
        v[finish] = aux;
        start++;
        finish--;
    }

    return 0;
}

int get_min(int k)
{
    int minn = 1;
    for(int i=1; i<=k; i++)
    {
        if(v[i] < v[minn])
            minn = i;
    }

    return minn;
}

bool valid(long long nr)
{
    int n7 = 0;
    int n8 = 0;
    int n9 = 0;

    while(nr > 0)
    {
        int c = nr % 10;
        if(c == 7)
        {
            n7++;
        }
        else if(c ==  8)
        {
            n8++;
        }
        else
        {
            n9++;
        }

        nr /= 10;
    }

    if(n7 <= n8 && n8 <= n9)
        return true;
    else return false;
}

long long brute(int number)
{
    q.push(7);
    q.push(8);
    q.push(9);
    int index = 0;
    while(!q.empty())
    {
        if(valid(q.front()))
        {
            index++;
            if(index == number)
            {
                return q.front();
            }
        }

        q.push(q.front() * 10 + 7);
        q.push(q.front() * 10 + 8);
        q.push(q.front() * 10 + 9);

        q.pop();
    }


}

int solve()
{
    int lastIndex = 0;
    for(int i=n; i >= 1; i--)
    {
        int minn = get_min(i);
        if(minn != i)
        {
            lastIndex = minn;
            flip(minn, i);
            taps++;
        }

    }
    if(lastIndex != 1)
    {
        lastIndex--;
    }

    g << taps << "\n" << brute(v[lastIndex]);
}


int main()
{
    f >> n;
    for(int i=1; i<=n; i++)
        f >> v[i];
    solve();
    return 0;
}
