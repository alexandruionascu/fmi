#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#define in cin
#define out cout
#define FIN "date.in"
using namespace std;

ifstream f(FIN);

vector< pair< int, int> > v;
int n, k;
int time;

int main()
{
    in >> n;
    in >> k;

    int x, y;

    for(int i = 1; i <= n; i++)
    {
        in >> x;
        in >> y;

        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());
    int currentFloor = k;

    for(int i = v.size() - 1; i >= 0; i--)
    {
        int floor = v[i].first;
        int wait = v[i].second;

        time += abs(currentFloor - floor);
        currentFloor = floor;

        int diff = time - wait;

        if(diff < 0)
        {
            time += abs(diff);
        }

    }

    time += currentFloor;
    out << time;

    return 0;
}
