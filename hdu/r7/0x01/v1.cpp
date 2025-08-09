#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

// #define LOCAL
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

const int MaxN(1e6+5);
pair<int,int> point[MaxN];
map<pair<int,int>,int> val;
int n,k;

struct T
{
    vector<int> nums;
    int sz;
    int lowbit(int a){return a&(-a);}
    int query(int index)
    {
        int res(0);
        while(index)
        {
            res+=nums[index];
            index-=lowbit(index);
        }
        return res;
    }
    void update(int index,int val)
    {
        while(index<=sz)
        {
            nums[index]+=val;
            index+=lowbit(index);
        }
    }
    void update(int l,int r,int val)
    {
        update(r,val);
        update(l-1,-val);
    }
    T(int n)
    {
        nums.resize(n+1);
        sz=n;
    }
};

int cal_vertical(int left,int right,int height,set<int> ys,T& tree)
{
    int ans(0);
    for(int tmp:ys)
    {
        int value=tree.query(tmp)-tree.query(max(tmp-height,0));
        debug0(value);
        ans=max(ans,value);
    }
    return ans;
}
int cal_horizontal(int width,int height)
{
    T tree(n);
    set<int>ys;
    int ans(0);
    int l(1),r(1);
    for(;r<n;r++)
    {
        if(point[r].first>point[l].first+width-1)ans=max(cal_vertical(point[l].first,point[r-1].first,height,ys,tree),ans);
        while(point[r].first>point[l].first+width-1)
        {
            ys.erase(point[l].second);
            tree.update(point[l].second+1,n,-val[point[r]]);
            l++;
        }      
        ys.insert(point[r].second);  
        tree.update(point[r].second+1,n,val[point[r]]);
    }
    ans=max(cal_vertical(l,r,height,ys,tree),ans);
    return ans;
}
void solve()
{
    val.clear();
    cin>>n>>k;
    inc(i,1,n)
    {
        int a,b,c;
        cin>>a>>b>>c;
        point[i].first=a;
        point[i].second=b;
        val[{a,b}]+=c;
    }
    debug1(point,1,n);
    debug2(weight,1,1,n,n);
    sort(point+1,point+1+n);
    int ans(0);
    inc(i,1,sqrt(k))
    {
        ans=max(ans,cal_horizontal(i,k/i));
        ans=max(ans,cal_horizontal(k/i,i));
    }
    cout<<ans<<endl;
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
2
5 4
1 2 5
2 1 8
4 4 1
4 5 2
5 5 3
2 1
1 1 1
1 1 1
*/