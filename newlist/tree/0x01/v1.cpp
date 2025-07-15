// https://www.luogu.com.cn/problem/P3128

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

const int MaxN(5e4+5),MaxK(1e5+5),MaxLg(MaxN);
int lg[MaxLg],nums[MaxN],fa[MaxN][50],depth[MaxN],val[MaxN];
vector<int> ed[MaxN];
int n,k,ans;
// 获取向下取整的log
void getLog()
{
    lg[1]=0;
    inc(i,2,MaxLg-5){
        lg[i]=lg[i-1];
        if((2<<lg[i-1])==i)lg[i]++;
    };
}
//dfs初始化倍增数组
void dfs(int index,int nowDepth,int pa){
    fa[index][0]=pa;
    depth[index]=nowDepth;
    inc(i,1,lg[nowDepth]+1)
    {
        fa[index][i]=fa[fa[index][i-1]][i-1];
    }
    for(int tmp:ed[index])
    {
        if(tmp==pa)continue;
        dfs(tmp,nowDepth+1,index);
    }
}
int LCA(int a,int b)
{
    if(depth[a]<depth[b])swap(a,b);
    while(depth[a]>depth[b])a=fa[a][lg[depth[a]-depth[b]]];
    if(a==b)return a;
    dec(i,lg[depth[a]],0)if(fa[a][i]!=fa[b][i]){a=fa[a][i];b=fa[b][i];}
    return fa[a][0];
}
void calVal(int index,int pa)
{
    val[index]=nums[index];
    for(int tmp:ed[index])
    {
        if(tmp==pa)continue;
        calVal(tmp,index);
        val[index]+=val[tmp];
    }
}

void solve()
{
    ans=0;
    cin>>n>>k;
    inc(i,1,n-1)
    {
        int a,b;
        cin>>a>>b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dfs(1,1,0);
    int x,y;
    // while(cin>>x>>y)
    // {
    //     cout<<LCA(x,y)<<endl;
    // }

    inc(i,1,k)
    {
        int a,b;
        cin>>a>>b;
        int lca = LCA(a,b);
        nums[a]++;
        nums[b]++;
        nums[lca]--;
        nums[fa[lca][0]]--;
    }

    calVal(1,0);
    inc(i,1,n)ans=max(ans,val[i]);
    // inc(i,1,n)cout<<val[i]<<" ";cout<<endl;
    cout<<ans<<endl;
}


signed main()
{
    getLog();
    ios::sync_with_stdio(false);
    int _=1;
    // cin>>_;
    while(_--)solve();
}
/*
5 10

3 4
1 5
4 2
5 4

5 4
5 4
3 5
4 3
4 3
1 3
3 5
5 4
1 5
3 4
*/