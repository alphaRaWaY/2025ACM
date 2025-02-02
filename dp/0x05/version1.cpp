//±³°üdp

#include<bits/stdc++.h>
using namespace std;
const int MaxN(105);
const int MaxT(1005);
struct obj
{
    int weight;
    int val;
    bool operator < (const obj & o) const 
    {
        if(weight*o.val==val*o.weight)
        {
            return weight*o.val>val*o.weight;
        }
        else
        {
            return weight>o.weight;
        }
    }
}objs[MaxN];
int dp[MaxT];
int main()
{
    memset(dp,0,sizeof(dp));
    ios::sync_with_stdio(false);
    int T,M;
    cin>>T>>M;
    for(int i(0);i<M;i++)
    {
        cin>>objs[i].weight>>objs[i].val;
    }
    sort(objs,objs+M);
    for(int i(0);i<M;i++)
    {
        for(int j(T);j>=0;j--)
        {
            if(j-objs[i].weight>=0)
            dp[j]=max(dp[j],dp[j-objs[i].weight]+objs[i].val);
        }
    }
    cout<<dp[T]<<endl;
    system("pause");
}