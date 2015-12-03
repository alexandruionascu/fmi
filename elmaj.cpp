/*

     Moore’s Voting Algorithm - implemented by Je

*/
#include<fstream>
#define MAXN 1000001
#define FIN "elmaj.in"
#define FOUT "elmaj.out"
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int v[MAXN];
int n;


int main()
{
    f >> n;
    //init first element
    f >> v[1];
    int candidate = 1;
    int votes = 1;

    for(int i=2; i<=n; i++)
    {
        f >> v[i];

        if(v[candidate] == v[i])
        {
            votes++;
        }
        else
        {
            votes--;
        }

        if(votes == 0)
        {
            candidate = i;
            votes = 1;
        }

    }

    int counter = 0;
    //cehck if is majority
    for(int i=1; i<=n; i++)
    {
        if(v[i] == v[candidate])
            counter++;
    }

    if(counter > n/2)
    {
        g << v[candidate] << " " << counter;
    }
    else
    {
        g << "-1";
    }



    return 0;
}
