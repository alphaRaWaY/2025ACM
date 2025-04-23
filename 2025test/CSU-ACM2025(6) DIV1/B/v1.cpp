#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(3e5+5),INF(0x3f3f3f3f);
int n;
int nums[MAXN];
pair<int,int> mm[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    mm[n+1]=make_pair(INF,n);
    dec(i,n,1)
    {
        if(mm[i+1].first<i-nums[i])
        {
            mm[i]=mm[i+1];
        }
        else
        {
            mm[i].first=i-nums[i];
            mm[i].second=i;
        }    
    }
    // inc(i,1,n)printf("{%d,%d}\n",mm[i].first,mm[i].second);
    // inc(i,1,n)cout<<nums[i]+i<<" ";cout<<endl;
    inc(i,1,n)
    {
        int right=max(nums[i]+i,1ll);
        if(right>n)
        {
            cout<<0<<endl;
            continue;
        }
        if(mm[right].first<=i)
        {
            cout<<1<<" "<<mm[right].second-i<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
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