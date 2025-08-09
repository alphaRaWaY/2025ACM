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

void solve()
{
    string s;
    cin>>s;
    if(s[0]!='-')
    {
        bool flag(false);
        inc(i,0,s.size()-1)
        {
            if(s[i]=='0'&&!flag)
            {
                flag=true;
                cout<<'1';
            }
            cout<<s[i];
        }
        if(!flag)cout<<"1";
        cout<<endl;
    }
    else
    {
        bool flag(false);
        cout<<"-";
        inc(i,1,s.size()-1)
        {
            if(s[i]>='2'&&!flag)
            {
                flag=true;
                cout<<'1';
            }
            cout<<s[i];
        }
        if(!flag)cout<<"1";
        cout<<endl;
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
/*
6
2
1
0
-1
-2
-1000000000000000000
*/