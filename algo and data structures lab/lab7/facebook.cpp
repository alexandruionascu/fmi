#include<bits/stdc++.h>
#define in f
#define out g
#define MOD 666013
#define INF 1 << 30
using namespace std;


ifstream f("facebook.in");
ofstream g("facebook.out");

typedef struct  Data {
    int value;
    int items;
};

vector<Data> H[MOD];
int n, k;
int minim = INF;

void insert(int x, int index) {
    int key = x % MOD;
    bool exists = false;

    for(int i = 0; i < H[key].size(); i++) {

        if(H[key][i].value == x) {

            H[key][i].items++;
            exists = true;

            if(H[key][i].items >= k) {

                int cost = index - k;

                if(cost < minim)
                    minim = cost;

            }

            break;

        }


    }

    if(exists == false) {
        Data data;
        data.value = x;
        data.items = 1;
        H[key].push_back(data);
    }
}

int main() {
    in >> n;
    in >> k;

    int x;
    for(int i = 1; i <= n; i++) {
        in >> x;
        insert(x, i);
    }

    if(minim == INF)
        out << -1;
    else out << minim;

    return 0;
}
