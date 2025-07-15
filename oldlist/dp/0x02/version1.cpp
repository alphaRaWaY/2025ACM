#include<bits/stdc++.h>
using namespace std;
int n;
const int MaxN(1005);
int nums[MaxN][MaxN];
void solve()
{
    for(int i(0);i<n;i++)
    {
        for(int j(0);j<=i;j++)
        {
            cin>>nums[i][j];
        }
    }
    for(int i(n-2);i>=0;i--)
    {
        for(int j(0);j<=i;j++)
        {
            nums[i][j]+=max(nums[i+1][j],nums[i+1][j+1]);
        }
    }
    cout<<nums[0][0]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n){solve();}
}