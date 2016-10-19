#include<iostream>
#include<fstream>
using namespace std;

#define FIN "minute1.in"
#define FOUT "minute1.out"

ifstream f(FIN);
ofstream g(FOUT);

int h1, m1, h2, m2;

int main()
{
    f >> h1;
    f >> m1;
    f >> h2;
    f >> m2;

    int time = h1 * 60;
    time += m1;
    time -= 5 * h2;
    if(m1 / 5 >= h1)
        time -= 5;

    int hours = time / 60;
    time -= hours * 60;

    cout << time << endl;




    //g << h1 << " " << m1;
    return 0;
}
