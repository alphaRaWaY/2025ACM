#include<bits/stdc++.h>
using namespace std;
const int mod = 1e5+3;
const int MaxN = 1e5+5;
int N,K;
int nums[MaxN]={1};
void solve()
{
    memset(nums,0,sizeof(nums));
    nums[0]=1;
    for(int i(0);i<N;i++)
    {
        for(int j(1);j<=K;j++)
        {
            nums[i+j]=(nums[i+j]+nums[i])%mod;
        }
    }
    cout<<nums[N]%mod<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>N>>K){solve();}
}