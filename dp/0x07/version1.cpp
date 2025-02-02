//多种决策的01背包dp

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MaxN(4e4+5),MaxM(65);
vector<int> pa,child[MaxM];
int option[MaxM][5],cost[MaxM][5];
int price[MaxM],weight[MaxM],dp[MaxN];
signed main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i(1);i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c) child[c].push_back(i);
        else pa.push_back(i);
        price[i]=a;
        weight[i]=b;
    }
    for(int i(0);i<=m;i++){child[i].resize(2);}
    for(int i:pa)
    {
        option[i][0]=0;
        cost[i][0]=0;
        option[i][1]=weight[i]*price[i];
        cost[i][1]=price[i];
        option[i][2]=weight[i]*price[i]+weight[child[i][0]]*price[child[i][0]];
        cost[i][2]=price[i]+price[child[i][0]];
        option[i][3]=weight[i]*price[i]+weight[child[i][1]]*price[child[i][1]];
        cost[i][3]=price[i]+price[child[i][1]];
        option[i][4]=weight[i]*price[i]+weight[child[i][0]]*price[child[i][0]]+weight[child[i][1]]*price[child[i][1]];
        cost[i][4]=price[i]+price[child[i][0]]+price[child[i][1]];
    }
    /*
    for(int i:pa)
    {
        cout<<i<<endl;
        for(int j(0);j<5;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
        for(int j(0);j<5;j++)
        {
            cout<<option[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i:pa)
    {
        for(int j(n);j>=0;j--)
        {
            for(int o(0);o<5;o++)
            {
                if(j>=cost[i][o])
                {
                    dp[j]=max(dp[j],dp[j-cost[i][o]]+option[i][o]);
                }
            }
        }
    }
    cout<<dp[n]<<endl;
    system("pause");
}