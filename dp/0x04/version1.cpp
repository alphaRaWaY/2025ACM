#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int mod(1e8);
const int MaxN(155);
int n,ans(0);
string s1,s2,s3;
int nxt1[MaxN][30],nxt2[MaxN][30],nxt3[MaxN][30];
int dp[MaxN][MaxN][MaxN];//在x,y,z的位置上之后的公共子串数量
int dfs(int x,int y,int z)
{
    if(dp[x][y][z])return dp[x][y][z];
    inc(i,0,25)
    {
        if(nxt1[x][i]&&nxt2[y][i]&&nxt3[z][i])
        dp[x][y][z]=(dp[x][y][z]+dfs(nxt1[x][i],nxt2[y][i],nxt3[z][i]))%mod;
    } 
    if(x||y||z)dp[x][y][z]=(dp[x][y][z]+1)%mod;
    return dp[x][y][z];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>s1>>s2>>s3;
    n++;
    s1='#'+s1;
    s2='#'+s2;
    s3='#'+s3;
    dec(i,n-2,0)
    {
        inc(j,0,25)nxt1[i][j]=nxt1[i+1][j];
        nxt1[i][s1[i+1]-'a']=i+1;
    }
    dec(i,n-2,0)
    {
        inc(j,0,25)nxt2[i][j]=nxt2[i+1][j];
        nxt2[i][s2[i+1]-'a']=i+1;
    }
    dec(i,n-2,0)
    {
        inc(j,0,25)nxt3[i][j]=nxt3[i+1][j];
        nxt3[i][s3[i+1]-'a']=i+1;
    }
    ans=dfs(0,0,0);
    cout<<ans%mod<<endl;
    system("pause");
}