#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(105),INF(1e18);
int n,m;
vector<int> ed[MAXN];
vector<int> trace,newans,ans[MAXN];
bool vis[MAXN],tracked[MAXN];
int fa[MAXN];
int fd(int a){return a==fa[a]?a:fd(fa[a]);}
void getDis(int index)
{
    tracked[index]=true;
    if(vis[index])
    {
        if(trace.size()>newans.size())newans=trace;
        return;
    }
    trace.push_back(index);
    vis[index]=true;
    for(int tmp:ed[index])
    {
        getDis(tmp);
    }
    vis[index]=false;
    trace.pop_back();
}
void solve()
{
    cin>>n>>m;
    inc(i,1,m)fa[i]=i;
    int a,b;
    while(cin>>a>>b)
    {
        if(a==-1&&b==-1)break;
        ed[a].push_back(b);
        ed[b].push_back(a);
        fa[fd(a)]=fd(b);
    }
    inc(i,1,m)
    {
        newans.clear();
        getDis(i);
        if(newans.size()>ans[fd(i)].size())ans[fd(i)]=newans;
        // cout<<"#"<<fd(i)<<": ";
        // for(int tmp:newans)cout<<tmp<<" ";cout<<endl;
    }
    int tot(0);
    inc(i,1,m)
    {
        if(fd(i)==i)tot+=ans[i].size()-(ans[i].size()&1);
    }
    cout<<tot/2<<endl;
    inc(i,1,m)
    {
        if(fd(i)==i)
        {
            inc(j,0,ans[i].size())
            {
                if(j+1>=ans[i].size())break;
                cout<<ans[i][j]<<" "<<ans[i][j+1]<<endl;
                j++;
            }
        }
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
