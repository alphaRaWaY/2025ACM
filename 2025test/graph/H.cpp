#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int MAXN(2e5+5);
int n;
vector<vector<int> >p;
queue<int> roots;
vector<int> child[MAXN];
void solve()
{
    cin>>n;
    p.clear();
    inc(i,1,n)child[i].clear();
    inc(i,1,n)
    {
        int a;
        cin>>a;
        if(a==i)
        {
            roots.push(i);
            continue;
        }
        child[a].push_back(i);
    }
    while(!roots.empty())
    {
        int r=roots.front();
        roots.pop();
        vector<int> np;
        int pos(r);
        while(pos)
        {
            np.push_back(pos);
            if(!child[pos].empty())
            {
                inc(i,1,child[pos].size()-1)roots.push(child[pos][i]);
                pos=child[pos].front();
            }
            else pos=0;
        }
        p.push_back(np);
    }
    cout<<p.size()<<endl;
    for(vector<int> np:p)
    {
        cout<<np.size()<<endl;
        for(int tmp:np)cout<<tmp<<" ";cout<<endl;
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
    system("pause");
}
/*
6
5
3 1 3 3 1
4
1 1 4 1
7
1 1 2 3 4 5 6
1
1
6
4 4 4 4 1 2
4
2 2 2 2

*/