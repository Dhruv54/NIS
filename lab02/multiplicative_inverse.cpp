#include <iostream>

using namespace std;

int multiplicative_inverse(int a, int b)
{
    int r1 = a, r2 = b;
    int t1 = 0, t2 = 1;

    while (r2 > 0)
    {
        int q = r1 / r2;
        int r = r1 - q * r2;

        r1 = r2;
        r2 = r;

        int t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (r1 == 1)
    {
        if(t1>0)
            return t1;
        else
            return t1+a;
        // return t1 > 0 ? t1:t1+a;
    }

    return 0;
}

// int main()
// {
//     int r1=26;
//     int r2=11;
//     int inverse=multiplicative_inverse(r1,r2);
//     int result=(r2*inverse)%r1;
//     cout<<"Multiplication Inverse of "<<r2<<" in z"<<r1<<" is :- "<<inverse<<" and (r2*inverse)mod r1 :-"<<result<<endl;
//     return 0;
// }