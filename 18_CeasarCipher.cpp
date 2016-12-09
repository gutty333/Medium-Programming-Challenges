// For this challenge you will transform a string using the Caesar Cipher.
// have the function CaesarCipher(str,num) take the str parameter and perform a Caesar Cipher shift on it using the num parameter as the shifting number. A Caesar Cipher works by shifting each letter in the string N places down in the alphabet (in this case N will be num). Punctuation, spaces, and capitalization should remain intact. For example if the string is "Caesar Cipher" and num is 2 the output should be "Ecguct Ekrjgt". 

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string CaesarCipher(string str, int num) {

	for (int x = 0; x < str.length(); x++)
	{
		// Ignore punctuation, spaces, etc
		if ((int(str[x]) >= 32 && int(str[x]) <= 64) || (int(str[x]) >= 91 && int(str[x]) <= 96))
		{
			continue;
		}
		// Make the shift if it is a letter
		else if ((str[x] >= 'a' && str[x] <= 'z') || (str[x] >= 'A' && str[x] <= 'Z'))
		{
			// Make sure that after the shift the new character is a letter
			if ((int(str[x]) + num >= 91 && int(str[x]) + num <= 96) || (int(str[x]) + num >= 123))
			{
				int number; 
				// Determine whether the letter is upper case or lower case
				if (islower(str[x]))
				{
					number = (int(str[x]) + num) - 122;
					str[x] = char(number + 96);
				}
				else if (isupper(str[x]))
				{
					number = (int(str[x]) + num) - 90;
					str[x] = char(number + 64);
				}
			}
			else
			{
				str[x] = char(num + int(str[x]));
			}
		}
	}
	return str;
}

int main() {

	// keep this function call here
	cout << CaesarCipher("Hello",4) << endl; // Lipps
	cout << CaesarCipher("abc",0) << endl; // abc
	cout << CaesarCipher("Caesar Cipher",2) << endl; // Ecguct Ekrjgt
	cout << CaesarCipher("dogs", 8) << endl;
	cout << CaesarCipher("byte", 13) << endl;
	return 0;

}