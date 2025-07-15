//使用树状数组

#include<bits/stdc++.h>
using namespace std;
//#define DEBUG
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e5+5);
int n,nums[MAXN],tree[MAXN];
struct node
{
    int val,ID;
    bool operator < (node & tmp) const 
    {
        if(val==tmp.val) return ID<tmp.ID;
        return val<tmp.val;
    }
}nodes[MAXN];
void update(int index,int val)
{
    while(index<=n)
    {
        tree[index]+=val;
        index+=index&-index;
    }
}
int sum(int index)
{
    int res(0);
    while(index)
    {
        res+=tree[index];
        index-=index&-index;
    }
    return res;
}
signed main()
{
    //ios::sync_with_stdio(false);
    cin>>n;
    inc(i,1,n)
    {
        nodes[i].ID=i;
        cin>>nodes[i].val;
    }
    sort(nodes+1,nodes+n+1);
    inc(i,1,n)nums[nodes[i].ID]=i;
    int ans(0);
    inc(i,1,n)
    {
        update(nums[i],1);
        ans+=i-sum(nums[i]);
    }
    #ifdef DEBUG
    inc(j,1,n)
    {
        cout<<nums[j]<<" ";
    }
    cout<<endl;
    #endif
    #ifndef DEBUG
    cout<<ans<<endl;
    #endif
    system("pause");
}