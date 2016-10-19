#include<bits/stdc++.h>
#define IN f
#define OUT cout
#define ASCII 'a'
using namespace std;

ifstream f("data.in");
ofstream g("data.out");

const int SIGMA = 27;

struct Vertex {
  int count = 0;
  Vertex* children[SIGMA];
};

struct Trie {
  Vertex root;

  void insert(const string& word) {
    insert(word, &root, 0);
  }

  void insert(const string& word, Vertex* vertex, unsigned int index) {
    auto ch = word[index] - ASCII;
    if(vertex->children[ch] == NULL) {
      vertex->children[ch] = new Vertex();
    }
    vertex = vertex->children[ch];
    if(index == word.size() - 1) {
      vertex->count++;
    } else {
      insert(word, vertex, index + 1);
    }
  }

  int count(const string& word) {
    return count(word, &root, 0);
  }

  int count(const string& word, Vertex* vertex, unsigned int index) {
    if(vertex == NULL) {
      return 0;
    }
    if(index == word.size() - 1) {
      return vertex->count;
    }

    vertex = vertex->children[word[index] - ASCII];
    return count(word, vertex, index + 1);
  }


};

int main() {
  Trie tr;
  tr.insert("mama");
  tr.insert("fuego");
  cout << tr.count("fuego");
}
