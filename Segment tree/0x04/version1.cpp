//虚置位置

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(3e5+5);
int Max[MAXN],Min[MAXN],n(0),m(0),tree[2*MAXN],pos[MAXN];
void update(int index,int val)
{
    while(index<=n+m)
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
    cin>>n>>m;
    int now = m;
    inc(i,1,n){Max[i]=Min[i]=i;pos[i] = m+i;update(m+i,1);}
    inc(_,1,m)
    {
        int tmp;
        cin>>tmp;
        Min[tmp] = 1;
        Max[tmp] = max(Max[tmp],sum(pos[tmp]));
        update(pos[tmp],-1);
        pos[tmp] = now--;
        update(pos[tmp],1);
    }
    inc(i,1,n)
    {
        Max[i] = max(Max[i],sum(pos[i]));
    }
    inc(i,1,n)
    {
        cout<<Min[i]<<" "<<Max[i]<<endl;
    }
    system("pause");
}