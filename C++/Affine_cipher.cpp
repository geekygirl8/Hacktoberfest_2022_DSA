#include<bits/stdc++.h>
using namespace std;

const int a = 17;
const int b = 20;

string encryption(string plaintext) {
    string cipher = "";
    for(int i = 0; i < plaintext.length(); i++) {
        if(plaintext[i] != ' ') {
            cipher += (char)((((plaintext[i] - 'a') * a) + b) % 26 + 'a');
        }
        else {
            cipher += plaintext[i];
        }
    }
    return cipher;
}

string decryption(string cipher) {
    string plaintext = "";
    int a_inv = 0, flag = 0;

    for(int i = 0; i < 26; i++) {
        flag = (a*i)%26;
        if(flag == 1) a_inv = i;
    }
    for(int i = 0; i < cipher.length(); i++) {
        if(cipher[i] != ' ') {
            plaintext += (char)(((a_inv*((cipher[i]+'a'-b))%26))+'a');
        }
        else {
            plaintext += cipher[i];
        }
    }
    return plaintext;
}

int main() {
    string plaintext, ciphertext;
    cout << "SELECT OPTION:\n";
    cout << "[1] Encrypt the message\n[2] Decrypt the message\n";
    int choice;
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter the message: ";
            cin >> plaintext;
            ciphertext = encryption(plaintext);
            cout << "Ciphertext: " << ciphertext << endl;
            break;
        case 2:
            cout << "Enter the ciphertext: ";
            cin >> ciphertext;
            plaintext = decryption(ciphertext);
            cout << "Plaintext: " << plaintext << endl;
            break;
        default:
            cout << "Invalid choice\n";
    }
    return 0;
}