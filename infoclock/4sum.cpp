#include<bits/stdc++.h>
#define in f
#define out cout
using namespace std;

ifstream f("date.in");
int n;
vector<int> v;

void read() {
    in >> n;
    int x;
    for(int i = 1; i <=n ;  i++) {
        in >> x;
        v.push_back(x);
    }
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<int> sums;
    unordered_map<int, int> h;
    vector<vector<int>> result;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            sums.push_back(v[i] + v[j]);
            h[v[i] + v[j]] = sums.size();
        }
    }

    for(int i = 0; i < sums.size(); i++) {
        if(h.find(target - sums[i]) != h.end()) {
            int j = h.find(target - sum[i]);
            vector<int> aux;
            aux.push_back();

        }
    }
}

void printArray(vector<vector<int>>& v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            out << v[i][j] << " ";
        }

        out << "\n";
    }
}



int main()
{

    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);

    vector< vector<int> > a = fourSum(v, 3);
}
