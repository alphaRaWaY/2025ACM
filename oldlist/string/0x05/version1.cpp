#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const string anses[3]={"OK","REPEAT","WRONG"};
const int MaxN(1e4+5);
unordered_map<string,bool> has,vis;
signed main()
{
    ios::sync_with_stdio(false);
    int n,q;
    cin>>n;
    inc(i,1,n)
    {
        string s;
        cin>>s;
        has[s]=true;
    }
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        if(!has[s])
        {
            cout<<anses[2]<<endl;
        }
        else if(vis[s])
        {
            cout<<anses[1]<<endl;
        }
        else 
        {
            cout<<anses[0]<<endl;
            vis[s]=true;
        }
    }
    system("pause");
}