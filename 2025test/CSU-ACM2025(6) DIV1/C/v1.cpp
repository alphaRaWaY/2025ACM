#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(3e5+5),INF(0x3f3f3f3f);
int n;
struct node{
    int x,y,diff,pos;
    bool operator < (const node& n) const{
        return diff<n.diff;
    }
    void print()
    {
        cout<<"at "<<pos<<": "<<x<<"-"<<y<<"="<<diff<<endl;
    }
}nums[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i].x>>nums[i].y;
    inc(i,1,n)nums[i].diff=nums[i].x-nums[i].y,nums[i].pos=i;
    sort(nums+1,nums+1+n);
    inc(i,1,n)nums[i].print();
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}