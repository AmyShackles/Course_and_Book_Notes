#include <iostream>
#include <string>
using std::cin;
using std::cout;

char *getEncoded() {
  char cipherArray[26] = {'Q', 'F', 'L', 'X', 'J', 'T', 'A', 'I', 'P',
                          'G', 'W', 'R', 'C', 'O', 'V', 'M', 'Z', 'N',
                          'H', 'B', 'K', 'D', 'S', 'Y', 'U', 'E'};
  int i = 0;
  char *text = new char[1024];
  char character = cin.get();
  while (character != '\n') {
    if (character >= 'A' && character <= 'z') {
      if (character >= 'A' && character <= 'Z') {
        character = (character - 'A');
      } else if (character >= 'a' && character <= 'z') {
        character = (character - 'a');
      }
      text[i] = cipherArray[character];
    } else {
      text[i] = character;
    }
    character = cin.get();
    i++;
  }
  text[i] = '\0';
  return text;
}

char *getDecoded(char *cipher) {
  char cipherArray[26] = {'Q', 'F', 'L', 'X', 'J', 'T', 'A', 'I', 'P',
                          'G', 'W', 'R', 'C', 'O', 'V', 'M', 'Z', 'N',
                          'H', 'B', 'K', 'D', 'S', 'Y', 'U', 'E'};

  char *text = new char[1024];
  int i = 0;
  int j = 0;
  while (cipher[i] != '\n') {
    for (int j = 0; j < 26; j++) {
      if (cipher[i] == cipherArray[j]) {
        if (i == 0) {
          text[i] = j + 'A';
        } else {
          text[i] = j + 'a';
        }
      } else if (cipher[i] < 'A') {
        text[i] = cipher[i];
      }
    }
    i++;
  }
  text[i] = '\0';
  return text;
}

int main() {
  cout << "Enter a message to encode: ";
  char *cipher = getEncoded();
  char *plaintext = getDecoded(cipher);
  cout << cipher << "\n";
  cout << "Was your original message: " << plaintext << "?\n";
  return 0;
}