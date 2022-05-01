#include <bits/stdc++.h>
#define ll long long
#define v vector<ll>
#define loop(var, s, n) for (ll var = s; var < n; var++)
#define rloop(var, s, n) for (ll var = s; var >= n; var--)
#define pb push_back
using namespace std;

class Point
{
public:
    ll x, y;
    Point(ll X, ll Y)
    {
        x = X;
        y = Y;
    }

    void print()
    {
        cout<<" ("<< x << ',' << y << ") ";
    }
};

ll squareMultiply(ll base, ll exp, ll mod) // base^exp(% mod)
{
	ll z = 1;
	while (exp > 0)
	{
		if (exp % 2 == 1)
			z = (z * base) % mod;
		exp = exp / 2;
		base = (base * base) % mod;
	}
	return z;
}

bool isPrime(ll n)
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

	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

ll mod(ll a,ll b) {
    ll mode = a % b;
    if(mode < 0)
        mode += b;
    return mode;
}

vector<Point> pointGeneration(ll a, ll b, ll p)
{
    vector<Point> points;
    loop(x,0,p) {
        ll y_square = mod((x*x*x)+(a*x)+b,p);
        ll r = squareMultiply(y_square,(p-1)/2,p);
        if(r == 1) {
            ll y = sqrt(y_square);
            while (y*y != y_square)
            {
                y_square+=p;
                y=sqrt(y_square);
            }
            ll y1 = mod(-y,p);
            points.pb(Point(x,y));
            points.pb(Point(x,y1));
        }
        else if(r == 0)
            points.pb(Point(x,0));
    }
    return points;
}

int main()
{
    ll a, b, p;
    cout<<"Enter a and b :";
    cin >> a >> b;

    while (1)
	{
		cout << "Enter prime number: ";
		cin >> p;
		if (!isPrime(p))
			cout << p << " is not a prime number so , ";
		else
			break;
	}

    vector<Point> points = pointGeneration(a, b, p);
    loop(i, 0, points.size()) points[i].print();
    cout<<endl;
}