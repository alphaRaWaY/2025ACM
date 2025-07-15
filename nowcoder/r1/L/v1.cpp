#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(2e5+5),INF(0x3f3f3f3f);
int n,q;
int nums[MaxN];
map<int,int> cnt;
multiset<int> q1;
multiset<int> q2;
void justify()
{
    while(q1.size()<q2.size())
    {
        int t=*q2.begin();
        q2.erase(t),q1.insert(t);
    }
    while(q1.size()>q2.size()+1)
    {
        int t=*--q1.end();
        q1.erase(t),q2.insert(t);
    }
}
void insert_q(int p)
{
    if(q1.empty()||p<=(*--q1.end())) q1.insert(p);
    else q2.insert(p);
    justify();
}

void erase_q(int q)
{
    auto tmp1 = q1.find(q);
    auto tmp2 = q2.find(q);
    if(tmp1!=q1.end()) q1.erase(tmp1);
    else q2.erase(tmp2);
    justify();
}
int getMid()
{
    return *--q1.end();
}
void solve()
{
    q1.clear();
    q2.clear();
    cnt.clear();
    cin>>n>>q;
    inc(i,1,n)
    {
        cin>>nums[i];
        cnt[nums[i]]++;
        q1.insert(nums[i]);
    }
    inc(i,1,n)
    justify();
    while(q--)
    {
        int pos,val;
        cin>>pos>>val;
        cnt[nums[pos]]--;
        if(!cnt[nums[pos]])
        {
            erase_q(nums[pos]);
        }
        nums[pos]++;
        if(!cnt[nums[pos]])
        {
            insert_q(nums[pos]);
        }
        cnt[nums[pos]]++;
        int ans1(0),ans2(0),ans3(0);
        cout<<getMid()<<endl;
        // ans2=cnt[getMid()];
        // for(auto tmp:q2)
        // {
        //     cout<<"["<<tmp<<"]"<<endl;
        //     ans3+=cnt[tmp];
        // }
        // ans1=n-ans3-ans2;
        // cout<<getMid()<<" "<<ans1<<" "<<ans2<<" "<<ans3<<" "<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _=1;
    cin>>_;
    while(_--)solve();
}

/*

2
5 3
1 2 3 4 5
2 1
3 2
2 1
4 2
4 5 2 3
4 1
4 3

*/