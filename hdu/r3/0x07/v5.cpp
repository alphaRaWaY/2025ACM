#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

mt19937_64 rng(time(0));
int n;
vector<pair<int,int> >nums;
set<int> ans;
void solve()
{
    nums.clear();
    ans.clear();
    cin>>n;
    inc(i,1,n)
    {
        int l,r;
        cin>>l>>r;
        r++;
        int index = rng();
        nums.push_back({l,index});
        nums.push_back({r,index});
    }
    sort(nums.begin(),nums.end());
    int cur=0,pre(-1);
    ans.insert(0);
    for(auto[x,y]:nums)
    {
        if(x!=pre)
        {
            ans.insert(cur);
        }
        pre=x;
        cur^=y;
    }
    cout<<ans.size()<<endl;
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