#include <iostream>
#include "./multiplicative_inverse.cpp"

using namespace std;

string multiplicative_encryption(string text, int key)
{
    int size = text.length();
    string encryptedText="";
    for (int i = 0; i < size; i++)
    {
        encryptedText=encryptedText+char(text[i]*key);
    }
    return encryptedText;
}

string multiplicative_decryption(string encrypted, int key)
{
    int size = encrypted.length();
    int inverseKey = multiplicative_inverse(256, key);
    string decryptedText="";
    for (int i = 0; i < size; i++)
    {
        decryptedText=decryptedText+char(encrypted[i] * inverseKey);
    }
    return decryptedText;
}
// int main()
// {
//     string text;
//     int key=7;
//     cin>>text;
//     string encrypted = multiplicative_encryption(text, key);
//     cout << "Encrypted Text is: " << encrypted << endl;
//     cout << "Decrypted Text is: " << multiplicative_decryption(encrypted, key);
//     return 0;
// }