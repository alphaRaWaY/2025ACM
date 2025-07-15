#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(2e5+5),INF(0x3f3f3f3f);
int n,q;
int nums[MaxN];
map<int,int> cnt,cnt1;
multiset<int> q1;
multiset<int> q2;
void justify()
{
    while(q1.size()<q2.size())
    {
        int tmp=*q2.begin();
        auto t = q2.find(tmp);
        q2.erase(t),q1.insert(tmp);
        cnt1[tmp]++;
    }
    while(q1.size()>q2.size()+1)
    {
        int tmp=*--q1.end();
        auto t = q1.find(tmp);
        q1.erase(t),q2.insert(tmp);
        cnt1[tmp]--;
    }
}
void insert_q(int p)
{
    if(q1.empty()||p<=(*--q1.end())){
        q1.insert(p);
        cnt1[p]++;
    } 
    else q2.insert(p);
    justify();
}
void erase_q(int q)
{
    auto tmp1 = q1.find(q);
    auto tmp2 = q2.find(q);
    if(tmp1!=q1.end()) {
        q1.erase(tmp1);
        cnt1[q]--;
    }
    else q2.erase(tmp2);
    justify();
}
int getMid()
{
    return *--q1.end();
}
void debug()
{
    cout<<"q1: ";
    for(auto tmp:q1)cout<<tmp<<" ";cout<<endl;
    cout<<"q2: ";
    for(auto tmp:q2)cout<<tmp<<" ";cout<<endl;
}
void debugCnt1()
{
    for(auto[x,y]:cnt1)cout<<x<<","<<y<<endl;
}
void solve()
{
    q1.clear();
    q2.clear();
    cnt.clear();
    cnt1.clear();
    cin>>n>>q;
    inc(i,1,n)
    {
        cin>>nums[i];
        cnt[nums[i]]++;
        insert_q(nums[i]);
        // q1.insert(nums[i]);
        // cnt1[nums[i]]++;
    }
    // justify();
    while(q--)
    {
        int pos,val;
        cin>>pos>>val;
        cnt[nums[pos]]--;
        erase_q(nums[pos]);
        nums[pos]+=val;
        insert_q(nums[pos]);
        cnt[nums[pos]]++;
        if(*q2.begin()==getMid())
        {
            cout<<q1.size()-cnt1[getMid()]<<endl;
        }
        else
        {
            cout<<n-q2.size()<<endl;
        }
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