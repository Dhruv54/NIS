#include <iostream>
#include<cstring>
using namespace std;

int array[256];

string decryption(string cipherText)
{
    string plainText="";
    for(int i=0;i<=cipherText.length();i++)
    {
        for(int j='a';j<='z';j++)
        {
            if(array[j]==cipherText[i])
                plainText=plainText+char(j);
        }
    }
    return plainText;
}

string encryption(string pt)
{
    string encryptText="";
    for(int i=0;i<=pt.length();i++)
    {
        encryptText=encryptText+char(array[pt[i]]);
    }
    return encryptText;
}

int main() {

    string substitution="qwertyuiopasdfghjklzxcvbnm";
    int k=0;
    for(int i='a';i<='z';i++)
    {
        array[i]=substitution[k];
        k++;
    }
    for(int i='a';i<='z';i++)
    {
        cout<<char(i)<<" ";
    }
    cout<<endl;
    for(int i='a';i<='z';i++)
    {
        cout<<char(array[i])<<" ";
    }
    cout<<endl;
    string pt="ceddit";

    string cipherText=encryption(pt);
    cout<<"Encrypt Text : "<<cipherText<<endl;
    
    string plainText=decryption(cipherText);
    cout<<"Plain Text : "<<plainText<<endl;

    return 0;
}