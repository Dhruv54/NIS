#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll  long long
#define loop(var,s,n) for(ll var=s ;var<n;var++)
// #define rloop(var,s,n) for(ll var=s ;var>=n;var--)
#define pb push_back
#define br cout<<endl;
using namespace std;

// ll randomNumberBetweenRange(int a,int b) {
// 	srand(time(NULL));
// 	ll random = 49%b;
//     // rand()%b;
// 	if(random < a)
// 		random += a;
// 	return random%b;
// }

ll randomNumberBetweenRange(ll n,ll m)//m not included
{
    srand(time(0));
    ll random = n + 1 % (m-n-1);
    return random;
}


bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i +=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

int main() {
    // int m,p=10;
    // while(1) {
	// 	cout<<"Enter the message less than prime number: ";
	// 	cin >> m;
	// 	if(m>p) 
	// 		cout << m << " is not less than "<<p<<" a prime number so , ";
	// 	else 
	// 		break;
	// }
    cout<<randomNumberBetweenRange(0,5);
}