#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int MAXN(2e5+5),INF(0x3f3f3f3f);
int n,m;
vector<pii> ed[MAXN];
struct node{
    int mx,mn,sum,pos;
    node(int mx,int mn,int sum,int pos){
        this->mn=mn;
        this->mx=mx;
        this->pos=pos;
        this->sum=sum;
    }
    int cal()
    {
        return sum-mx+mn;
    }
    void print()
    {
        cout<<"#info :"<<endl;
        cout<<"max : "<<mx<<endl;
        cout<<"min : "<<mn<<endl;
        cout<<"sum : "<<sum<<endl;
        cout<<"position : "<<pos<<endl;
    }
};
queue<node> q;
int weight[MAXN];
void solve()
{
    cin>>n>>m;
    inc(i,1,n)weight[i]=INF;
    weight[1]=0;
    inc(i,1,m)
    {
        int a,b,w;
        cin>>a>>b>>w;
        ed[a].push_back({b,w});
        ed[b].push_back({a,w});
    }
    q.push(node(0,INF,0,1));
    while(!q.empty())
    {
        auto[mx,mn,sum,pos]=q.front();
        // q.front().print();
        q.pop();
        for(auto[p,w]:ed[pos])
        {
            node n(max(mx,w),min(mn,w),sum+w,p);
            // n.print();
            if(n.cal()<weight[p])
            {
                q.push(n);
                weight[p]=n.cal();
            }
        }
    }
    inc(i,2,n)cout<<weight[i]<<" ";cout<<endl;
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