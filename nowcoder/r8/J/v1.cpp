#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

#define LOCAL
#ifdef LOCAL
#define debug0(x) cout<<"[DEBUG] "<<#x<<"="<<x<<endl
#define debug1(c,l,r) cout<<"[DEBUG] "<<#c<<" : ";\
inc(i,l,r)cout<<c[i]<<" ";cout<<endl
#define debug2(c,l,r,ll,rr)cout<<"[DEBUG]"<<#c<<endl;\
inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
ostream& operator<< (ostream& o,const pair<int,int>& a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}
#else
#define debug0(x)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif
// 两个字符串长度对齐
void len(string &a,string &b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(a.size()<b.size())a.push_back('0');
    while(a.size()>b.size())b.push_back('0');
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
}
// 二进制相加
string add(string a,string b)
{
    len(a,b);
    bool p(false);
    string res;
    dec(i,a.size()-1,0)
    {
        res.push_back((
            a[i]=='1'^b[i]=='1'^p
        )?'1':'0');
        p=(
            a[i]=='1'&&p||
            b[i]=='1'&&p||
            a[i]=='1'&&b[i]=='1'
        );
    }
    if(p)res.push_back('1');
    reverse(res.begin(),res.end());
    return res;
}
/**
 * 合并
 * @param a 奇数位
 * @param b 偶数位
 */
string merge(string a,string b)
{
    string res;
    len(a,b);
    inc(i,0,a.size()-1)
    {
        if(i||a[i]=='1')res.push_back(a[i]);
        res.push_back(b[i]);
    }
    return res;
}
// 二进制相乘
string mul(string a,string b,int c)
{
    len(a,b);
    if(a.size()==1)
    {
        string tmp=(a=="1"&&b=="1")?"1":"0";       
        return tmp;
    }
    string aa,aaa,bb,bbb;
    inc(i,1,a.size())
    {
        // 偶数位
        if(i&1)
        {
            aa.push_back(a[a.size()-i]);
            bb.push_back(b[b.size()-i]);
        }
        else
        {
            aaa.push_back(a[a.size()-i]);
            bbb.push_back(b[b.size()-i]);
        }
    }
    reverse(aa.begin(),aa.end());
    reverse(aaa.begin(),aaa.end());
    reverse(bb.begin(),bb.end());
    reverse(bbb.begin(),bbb.end());
    int childC(c==-1?-2:c*c);
    string tmp=merge(
        add(
            mul(aa,bbb,childC),
            mul(aaa,bb,childC)
        ),
        add(
            mul(aa,bb,childC),
            mul(aaa,bbb,childC)+"0"
        )
    );
    return tmp;
}
void solve()
{
    string a,b;
    cin>>a>>b;
    cout<<mul(a,b,-1)<<endl;
}
void test()
{
    // cout<<add("1010","100")<<endl;
    // cout<<add("1010","10")<<endl;
    // cout<<add("1010","1")<<endl;
    // cout<<add("1","100")<<endl;
    // cout<<add("1","1010")<<endl;
    // cout<<add("101","10110")<<endl;
    // cout<<add("101","10110")<<endl;
    // debug0(val("1101",-2));
    // debug0(val("110101",-2));
    debug0(mul("11","11",-2));
}
signed main()
{
    // test();
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
 5
 0 1
 10 10
 10 11
 101 101
 110 110
*/