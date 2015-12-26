#include<iostream>
#include<fstream>
#define MAXN 300001
#define FIN "heapuri.in"
#define FOUT "heapuri.out"
#define in f
#define out g

using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int h[MAXN];
int p[MAXN];
int length;
int n;
int v[MAXN];



int swap(int firstPos, int secondPos)
{
    p[h[firstPos]] = secondPos;
    p[h[secondPos]] = firstPos;

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
    while(v[h[position]] <  v[h[position / 2]] && position > 1)
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

    if(v[h[pos]] < v[h[pos / 2]])
    {
        while(pos > 1 && v[h[pos]] < v[h[pos / 2]])
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
            if ((2 * pos + 1 > length || v[h[2 * pos + 1]] > v[h[2 * pos]]) && v[h[2 * pos]] < v[h[pos]])
            {
                swap(pos, 2 * pos);
                pos = 2 * pos;
                son = 1;
            }
            else if (2 * pos + 1 <= length && v[h[2 * pos + 1]] < v[h[pos]])
            {
                swap(pos, pos * 2 + 1);
                pos = 2 * pos + 1;
                son = 1;
            }
        }
    }

    return 0;
}

int getMax()
{
    return v[h[1]];
}

int main()
{
    in >> n;

    int x, y;
    int index = 0;
    for(int i = 1; i <= n; i++)
    {
        in >> x;

        switch(x)
        {
            case 1:
                in >> y;
                index++;
                v[index] = y;
                p[index] = index;
                insert(index);
                break;
            case 2:
                in >> y;
                erase(p[y]);
                break;
            case 3:
                out << getMax() << "\n";
                break;
        }


    }

    return 0;
}
