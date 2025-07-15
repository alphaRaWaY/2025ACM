#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF(0x3f3f3f3f);
const int MaxN(105);
int nums[2*MaxN];
int dp1[MaxN*2][MaxN*2],dp2[MaxN*2][MaxN*2];
signed main()
{
    //ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i(0);i<n;i++)
    {
        cin>>nums[i];
    }
    for(int i(n);i<2*n;i++)
    {
        nums[i]=nums[i-n];
    }
    //for(int i(0);i<2*n-1;i++)cout<<nums[i]<<" ";cout<<endl;
    partial_sum(nums,nums+2*n,nums);
    //for(int i(0);i<2*n-1;i++)cout<<nums[i]<<" ";cout<<endl;
    n=2*n-1;
    for(int i(0);i<n;i++)
    {
        dp1[i][i]=0;
        dp2[i][i]=0;
    }
    for(int _(1);_<n;_++)
    {
        for(int i(0);i<n;i++)
        {
            int j=_+i;
            if(j>=n)break;
            for(int k(i);k<j;k++)
            {
                int Sum=nums[j]-(i>0?nums[i-1]:0);
                dp1[i][j]=max(dp1[i][j],dp1[i][k]+dp1[k+1][j]+Sum);
                dp2[i][j]=dp2[i][j]?min(dp2[i][j],dp2[i][k]+dp2[k+1][j]+Sum):dp2[i][k]+dp2[k+1][j]+Sum;
            }
        }
    }
    /*
    for(int i(0);i<n;i++)
    {
        for(int j(0);j<n;j++)
        {
            if(!dp1[i][j])cout<<"\t";
            else cout<<dp1[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(int i(0);i<n;i++)
    {
        for(int j(0);j<n;j++)
        {
            if(!dp2[i][j])cout<<"\t";
            else cout<<dp2[i][j]<<"\t";
        }
        cout<<endl;
    }
    */
    int ansM(-INF),ansm(INF);
    n=(n+1)/2;
    for(int i(0);i<n;i++)
    {
        ansM=max(ansM,dp1[i][i+n-1]);
        ansm=min(ansm,dp2[i][i+n-1]);
    }
    cout<<ansm<<endl<<ansM<<endl;
    system("pause");
    return 0;
}