// Section 10
// Challenge -
// Substitution Cipher

/*
A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted_message message.
Then decryped the encrypted_message message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.

Have fun! And make the cipher stronger if you wish!
Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
This could also be improved.

Remember, the less code you write the less code you have to test!
Reuse existing functionality in libraries and in the std::string class!
*/

#include <iostream>
#include <string>

using namespace std;

string encrypting (string message, string alphabet, string key){
    
    string encrypted_message {};
    
    for(auto c : message){
        size_t position = alphabet.find(c);
        if (position != string::npos){
            encrypted_message += key[position];
        } else {
            encrypted_message += c;
        }
    }
    
    return encrypted_message;
}

string decrypting (string message, string alphabet, string key){
    
    string decrypted_message {};
    
    for(size_t i = 0; i < message.length(); i++) {
        size_t position = key.find(message[i]);
        if(position != string::npos) {
            decrypted_message += alphabet[position];
        } else {
            decrypted_message += message[i];
        }
    }
    
    return decrypted_message;
}

int main() {

    string alphabet { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    string key { "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" };

    cout << "Enter your secret message: ";
    string message {};
    getline(cin, message);
    cout << "\n";
    
    cout << "Encrypting message...\n\n" ;
    string encrypted_message = encrypting(message, alphabet, key);
    cout << "Encrypted message: " << encrypted_message << "\n\n";
    
    cout << "Decrypting message...\n\n" ;
    string decrypted_message = decrypting(encrypted_message, alphabet, key);
    cout << "Decrypted message: "<< decrypted_message << "\n\n";
    
    return 0;
}
