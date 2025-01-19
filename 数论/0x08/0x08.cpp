#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=n;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MOD(1e9+7),MAXN(405);
void exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        exgcd(b,a%b,x,y);
        int tmp = x;
        x = y;
        y = tmp-(a/b)*y;
    }
}
int getver(int a,int mod)
{
    a=(a%mod+mod)%mod;
    int x,y;
    exgcd(a,mod,x,y);
    //cout<<x<<" "<<y<<endl;
    x=(mod+x%mod)%mod;
    return x;
}
int n;
int matrix[MAXN][MAXN],ans[MAXN][MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)
    inc(j,1,n)cin>>matrix[i][j];
    inc(i,1,n)ans[i][i]=1;
    bool isOK(true);
    inc(i,1,n-1)//删除下三角第i列
    {
        inc(j,i+1,n)//当前删除第j行的第i列
        {
            if(!matrix[i][i])
            {
                cout<<"No Solution"<<endl;
                return;
            }
            int tmp((matrix[j][i]*getver(matrix[i][i],MOD))%MOD);
            inc(k,1,n)//对第j行的第k个数进行计算
            {
                matrix[j][k]=(matrix[j][k]-tmp*matrix[i][k]%MOD)%MOD;
                ans[j][k]=(ans[j][k]-tmp*ans[i][k]%MOD)%MOD;
            }
        }
    }
    dec(i,n,2)//删除上三角第i列
    {
        dec(j,i-1,1)//当前删除第j行的第i列
        {
            if(!matrix[i][i])
            {
                cout<<"No Solution"<<endl;
                return;
            }
            int tmp((matrix[j][i]*getver(matrix[i][i],MOD))%MOD);
            inc(k,1,n)//对第j行的第k个数进行计算
            {
                matrix[j][k]=(matrix[j][k]-tmp*matrix[i][k]%MOD)%MOD;
                ans[j][k]=(ans[j][k]-tmp*ans[i][k]%MOD)%MOD;
            }
        }
    }
    inc(i,1,n)
    {
        inc(j,1,n)
        {
            ans[i][j]=((ans[i][j]*getver(matrix[i][i],MOD))%MOD+MOD)%MOD;
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
}
/*
3
1 2 8
2 5 6
5 1 2
*/

/*
3
3 2 4
7 2 9
2 4 3
*/