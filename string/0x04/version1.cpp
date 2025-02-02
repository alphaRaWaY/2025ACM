#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define ALL(x) x.begin(),x.end()
struct node
{
    int cnt;
    unordered_map<char,node*> child;
    node():cnt(0) {}
}*root;
int n,q;
void solve()
{
    cin>>n>>q;
    root=new node;
    inc(i,1,n)
    {
        string s;
        cin>>s;
        node* now=root;
        for(char c:s)
        {
            now->cnt++;
            if(!now->child[c])now->child[c]=new node;
            now=now->child[c];
        }
        now->cnt++;
    }
    while(q--)
    {
        string s;
        cin>>s;
        bool  flag(true);
        node* now=root;
        for(char c:s)
        {
            if(!now->child[c])
            {
                flag=false;
                break;
            }
            now=now->child[c];
        }
        if(!flag)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<now->cnt<<endl;
    }
    delete root;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;cin>>_;while(_--)solve();
    system("pause");
}