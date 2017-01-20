#include <cstdio>
using namespace std;
 
#define Nmax 400001
#define Amax 30
#define ValMax 250000
#define Lmax 14
 
FILE *f = fopen ( "zimeria.in", "r" );
FILE *g = fopen ( "zimeria.out", "w" );
 
int cheie[Amax], pw12[5];
char alfa[Lmax], s[Lmax];
int ap[ValMax];
 
void Convert ( int cod ){
 
    s[5] = 0;
    for ( int i = 4; i >= 0; --i ){
        s[i] = alfa[cod % 12];
        cod /= 12;
    }
}
 
 
int main(){
 
    int Task, N, unice = 0;
 
    fscanf ( f, "%d", &Task );
 
    pw12[0] = 1;
    for ( int i = 1; i < 5; ++i )
        pw12[i] =  pw12[i-1] * 12;
 
    fscanf ( f, "%d%*c%s", &N, s );
 
    for ( int i = 0; i < 12; ++i ){
        cheie[s[i]-'a'] = i;
        alfa[i] = s[i];
    }
 
    for ( int i = 0; i < N; ++i ){
        int cod = 0;
        fscanf ( f, "\n%s", s );
 
        for ( int j = 0; j < 5; ++j )
            cod += ( cheie[s[j]-'a'] * pw12[4-j] );
 
        if ( !ap[cod] )
            unice++;
 
        ap[cod]++;
    }
 
    if ( Task == 1 ){
        fprintf ( g, "%d", unice );
    }
    else{
 
        for ( int i = 0; i < ValMax; ++i ){
            if ( ap[i] ){
                Convert(i);
                for ( int j = 1; j <= ap[i]; ++j )
                    fprintf ( g, "%s\n", s );
            }
        }
    }
 
    return 0;
}
