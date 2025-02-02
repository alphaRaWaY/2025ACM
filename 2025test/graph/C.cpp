#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int MAXN(105);
int n,k;
priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<> >ed;
int fa[MAXN];
int fd(int a){return fa[a]==a?a:fa[a]=fd(fa[a]);}
bool add(int a,int b)
{
    int m=fd(a);
    int n=fd(b);
    if(m==n)return false;
    fa[m]=n;
    return true;
}
void solve()
{
    cin>>n>>k;
    inc(i,1,n)fa[i]=i;
    int ans(0);
    inc(i,1,k)
    {
        int a,b,val;
        cin>>a>>b>>val;
        ed.push({val,{a,b}});
        ans+=val;
    }
    int cnt(0);
    while(!ed.empty())
    {
        auto[val,e]=ed.top();
        ed.pop();
        if(add(e.first,e.second))
        {
            ans-=val;
            cnt++;
        }
        if(cnt>=n-1)break;
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
    system("pause");
}
/*
5 5
1 2 8
1 3 1
1 5 3
2 4 5
3 4 2
*/

/*
7 9

1 2 1
1 5 2
2 3 3
2 6 4
3 4 5
4 6 6
5 6 7
5 7 8
6 7 9
*/