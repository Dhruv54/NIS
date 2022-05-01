#include<iostream>
#include<math.h>
using namespace std;


int mod(int a)
{
    int modN = a % 26;
    if (modN < 0)
        modN += 26;
    return modN;
}

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

int **inverseMatrix(int **mat,int n)
{
    int **temp=adjointOfMatrix(mat,n);
    int det=mod(determinantOfMatrix(mat,n));
    det = multiplicativeInverse(det,26);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            temp[i][j] = mod(temp[i][j]*det);
    return temp;
}
int main()
{
    int n,i,j;
    cout<<"Enter matrix size:";
    cin>>n;
    cout<<"Enter matrix:\n";
    int **mat=new int*[n];
    for(i=0;i<n;i++)
    {
        mat[i]=new int[n];
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    int **inverseMat=inverseMatrix(mat,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<inverseMat[i][j]<<" ";
        cout<<"\n";
    }
}