#include <iostream>
#include <string>
using namespace std;

int Modulo(int a, int n)
{
    int moduloN = a % n;
    if (moduloN < 0)
        moduloN += n;
    return moduloN;
}

string Encrypt(int key, string plainText)
{
    string cipherText;
    int lengthOfText = plainText.length() , textMap;
    for (int i = 0; i < lengthOfText; i++)
    {
        if (isupper(plainText[i]))
            textMap = plainText[i] - 'A';
        else
            textMap = plainText[i] - 'a';
        cipherText += Modulo(textMap + key, 26) + 'A';
    }
    return cipherText;
}

string Decrypt(int key, string cipherText)
{
    string plainText;
    int lengthOfCipher = cipherText.length() , textMap;
    for (int i = 0; i < lengthOfCipher; i++)
    {
        textMap = cipherText[i] - 'A';
        plainText += Modulo(textMap - key, 26) + 'a';
    }
    return plainText;
}

int main()
{
    string plainText;
    cout << "Enter Plain Text:" << endl;
    cin >> plainText;
    
    int key;
    cout << "Enter Key:";
    cin >> key;
    
    string encryptText = Encrypt(key, plainText);
    cout << "Encrypt Text:" << encryptText << endl;
    cout << "Decrypt Text:" << Decrypt(key, encryptText) << endl << endl;
    
    // Cryptanalysis using brute force
    cout << "Enter cipher Text:";
    string cipherText;
    cin >> cipherText;
    for (int i = 1; i < 26; i++)
        cout << "key:" << i << " " << Decrypt(i, cipherText) << endl;
    return 0;
}