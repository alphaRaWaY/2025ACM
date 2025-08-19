#include<bits/stdc++.h>
#define ri int
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int, int> PII;
const int N = 150010, M = 1e6 + 10;
int _, n, ans, ansl, ansr, a[N], nxt[M], last[M], order[M];
struct Tree
{
    int l,r,c,tag,pos;
    Tree(){c=tag=0;}
} tr[4 * N];
inline void pushup(int now)
{
    tr[now].c=max(tr[now<<1].c, tr[now<<1|1].c);
    if(tr[now << 1].c >= tr[now << 1 | 1].c)
    {
        tr[now].pos = tr[now << 1].pos;
    }
    else
    {
        tr[now].pos = tr[now << 1 | 1].pos;
    }
}
inline void f(int now,int l,int r,int k){tr[now].tag+=k;tr[now].c+=k;}
inline void pushdown(int now,int l,int r)
{
    int mid=(l+r)>>1;
    f(now<<1,l,mid,tr[now].tag);
    f(now<<1|1,mid+1,r,tr[now].tag);
    tr[now].tag=0;
}
void bt(int now,int l,int r)
{
    tr[now].l=l,tr[now].r=r;
    if(l==r) tr[now].c=0,tr[now].tag = 0,tr[now].pos=l;
    else
    {
        tr[now].c = 0,tr[now].tag = 0;
        int mid=(l+r)>>1;
        bt(now<<1,l,mid);
        bt(now<<1|1,mid+1,r);
        pushup(now);
    }
}
void update(int ul,int ur,int l,int r,int now,int k)
{
    if(ul<=l&&r<=ur)
    {
        tr[now].tag+=k;
        tr[now].c+=k;
        return;
    }
    if(tr[now].tag!=0) pushdown(now,l,r);
    int mid=(l+r)>>1;
    if(ul<=mid)update(ul,ur,l,mid,now<<1,k);
    if(ur>mid) update(ul,ur,mid+1,r,now<<1|1,k);
    pushup(now);
}
int Query(int ql,int qr,int l,int r,int now)
{
    if(ql <= l && r <= qr) return tr[now].c;
    if(tr[now].tag!=0) pushdown(now,l,r);
    int mid=(l+r)>>1,sum=0;
    if(ql <= mid) sum=max(sum,Query(ql,qr,l,mid,now<<1));
    if(qr > mid) sum=max(sum, Query(ql,qr,mid+1,r,now<<1|1));
    return sum;
}
int Query2(int ql,int qr,int l,int r,int now)
{
    if(ql <= l && r <= qr) return tr[now].pos;
    if(tr[now].tag!=0) pushdown(now,l,r);
    int mid=(l+r)>>1,sum=0;
    if(ql <= mid) sum=max(sum,Query2(ql,qr,l,mid,now<<1));
    if(qr > mid) sum=max(sum, Query2(ql,qr,mid+1,r,now<<1|1));
    return sum;
}
void solve()
{
    //nxt:
    ans = ansl = ansr = 0;
    scanf("%d", &n);
    for(ri i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(ri i = 1; i <= n; i++) last[i] = nxt[i] = order[i] = 0;
    bt(1, 1, n);
    for(ri i = 1; i <= n; i++)
    {
        order[i] = order[last[a[i]]] + 1;
        nxt[last[a[i]]] = i;
        last[a[i]] = i;
    }
    for(ri i = 2; i <= n - 1; i++)
    {
        if(order[i - 1] == 1)
        {
            if(nxt[i - 1] + 1 <= last[a[i - 1]])
                update(nxt[i - 1] + 1, last[a[i - 1]], 1, n, 1, 1);
        }
        else
        {
            if(i <= nxt[i - 1]) update(i, nxt[i - 1] , 1, n, 1, -1);
        }
        int res = Query(i + 1, n, 1, n, 1);
        if(res > ans)
        {
            ans = res;
            ansl = i, ansr = Query2(i + 1, n, 1, n, 1);
        }
    }
    if(ans == 0)
    {
        printf("0\n2 3\n");
    }
    else printf("%d\n%d %d\n", ans, ansl, ansr);
    for(ri i = 1; i <= n; i++) last[a[i]] = 0;
}
signed main()
{
    scanf("%d", &_);
    while(_--) solve();
    return 0;
}