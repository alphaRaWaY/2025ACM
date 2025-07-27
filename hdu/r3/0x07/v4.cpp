#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(2e5+5),INF(0x3f3f3f3f3f);
int n;
pair<int,int> nums[MaxN];
priority_queue< int > q;
bool cmp1(pair<int,int> x, pair<int,int> y) {
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}
bool cmp2(pair<int,int> x, pair<int,int> y) {
    if (x.second == y.second) return x.first < y.first;
    return x.second > y.second;
}
void solve()
{
    cin>>n;
    inc(i,1,n)
    {
        cin>>nums[i].first>>nums[i].second;
    }
    set<int> ans;
    sort(nums + 1, nums + n + 1, cmp1);
//    cerr<<'*';
    while (!q.empty()) q.pop();
//    cerr<<'*';
    inc(i,1,n)
    {
//        cerr<<'*';
        ans.insert(nums[i].first);
//        cerr<<'*';
        while (!q.empty() && -q.top() < nums[i].first) q.pop();
//        cerr<<'*';
        if (!q.empty() && -q.top() < nums[i].second) ans.insert(nums[i].second);
//        cerr<<'*';
        q.push(-nums[i].second);
//        cerr<<'*';
    }
    sort(nums + 1, nums + n + 1, cmp2);
    while (!q.empty()) q.pop();
    inc(i,1,n)
    {
        while (!q.empty() && q.top() > nums[i].second) q.pop();
        if (!q.empty() && q.top() > nums[i].first) ans.insert(nums[i].second);
        q.push(nums[i].first);
    }
    cout<<ans.size()+1<<endl;
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
5
1
1 6
4
0 12
4 13
6 13
12 13
0
3
-1 1
0 1
0 2
2
0 1
0 1
*/