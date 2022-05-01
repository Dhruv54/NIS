#include<iostream>
using namespace std;

int multiplicative_inverse(int a,int b){
    int q,r,t,t1=0,t2=1,r1=b,r2=a;
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
    return 0;
}

int main(){
    int a,b;
    cout<<"Enter two number:"<<endl;
    cin>>a>>b;
    if(int ans = multiplicative_inverse(a,b)){
        cout<<"Multiplicative inverse is "<<ans;
    }
    else
    {
        cout<<"Multiplicative inverse not possible";
    }
}