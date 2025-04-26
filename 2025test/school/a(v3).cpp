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
bool Elowbit(int a){return (a&(-a))==a;}
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    if(n==1){cout<<1<<endl;return;}
    if(!Elowbit(llabs(nums[2]-nums[1]))){cout<<1<<endl;return;}
    int ext1(2*min(nums[1],nums[2])-max(nums[1],nums[2]));
    int ext2(2*max(nums[1],nums[2])-min(nums[1],nums[2]));
    // cout<<"#"<<ext1<<" "<<ext2<<endl;
    int ans(2);
    inc(i,3,n)
    {
        if(nums[i]!=nums[1]&&nums[i]!=nums[2]&&nums[i]!=ext1)break;
        ans=i;
    }
    inc(i,3,n)
    {
        if(nums[i]!=nums[1]&&nums[i]!=nums[2]&&nums[i]!=ext2)break;
        ans=max(ans,i);
    }
    if((nums[1]&1)==(nums[2]&1))
    {
        int ext3((nums[1]+nums[2])>>1);
        inc(i,3,n)
        {
            if(nums[i]!=nums[1]&&nums[i]!=nums[2]&&nums[i]!=ext3)break;
            ans=max(ans,i);
        }
    }
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