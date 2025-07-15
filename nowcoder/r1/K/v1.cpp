#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int read()
{
    int f=1,x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return f*x;
}
const int MaxN(2e5+5);
int ans[MaxN][3];
map<pair<int,int>,int> doorId;
bool vis[MaxN][3];
int n;
vector<int> ed[MaxN];
set<pair<int,int> >s;
int dfs(int index,int indoor)
{
    // cout<<"#"<<index<<","<<indoor+1<<endl;
    // system("pause");
    // if(ans[index][indoor])return ans[index][indoor];
    // if(vis[index][indoor])return ans[index][indoor]=1;
    // vis[index][indoor]=true;
    // int tmp = ed[index][(indoor+1)%ed[index].size()];
    // ans[index][indoor] = dfs(tmp,doorId[{tmp,index}]) + 1;
    // return ans[index][indoor];
    vis[index][indoor]=true;
    int tmp = ed[index][(indoor+1)%ed[index].size()];
    int tmpDoor = doorId[{tmp,index}];
    s.insert({min(index,tmp),max(index,tmp)});
    if(!vis[tmp][tmpDoor]){
        dfs(tmp,tmpDoor);
        ans[index][indoor]=s.size();
    }
    vis[index][indoor]=false;
    return ans[index][tmpDoor];
}
void solve()
{
    // cin>>n;
    n=read();
    inc(i,1,n)
    {
        int degree;
        // cin>>degree;
        degree = read();
        inc(j,1,degree){
            int p;
            // cin>>p;
            p = read();
            ed[i].push_back(p);
            doorId[{i,p}]=j-1;
        }
    }
    inc(i,1,n)
    {
        if(ans[i][ed[i].size()-1])continue;
        // cout<<"{"<<i<<"}"<<endl;
        // memset(vis,false,sizeof(vis));
        s.clear();
        dfs(i,ed[i].size()-1);
        // cout<<"==============="<<endl;
    }
    inc(i,1,n)cout<<ans[i][ed[i].size()-1]<<endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    int _=1;
    // cin>>_;
    // _=read();
    while(_--)solve();
}
/*
6
3 4 2 3
3 5 1 3
3 6 1 2
1 1
1 2
1 3
*/

/*
4
2 2 4
2 1 3
2 2 4
2 1 3
*/