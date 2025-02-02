#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int a,b;
const int MAXN(15);
int dp[MAXN][MAXN][1<<MAXN];
int ans[MAXN][MAXN];
int n=11;
bool check(int a,int b,int n)
{
    if(a&b)return false;
    int c(a|b);
    int cnt(0);
    inc(i,1,n)
    {
        if((c>>(i-1))&1)
        {
            if(cnt&1)return false;
            cnt=0;
        }
        else cnt++;
    }
    return !(cnt&1);
}
void fillPD()
{
    inc(height,0,n)
    {
        inc(sta,0,(1<<height)-1)
        {
            dp[1][height][sta]=0;
            dp[2][height][sta]=check(sta,0,height);
        }
        dp[1][height][0]=!(height&1);
        inc(i,3,n)
        {
            if((i&1)&&(height&1))continue;
            inc(sta,0,(1<<height)-1)
            {
                inc(pre,0,(1<<height)-1)
                {
                    if(check(sta,pre,height))dp[i][height][sta]+=dp[i-1][height][pre];
                }
            }
        }
        inc(i,1,n)
        {
            inc(sta,0,(1<<height)-1)
            {
                ans[i][height]+=dp[i][height][sta];
            }
        }
    }
}
signed main()
{
    fillPD();
    inc(i,1,n)
    {
        inc(j,1,n)cout<<ans[i][j]<<" ";cout<<endl;
    }
    ios::sync_with_stdio(false);
    while(cin>>a>>b)
    {
        if(!a&&!b)break;
        cout<<ans[a][b]<<endl;
    }
    system("pause");
}