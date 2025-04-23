#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e6+5),MAXM(2e3+5),INF(0x3f3f3f3f);
int n,m;
int nums[MAXN];
int mm[MAXM];
struct node
{
    int val,pos;
    bool operator < (const node& n) const{
        return pos>n.pos;
    }
};
priority_queue<node> q;
void solve()
{
    cin>>n>>m;
    inc(i,1,n)cin>>nums[i];
    int cnt(0);
    pair<int,int> ans({0,INF});
    vector<pair<int,int> >v;
    inc(i,1,n)
    {
        q.push({i,nums[i]});
        if(!mm[i])cnt++;
        mm[nums[i]]=i; 
        if(cnt==m)
        {
            while(q.top().pos<=mm[q.top().val])q.pop();
            auto[num,left] = q.top();
            v.push_back(make_pair(left,i));
            if(i-left<ans.second-ans.first)
            {
                ans=make_pair(left,i);
            }
        }
    }
    for(auto[x,y]:v)cout<<x<<" "<<y<<endl;
    cout<<ans.first<<" "<<ans.second<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}