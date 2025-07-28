// https://www.luogu.com.cn/problem/P1452
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

// #define LOCAL
#ifdef LOCAL
ostream &operator<< (ostream & o,const pair<int,int> a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}
#define split cout<<"-------------------------------"<<endl
#define debug0(c) cout<<"[DEBUG] "<<#c<<"="<<c<<endl
#define debug1(c,l,r)\
cout<<"[DEBUG] "<<#c<<": ";\
inc(i,l,r)cout<<c[i]<<" ";cout<<endl 
#define debug2(c,l,r,ll,rr)\
cout<<"[DEBUG] "<<#c<<endl;\
inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
#define T test()
#define case_ans cout<<"[ANSWER] "
#else
#define T
#define case_ans
#define split
#define debug0(c)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif

pair<int,int> getVector(pair<int,int> a,pair<int,int> b){return {b.first-a.first,b.second-a.second};}
int intersection(pair<int,int> a,pair<int,int> b){return a.first*b.second-a.second*b.first;}
int cross(pair<int,int> a,pair<int,int> b,pair<int,int> c){return intersection(getVector(a,b),getVector(b,c));}
int getDist(pair<int,int> a,pair<int,int> b){return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);}
// double getH(pair<int,int> a,pair<int,int> b,pair<int,int> c)
// {
//     double S =  intersection(
//         getVector(a,b),
//         getVector(b,c)
//     )/2;
//     int l=sqrtl(getDist(b,c));
//     if(!l)return sqrtl(getDist(a,b));
//     else return fabsl(S/l);
// }
const int MaxN(5e4+5);
int n;
pair<int,int> nums[MaxN];

vector<pair<int,int>> ss,hull;
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i].first>>nums[i].second;
    sort(nums+1,nums+1+n);
    ss.push_back(nums[1]);
    inc(i,2,n)
    {
        while(ss.size()>1&&cross(ss[ss.size()-2],ss[ss.size()-1],nums[i])<=0)ss.pop_back();
        ss.push_back(nums[i]);
    }
    inc(i,0,ss.size()-2)hull.push_back(ss[i]);
    // debug1(ss,0,ss.size()-1);
    ss.clear();
    reverse(nums+1,nums+1+n);
    ss.push_back(nums[1]);
    inc(i,2,n)
    {
        while(ss.size()>1&&cross(ss[ss.size()-2],ss[ss.size()-1],nums[i])<=0)ss.pop_back();
        ss.push_back(nums[i]);
    }
    inc(i,0,ss.size()-2)hull.push_back(ss[i]);
    // debug1(ss,0,ss.size()-1);
    debug1(hull,0,hull.size()-1);
    int sz=hull.size(),cur(1),ans(0);
    auto nxt = [sz](int a){return (a+1)%sz;};
    inc(i,0,sz-1)
    {
        while(cross(hull[i],hull[nxt(i)],hull[cur])<cross(hull[i],hull[nxt(i)],hull[nxt(cur)])){cur=nxt(cur);}
        ans=max({ans,getDist(hull[i],hull[cur]),getDist(hull[nxt(i)],hull[cur])});
    }
    case_ans;
    cout<<ans<<endl;
}
void test()
{
    // pair<int,int> a({4,8}),b({4,12}),c({5,2});
    // debug0(getVector(a,b));
    // debug0(getVector(b,c));
    // debug0(cross({4,8},{4,12},{5,2}));
}
signed main()
{
    T;
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)
    {
        split;
        solve();
    }
}
/*
4
4 8
4 12
5 2
7 8

4
0 0
0 1
1 1
1 0

10   
5 0   
0 0   
2 0   
6 0   
9 0   
8 0   
1 0   
7 0   
4 0   
3 0   


*/