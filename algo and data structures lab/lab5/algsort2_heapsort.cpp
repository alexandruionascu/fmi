#include<iostream>
#include<fstream>
#define MAXN 500001
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define in f
#define out g

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

int insert(int x)
{
    length++;
    h[length] = x;
    int position = length;
    while(h[position] <  h[position / 2] && position > 1)
    {
        swap(position, position / 2);
        position /= 2;
    }

    return 0;
}

int erase(int pos)
{
    swap(pos, length);
    length--;

    if(h[pos] < h[pos / 2])
    {
        while(pos > 1 && h[pos] < h[pos / 2])
        {
            swap(pos, pos / 2);
            pos /= 2;
        }
    }
    else
    {
        int son = 1;

        while(2 * pos <= length && son)
        {
            son = 0;
            if ((2 * pos + 1 > length || h[2 * pos + 1] > h[2 * pos]) && h[2 * pos] < h[pos])
            {
                swap(pos, 2 * pos);
                pos = 2 * pos;
                son = 1;
            }
            else if (2 * pos + 1 <= length && h[2 * pos + 1] < h[pos])
            {
                swap(pos, pos * 2 + 1);
                pos = 2 * pos + 1;
                son = 1;
            }
        }
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
    {
        out << h[1] << " ";
        erase(1);
    }



    return 0;
}
