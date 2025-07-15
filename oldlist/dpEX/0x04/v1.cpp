#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e4+5),MAXM(1e3+5),INF(0x3f3f3f3f);
int n,m,k;
int up[MAXN],down[MAXN],l[MAXN],h[MAXN];
int dp[MAXN][MAXM];
int ans(0);
void print()
{
    dec(i,m,0)
    {
        inc(j,0,n)
        {
            if(dp[j][i]>=INF)
            {
                cout<<"x"<<" ";
                continue;
            }
            cout<<dp[j][i]<<" ";
        }
        cout<<endl;
    }
}
void solve()
{
    cin>>n>>m>>k;
    inc(i,0,n)inc(j,0,m)dp[i][j]=INF;
    inc(i,1,m)dp[0][i]=0;
    inc(i,0,n){l[i]=1;h[i]=m;}
    inc(i,0,n-1)
    {
        cin>>up[i]>>down[i];
    }
    inc(i,1,k)
    {
        int p;
        cin>>p;
        cin>>l[p]>>h[p];
        l[p]++;
        h[p]--;
    }
    print();
    inc(i,0,n-1)
    {
        inc(j,l[i+1],h[i+1])if(j-up[i]>=1)dp[i+1][j]=min(dp[i+1][j-up[i]],dp[i][j-up[i]])+1; 
        dec(j,h[i+1],l[i+1])if(j+down[i]<=m)dp[i+1][j]=min(dp[i+1][j],dp[i][j+down[i]]);
        if(h[i]==m)inc(j,m-up[i],m)dp[i+1][m]=min(dp[i+1][m],dp[i][j]+1);
        bool isOK(false);
        inc(j,1,m)
        {
            if(dp[i][j]<INF)
            {
                isOK=true;
                break;
            }
        }
        if(!isOK)
        {
            cout<<0<<endl<<ans<<endl;
            return;
        }
        if(h[i]!=m||l[i]!=1)ans++;
    }
    ans=INF;
    inc(i,1,m)ans=min(ans,dp[n][i]);
    cout<<1<<endl<<ans<<endl;
    print();
}
signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
    system("pause");
}

/*
10 10 6 
3 9  
9 9  
1 2  
1 3  
1 2  
1 1  
2 1  
2 1  
1 6  
2 2  
1 2 7 
5 1 5 
6 3 5 
7 5 8 
8 7 9 
9 1 3 
*/