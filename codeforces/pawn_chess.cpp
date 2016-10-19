#include<fstream>
#include<iostream>
using namespace std;

ifstream f("pawnchess.in");

int blockA[10];
int blockB[10];
char c[10][10];
int A, B;

int solveA()
{
    for(int i=1; i<=8;i++)
    {
        for(int j=1; j<=8; j++)
        {
            if(c[i][j] == 'W' && (blockB[j] == 0 || blockB[j] > i) )
            {
                A = i;
                return 0;
            }
        }
    }
}

int solveB()
{
    for(int i=8; i >= 1; i--)
    {
        for(int j=8; j>= 1; j--)
        {
            if(c[i][j] == 'B' && (blockA[j] == 0 || blockA[j] < i) )
            {
                B = 8 - i + 1;
                return 0;
            }
        }
    }
}

int main()
{
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {

           cin >> c[i][j];
           if(c[i][j] == 'W')
           {
                blockA[j] = i;
           }
           else if(c[i][j] == 'B')
           {
                blockB[j] = i;
           }

        }
    }

    solveA();
    solveB();

    if(A <= B)
    {
        cout << "A";
    } else
    {
        cout << "B";
    }

}
