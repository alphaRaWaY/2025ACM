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
#define ll int
#else
#define debug0(x)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif

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
    T(int n)
    {
        nums.resize(n+1);
        sz=n;
    }
};

int id,n,m,k;
int g[15][15];
int pp[105][15];
void solve()
{   
    cin>>id>>m>>k>>n;
    inc(i,1,m)
    {
        inc(j,1,k)
        {
            T tree(105);
            int cnt(0);
            inc(_,1,n*n)
            {
                int tmp;
                cin>>tmp;
                tree.update(tmp+1,1);
                cnt+=_-1-tree.query(tmp);
            }
            pp[i][j]=cnt;
        }
    }
    inc(i,1,m)
    {
        char ans('0');
        inc(j,1,k)
        {
            if(pp[i][j]&1)
            {
                ans='1';
                break;
            }
        }
        cout<<ans;
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
}