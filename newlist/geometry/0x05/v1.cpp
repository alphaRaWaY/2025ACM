// https://www.luogu.com.cn/problem/P2742
// 凸包
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define debug1(c,l,r) inc(i,l,r)cout<<c[i]<<" ";cout<<endl
#define debug2(c,l,r,ll,rr) inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
const int MaxN(1e5+5);
int n;

ostream &operator<< (ostream & o,const pair<double,double> a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}

pair<double,double>nums[MaxN];
pair<double,double> getVector(
    pair<double,double> a,
    pair<double,double> b
){
    return make_pair(b.first-a.first,b.second-a.second);
}
double intersection(
    pair<double,double> a,
    pair<double,double> b
){
    return a.first*b.second-a.second*b.first;
}
double cross(
    pair<double,double> a,
    pair<double,double> b,
    pair<double,double> c
){
    return intersection(
        getVector(a,b),
        getVector(b,c)
    );
}
double getDist(
    pair<double,double> a,
    pair<double,double> b
){
    return sqrtl((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
vector<pair<double,double> >ss;
vector<pair<double,double> >ans;
void solve()
{
    ss.clear();
    ans.clear();
    cin>>n;
    inc(i,1,n)cin>>nums[i].first>>nums[i].second;
    // debug1(nums,1,n);
    sort(nums+1,nums+1+n);
    ss.push_back(nums[1]);
    inc(i,2,n)
    {
        while(ss.size()>1&&cross(ss[ss.size()-2],ss[ss.size()-1],nums[i])<0)ss.pop_back();
        ss.push_back(nums[i]);
    }
    // debug1(ss,0,ss.size()-1);
    ss.swap(ans);
    reverse(nums+1,nums+1+n);
    ss.push_back(nums[1]);
    inc(i,2,n)
    {
        while(ss.size()>1&&cross(ss[ss.size()-2],ss[ss.size()-1],nums[i])<0)ss.pop_back();
        ss.push_back(nums[i]);
    }
    // debug1(ss,0,ss.size()-1);
    inc(i,1,ss.size()-2)ans.push_back(ss[i]);
    // debug1(ans,0,ans.size()-1);
    double cnt(0.0);
    inc(i,0,ans.size()-1)
    {
        if(!i)cnt+=getDist(ans.front(),ans.back());
        else cnt+=getDist(ans[i],ans[i-1]);
    }
    // cout<<cnt<<endl;
    printf("%.2Lf\n",cnt);
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
4
4 8
4 12
5 9.3
7 8

*/