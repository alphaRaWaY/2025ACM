#include<bits/stdc++.h>
using namespace std;
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define endl '\n'
#define int long long
namespace stringUtil{

    /********************************
     * kmp
     */
    vector<int> nxt;
    /**
     * 获取nxt数组：每一个位置前后缀相等的长度
     * @param s 字符串
     */
    void getNxt(const string& s)
    {
        nxt.assign(s.size(),-1);
        int j(-1);
        inc(i,1,s.size()-1)
        {
            while(j>=0&&s[j+1]!=s[i])j=nxt[j];
            if(s[j+1]==s[i])j++;   
                nxt[i]=j;
        }
    }

    /**
     * kmp求子串位置
     * @param s1 待匹配串
     * @param s2 子串
     * @return 返回子串出现的各个位置
     */
    vector<int> kmp_pos(string s1,string s2)
    {
        vector<int> ans;
        getNxt(s2);
        // inc(i,0,s2.size()-1)cout<<nxt[i]<<" ";cout<<endl;
        int j(-1);
        inc(i,0,s1.size()-1)
        {
            while(j>=0&&s1[i]!=s2[j+1])j=nxt[j];
            if(s1[i]==s2[j+1])j++;
            if(j==s2.size()-1)
            {
                ans.push_back(i-s2.size()+1);
                j=nxt[j];
            }
        }
        return ans;
    }

    /**
     * kmp求子串位置
     * @param s1 待匹配串
     * @param s2 子串
     * @return 返回子串出现的第一个位置，如果没有出现过则返回-1
     */
    int kmp_check(string s1,string s2)
    {
        getNxt(s2);
        // inc(i,0,s2.size()-1)cout<<nxt[i]<<" ";cout<<endl;
        int j(-1);
        inc(i,0,s1.size()-1)
        {
            while(j>=0&&s1[i]!=s2[j+1])j=nxt[j];
            if(s1[i]==s2[j+1])j++;
            if(j==s2.size()-1) return i-s2.size()+1;
        }
        return -1;
    }

};

void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<int> ans = stringUtil::kmp_pos(s1,s2);
    for(int tmp:ans)cout<<tmp+1<<endl;
    for(int tmp:stringUtil::nxt)cout<<tmp+1<<" ";cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}
/*
ABABABC
ABA
*/