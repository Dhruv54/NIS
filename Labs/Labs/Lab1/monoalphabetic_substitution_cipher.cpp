#include <bits/stdc++.h>
using namespace std;

vector<int> generateKey() {
    vector<int> key;
    int n = 26,i; 
    for (i = 0; i < n; i++)
        key.push_back(i);
    for (i = n - 1; i > 0; i--)
    {
        srand((unsigned int)time(NULL));
        int j = rand() % i;
        int temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }
    cout << "\nMap : ";
    for (i = 0; i < n; i++)
        cout << char(i + 'A') << " ";
    cout << "\nKey : ";
    for (i = 0; i < n; i++)
        cout << char(key[i] + 'A') << " ";
    cout << "\n\n";
    return key;
}

string monoalphabeticCipher(string plainText)
{
    vector<int> key = generateKey();
    string encryptText;
    for (int i = 0; i < plainText.length(); i++)
    {
        if (isupper(plainText[i])) 
        {
            int a = plainText[i] - 'A';
            encryptText += key[a] + 'A';
        }
        else
        {
            int a = plainText[i] - 'a';
            encryptText += key[a] + 'A';
        }
    }
    return encryptText;
}

int main()
{
    string plainText , encryptText;
    cout << "Enter Plain Text : ";
    cin >> plainText;
    encryptText = monoalphabeticCipher(plainText);
    cout << "Encrypt Text : " << encryptText;
}