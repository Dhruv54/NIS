#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int multiplicativeInverse(int a, int b)
{
    int q, r, t, t1 = 0, t2 = 1, r1 = b, r2 = a;
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

bool isIncreasingSequence(vector<int> v)
{
    int sum = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        // cout<<sum<<" ";
        if (sum >= v[i])
            return false;
        else
            sum += v[i];
    }
    return true;
}

vector<int> DecToBinary(int n)
{
    vector<int> binaryNum;

    while (n > 0)
    {
        binaryNum.insert(binaryNum.begin(), n % 2);
        n /= 2;
    }
    return binaryNum;
}

vector<int> encrypt(int message, vector<int> a)
{
    vector<int> X = DecToBinary(message) , sum;
    cout << "Binary of message '" << message << "' = ";
    print(X);
    
    while (X.size() % a.size() != 0)
        X.insert(X.begin(), 0);
    
    for (int i = 0, k = 0; k < X.size(); i++)
    {
        sum.push_back(0);
        for (int j = 0; j < a.size() && k < X.size(); j++, k++)
        {
            if (X[k])
                sum[i] += a[j];
        }
    }
    return sum;
}

int decrypt(int w, int m, vector<int> a_dash, int n, vector<int> encryption)
{
    int w_inverse = multiplicativeInverse(w, m);

    if (w_inverse != -1)
    {
        cout << "Multiplicative Inverse of 'w = " << w << "' = " << w_inverse << endl;
        string X = "";
        for (int i = encryption.size() - 1; i >= 0; i--)
        {
            int sum = (w_inverse * encryption[i]) % m;
            // cout << "Sum=" << sum << endl;
            for (int i = n - 1; i >= 0; i--)
            {
                if (sum >= a_dash[i])
                {
                    X = "1" + X;
                    sum -= a_dash[i];
                }
                else
                    X = "0" + X;
            }

            if (sum != 0)
            {
                cout << "\nDecryption not possible\n";
                return -1;
            }
        }
        cout << "Binary of Decryption message = " << X << endl;
        return stoi(X, 0, 2); // convert binary to decimal
    }
    else
    {
        cout << "\nMultiplicative Inverse of '" << w << "' is not possible !\n";
        return -1;
    }
}

int main()
{
    int n;
    cout << "Enter total number of item in a' :- ";
    cin >> n;
    vector<int> a_dash(n, 0);
    cout << "Enter Super Increasing Sequence for a' :- ";
    for (int i = 0; i < n; i++)
        cin >> a_dash[i];

    if (isIncreasingSequence(a_dash))
    {
        int m = accumulate(a_dash.begin(), a_dash.end(), 1), w = 2;
        while (gcd(m, w) != 1)
            w++;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = (w * a_dash[i]) % m;

        cout << "\nPrivate Key : \nm = " << m << endl;
        cout << "w = " << w << endl;
        cout << "a_dash = ";
        print(a_dash);
        cout << "\nPublic Key : \na = ";
        print(a);

        int msg = 14;
        cout << "\nEnter Message :- ";
        cin >> msg;
        // cout << "Message = " << msg << endl;

        cout << "\nEncryption :\n";
        vector<int> cipher = encrypt(msg, a);
        cout << "Encryption of '" << msg << "' is:- ";
        print(cipher);

        cout << "\nDecryption :\n";
        cout << "Decryption of Message is:- " << decrypt(w, m, a_dash, n, cipher) << endl;
    }
    else
        cout << "\nEntered sequence is not Increasing Sequence !" << endl;

    return 0;
}