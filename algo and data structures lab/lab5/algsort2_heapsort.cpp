#include<iostream>
#include<fstream>
#include<vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500001
using namespace std;

int heap[MAXN];
int n;
int solution[MAXN];
int node;

ifstream f(FIN);
ofstream g(FOUT);

int leftSon(int i)
{
    return heap[2 * i];
}

int rightSon(int i)
{
    return heap[2 * i + 1];
}

int heapify()
{
    if(!(rightSon(node) || leftSon(node)))
    {
        return 0;
    }
    else
    {
        if(rightSon(node) > heap[node])
        {
            swap(heap[node], heap[2 * node + 1]);
            node = node * 2 + 1;
            heapify();
        }

        if(leftSon(node) > heap[node])
        {
            swap(heap[node], heap[2 * node]);
            node *= 2;
            heapify();
        }
    }

    return 0;
}

int makeHeap()
{
    for(int i = n / 2; i > 0; i--)
    {
        node = i;
        heapify();
    }

    return 0;
}

int remove(int k)
{
    heap[k] = 0;
    if(k == 1)
    {
        node = 1;
        heapify();
    }
    else
    {
        node = k / 2;
        heapify();
    }

    return 0;
}

int main()
{
    f >> n;
    int index = n;
    for(int i = 1; i <= n; i++)
    {
        f >> heap[i];
    }

    makeHeap();

    for(int i=1; i<=n; i++)
    {
        solution[index] = heap[1];
        index--;
        remove(1);
    }

    for(int i=1; i<=n; i++)
        cout << solution[i] << " ";

    return 0;

}
