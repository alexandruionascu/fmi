#include<fstream>
#include<map>
#include<string.h>
#define FIN "random.in"
#define FOUT "random.out"
using namespace std;
 
ifstream f(FIN);
ofstream g(FOUT);
 
map<int, string> m;
 
int main()
{
    m[1982] = "Robert Tarjan";
    m[1986] = "Leslie Valiant";
    m[1990] = "Alexander Razborov";
    m[1994] = "Avi Wigderson";
    m[1998] = "Peter Shor";
    m[2002] = "Madhu Sudan";
    m[2006] = "Jon Kleinberg";
    m[2010] = "Daniel Spielman";
    m[2014] = "Subhash Khot";
 
    int x;
    f >> x;
    g << m[x];
    return 0;
}