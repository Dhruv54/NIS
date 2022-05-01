#include <bits/stdc++.h>
using namespace std;
#define BITS 3              
#define DIMS 4              
#define MSG DIMS *DIMS *BITS 
vector<vector<int>> lsb_embed(vector<vector<int>> img,bitset<MSG> num)
{
    for (int i = 0, k = 0; i < DIMS; i++)
    {
        for (int j = 0; j < DIMS; j++)
        {
            bitset<8> t(img[i][j]);
            for (int l = BITS - 1; l >= 0; l--, k++)
            {
                t[l] = num[MSG - 1 - k];
            }
            string t1 = t.to_string();
            img[i][j] = stoi(t1, 0, 2);
        }
    }
    return img;
}
float MSE(vector<vector<int>> img, vector<vector<int>> stegoImg)
{
    float sum = 0;
    for (int i = 0; i < DIMS; i++)
    {
        for (int j = 0; j < DIMS; j++)
        {
            sum += pow(img[i][j] - stegoImg[i][j], 2);
        }
    }
    return (sum / (DIMS * DIMS));
}
float PSNR(float mse)
{
    float temp = pow(255, 2) / mse;
    return (10 * log10(temp));
}
long long extract(vector<vector<int>> stegoImg)
{
    string msg = "";
    for (int i = 0; i < DIMS; i++)
    {
        for (int j = 0; j < DIMS; j++)
        {
            bitset<8> t(stegoImg[i][j]);
            for (int l = BITS - 1; l >= 0; l--)
                msg += to_string(t[l]);
        }
    }
    return stoll(msg, 0, 2);
}
int main()
{
    long long n;
    cout << "Enter number in decimal:";
    cin >> n;
    bitset<MSG> num(n);
    cout << "Enter cover Image:\n";
    auto img = vector<vector<int>>(DIMS, vector<int>(DIMS));
    for (int i = 0; i < DIMS; i++)
        for (int j = 0; j < DIMS; j++)
            cin >> img[i][j];
    vector<vector<int>> stegoImg = lsb_embed(img, num);
    cout << "\nStego Image:\n";
    for (vector<int> vect1D : stegoImg)
    {
        for (int pix : vect1D)
        {
            cout << pix << " ";
        }
        cout << endl;
    }
    cout << "\nMSE:";
    float mse = MSE(img, stegoImg);
    cout << mse;
    cout << "\nPSNR:";
    cout << PSNR(mse);
    cout << "\nextracted From Stego Image:";
    cout << extract(stegoImg);

    return 0;
}