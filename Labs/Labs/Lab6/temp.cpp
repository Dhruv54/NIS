#include <bits/stdc++.h>
using namespace std;
// #define v2d vector<vector<int>>
// #define v1d vector<int>

int mod(int a)
{
    int modN = a % 26;
    if (modN < 0)
        modN += 26;
    return modN;
}

// string removeSpaces(string str)
// {
//     str.erase(remove(str.begin(), str.end(), ' '), str.end());
//     return str;
// }

// int multiplicativeInverse(int a, int b)
// {
//     int q, r, t, t1 = 0, t2 = 1, r1 = b, r2 = a;
//     while (r2 > 0)
//     {
//         q = r1 / r2;
//         r = r1 - q * r2;
//         r1 = r2;
//         r2 = r;
//         t = t1 - q * t2;
//         t1 = t2;
//         t2 = t;
//     }
//     if (r1 == 1)
//     {
//         if (t1 < 0)
//             t1 += b;
//         return t1;
//     }
//     else
//         return -1;
// }

// v2d getCofactor(v2d mat, int p, int q, int n)
// {
// 	cout<<"in getCofactor  "<<n<<endl;
//     v2d ans(n-1);
//     int i = 0, j = 0;
//     ans[0] = v1d(n-1);
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col < n; col++)
//         {
//             if (row != p && col != q)
//             {
//                 ans[i][j] = mat[row][col];
//                 j++;
//                 if (j == n - 1)
//                 {
//                     j = 0;
//                     i++;
//                     ans[i] = v1d(n-1);
//                 }
//             }
//         }
//     }
// 	cout<<"out getCofactor"<<endl;

//     return ans;
// }

// int determinantOfMatrix(v2d mat, int n)
// {
// 	cout<<"in determinantOfMatrix"<<endl;

//     int ans = 0; // for storing result
//     if (n == 1)  // base case
//         return mat[0][0];

//     v2d temp; // for storing cofactor

//     int sign = 1; // to store sign multiplier

//     for (int i = 0; i < n; i++)
//     {
//         temp = getCofactor(mat, 0, i, n);
//         ans += sign * mat[0][i] * determinantOfMatrix(temp, n - 1);
//         sign = -sign;
//     }
// 	cout<<"out determinantOfMatrix"<<endl;

//     return ans;
// }
// v2d transposeOfMatrix(v2d mat, int n, int m)
// {
// 	cout<<"in transposeOfMatrix"<<endl;

//     v2d ans(n);
//     for (int i = 0; i < n; i++)
//     {
//         ans[i] = v1d(m);
//         for (int j = 0; j < m; j++)
//         {
//             ans[i][j] = mat[j][i];
//         }
//     }
// 	cout<<"out transposeOfMatrix"<<endl;

//     return ans;
// }
// v2d adjointOfMatrix(v2d mat, int n)
// {
// 	cout<<"in adjointOfMatrix"<<endl;

// 	if(n == 1)
// 		return mat;
//     v2d ans(n);
//     for (int i = 0; i < n; i++)
//     {
//         ans[i] = v1d(n);
//         for (int j = 0; j < n; j++)
//         {
//             v2d temp = getCofactor(mat, i, j, n);
//             int a = determinantOfMatrix(temp, n - 1);
//             ans[i][j] = pow(-1, i + j + 2) * a;
//         }
//     }
//     ans = transposeOfMatrix(ans, n, n);
// 	cout<<"out adjointOfMatrix"<<endl;

//     return ans;
// }
// v2d inverseMatrix(v2d mat, int n)
// {
//     v2d temp = adjointOfMatrix(mat, n);
//     int det = mod(determinantOfMatrix(mat, n));
//     det = multiplicativeInverse(det, 26);
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             temp[i][j] = mod(temp[i][j] * det);
//     return temp;
// }

// string multiply_Text_X_Key(string text, v2d key, int n)
// {
//     string resultText;
//     int i = 0;
//     while (i < text.size())
//     {
//         v1d t(n);
//         for (int j = 0; j < n; j++, i++)
//             t[j] = text[i] - 'a';
//         for (int j = 0; j < n; j++)
//         {
//             int ans = 0;
//             for (int k = 0; k < n; k++)
//                 ans += t[k] * key[k][j];
//             resultText += mod(ans) + 'a';
//         }
//     }
//     return resultText;
// }

// string encrypt(string plainText, v2d key, int n)
// {
//     while (plainText.size() % n != 0)
//         plainText += "z";
//     string cipherText = multiply_Text_X_Key(plainText, key, n);
//     return cipherText;
// }

// string decrypt(string cipherText, v2d key, int n)
// {
//     // int **ans = new int *[n];
//     // for (int i = 0; i < n; i++)
//     // {
//     //     ans[i] = new int[n];
//     //     for (int j = 0; j < n; j++)
//     //     {
//     //         ans[i][j] = key[i][j];
//     //     }
//     //     cout << endl;
//     // }
//     v2d key_inverse = inverseMatrix(key, n);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout<<key_inverse[i][j]<<" ";
//             // key[i][j] = key_inverse[i][j];

//         }
//         cout << endl;
//     }
//     string plainText = multiply_Text_X_Key(cipherText, key_inverse, n);
//     return plainText;
// }

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    
    cout<<gcd(mod(-939),26);
//     int n;
//     cout << "Enter key size : ";
//     cin >> n;
//     v2d key(n);
//     cout << "Enter Key : \n";
//     for (int i = 0; i < n; i++)
//     {
//         key[i] = v1d(n);
//         for (int j = 0; j < n; j++)
//             cin >> key[i][j];
//     }

//     string plainText;
//     cout << "Enter plain text : ";
//     cin >> ws;
//     getline(cin, plainText);
//     plainText = removeSpaces(plainText);
//     string encryptText = encrypt(plainText, key, n);
//     cout << "Cipher Text : " << encryptText << endl;
//     cout << "Decrypt Text:" << decrypt(encryptText,key,n);
}