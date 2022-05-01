#include<iostream>
using namespace std;
#define ll long long

ll squareMultiply(ll base, ll exp,ll mod)//base^exp(% mod)
{
    ll z=1;
    while(exp>0)
    {
        if(exp%2==1)
            z=(z*base)%mod;
        exp=exp/2;
        base=(base*base)%mod;
    }
    return z;
}

int main()
{
    ll num,exp,modeNum;
    cout<<"Enter number , Exponential Number and Mode Number : ";
    cin>>num>>exp>>modeNum;
    cout<<num<<"^"<<exp<<" mode "<<modeNum<<": "<<squareMultiply(num,exp,modeNum);
}