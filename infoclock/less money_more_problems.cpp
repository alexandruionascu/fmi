#include<iostream>
#include<fstream>
#include<deque>
#define FIN "problems.in"
#define FOUT "problems.out"
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);


long long t, c, v, d;
deque<long long> deq;

int main()
{
    f >> t;

    for(int i=1; i<=t; i++)
    {
        f >> c;
        f >> d;
        f >> v;

        int x;
        for(int j=1; j <= d; j++)
        {
            f >> x;
            deq.push_back(x);
        }

        long long sum = 0;
        int counter = 0;

        while(sum < v)
        {
            if(deq.empty() || deq.front() > sum + 1)
            {
                counter++;
                deq.push_front(sum + 1);
            }
            else
            {
                sum += c * deq.front();
                deq.pop_front();
            }
        }

        g << "Case #" << i << ": " << counter << "\n";


        deq.clear();
    }

    return 0;
}
