/*
* Leo Ceralde
* CIS-7 Online
* 7 June 2022
* Final Project: Vigenere Cipher
*/

// Objectives:
// 1. program that encrypts/decrypts user input message
// 2. Test program to verify output accuracy. Address limitations
// 3. Provide documentation for approach

#include <iostream>

using namespace std;

string Keygen(string str, string key) {
	int g = str.size();

	// no condition statement, breaks when key size = size of message
	for (int i = 0; ; i++) {
		if (g == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	
	return key;
}

string encryptedText(string str, string key) {
	string encrypt_text;

	for (int i = 0; i < str.size(); i++) {
		// converting with range 0-25
		char n = (str[i] + key[i]) % 26;

		// converting back into alphabet (ASCII)
		n += 'A';

		encrypt_text.push_back(n);
	}

	return encrypt_text;
}

// decrypter, returns original text
string originalText(string encrypt_text, string key) {
	string orText;

	for (int i = 0; i < encrypt_text.size(); i++) {
		// converting with range 0-25
		char n = (encrypt_text[i] - key[i] + 26) % 26;

		// converting back into alphabet (ASCII)
		n += 'A';

		orText.push_back(n);
	}

	return orText;
}

int main() {
	string str;
	char choice = 'y';

	// Display Welcome Message
	cout << "Hello! This program is designed to use the Vigenere Cipher to\nencrypt and decrypt the message. The encrypted and decrypted text, " <<
		"as we the key, will be displayed.\n\n";

	do {
		// Prompt User input for message
		cout << "Please enter your message (all uppercase, no spaces): ";
		cin >> str;

		// Keyword "MARIO" for this program, can be interchanged
		string keyword = "MARIOPARTY";

		string key = Keygen(str, keyword);
		string encrypt_text = encryptedText(str, key);

		// Display Ciphered text, Original/Decrypted Text
		cout << "Encrypted Text: " << encrypt_text << endl;
		cout << "Original Text: " << originalText(encrypt_text, key);
		cout << endl << endl;

		// Prompt to enter a new message
		cout << "Would you like to enter a new message? (y/n): ";
		cin >> choice;

		cout << endl << endl;
	} while (choice == 'y' || choice == 'Y');

	// Farewell Message
	cout << "Thank you for using this program. Have a great summer!" << endl << endl;

	return 0;
}

// Post-Note: Can only take messages with no spaces, and only in ALL CAPS.