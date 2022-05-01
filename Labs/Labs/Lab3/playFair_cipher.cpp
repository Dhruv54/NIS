#include <bits/stdc++.h>
using namespace std;

int keyMatrix[5][5];

class Pointer
{
public:
    int x;
    int y;
};

void findInMatrix(char a,char b,Pointer p[])
{
    if (a == 'J')
        a = 'I';
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (keyMatrix[i][j] == a)
            {
                p[0].x = i;
                p[0].y = j;
            }
            else if (keyMatrix[i][j] == b)
            {
                p[1].x = i;
                p[1].y = j;
            }
}

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int mode(int a, int n)
{
    int modeN = a % n;
    if (modeN < 0)
        modeN += n;
    return modeN;
}

void generateMatrix(string key)
{
    int i, j, k = 0, l = key.length();
    char s = 'A';
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5;)
        {
            if (k < l)
            {
                keyMatrix[i][j] = key[k];
                k++;
                j++;
            }
            else
            {
                if (s == 'J')
                    s++;
                if (key.find(s) == string::npos)
                {
                    keyMatrix[i][j] = s;
                    s++;
                    j++;
                }
                else
                    s++;
            }
        }
    }
}
string encrypt(string plainText)
{
    int l = plainText.length(), i, j;
    string encryptText;
    if (l % 2 != 0)
    {
        plainText[l] = 'z';
    }
    for (i = 0; i < l; i++)
    {
        Pointer p[2];
        findInMatrix(toupper(plainText[i]),toupper(plainText[i+1]),p);
        i++;
        if (p[0].x == p[1].x)
        {
            encryptText += keyMatrix[p[0].x][mode(p[0].y + 1, 5)];
            encryptText += keyMatrix[p[0].x][mode(p[1].y + 1, 5)];
        }
        else if (p[0].y == p[1].y)
        {
            encryptText += keyMatrix[mode(p[0].x + 1, 5)][p[0].y];
            encryptText += keyMatrix[mode(p[1].x + 1, 5)][p[0].y];
        }
        else
        {
            encryptText += keyMatrix[p[0].x][p[1].y];
            encryptText += keyMatrix[p[1].x][p[0].y];
        }
    }
    return encryptText;
}

string decrypt(string cipherText)
{
    int l = cipherText.length(), i, j;
    string decryptText;
    for (i = 0; i < l; i++)
    {
        Pointer p[2];
        findInMatrix(cipherText[i],cipherText[i+1],p);
        i++;
        if (p[0].x == p[1].x)
        {
            decryptText += keyMatrix[p[0].x][mode(p[0].y - 1, 5)];
            decryptText += keyMatrix[p[0].x][mode(p[1].y - 1, 5)];
        }
        else if (p[0].y == p[1].y)
        {
            decryptText += keyMatrix[mode(p[0].x - 1, 5)][p[0].y];
            decryptText += keyMatrix[mode(p[1].x - 1, 5)][p[0].y];
        }
        else
        {
            decryptText += keyMatrix[p[0].x][p[1].y];
            decryptText += keyMatrix[p[1].x][p[0].y];
        }
    }
    transform(decryptText.begin(), decryptText.end(), decryptText.begin(), ::tolower);
    return decryptText;
}

int main()
{
    string plainText, key = "MONARCHY";
    generateMatrix(key);
    cout << "Plain Text:";
    getline(cin, plainText);
    plainText = removeSpaces(plainText);
    string encryptText = encrypt(plainText);
    cout << "Cipher Text:" << encryptText << endl;
    cout << "Decrypt Text:" << decrypt(encryptText);
}