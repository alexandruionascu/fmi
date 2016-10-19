#include<fstream>
#include<map>
using namespace std;

#define FIN "hashuri.in"
#define FOUT "hashuri.out"

ifstream f(FIN);
ofstream g(FOUT);

map<int,int> m;
int n;

int main()
{
    int x,y;
    map<int,int>::iterator it;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x;
        f>>y;

        switch(x)
        {
        case 1:
            m[y] = 1;
            break;
        case 2:
            m.erase(y);
            break;
        case 3:
            it=m.find(y);
            if(it!=m.end())
            {
                g<<1<<endl;
            }
            else g<<0<<endl;
        }
    }

    return 0;
}
