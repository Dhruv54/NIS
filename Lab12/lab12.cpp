#include <bits/stdc++.h>
#include <vector>
using namespace std;

int convertBintoDec(string bin)
{
    int dec = 0;
    for (int i = bin.length() - 1, j = 0; i >= 0; i--, j++)
    {
        if (bin[i] == '1')
        {
            dec += pow(double(2), double(j));
        }
    }
    return dec;
}
string convertDectoBin(int dec)
{
    string bin;
    while (dec != 0)
    {
        bin += to_string(dec % 2);
        dec /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}
vector<vector<int>> embeded(vector<vector<int>> cover, string msg)
{
    vector<vector<int>> stego_obj;
    int index = 0;
    for (int i = 0; i < cover.size(); i++)
    {
        vector<int> row;
        for (int j = 0; j < cover[0].size(); j++)
        {
            string bin = convertDectoBin(cover[i][j]);
            bin[bin.length() - 1] = msg[index];
            cover[i][j] = convertBintoDec(bin);
            row.push_back(cover[i][j]);
            index++;
        }
        stego_obj.push_back(row);
    }
    return stego_obj;
}
string extraction(vector<vector<int>> embeded_cover)
{
    string extracted_msg = "";
    for (int i = 0; i < embeded_cover.size(); i++)
    {
        for (int j = 0; j < embeded_cover[0].size(); j++)
        {
            string bin = convertDectoBin(embeded_cover[i][j]);
            extracted_msg += bin[bin.length() - 1];
        }
    }
    return extracted_msg;
}
double MSE(vector<vector<int>> i1, vector<vector<int>> i2)
{
    double mse = 0;
    for (int i = 0; i < i1.size(); i++)
    {
        for (int j = 0; j < i1[0].size(); j++)
        {
            mse += pow(double(i1[i][j] - i2[i][j]), double(2));
        }
    }
    mse /= i1.size() * i1[0].size();
    return mse;
}
double PSNR(double MSE)
{
    double r = 255;
    double psnr = 10 * (log10(r * r / MSE));
    return psnr;
}
int isBinary(string input)
{
    for (int i = 0; input[i]; ++i)
        if (input[i] != '0' && input[i] != '1')
            return 0;
    return 1;
}
int main()
{
    string msg;
    cout << "Enter Message (in binary) :" << endl;
    cin >> msg;
    if (isBinary(msg) == 0)
    {
        cout << "Enter valid binary number" << endl;
        return 0;
    }
    int n = sqrt(msg.length());
    if (n * n != msg.length())
    {
        cout << "Enter Binary Mesage with legth whose whole square root is possible " << endl;
        return 0;
    }
    cout << "----------------------------------------------------- " << endl;
    cout<< "Enter Cover (Dimensions " << n << " * " << n << " ) : " << endl;
    vector<vector<int>>cover;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            row.push_back(val);
        }
        cover.push_back(row);
    }
    cout << "----------------------------------------------------- " << endl;
    cout<< "Stego Object : " << endl;
    vector<vector<int>> stego_obj = embeded(cover, msg);
    for (int i = 0; i < stego_obj.size(); i++)
    {
        for (int j = 0; j < stego_obj[0].size(); j++)
        {
            cout << stego_obj[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------------------------- " << endl;
    string extraction_msg = extraction(stego_obj);
    cout << "Extracted message : " << extraction_msg << endl;
    cout << "----------------------------------------------------- " << endl;
    double mse = MSE(cover, stego_obj);
    cout << "Min Square Error :" << mse << endl;
    cout << "----------------------------------------------------- " << endl;
    cout<< "Peak Signal to Noise Ratio (PSNR) : " << PSNR(mse)<< endl;
    return 0;
}