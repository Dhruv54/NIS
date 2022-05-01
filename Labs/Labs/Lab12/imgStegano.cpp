#include <bits/stdc++.h>
using namespace std;
#define DIMS 4         // image dimensions
#define MSG DIMS *DIMS // input number size(in bits)
#define v2D vector<vector<int>>

v2D lsbEmbed(v2D img, bitset<MSG> num)
{
    for (int i = 0, k = 0; i < DIMS; i++)
    {
        for (int j = 0; j < DIMS; j++, k++)
        {
            bitset<8> t(img[i][j]); // convert decimal to binary
            t[0] = num[15 - k]; // assign bit to img pixel lsb bit
            string t1 = t.to_string();
            img[i][j] = stoi(t1, 0, 2); // convert binary to decimal
        }
    }
    return img;
}

float MSE(v2D img,v2D stegoImg)
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

int extract(v2D stegoImg)
{
    string msg = "";
    for (int i = 0; i < DIMS; i++)
    {
        for (int j = 0; j < DIMS; j++)
        {
            bitset<8> t(stegoImg[i][j]);
            msg += to_string(t[0]);
        }
    }
    return stoi(msg, 0, 2);
}

int main()
{
    int n, x;
    cout << "Enter number(decimal): ";
    cin >> n;
    bitset<MSG> num(n);
    cout << "Enter cover Image:\n";
    auto img = v2D(DIMS, vector<int>(DIMS));
    for (int i = 0; i < DIMS; i++)
        for (int j = 0; j < DIMS; j++)
            cin >> img[i][j];
    v2D stegoImg = lsbEmbed(img, num);
    cout << "\nStego Image:\n";
    for (vector<int> vect1D : stegoImg)
    {
        for (int pix : vect1D)
            cout << pix << " ";
        cout << endl;
    }
    cout << "\nMSE: ";
    float mse = MSE(img, stegoImg);
    cout << mse;
    cout << "\nPSNR: ";
    cout << PSNR(mse);
    cout << "\nExtracted From Stego Image: ";
    cout << extract(stegoImg);
}