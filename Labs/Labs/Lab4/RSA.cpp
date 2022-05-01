#include<bits/stdc++.h>
using namespace std;

long long squareMultiply(long long base, long long exp, long long mod)//base^exp(% mod)
{
    long long z=1;
    while(exp>0)
    {
        if(exp%2==1)
            z=(z*base)%mod;
        exp=exp/2;
        base=(base*base)%mod;
    }
    return z;
}

int randomNumberBetweenRange(int n,int m)//n and m not included
{
    int num;
    srand(time(0));
    while(true)
    {
        num=rand()%m;
        if(num>n)
        break;
    }
    return num;
}

bool millerRabin(int n)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    int d=n-1,i=0,k,m,a;
    while(d%2==0)
    {
        d/=2;
        i++;
    }
    k=i;
    d=n-1;
    m=d/pow(2,k);
    a=randomNumberBetweenRange(1,d);
    int b=squareMultiply(a,m,n);
    if(b%n==1)
    {
        return true;//n is prime
    }
    for(i=0;i<k;i++)
        if(b%n==d)//b%n==-1
            return true; //n is prime
        else
            b=(b*b)%n;
    return false;//n is composite
}


int multiplicative_inverse(int a,int b){
    int q,r,t,t1=0,t2=1,r1,r2;
    r1=b;
    r2=a;
    while(r2>0){
        q=r1/r2;
        r=r1-q*r2;
        r1=r2;
        r2=r;
        t=t1-q*t2;
        t1=t2;
        t2=t;
    }
    if(r1==1)
    {
        if(t1<0)
        t1+=b;
        return t1;
    }
    else//gcd!=1
    return 0;
}

void keyGenerate(long long *key)
{
    int p,q,n;
    srand(time(0));
    while(true)
    {
        p=rand();
        q=rand();
        if(p!=q && millerRabin(p) && millerRabin(q))
        {
            break;
        }
    }
    n=p*q;
    int fi=(p-1)*(q-1),e,d;
    while(true)
    {
        e=randomNumberBetweenRange(1,fi);
        // e=5;
        d=multiplicative_inverse(e,fi);
        if(d!=0)
        break;
    }
    key[0]=e;
    key[1]=d;
    key[2]=n;
    key[3]=p;
    key[4]=q;
}

long long encrypt(long long num,long long publicKey,long long modeNum)
{
    return squareMultiply(num,publicKey,modeNum);
}

long long decrypt(long long encryptNum,long long privateKey,long long modeNum)
{
    return squareMultiply(encryptNum,privateKey,modeNum);
}

int main()
{
    long long num;
    cout<<"Enter Number:";
    cin>>num;
    long long key[5];
    keyGenerate(key);//key[0]=public key,key[1]=private key,key[2]=n,key[3]=p,key[4]=q;
    cout<<"public key="<<key[0]<<" private key="<<key[1]<<" n="<<key[2]<<endl;
    cout<<"p="<<key[3]<<" q="<<key[4]<<endl;
    long long encryptNum=encrypt(num,key[0],key[2]);
    cout<<"encrypt Number:"<<encryptNum<<endl;
    cout<<"decrypt Number:"<<decrypt(encryptNum,key[1],key[2]);
}