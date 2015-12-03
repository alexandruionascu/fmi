#include<iostream>
using namespace std;

int st[100];
int n;

int init(int top)
{
    st[top] = 0;
    return 0;
}

int succesor(int top)
{
    if(st[top] < n)
    {
        st[top]++;
        return 1;
    }

    return 0;
}

int valid(int top)
{
    int sum = 0;
    for(int i = 1; i < top; i++)
    {
        sum += st[i];
    }

    if(sum <= n)
        return 1;
    else return 0;
}

int solutie(int top)
{
    int sum = 0;
    for(int i = 1; i < top; i++)
    {
        sum += st[i];
    }

    if(sum == n)
        return 1;
    else return 0;
}

int tipar(int top)
{
    for(int i = 1; i < top; i++)
    {
        cout << st[i] << " ";
    }

    cout << "\n";
    return 0;
}

int back(int top)
{
    if(solutie(top))
    {
        tipar(top);
    }
    else
    {
        init(top);
        while(succesor(top))
        {
            if(valid(top))
                back(top + 1);
        }
    }
}

int main()
{
    cout << "n = ";
    cin >> n;

    back(1);

    return 0;
}
