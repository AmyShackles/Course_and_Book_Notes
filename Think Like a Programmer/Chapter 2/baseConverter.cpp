

#include <iostream>
using std::cin;
using std::cout;

// If entering a binary number, preface with 0b (e.g.: 0b100111111011001)
// If entering a hexadecimal number, preface with 0x (e.g.: 0xDEADBEEF)
// If entering an octal number, preface with 0 (e.g.: 077)

int inferBase(char digitChar) {
  if (digitChar == 'b') {
    return 2;
  } else if (digitChar == 'x') {
    return 16;
  } else {
    return 8;
  }
}

long long digitValue(char digitChar) {
  if (digitChar > '9') {
    // The capitalized alphabet is offset from '0' - '9' by 7 numbers.
    // If we subtract '0' from a letter, we're 7 digits off from where we should
    // be For example, 'B' in ASCII is 66, '0' is 48 66 - 48 = 18, but 'B'
    // represents 11.
    digitChar = (digitChar - '0') - 7;
  } else {
    digitChar = digitChar - '0';
  }
  return digitChar;
}

long long readNum() {
  int base;
  long long number = 0;
  char digitChar = cin.get();

  if (digitChar == '0') {
    // Have to read next digit here or we'll lose an octal's first digit
    digitChar = cin.get();
    base = inferBase(digitChar);
  } else {
    base = 10;
  }
  if (base == 16 || base == 2) {
    // Need to get next digit for base 16 and base 2
    // ... because current digit is still just information about base
    digitChar = cin.get();
  }
  number = digitValue(digitChar);
  digitChar = cin.get();
  while (digitChar != '\n') {
    number = number * base + digitValue(digitChar);
    digitChar = cin.get();
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
  long long dec;
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

  // Need to keep this first test of whether or not the digitChar is '0' here
  // because if it's moved to the inferBase function,
  // we lose access to the first real index of an octal value
  // (as it will only exist in inferBase)

  dec = readNum();
  binary = intToBaseString(dec, 2);
  ternary = intToBaseString(dec, 3);
  quaternary = intToBaseString(dec, 4);
  quinary = intToBaseString(dec, 5);
  senary = intToBaseString(dec, 6);
  octal = intToBaseString(dec, 8);
  decimal = intToBaseString(dec, 10);
  duodecimal = intToBaseString(dec, 12);
  hexadecimal = intToBaseString(dec, 16);
  vigesimal = intToBaseString(dec, 20);
  base36 = intToBaseString(dec, 36);

  cout << "Number entered in binary (base 2): " << binary << "\n";
  cout << "Number entered in ternary (base 3): " << ternary << "\n";
  cout << "Number entered in quaternary (base 4): " << quaternary << "\n";
  cout << "Number entered in quinary (base 5): " << quinary << "\n";
  cout << "Number entered in senary (base 6): " << senary << "\n";
  cout << "Number entered in octal (base 8): " << octal << "\n";
  cout << "Number entered in decimal (base 10): " << decimal << "\n";
  cout << "Number entered in duodecimal (base 12): " << duodecimal << "\n";
  cout << "Number entered in hexadecimal (base 16): " << hexadecimal << "\n";
  cout << "Number entered in vigesimal (base 20): " << vigesimal << "\n";
  cout << "Number entered in base 36: " << base36 << "\n";
}