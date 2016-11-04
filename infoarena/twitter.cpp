#include<bits/stdc++.h>
#define asciiA (int)'A'
#define asciia (int)'a'
#define asciiZ (int)'Z'
#define asciiz (int)'z'
#define SIGMA 27
#define in f
#define out cout
using namespace std;

int getDistance(char signature, char encrypted) {
  int distance = 0;
  while(signature != encrypted) {
  //  out << "Signature : " << signature << " Encrypted : " << encrypted << endl;
    if((int)encrypted == asciiA) {
      encrypted = (char)asciiZ;
      distance++;
      continue;
    }

    if((int)encrypted == asciia) {
      distance++;
      encrypted = (char)asciiz;
      continue;
    }

    encrypted--;

    distance++;
  }

  return distance;
}

char revertLetter(char letter, int distance) {
  out << "rev letter " << letter  << " " << distance << endl;
  if(distance == 0) {
    return letter;
  } else {
    if((int)letter == asciia) {
      return revertLetter((char)asciiz, distance - 1);
    }

    if((int)letter == asciiA) {
      return revertLetter((char)asciiZ, distance - 1);
    }

    return revertLetter(letter - 1, distance - 1);
  }
}

string decryptText(string text) {
  int key[] = {8, 2, 5, 1, 2, 2, 0};
  int keyIndex = 0;
  for(int i = 0; i < text.size(); i++) {
    if(text[i] >= asciiA && text[i] <= asciiZ) {
      text[i] = revertLetter(text[i], key[keyIndex]);
      keyIndex++;
      keyIndex %= 7;
    }

    if(text[i] >= asciia && text[i] <= asciiz) {
      text[i] = revertLetter(text[i], key[keyIndex]);
      keyIndex++;
      keyIndex %= 7;
    }
  }

  return text;
}

int main() {
  string signature = "-Your friend, Alice";
  string encrypted = "-Atvt hrqgse, Cnikg";

  for(int i = 0; i < encrypted.size(); i++) {
    if(encrypted[i] >= asciiA && encrypted[i] <= asciiZ) {
      out << getDistance(signature[i], encrypted[i]) << " ";
    }

    if(encrypted[i] >= asciia && encrypted[i] <= asciiz) {
      out << getDistance(signature[i], encrypted[i]) << " ";
    }
  }

  out << decryptText("Bjj rwkcs");
}
