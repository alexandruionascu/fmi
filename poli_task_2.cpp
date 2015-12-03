//Cate palindroame mai mici decat X se pot scrie ca produs de 2 numere diferite de P cifre

#include <stdio.h>
#include <math.h>

//returneaza numarul rasturnat
int rasturnatul(int n,int r)
{
  if(n == 0) return r;
  else return rasturnatul(n/10, r*10+n%10);
}

int main()
{
   int X, P;
   //citesc P si X
   scanf("%d %d", &P, &X);

   //numarul palindroamelor mai mici decat X cu proprietatea cautata
   int nr = 0;
   //luam toate numerele mai mici decat X
   for(int k=1; k<X; k++)
   {
        //verificam daca este palindrom
        if(rasturnatul(k, 0) == k)
        {

            //luam toate produsele de 2 numere diferite de P-2 cifre
            //10^(P-2) e primul numar care are P cifre
            for(double i = pow(10, P-2); i < pow(10, P-1); i++)
            {

                //J = i pentru a nu inmulti de 2 ori i * j si j * i, astfel mereu va fi (i <= j)
                for(double j = i; j < pow(10, P-1) / 2; j++)
                {
                    if(i != j && i * j == k)
                    {
                        nr++;
                        printf("%d x %d = %d \n", i, j, k);
                    }
                    //daca produsul numerelor de P cifre e mai mare, sarim peste J, trecem la urmatorul I
                    if(i * j > k)
                        break;
                }
            }
        }
   }

   printf("%d \n",nr);
   return 0;
}

