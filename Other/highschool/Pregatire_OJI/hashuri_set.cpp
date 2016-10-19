#include<fstream>
#include<set>
using namespace std;

#define FIN "hashuri.in"
#define FOUT "hashuri.out"

ifstream f(FIN);
ofstream g(FOUT);

set<int> s;
int n;

int main()
{
    int x,y;
    set<int>::iterator it;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x;
        f>>y;

        switch(x)
        {
        case 1:
            s.insert(y);
            break;
        case 2:
            s.erase(y);
            break;
        case 3:
            it=s.find(y);
            if(it!=s.end())
            {
                g<<1<<endl;
            }
            else g<<0<<endl;
        }
    }

    return 0;
}
