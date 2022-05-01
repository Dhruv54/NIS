#include<bits/stdc++.h>
using namespace std;

int mode(int a,int n)
{
    int modeN=a%n;
    if(modeN<0)
    modeN+=n;
    return modeN;
}

string encrypt(int key,string plainText){
    string cipherText;
    int i,textMap;
    transform(plainText.begin(), plainText.end(),plainText.begin(), ::toupper);
    for(i=0;i<plainText.length();i++){
        textMap=plainText[i]-'A';
        cipherText+=mode(textMap+key,26)+'A';
        key=textMap;
    }
    return cipherText;
}

string decrypt(int key,string cipherText){
    string plainText;
    int i,textMap;
    for(i=0;i<cipherText.length();i++){
        textMap=cipherText[i]-'A';
        plainText+=mode(textMap-key,26)+'a';
        key=plainText[i]-'a';
    }
    return plainText;
}

int main(){
    string plainText;
    cout<<"Enter Plain Text:";
    cin>>plainText;
    int key;
    cout<<"Enter Key:";
    cin>>key;
    string encryptText= encrypt(key,plainText);
    cout<<"Encrypt Text:"<<encryptText<<endl;
    cout<<"Decrypt Text:"<<decrypt(key,encryptText);
    return 0;
}