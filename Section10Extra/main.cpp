// Letter Pyramid
// Written by Gabriel Faustino de Araujo

#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Enter a string of characters to form a pyramid of it: ";
    string input {};
    getline(cin, input);

    string line (input.length(), ' ');
    string reverse_line {};
    
    for (size_t i = 0; i < input.length(); i++) {
        line.erase(0, 1);
        reverse_line = line;
        reverse(reverse_line.begin(), reverse_line.end());
        line += input[i];
        
        cout << line << reverse_line << "\n";
    }

    return 0;
}
