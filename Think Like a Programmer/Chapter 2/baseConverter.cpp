#include <iostream>
using std::cin;
using std::cout;

// If entering a binary number, preface with 0b (e.g.: 0b100111111011001)
// If entering a hexadecimal number, preface with 0x (e.g.: 0xDEADBEE)
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
  if ((digitChar - '0') > 9) {
    digitChar = (digitChar - '0') - 7;
  } else {
    digitChar = digitChar - '0';
  }
  return digitChar;
}

long long convertToDecimal(long long number, char digitChar, int base) {
  if (number > 9) {
    number = number - 7;
  }
  while (digitChar != 10) {

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
  char digitChar = cin.get();
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
  int number = 0;
  int base;

  // Need to keep this first test of whether or not the digitChar is '0' here
  // because if it's moved to the inferBase function, we lose access to the
  // first real index of an octal value (as it will only exist in inferBase)
  if ((digitChar - '0') == 0) {
    digitChar = cin.get();
    base = inferBase(digitChar);
  } else {
    base = 10;
  }
  if (base == 16 || base == 2) {
    cout << "Base: " << base << "\n";
    digitChar = cin.get();
    number = (digitChar - '0');
    digitChar = cin.get();
  } else if (base == 10 || base == 8) {
    cout << "Base: " << base << "\n";
    number = (digitChar - '0');
    digitChar = cin.get();
  }
  dec = convertToDecimal(number, digitChar, base);
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