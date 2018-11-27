## Problem: Decode a Message

A message has been encoded as a text stream that is to be read character by character. The stream contains a series of comma-delimited integers, each a positive number capable of being represented by a C++ int. However, the character represented by a particular integer depends on the current decoding mode. There are three modes: uppercase, lowercase, and punctuation.

In uppercase mode, each integer represents an uppercase letter: The integer modulo 27 indicates the letter of the alphabet (where 1 = A and so on). So an input value of 143 in uppercase mode would yield the letter H because 143 module 27 is 8 and H is the eighth letter in the alphabet.

The lowercase mode works the same but with lowercase letters; the remainder of dividing the integer by 27 represents the lowercase letter (1 = a and so on). So an input value of 56 in lowercase mode would yield b because 56 modulo 27 is 2 and b is the second letter of the alphabet.

In punctuation mode, the integer is instead considered modulo 9, with the interpretation given by Table 2-3 below. So 19 would yield an exclamation point because 19 modulo 9 is 1.

At the beginning of each message, the decoding mode is uppercase ltters. Each time the modulo operation (by 27 or 9 depending on mode) results in 0, the decoding mode switches. If the current mode is uppercase, the mode switches to lowercase letters. If the current mode is lowercase, the mode switches to punctuation, and if the current mode is punctuation, it switches back to uppercase.

#### Table 2-3: Punctuation Decoding Mode

| Number | Symbol  |
| ------ | ------- |
| 1      | !       |
| 2      | ?       |
| 3      | ,       |
| 4      | .       |
| 5      | (space) |
| 6      | ;       |
| 7      | "       |
| 8      | '       |

#### My Notes on Problem - Restate Problem with Constraints

1. Read a text stream character by character
2. Characters are separated by commas
3. Program starts in Uppercase decode mode
4. Start decoding characters by performing modulo 27 and using corresponding letter - 1 = A, etc.
5. If integer modulo 27 == 0, switch to Lowercase decode mode
6. Continue processing characters using modulo 27, though now letters are in lowercase
7. If modulo 27 == 0, switch to Punctuation decode mode
8. Continue decoding, but now perform modulo 9 and consult Table 2-3 to find the punctuation mark the character represents
9. If int modulo 9 == 0, switch decode mode to Uppercase
10. Repeat until out of characters to decode (end of line)

#### Notes from Book:

1. Read character by character until you reach the end of the line
2. Convert a series of characters representing a number to an integer
3. Convert an integer 1-26 to an uppercase character
4. Convert an integer 1-26 to a lowercase character
5. Convert an integer 1-8 into a punctuation symbol based on Table 2-3.
6. Tracking a decoding mode

#### Example of the process

Original input: 18, 12312, 171, 763, 98423, 1208, 216, 11, 500, 18, 241, 0, 32, 20620, 27, 10

| (a)   | (b) | (c) | (d) | (e) | (f) |
| ----- | --- | --- | --- | --- | --- |
| 18    | (U) | 27  | 18  | R   |     |
| 12312 | (U) | 27  | 0   | →   | (L) |
| 171   | (L) | 27  | 6   | i   |     |
| 763   | (L) | 27  | 7   | g   |     |
| 98423 | (L) | 27  | 8   | h   |     |
| 1208  | (L) | 27  | 20  | t   |     |
| 216   | (L) | 27  | 0   | →   | (P) |
| 11    | (P) | 9   | 2   | ?   |     |
| 500   | (P) | 9   | 5   |     |     |
| 18    | (P) | 9   | 0   | →   | (U) |
| 241   | (U) | 27  | 25  | Y   |     |
| 0     | (U) | 27  | 0   | →   | (L) |
| 32    | (L) | 27  | 5   | e   |     |
| 20620 | (L) | 27  | 19  | s   |     |
| 27    | (L) | 27  | 0   |     |     |
| 10    | (P) | 9   | 1   | !   |     |

a) Current number in the input

b) Current mode

c) Divisor for the current mode

d) Remainder

e) Decoded character or arrow pointing to new mode

f) Mode switching to
