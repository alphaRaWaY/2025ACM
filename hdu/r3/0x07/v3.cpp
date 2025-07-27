#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(2e6+5);
int n;
pair<int,int> nums[MaxN];
map<int,pair<int,int>> status;
void solve()
{
    status.clear();
    cin>>n;
    inc(i,1,n)
    {
        int x,y;
        cin>>x>>y;
        nums[i].first=x;
        nums[i].second=y;
        if(status[x].second){
            if(status[x].first!=0)status[x]={2,i};
            if(nums[status[x].second].second>y)status[x].second=n+1;
        }
        else status[x]={0,i};  
        if(status[y].second)
        {
            if(status[y].first!=1)status[y]={2,i};
            if(nums[status[y].second].first<x)status[y].second=n+1;
        }
        else status[y]={1,i};  
    }
    if(!n)
    {
        cout<<1<<endl;
        return;
    }
    int cnt(0);
    vector<pair<int,int> > ss;
    for(auto[pos,ed]:status)
    {
        if(ss.empty())
        {
            ss.push_back(ed);
            continue;
        }
        auto top=ss.back();
        if(ed.first==1&&top.first==0)
        {
            ss.pop_back();
            cnt++;
            if(ed.second!=top.second||top.second==n+1)
            {
                ss.push_back({2,0});
                cnt--;
            }
        }
        else ss.push_back(ed);
    }
    cout<<ss.size()+cnt+1<<endl;
}   
signed main()
{
    ios::sync_with_stdio(false);
    int 🐷;
    🐷=1;
    cin>>🐷;
    while(🐷--)solve();
}

/*
9

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

3
1 4
2 6
3 5

2
1 3
1 2
*/

/*
1
6
4 6
4 8
4 7
1 5
3 5
2 5
*/