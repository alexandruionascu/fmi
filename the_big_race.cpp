#include<iostream>
#include<algorithm>
using namespace std;

unsigned long long t, w, b;

int main()
{
    cin >> t;
    cin >> w;
    cin >> b;

    bool found = false;
    unsigned long long i = max(w, b) - 1;


    while(!found)
    {
        i++;

        if(i % w == i % b)
        {
            found = true;
        }
    }

    unsigned long possible = t / i;

    cout << i << " " << t;
}
