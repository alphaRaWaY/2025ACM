#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(2e5+5),INF(0x3f3f3f3f3f);
int n;
vector<pair<int,int>>nums;
void solve()
{
    nums.clear();
    cin>>n;
    inc(i,1,n)
    {
        int x,y;
        cin>>x>>y;
        nums.push_back({x,0});
        nums.push_back({y,1});
    }
    if(n==0)
    {
        cout<<1<<endl;
        return;
    }
    sort(nums.begin(),nums.end());
    vector<pair<int,int> >ss;
    int cnt(0);
    inc(i,0,nums.size()-1)
    {
        if(!i)
        {
            ss.push_back(nums[i]);
            continue;
        }
        auto top = ss.back();
        if(top.first==nums[i].first)
        {
            if(top.second!=nums[i].second&&top.second!=2)
            {
                ss.pop_back();
                ss.push_back({top.first,2});
            }
        }
        else
        {
            if(top.second==0&&nums[i].second==1)
            {
                cnt++;
                ss.pop_back();
            }
            else
            {
                ss.push_back(nums[i]);
            }
        }
    }
    cout<<cnt+ss.size()+1<<endl;
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
7

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

4
2 3
5 8
1 4
6 7

4
2 3
4 8
1 5
6 7


*/