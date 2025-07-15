#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MaxN(6e3+5);
vector<int> child[MaxN];
int r[MaxN],dp[MaxN][2];
bool isroot[MaxN];
void dfs(int root)
{
    dp[root][1]=r[root];
    dp[root][0]=0;
    for(int c:child[root])
    {
        dfs(c);
        dp[root][1]+=dp[c][0];
        dp[root][0]+=max(dp[c][0],dp[c][1]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    memset(isroot,true,sizeof(isroot));
    int n;
    cin>>n;
    for(int i(1);i<=n;i++)
    {
        cin>>r[i];
    }
    for(int i(0);i<n-1;i++)
    {
        int c,p;
        cin>>c>>p;
        child[p].push_back(c);
        isroot[c]=false;
    }
    int root(-1);
    for(int i(1);i<=n;i++)if(isroot[i]){root=i;break;}
    dfs(root);
    /*
    cout<<root<<endl;
    cout<<"======================================="<<endl;
    for(int i(1);i<=n;i++)
    {
        cout<<dp[i][1]<<" "<<dp[i][0]<<endl;
    }
    */
    cout<<max(dp[root][1],dp[root][0])<<endl;
    system("pause");
}