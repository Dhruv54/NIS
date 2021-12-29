#include <iostream>
#include "./multiplicative_cipher.cpp"
// #include "./ceasercipher.cpp"
using namespace std;

string caesar_encryption(string str, int key)
{
    string encryptText = "";
    int size = str.length();
    for (int i = 0; i < size; i++)
    {   
        encryptText=encryptText+char((str[i]+key)%256);
    }
    return encryptText;
}

string caesar_decryption(string encrypt,int key)
{
    string  decryptText = "";
    int size = encrypt.length();
    for (int i = 0; i < size; i++)
    {
        int t = (encrypt[i] - key) % 256;
        if (t < 0)
            t=t+256;
        decryptText=decryptText+char(t);
    }
    return decryptText;
}

int main()
{
    string str;
    int key;
    cout << "Enter Text :- ";
    cin>>str;
    cout << "Enter Key :- ";
    cin >> key;
    // key=key%256;

    string encrypt = multiplicative_encryption(str, 7);
    encrypt = caesar_encryption(encrypt, key);
    cout << "encrypted Text is " << encrypt << endl;

    string decrypt = caesar_decryption(encrypt, key);
    decrypt = multiplicative_decryption(decrypt, 7);
    cout <<"decrypted Text is "<< decrypt << endl;

    return 0;
}