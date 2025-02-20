#include <iostream>  
#include <string>  
#include <set>  
#include <vector>  
using namespace std;  
#define inc(i,a,b) for(int i(a);i<=b;i++)
// 生成所有子串  
void generateSubsequences(const vector<int>& s, vector<int> current, int index, set<vector<int> >& results) {  
    // 每次递归调用都将当前字符串添加到结果集  
    if (!current.empty()) { // 不添加空串  
        results.insert(current);  
    }  
    // 从当前位置索引继续向后遍历  
    for (int i = index; i < s.size(); i++) {  
        // 选择当前字符并继续递归  
        if(!current.empty()&&s[i]<current.back())continue;
        current.push_back(s[i]);
        generateSubsequences(s, current, i + 1, results);  
        current.pop_back();
    } 
}  
int main() {  
    int _;
    cin>>_;
    while(_--)
    {
        int n;
        cin>>n;
        vector<int> s(n); // 可以将这个 s 替换成任何字符串  
        for(int &tmp:s)cin>>tmp;
        set<vector<int> > results; // 使用 set 来存储子串，以避免重复  
        vector<int> emptyV;
        int ans(0);
        generateSubsequences(s, emptyV, 0, results); // 开始生成子串  
        for (const vector<int>& subsequence : results) {  
            ans=max(ans,(int)subsequence.size());
        }  
        cout<<ans<<endl;
    }
}