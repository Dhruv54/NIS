#include<iostream>
#include<algorithm>
using namespace std;
int table[5][5];
struct Coordinates
{
    int u;
    int v;
};

void createTable(string plainText)
{
    int size=plainText.length(),k=0,a=0;
    string alphabets="qwertyuiopasdfghklzxcvbnm";
    for(int a=0;a<size;a++)
    {
        alphabets.erase(remove(alphabets.begin(),alphabets.end(),plainText[a]));
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(k!=size)
            {
                table[i][j]=plainText[k];
                k++;
            }
            else{
                table[i][j]=alphabets[a];
                a++;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<char(table[i][j])<<" ";
        }cout<<endl;
    }
}

void search(char ch1,char ch2,struct Coordinates *x,struct Coordinates *y)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(table[i][j]==ch1)
            {
                x->u=i;
                x->v=j;
            }
            if(table[i][j]==ch2)
            {
                y->u=i;
                y->v=j;
            }
        }
    }
}

string playfairEncryption(string plainText)
{
    int size=plainText.length(),i=0,s,t;
    string encryptioText="";
    struct Coordinates x;
    struct Coordinates y;
    while (i!=size)
    {
        search(plainText[i],plainText[i+1],&x,&y);
        cout<<x.u<<x.v<<y.u<<y.v<<endl;
        if(x.u==y.u)
        {
            s=(x.v+1)%5;
            t=(y.v+1)%5;
            encryptioText=encryptioText+char(table[x.u][s]);
            encryptioText=encryptioText+char(table[x.u][t]);
        }
        else if(x.v==y.v)
        {
            s=(x.u+1)%5;
            t=(y.u+1)%5;
            encryptioText=encryptioText+char(table[s][x.v]);
            encryptioText=encryptioText+char(table[t][x.v]);
        }
        else{
            encryptioText=encryptioText+char(table[x.u][y.v]);
            encryptioText=encryptioText+char(table[y.u][x.v]);
        }
        i=i+2;
    }
    return encryptioText;
}
string playfairDecryption(string encrptText)
{
    string plainText="";
    int size=encrptText.length(),i=0,s,t;
    struct Coordinates x;
    struct Coordinates y;
    while (i!=size)
    {
        search(encrptText[i],encrptText[i+1],&x,&y);
        cout<<x.u<<x.v<<y.u<<y.v<<endl;
        if(x.u==y.u)
        {
            s=(x.v-1)%5;
            t=(y.v-1)%5;
            plainText=plainText+char(table[x.u][s]);
            plainText=plainText+char(table[x.u][t]);
        }
        else if(x.v==y.v)
        {
            s=(x.u-1)%5;
            t=(y.u-1)%5;
            plainText=plainText+char(table[s][x.v]);
            plainText=plainText+char(table[t][x.v]);
        }
        else{
            plainText=plainText+char(table[x.u][y.v]);
            plainText=plainText+char(table[y.u][x.v]);
        }
        i=i+2;
    }
    return plainText;
}

int main()
{
    string KeyText="monarchy";
    string plainText="give me more ";
    int l=plainText.length();
    int c=count(plainText.begin(),plainText.end(),' ');
    remove(plainText.begin(),plainText.end(),' ');
    plainText.resize(l-c);
    if(plainText.length()%2!=0)
    {
        plainText.append("z");
    }
    createTable(KeyText);
    cout<<plainText<<endl;
    cout<<"Original Plain Text :- "<<plainText<<endl;
    string encrptText=playfairEncryption(plainText);
    cout<<"Playfair Encryption Text :- "<<encrptText<<endl;
    string decryptText=playfairDecryption(encrptText);
    cout<<"Playfair Decryption Text :- "<<decryptText<<endl;
    return 0;
}