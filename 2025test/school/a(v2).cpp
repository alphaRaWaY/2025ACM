#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n;
map<int,int> cnt;
int nums[MAXN];
// map<int,map<int,int> >cnt;
int lowbit(int a){return a&(-a);}
void solve()
{
    cnt.clear();
    cin>>n;
    inc(i,1,n)
    {
        int tmp;
        cin>>tmp;
        cnt[tmp]++;
    }
    int id(0);
    for(auto [x,y]:cnt)nums[++id]=x; 
    int ans(0);
    n=id;
    inc(i,1,n)ans=max(ans,cnt[nums[i]]);
    inc(i,1,n-1)if(nums[i+1]-nums[i]==lowbit(nums[i+1]-nums[i]))ans=max(cnt[nums[i+1]]+cnt[nums[i]],ans);
    inc(i,1,n-2)
    if(nums[i+1]-nums[i]==lowbit(nums[i+1]-nums[i])
    &&nums[i+2]-nums[i+1]==lowbit(nums[i+2]-nums[i+1])
    &&nums[i+1]-nums[i]==nums[i+2]-nums[i+1])ans=max(ans,cnt[nums[i]]+cnt[nums[i+1]]+cnt[nums[i+2]]);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
    // system("pause");
}
/*

*/