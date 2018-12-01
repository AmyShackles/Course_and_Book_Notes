#include <iostream>
using std::cin;
using std::cout;

// If entering a binary number, preface with 0b (e.g.: 0b100111111011001)
// If entering a hexadecimal number, preface with 0x (e.g.: 0xDEADBEEF)
// If entering an octal number, preface with 0 (e.g.: 077)

int inferBase(char *string) {
  if (string[0] == '0') {
    if (string[1] == 'b') {
      return 2;
    } else if (string[1] == 'x') {
      return 16;
    } else {
      return 8;
    }
  } else {
    return 10;
  }
}

char *parseString(char digitChar) {
  char *string = new char[100];
  int i = 0;
  while (digitChar != '\n') {
    string[i] = digitChar;
    digitChar = cin.get();
    i++;
  }
  string[i] = '\0';
  cout << "String: " << string << "\n";
  return string;
}

long long convertToInt() {
  char digitChar = cin.get();
  char *string = parseString(digitChar);
  int base = inferBase(string);
  long long number = 0;
  int i = 0;
  if (base == 16 || base == 2) {
    // Need to get next digit for base 16 and base 2
    // ... because current digit is still just information about base
    i = 2;
  } else if (base == 8) {
    i = 1;
  }
  while (string[i] != '\0') {
    string[i] = string[i] - '0';
    // The capitalized alphabet is offset from '0' - '9' by 7 numbers.
    // If we subtract '0' from a letter, we're 7 digits off from where we should
    // be For example, 'B' in ASCII is 66, '0' is 48 66 - 48 = 18, but 'B'
    // represents 11.
    if (string[i] > 9) {
      string[i] = string[i] - 7;
    }
    number = number * base + string[i];
    i++;
  }
  return number;
}

char *reverseInPlace(char *str, int endIndex) {
  int startIndex = 0;

  while (startIndex < endIndex) {
    char temp = str[startIndex];
    str[startIndex] = str[endIndex];
    str[endIndex] = temp;
    startIndex++;
    endIndex--;
  }
  return str;
}

char *intToBaseString(long long number, int base) {
  long long remainder;
  char *str = new char[100];
  char *string;
  int i = 0;
  char output;
  while (number != 0) {
    remainder = number % base;
    number /= base;
    if (remainder > 9) {
      // if remainder is greater than int 9, subtract 10
      // this takes you back to 0 in the ASCII table,
      // allowing you to add 'A' to get in range of the alphabet
      output = remainder - 10 + 'A';
      str[i] = output;
    } else {
      str[i] = remainder + '0';
    }
    i++;
  }
  str[i] = '\0';
  string = reverseInPlace(str, i - 1);
  return string;
}

int main() {
  cout << "Enter a number in binary, octal, hexadecimal, or decimal.\nNotes: "
          "Can only handle numbers up to 2147483,647.\nIf entering a binary "
          "number, preface with '0b'.\nIf entering a hexadecimal number, "
          "preface with '0x'.\nIf entering an octal number, preface with "
          "'0'\n>> ";
  long long integer;
  char *binary;
  char *ternary;
  char *quaternary;
  char *quinary;
  char *senary;
  char *octal;
  char *decimal;
  char *duodecimal;
  char *hexadecimal;
  char *vigesimal;
  char *base36;
  int number = 0;
  int base;

  integer = convertToInt();
  binary = intToBaseString(integer, 2);
  ternary = intToBaseString(integer, 3);
  quaternary = intToBaseString(integer, 4);
  quinary = intToBaseString(integer, 5);
  senary = intToBaseString(integer, 6);
  octal = intToBaseString(integer, 8);
  decimal = intToBaseString(integer, 10);
  duodecimal = intToBaseString(integer, 12);
  hexadecimal = intToBaseString(integer, 16);
  vigesimal = intToBaseString(integer, 20);
  base36 = intToBaseString(integer, 36);

  cout << "Number entered (in decimal): " << decimal << "\n";
  cout << "Number entered (in binary): " << binary << "\n";
  cout << "Number entered (in ternary): " << ternary << "\n";
  cout << "Number entered (in quaternary): " << quaternary << "\n";
  cout << "Number entered (in quinary): " << quinary << "\n";
  cout << "Number entered (in senary): " << senary << "\n";
  cout << "Number entered (in octal): " << octal << "\n";
  cout << "Number entered (in duodecimal): " << duodecimal << "\n";
  cout << "Number entered (in hexadecimal): " << hexadecimal << "\n";
  cout << "Number entered (in vigesimal): " << vigesimal << "\n";
  cout << "Number entered (in base 36): " << base36 << "\n";
}