#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5),INF(0x3f3f3f3f);
int nums[MAXN];
int n,q;
vector<int> change[MAXN];
int dp[MAXN];
/**
 * 查找当前长度子序列尾端的最小值是否小于当前允许最大值
 * @param length 当前查找的子序列长度
 * @param M 当前允许的最大值
 */
bool check(int length,int X,int R)
{   
    if(change[length].empty())return false;
    int pos = upper_bound(change[length].begin(),change[length].end(),R)-change[length].begin()-1;
    if(pos<change[length].size()&&pos>=0&&nums[change[length][pos]]<=X)return true;
    else return false;
}
void solve()
{
    cin>>n>>q;
    inc(i,1,n)dp[i]=INF;
    inc(i,1,n)cin>>nums[i];
    inc(i,1,n)
    {
        int pos = lower_bound(dp,dp+1+n,nums[i])-dp;
        // cout<<pos<<"#";
        change[pos].push_back(i);
        dp[pos]=nums[i];
    }
    // inc(i,1,n)cout<<dp[i]<<" ";cout<<endl;
    // inc(i,1,n)
    // {
    //     if(change[i].empty())break;
    //     for(int tmp:change[i])cout<<tmp<<" ";cout<<endl;
    // }
    while(q--)
    {
        int R,X;//边界、最大值
        cin>>R>>X;
        int l(0),r(R+1);
        while(r-l>1)
        {
            int mid(((r-l)>>1)+l);
            if(check(mid,X,R))
            {
                l=mid;
                // cout<<"#"<<mid<<",max:"<<X<<",pre:"<<R<<" is OK"<<endl;
            }
            else r=mid;
        }
        cout<<l<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
100
5 3
2 4 1 3 3
2 5
5 2
5 3

100
10 8
2 5 6 5 2 1 7 9 7 2
7 8
5 2
2 3
2 6
7 3
8 9
9 6
8 7

*/