#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define ALL(x) x.begin(),x.end()
unordered_map<string,set<int> > has;
signed main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    inc(i,1,n)
    {
        int tmp;cin>>tmp;
        while(tmp--)
        {
            string s;
            cin>>s;
            has[s].insert(i);
        }
    }
    int m;
    cin>>m;
    while(m--)
    {
        string s;
        cin>>s;
        for(int temp:has[s])
        {
            cout<<temp<<" ";
        }
        cout<<endl;
    }
    system("pause");
}