#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e3+5);
struct node{
    int l,r,val;
    bool operator < (const node & n) const
    {
        if(r==n.r)return l<n.l;
        else return r<n.r;
    }
}nums[MAXN];
int n,m;
bool vis[MAXN];
struct tree{
    int size;
    vector<int> a;
    int lowbits(int tmp){return tmp&(-tmp);}
    int query(int pos)
    {
        int res(0);
        while(pos)
        {
            res+=a[pos];
            pos-=lowbits(pos);
        }
        return res;
    }
    void add(int pos,int val)
    {
        while(pos<=size)
        {
            a[pos]+=val;
            pos+=lowbits(pos);
        }
    }
    tree(int size)
    {
        a.clear();
        a.resize(size*4);
        this->size=size;
    }
}T(MAXN);
void solve()
{
    cin>>n>>m;
    inc(i,1,m)
    {
        cin>>nums[i].l>>nums[i].r>>nums[i].val;
    }
    sort(nums+1,nums+1+m);
    int ans(0);
    inc(i,1,m)
    {
        // cin>>nums[i].l>>nums[i].r>>nums[i].val;
        // cout<<nums[i].l<<" "<<nums[i].r<<" "<<nums[i].val<<endl;
        int cnt(T.query(nums[i].r)-T.query(nums[i].l-1));
        if(cnt>=nums[i].val)continue;
        int tmp(nums[i].val-cnt);
        ans+=tmp;
        dec(j,nums[i].r,nums[i].l)
        {
            if(vis[j])continue;
            vis[j]=true;
            T.add(j,1);
            tmp--;
            if(!tmp)break;
        }
    }
    // inc(i,1,n)cout<<T.query(i)-T.query(i-1)<<" ";cout<<endl;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
}
