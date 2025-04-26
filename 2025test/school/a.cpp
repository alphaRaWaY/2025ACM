#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n;
int nums[MAXN];
// map<int,map<int,int> >cnt;
int lowbit(int a){return a&(-a);}
bool ans[2];
void solve()
{
    memset(ans,false,sizeof(ans));
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    sort(nums+1,nums+1+n);
    inc(i,1,n-1)if(nums[i+1]-nums[i]==lowbit(nums[i+1]-nums[i]))ans[0]=true;
    inc(i,1,n-2)
    if(nums[i+1]-nums[i]==lowbit(nums[i+1]-nums[i])
    &&nums[i+2]-nums[i+1]==lowbit(nums[i+2]-nums[i+1])
    &&nums[i+1]-nums[i]==nums[i+2]-nums[i+1])ans[1]=true;
    if(ans[1])cout<<3<<endl;
    else if(ans[0])cout<<2<<endl;
    else cout<<1<<endl;
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