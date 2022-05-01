#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

int **getCofactor(int **mat,int p,int q,int n)
{
    int** ans;
    int i=0,j=0;
    ans=new int*[n-1];
    ans[0]=new int[n-1];
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(row!=p && col!=q)
            {
                ans[i][j]=mat[row][col];
                j++;
                if(j==n-1)
                {
                    j=0;
                    i++;
                    ans[i]=new int[n-1];
                }
            }
        }
    }
    return ans;
}

int determinantOfMatrix(int **mat,int n)
{
    int ans=0;//for storing result
    if(n==1)//base case
    return mat[0][0];

    int **temp;//for storing cofactor

    int sign=1;// to store sign multiplier

    for(int i=0;i<n;i++)
    {
        temp=getCofactor(mat,0,i,n);
        ans+=sign*mat[0][i]*determinantOfMatrix(temp,n-1);
        sign=-sign;
    }
    return ans;
}
int **transposeOfMatrix(int **mat,int n,int m)
{
    int **ans=new int*[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            ans[i][j]=mat[j][i];
        }
    }
    return ans;
}
int **adjointOfMatrix(int **mat,int n)
{
    int **ans=new int*[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            int **temp=getCofactor(mat,i,j,n);
            int a=determinantOfMatrix(temp,n-1);
            ans[i][j]=pow(-1,i+j+2)*a;
        }
    }
    ans=transposeOfMatrix(ans,n,n);
    return ans;
}
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
double **inverseMatrix(int **mat,int n)
{
    int **temp=adjointOfMatrix(mat,n);
    int det=determinantOfMatrix(mat,n);
    if(det<0)
    {
        det=-det;
        int inverseDet=multiplicative_inverse(det,26);
        inverseDet=-inverseDet;
        det=inverseDet+26;
    }
    else
    {
        int inverseDet=multiplicative_inverse(det,26);
        det=inverseDet;
    }
    double **ans=new double*[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=new double[n];
        for(int j=0;j<n;j++)
        {
            ans[i][j]=temp[i][j]*det;
        }
    }
    return ans;
}

int gcd(int key,int number){
   if (number == 0)
   return key;
   return gcd(number, key % number);
}

template <typename V,typename T>
int** matrix_multipication(int n,int m,int s,V **mat1,T **mat2)
{
    int **ans;
    ans=new int*[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=new int[s];
        for(int j=0;j<s;j++)
        {
            ans[i][j]=0;
            for(int k=0;k<m;k++)
                ans[i][j]+=mat1[i][k]*mat2[k][j];
            ans[i][j]=ans[i][j]%26;
            if(ans[i][j]<0)
            ans[i][j]+=26;
        }
    }
    return ans;
}
string encrypt(string plainText,int **key,int n)
{
    int i,j,k=0;
    double length=plainText.length();
    int rows=ceil(length/n);
    int **textMap;
    textMap=new int*[rows];
    for(i=0;i<rows;i++)
    {
        textMap[i]=new int[n];
        for(j=0;j<n;j++)
        {
            if(k>=length)
            {
                textMap[i][j]=25;
            }
            else{
                plainText[k]=tolower(plainText[k]);
                textMap[i][j]=plainText[k]-'a';
                k++;
            }
        }
    }
    // cout<<"plain text map:\n";
    // for(i=0;i<rows;i++)
    // {
    //     for(j=0;j<n;j++)
    //     cout<<textMap[i][j]<<" ";
    //     cout<<"\n";
    // }
    int** ans=matrix_multipication<int,int>(rows,n,n,textMap,key);
    string cipherText;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<n;j++)
        cipherText+=ans[i][j]+'A';
    }
    return cipherText;
}
string decrypt(string cipherText,int** key,int n)
{
    int i,j,k=0;
    double length=cipherText.length();
    int rows=ceil(length/n);
    int **textMap;
    textMap=new int*[rows];
    for(i=0;i<rows;i++)
    {
        textMap[i]=new int[n];
        for(j=0;j<n;j++)
        {
            cipherText[k]=toupper(cipherText[k]);
            textMap[i][j]=cipherText[k]-'A';
            k++;
        }
    }
    // cout<<"cipher text map:\n";
    // for(i=0;i<rows;i++)
    // {
    //     for(j=0;j<n;j++)
    //     cout<<textMap[i][j]<<" ";
    //     cout<<"\n";
    // }
    double **inverseKey=inverseMatrix(key,n);
    // cout<<"inverse key:\n";
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<n;j++)
    //     cout<<inverseKey[i][j]<<" ";
    //     cout<<"\n";
    // }
    int **ans= matrix_multipication<int,double>(rows,n,n,textMap,inverseKey);
    string plainText;
    // cout<<"plain Text map:\n";
    // for(i=0;i<rows;i++)
    // {
    //     for(j=0;j<n;j++)
    //     cout<<ans[i][j]<<" ";
    //     cout<<"\n"; 
    // }
    for(i=0;i<rows;i++)
    {
        for(j=0;j<n;j++)
        plainText+=ans[i][j]+'a';
    }
    return plainText;
}
int mode(int a,int b)
{
    int temp=a%b;
    if(temp<0)
    temp+=b;
    return temp;
}
int main()
{
    string plainText;
    cout<<"Enter Plain Text:";
    cin>>plainText;
    int n,i,j;
    cout<<"Enter key matrix size:";
    cin>>n;
    int **key=new int*[n];
    cout<<"Enter Key Matrix that the determinant gcd(determinant,26) should be 1:\n";
    for(i=0;i<n;i++)
    {
        key[i]=new int[n];
        for(j=0;j<n;j++)
        cin>>key[i][j];
    }
    int a=determinantOfMatrix(key,n);
    if(gcd(mode(a,26),26)!=1)
    {
        cout<<"key matrix determinant gcd(determinant,26) should be 1";
        return 1;
    }
    string cipherText= encrypt(plainText,key,n);
    cout<<"\nCipher Text:"<<cipherText<<endl;
    cout<<"plain Text:"<<decrypt(cipherText,key,n)<<endl;
}