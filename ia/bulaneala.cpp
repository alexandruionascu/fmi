#include <bits/stdc++.h>
using namespace std;

ifstream trainFile("trainVectors.txt");
ifstream labelFile("labels.txt");
ifstream testFile("test.txt");
ofstream g("output.csv");


long double v[10000][405];
int labels[10000];
long double test[10000][405];
int n = 9873;
int m = 400;
int testLength = 5476;
int c[10000];
const int MAX_ERROR = 1 << 30;
bool blat[10000];


int classify(long double* u, int k) {
  priority_queue< pair<long double, int> > q;
  long double bestError = MAX_ERROR;
  long double score[6] = {0, 0, 0, 0, 0, 0};
  int label = 1;
  for (int i = 1; i <= n; i++) {
    long double current = 0;

    for (int j = 1; j <= m; j++) {
      current += (v[i][j] - u[j]) * (v[i][j] - u[j])  * (v[i][j] - u[j])  * (v[i][j] - u[j]);
    }

    if(current < bestError) {
      bestError = current;
      label = labels[i];
    }
    q.push({current * (long double)-1, i});
  }


  for (int i = 1; i <= k; i++) {
    score[labels[q.top().second]]++;
    q.pop();
  }

 int maxx = score[1];

  for(int i = 2; i <= 5; i++) {
    if (score[i] > maxx) {
      maxx = score[i];
      label = i;
    }
  }
  return label;
}

int main() {
  g << "Id,Prediction" << "\n";

  for (int i = 1; i <= 6500; i++) {
    for (int j = 1; j <= m; j++) {
      trainFile >> v[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    labelFile >> labels[i];
    c[labels[i]]++;
  }


/*  for (int i = 1; i <= testLength; i++) {
    for (int j = 1; j <= m; j++) {
      testFile >> test[i][j];
    }
  } */

  int offset = 6000;

  for (int i = 6501; i <= n; i++) {
    for (int j = 1; j <= 400; j++) {
      trainFile >> test[i][j];
    }
  }

  double good = 0;
  double bad = 0;

  for (int i = 6501; i <= n; i++) {
    int label = classify(test[i], 30);
    if (label == labels[i]) {
      good++;
    } else {
      bad++;
    }

    g << i << "," << label << "\n";
    cout << "classified " << i << " " << label << endl;
    cout << "Score " << (good / (good + bad)) * 100 << " %" << endl;
  }


}
