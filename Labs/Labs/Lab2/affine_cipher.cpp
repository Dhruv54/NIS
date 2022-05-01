#include <iostream>
using namespace std;

bool gcd(int key, int number)
{
    while (key > 0)
    {
        int temp = key;
        key = number % key;
        number = temp;
    }
    if (number == 1)
        return true;
    else
        return false;
}

int multiplicative_inverse(int a, int b)
{
    int q, r, t, t1 = 0, t2 = 1, r1, r2;
    r1 = b;
    r2 = a;
    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    if (r1 == 1)
    {
        if (t1 < 0)
            t1 += b;
        return t1;
    }
    else // gcd!=1
        return 0;
}

string encrypt(string plainText, int key1, int key2)
{
    string encryptText;
    for (int i = 0; i < plainText.length(); i++)
    {
        int textMap = plainText[i];
        if (isupper(textMap))
            textMap -= 'A';
        else
            textMap -= 'a';
        encryptText += (textMap * key1 + key2) % 26 + 'A';
    }
    return encryptText;
}

string decrypt(string encryptText, int key1, int key2)
{
    int InverseKey1 = multiplicative_inverse(key1, 26);
    string decryptText;
    for (int i = 0; i < encryptText.length(); i++)
    {
        int textMap = encryptText[i] - 'A';
        textMap = ((textMap - key2) * InverseKey1) % 26;
        if (textMap < 0)
            textMap += 26;
        decryptText += textMap + 'a';
    }
    return decryptText;
}

int main()
{
    string plainText;
    cout << "Enter plain Text:\n";
    cin >> plainText;
    int key1, key2;
    cout << "Enter Key1:";
    cin >> key1;
    while (!gcd(key1, 26))
    {
        cout << "again Enter key becuse this key multiplicative inverse not possible:";
        cin >> key1;
    }
    cout << "Enter Key2:";
    cin >> key2;
    string encryptText = encrypt(plainText, key1, key2);
    cout << "Encrypt Text:" << encryptText << endl;
    cout << "Decrypt Text:" << decrypt(encryptText, key1, key2);
}