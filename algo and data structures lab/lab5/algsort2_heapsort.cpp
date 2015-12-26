#include<iostream>
#include<fstream>
#define MAXN 500001
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define in f
#define out cout

using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int h[MAXN];
int n;
int length;

int swap(int firstPos, int secondPos)
{

    int aux = h[firstPos];
    h[firstPos] = h[secondPos];
    h[secondPos] = aux;

    return 0;
}

int insert(int value)
{
    length++;
    h[length] = value;
    int position = length;
    while(h[position] <  h[position / 2] && position > 1)
    {
        swap(position, position / 2);
        position /= 2;
    }

    return 0;
}


int main()
{
    in >> n;

    int x;

    for(int i = 1; i <= n; i++)
    {
        in >> x;
        insert(x);
    }

    for(int i = 1; i <= n; i++)
        out << h[i] << " ";


    return 0;
}
