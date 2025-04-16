#include<bits/stdc++.h>
#define inc(i,a,b) for(int i(a);i<=b;i++)
using namespace std;
set<string> s;
int main()
{
    int n;
    cin>>n;
    inc(i,1,n)
    {
        string tmp;
        cin>>tmp;
        s.insert(tmp);
    }    
    cout<<s.size()<<endl;
    // system("pause");
}