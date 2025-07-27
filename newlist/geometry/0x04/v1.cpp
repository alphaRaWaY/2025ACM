// https://www.luogu.com.cn/problem/P1325
// 线段
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define debug1(c,l,r) inc(i,l,r)cout<<c[i]<<" ";cout<<endl
#define debug2(c,l,r,ll,rr) inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
ostream &operator<< (ostream& o,const pair<int,int> a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}
const int MaxN(1005);
int n,d;
pair<double,double> nums[MaxN];
int lid[MaxN],rid[MaxN];
bool vis[MaxN];
void solve()
{
    cin>>n>>d;
    inc(i,1,n)
    {
        int x,y;
        cin>>x>>y;
        if(y>d)
        {
            cout<<-1<<endl;
            return;
        }
        double offset = sqrtl(d*d-y*y);
        nums[i]={x-offset,x+offset};
        lid[i]=rid[i]=i;
    }
    sort(lid+1,lid+1+n,[=](int a,int b)->bool{
        if(nums[a].first==nums[b].first)return nums[a].second<nums[b].second; 
        return nums[a].first<nums[b].first;
    });
    sort(rid+1,rid+1+n,[=](int a,int b)->bool{
        if(nums[a].second==nums[b].second)return nums[a].first<nums[b].first; 
        return nums[a].second<nums[b].second;
    });
    // debug1(nums,1,n);
    // debug1(lid,1,n);
    // debug1(rid,1,n);
    int i(1);
    int ans(0);
    // inc(i,1,n)cout<<nums[rid[i]].second<<" ";cout<<endl;
    inc(j,1,n)
    {
        if(vis[rid[j]])continue;
        vis[rid[j]]=true;
        while(
            i<=n
            &&nums[rid[j]].second>=nums[lid[i]].first
        ){
            vis[lid[i]]=true;
            // cout<<"#"<<i<<endl;
            i++;
        }
        // cout<<rid[j]<<endl;
        ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
}
/*
3 2
1 2
-3 1
2 1

*/