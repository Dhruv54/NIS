#include<iostream>
#include <cstring>
using namespace std;
int array[256];
void cryptAnalysis(string cipher)
{
    int pikmode26[cipher.length()],key,cik[cipher.length()],cikmode26[cipher.length()],j=1;
    while (j!=26)
    {
        for (int i = 0; i < cipher.length(); i++)
        {
            pikmode26[i]=array[int(cipher[i])];
            key=j;
            cik[i]=pikmode26[i]-key;
            if(cik[i]>=0)
                cikmode26[i]=cik[i]%26;
            else
                cikmode26[i]=cik[i]+26;
        }
        int k=0;
        string ch="";
        for(int j=0;j< cipher.length();j++)
        {
            for (int i = 'a'; i <='z'; i++)
            {
                if(cikmode26[k]==array[i])
                {
                    ch=ch+char(i);
                    k++;
                }
            }
        }
        cout<<ch<<endl;
        j++;
    }
}
string encryption(string pt)
{
    int pv[pt.length()],key=17,pt_plus_k[pt.length()],ptkmode26[pt.length()];
    for(int i=0;i<pt.length();i++)
    {
        pv[i]=array[int(pt[i])];
        pt_plus_k[i]=pv[i]+key;
        ptkmode26[i]=pt_plus_k[i]%26;
    }
    string cipherText="";
    int k=0;
    while (k<pt.length())
    {
        for (int i = 'a'; i <='z'; i++)
        {
            if(array[i]==ptkmode26[k])
            {
                cipherText=cipherText+char(i);
                k++;
            }
        }
    }
    for (int i = 0; i <  pt.length(); i++)
        cout<<pt[i]<<"   ";
    cout<<endl;
    for (int i = 0; i <  pt.length(); i++)
        cout<<pv[i]<<"   ";
    cout<<endl;
    for (int i = 0; i <  pt.length(); i++)
        cout<<key<<"   ";
    cout<<endl;
    for (int i = 0; i <  pt.length(); i++)
        cout<<pt_plus_k[i]<<"   ";
    cout<<endl;
    for (int i = 0; i <  pt.length(); i++)
        cout<<ptkmode26[i]<<"   ";
    cout<<endl;
    for (int i = 0; i <  pt.length(); i++)
        cout<<char(toupper(cipherText[i]))<<"   ";
    cout<<endl;
    
    return cipherText;
}

string decryption(string cipherText)
{
    int cv[cipherText.length()],key=17,ct_minus_k[cipherText.length()],ctkmode26[cipherText.length()];
    for(int i=0;i<cipherText.length();i++)
    {
        cv[i]=array[int(cipherText[i])];
        ct_minus_k[i]=cv[i]-key;
        if(ct_minus_k[i]>=0)
        {
            ctkmode26[i]=ct_minus_k[i]%26;
        }
        else
        {
            ctkmode26[i]=ct_minus_k[i]+26;
        }
    }
    string plainText="";
    int k=0;
    while (k<cipherText.length())
    {
        for (int i = 'a'; i <='z'; i++)
        {
            if(array[i]==ctkmode26[k])
            {
                plainText=plainText+char(i);
                k++;
            }
        }
    }
    for (int i = 0; i <  cipherText.length(); i++)
        cout<<char(toupper(cipherText[i]))<<"   ";
    cout<<endl;
    for (int i = 0; i <  cipherText.length(); i++)
        cout<<cv[i]<<"   ";
    cout<<endl;
    for (int i = 0; i <  cipherText.length(); i++)
        cout<<key<<"   ";
    cout<<endl;
    for (int i = 0; i <  cipherText.length(); i++)
        cout<<ct_minus_k[i]<<"   ";
    cout<<endl;
    for (int i = 0; i <  cipherText.length(); i++)
        cout<<ctkmode26[i]<<"   ";
    cout<<endl;
    for (int i = 0; i <  cipherText.length(); i++)
        cout<<plainText[i]<<"   ";
    cout<<endl;

    return plainText;
}
int main()
{
    int j=0;
    for (int i = 'a'; i <='z'; i++)
    {
        array[i]=j;
        j++;
    }
    string pt="ceddit";
    cout<<"Encryption Table :"<<endl<<endl;
    string cipherText=encryption(pt);
    cout<<"Encrypted Text :"<<cipherText<<endl<<endl;
    cout<<"Decryption Table :"<<endl<<endl;
    string plainText=decryption(cipherText);
    cout<<"Plain Text: "<<plainText<<endl<<endl;;
    cout<<"Possible patterns : "<<endl;
    cryptAnalysis(cipherText);
    return 0;
}