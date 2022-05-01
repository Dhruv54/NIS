#include <bits/stdc++.h>
#define FAST                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
#define ll long long
#define v vector<ll>
#define loop(var, s, n) for (ll var = s; var < n; var++)
#define rloop(var, s, n) for (ll var = s; var >= n; var--)
#define pb push_back
#define br cout << endl;
using namespace std;

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

v primitiveRoot(v z_star, ll p)
{
	v roots;
	loop(i, 1, p - 1)
	{
		loop(j, 1, p)
		{
			// cout<<z[i]<<" ";
			if (squareMultiply(z_star[i], j, p) == 1)
			{
				if (j < p - 2)
					break;
				else
					roots.pb(z_star[i]);
			}
		}
		// br
	}
	return roots;
}

ll multiplicativeInverse(ll a, ll b)
{
	ll q, r, t, t1 = 0, t2 = 1, r1 = b, r2 = a;
	while (r2 > 0)
	{
		q = r1 / r2;
		r = r1 - q * r2;
		r1 = r2;
		r2 = r;
		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	if (r1 == 1)
	{
		if (t1 < 0)
			t1 += b;
		return t1;
	}
	else
		return -1;
}

ll randomNumberInRange(ll n, ll m) // m not included and n included
{
	srand(time(0));
	ll random = n + rand() % (m - n - 1);
	return random;
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

v encrypt(v z_star,ll e1, ll e2, ll m, ll p)
{
	v c(2);
	ll r = z_star[randomNumberInRange(0, p-1)];
	cout<< "\tr = " << r;br
	c[0] = squareMultiply(e1, r, p);
	c[1] = (squareMultiply(e2, r, p) * m) % p;
	return c;
}

ll decrypt(v c, ll p, ll d)
{
	return (multiplicativeInverse(squareMultiply(c[0], d, p), p) * c[1]) % p;
}

int main()
{

	// #ifdef SHUBHAM
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	// FAST

	ll p;
	while (1)
	{
		cout << "Enter the large prime number: ";
		cin >> p;
		if (!isPrime(p))
			cout << p << " is not a prime number so , ";
		else
			break;
	}

	// key -- gereration ----

	v z_star;
	loop(i, 1, p) z_star.pb(i);
	// cout<<z_star.size()<<" ";
	// loop(i,0,z_star.size())
	// 	cout<<z_star[i]<<" ";
	// br

	v roots = primitiveRoot(z_star, p);
	// loop(i,0,roots.size()) cout<<roots[i]<<" ";br
	// cout<<roots.size();br

	ll d = z_star[randomNumberInRange(0, p-1)];
	ll e1 = roots[randomNumberInRange(0, roots.size())];
	ll e2 = squareMultiply(e1, d, p);

	cout << "public key : \n\te1 = " << e1;br
	cout<< "\te2 = " << e2;br
	cout<< "\tp = " << p;br
	cout<< "private key : \n\td = " << d;br

	ll m;
	while (1)
	{
		cout << "Enter the message less than prime number: ";
		cin >> m;
		if (m >= p)
			cout << m << " is not less than " << p << " a prime number so , ";
		else
			break;
	}

	v cipher = encrypt(z_star,e1, e2, m, p);
	cout << "Encryption numbers: " << cipher[0] << " and " << cipher[1];br
	cout<< "Decryption message: " << decrypt(cipher, p, d);br 
	return 0;
}