//归并排序实现

#include<bits/stdc++.h>
using namespace std;
//#define DEBUG
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e5+5);
int n,nums[MAXN],ans(0),tmp[MAXN];
//合并
void Merge(int l,int r)
{
    int mid((l+r)>>1);
    int l1=l,l2=mid+1,pos(l);
    while(l1<=mid&&l2<=r)
    {
        if(nums[l1]>nums[l2])
        {
            ans+=mid-l1+1;
            tmp[pos++] = nums[l2];
            l2++;
        }
        else
        {
            tmp[pos++] = nums[l1];
            l1++;
        }
    }
    while(l1<=mid)
    {
        tmp[pos++] = nums[l1];
        l1++;
    }
    while(l2<=r)
    {
        tmp[pos++] = nums[l2];
        l2++;
    }
    inc(i,l,r)
    {
        nums[i]=tmp[i];
    }
}
//归并排序
void merge_sort(int l,int r)
{
    if(l==r)return;
    int mid((l+r)>>1);
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    Merge(l,r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    merge_sort(1,n);
    cout<<ans<<endl;
    system("pause");
}