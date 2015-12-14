#include<iostream>
#include<string.h>
using namespace std;

char word[302];
char match[] = {'P', 'E', 'R'};

int main()
{
    cin >> word;
    int switches = 0;
    for(int i=0, l = strlen(word); i < l; i++)
    {
        if(word[i] != match[i%3])
            switches++;

    }

    cout << switches;


}
