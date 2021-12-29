#include <bits/stdc++.h>

using namespace std;

string caesar_encryption(string s, int key)
{
    string encrypt = "";
    int len = s.length();

    for (int i = 0; i < len; i++)
    {   
        encrypt.insert(encrypt.end(), (s[i] +key)%256 );
    }

    return encrypt;
}

string caesar_decryption(string encrypt,int key)
{
    string  decrypt = "";

    int len = encrypt.length();

    for (int i = 0; i < len; i++)
    {
        int t = (encrypt[i] - key) % 256;

        if (t < 0)
            t += 256;
        decrypt.insert(decrypt.end(), t);
    }

    return decrypt;
}

// int main()
// {

//     string s;
//     int key;

//     cout << "Enter Text\n";
//     cin >> s;

//     cout << "Enter Key\n";
//     cin >> key;
//     key %= 26;

//     string encrypt = encryption(s,key), decrypt;

//     cout << "encrypted Text is " << encrypt << endl;

//     decrypt = decryption(encrypt,key);


//     cout << "cryptoanalysis\n";

//     for(int i=1;i<=26;i++)
//     {
//         cout << "key " << i << " : text " << decryption(encrypt,i) << endl; 
//     }
//     return 0;
// }