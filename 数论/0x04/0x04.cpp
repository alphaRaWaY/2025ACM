//矩阵乘法加快速幂

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(105),mod(1e9+7);
int matrix[60][MaxN][MaxN];
int ans[MaxN][MaxN];
signed main()
{
    ios::sync_with_stdio(false);
    int n,k,top(0),tk;
    cin>>n>>k;tk=k;
    while(tk){top++;tk>>=1;}
    inc(i,1,n)inc(j,1,n)cin>>matrix[1][i][j];
    inc(i,1,n)matrix[0][i][i]=1;
    inc(i,1,n)ans[i][i]=1;
    inc(i,1,top)
    {
        inc(x,1,n)inc(y,1,n)inc(z,1,n)
        {
            matrix[i+1][x][y]=(matrix[i][x][z]*matrix[i][z][y]+matrix[i+1][x][y])%mod;
        }
    }
    int pos(1);
    while(k)
    {
        if(k&1)
        {
            int tmp[MaxN][MaxN];
            memset(tmp,0,sizeof(tmp));
            inc(x,1,n)inc(y,1,n)inc(z,1,n)
            {
                tmp[x][y]=(ans[x][z]*matrix[pos][z][y]+tmp[x][y])%mod;
            }
            inc(i,1,n)inc(j,1,n)
            {
                ans[i][j]=tmp[i][j]%mod;
            }
        }
        pos++;
        k>>=1;
    }
    inc(i,1,n)
    {
        inc(j,1,n)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
}