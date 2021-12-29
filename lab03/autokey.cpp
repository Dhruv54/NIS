#include<iostream>
using namespace std;
int array[256];

string autoDecryption(string cipherText,int keyArr[],int size)
{
    string decryptText="";
    int plainText[size];
    for (int i = 0; i < size; i++)
    {
        plainText[i]=(array[cipherText[i]]-keyArr[i])%26;
        if(plainText[i]<0)
        {
            plainText[i]=plainText[i]+26;
        }
    }
    int k=0;
    int i='a';
    while(k!=size)
    {
        if(array[i]==plainText[k])
        {
            decryptText=decryptText+char(i);
            k++;
            i='a';
        }
        i++;
    }
    return decryptText;
}
string autoEncryption(string plainText,int keyArr[],int size)
{
    string encryptText="";
    int cipherText[size];
    for (int i = 0; i < size; i++)
    {
        cipherText[i]=(array[plainText[i]]+keyArr[i])%26;
    }
    int k=0;
    int i='a';
    while(k!=size)
    {
        if(array[i]==cipherText[k])
        {
            encryptText=encryptText+char(i);
            k++;
            i='a';
        }
        i++;
    }
    return encryptText;
}

int main()
{
    int j=0;
    for (int i = 'a'; i <='z'; i++)
    {
        array[i]=j;
        j++;
    }
    string plainText="ceddit";
    int size=plainText.length();
    int keyArr[size];
    keyArr[0]=12;
    for (int i = 0; i < size-1; i++)
    {
        keyArr[i+1]=array[plainText[i]];
    }
    cout<<"Original Plain Text :- "<<plainText<<endl;
    string encryptText=autoEncryption(plainText,keyArr,size);
    cout<<"Auto Encryption Text :- "<<encryptText<<endl;
    string decryptText=autoDecryption(encryptText,keyArr,size);
    cout<<"Auto Decryption Text :- "<<decryptText<<endl;
    return 0;
}