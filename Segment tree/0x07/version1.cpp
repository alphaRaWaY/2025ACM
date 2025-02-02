//线段树

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define inc(i, a, b) for (int i(a); i <= b; i++)
#define dec(i, a, b) for (int i(a); i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
#define Mod1 998244353
#define Mod2 1004535809
inline int rs(int r){return r<<1|1;}
inline int ls(int r){return r<<1;}
string int128ToString(__int128 x) {
  if (x == 0) return "0";
  string result;
  bool is = x < 0;
  if (is) x = -x;
  while (x > 0) {
    result.push_back('0' + (x % 10));
    x /= 10;
  }
  if (is) result.push_back('-');
  reverse(result.begin(), result.end());
  return result;
}
const int MaxN(5e5+5);
int nums[MaxN];
struct node
{
    int num;
    int l,r;
    int add;
}tr[MaxN];
void build(int pos,int l,int r)
{
    tr[pos].l=l;tr[pos].r=r;
    if(l==r)
    {
        tr[pos].num=nums[l];
        return;
    }
    int mid((l+r)>>1);
    build(ls(pos),l,mid);
    build(rs(pos),mid+1,r);
    tr[pos].num=tr[ls(pos)].num+tr[rs(pos)].num;
}
void spread(int index)
{
    if(tr[index].add)
    {
        tr[ls(index)].add+=tr[index].add;
        tr[rs(index)].add+=tr[index].add;
        tr[ls(index)].num+=tr[index].add*(tr[ls(index)].r-tr[ls(index)].l+1);
        tr[rs(index)].num+=tr[index].add*(tr[rs(index)].r-tr[rs(index)].l+1);
        tr[index].add=0;
    }
}
void add(int index,int l,int r,int val)
{
    if(tr[index].l>=l&&tr[index].r<=r)
    {
        tr[index].num+=(tr[index].r-tr[index].l+1)*val;
        tr[index].add+=val;
        return;
    }
    spread(index);
    int mid((tr[index].l+tr[index].r)>>1);
    if(l<=mid)add(ls(index),l,r,val);
    if(r>mid)add(rs(index),l,r,val);
    tr[index].num=tr[ls(index)].num+tr[rs(index)].num;
}
int search(int index,int l,int r)
{
    if(tr[index].l>=l&&tr[index].r<=r)return tr[index].num;
    spread(index);
    int ans(0);
    int mid((tr[index].l+tr[index].r)>>1);
    if(l<=mid)ans+=search(ls(index),l,r);
    if(r>mid)ans+=search(rs(index),l,r);
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    inc(i,1,n)cin>>nums[i];
    build(1,1,n);
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int l,r,k;
            cin>>l>>r>>k;
            add(1,l,r,k);
        }
        else if(type==2)
        {
            int l,r;
            cin>>l>>r;
            cout<<search(1,l,r)<<endl;
        }
    }
    system("pause");
}