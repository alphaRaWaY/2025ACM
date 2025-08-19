// 位逆序置换
// 必备板子
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
// 方便本地调试的板子
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

int n,m;
string a,b;
int nums[35];
void solve()
{
    cin>>n>>m>>a>>b;
    int t(0),cur(0);
    for(char tmp:b){t=(t<<1)+tmp-'0';}
    inc(i,0,m-1){cur=(cur<<1)+a[i]-'0';}

    int ans(0);
    inc(pos,m-1,n-1)
    {
        auto shift = [pos](int tmp)->int{
            return (tmp<<1)|(a[pos+1]-'0');
        };
        debug0(cur);
        if(!(cur&(1<<(m-1))))
        {
            if(pos!=n-1)cur=shift(cur);
            continue;
        }
        ans++;
        cur=cur^t;
        if(pos!=n-1)cur=shift(cur);
    }
    if(cur)cout<<-1<<endl;
    else cout<<ans<<endl;
    // debug0(t);
    // debug0(cur);

}
// 用于在程序启动前预先测试
void test()
{

}
signed main()
{
    inc(i,0,31)nums[i]=1<<i;
    T;
    ios::sync_with_stdio(false);
    int _;
    _ = 1;
    cin>>_;
    while(_--)
    {
        // 样例分隔符，仅在#define LOCAL时生效
        split;
        solve();
    }
}
/*
1
5 3
10100
110
*/
