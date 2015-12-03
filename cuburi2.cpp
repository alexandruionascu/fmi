#include<fstream>
#include<iostream>
#define MAXN 1000001
using namespace std;

ifstream f("cuburi2.in");
ofstream g("cuburi2.out");


int n;
int m[11];
int v[MAXN];

int main()
{
    f >> n;
    for(int i=1; i<=n; i++)
        f >> v[i];

    int current = 0;
    int counter = 0;
    bool replaced = 0;
    int maxx = 0;

    for(int i=1; i<=n; i++)
    {
        if(current == v[i])
        {
            counter++;
        }
        else
        {
            if(current == v[i+1])
            {
                if(replaced == 0)
                {
                    i++;
                    replaced = 1;
                }
                else
                {
                    replaced = 0;
                    counter = 1;
                    current = v[i];
                }
            }
            else
            {
                counter = 1;
                current = v[i];
                replaced = 0;
            }
        }

        if(counter > m[v[i]])
            m[v[i]] = counter+1;

        if(counter + 1 > maxx)
            maxx = counter + 1;

    }
    cout << maxx << '\n';
    for(int i=1; i<=10; i++)
        if(m[i] == maxx)
            g << i << " ";

    cout << endl << endl;
    for(int i=1; i<=10; i++)
        cout << m[i] << " ";

}
