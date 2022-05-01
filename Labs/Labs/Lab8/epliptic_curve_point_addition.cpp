#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> point;

int p,a,b;

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

int mode(int a,int b)
{
    int ans=a%b;
    if(ans<0)
    ans+=b;
    return ans;
}
point operator+(point p1,point p2)
{
    point p3;
    int x1=p1.first,x2=p2.first,y1=p1.second,y2=p2.second;
    int lamda;
    if(x1!=x2 && y1 !=y2)
    {
        int t=x2-x1,t1=y2-y1;
        if(t<0)
        {
            t1=(-1)*t1;
            t=(-1)*t;
        }
        lamda=mode(t1*multiplicative_inverse(t,p),p);//((y2-y1)/(x2-x1))mode p
    }
    else if(x1==x2 && y1==y2)
    {
        lamda=mode((3*x1*x1+a)*multiplicative_inverse(2*y1,p),p);
    }
    p3.first=mode((lamda*lamda-x1-x2),p);// x3=(lamda^2 - x1 - x2)mode p
    p3.second=mode(lamda*(x1-p3.first)-y1,p);// y3=(lamda(x1-x3) - y1)mode p
    return p3;
}
point operator*(point p1,int n)
{
    point ans;
    ans.first=p1.first;
    ans.second=p1.second;

    while(n>1)
    {
        ans=ans+p1;
        n--;
    }
    return ans;
}
int main()
{
    a=1,b=1,p=13;
    point p1=make_pair(11,11);
    point p2=make_pair(1,4);
    point p=p2*17;
    cout<<p.first<<" "<<p.second;

}