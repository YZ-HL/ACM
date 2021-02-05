#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int ans;
set<string> s1;
queue<string> q1;
string updown(string s){
    string tmp = s;
    s[1] = tmp[3 + 4 * 4]; s[2] = tmp[4 + 4 * 4]; 
    s[3] = tmp[1 + 4 * 4]; s[4] = tmp[2 + 4 * 4];
    
    s[1 + 4] = tmp[1]; s[2 + 4] = tmp[2]; 
    s[3 + 4] = tmp[3]; s[4 + 4] = tmp[4];
    
    s[1 + 4 * 3] = tmp[3 + 4]; s[2 + 4 * 3] = tmp[4 + 4];
    s[3 + 4 * 3] = tmp[1 + 4]; s[4 + 4 * 3] = tmp[2 + 4];
    
    s[1 + 4 * 4] = tmp[1 + 4 * 3]; s[2 + 4 * 4] = tmp[2 + 4 * 3];
    s[3 + 4 * 4] = tmp[3 + 4 * 3]; s[4 + 4 * 4] = tmp[4 + 4 * 3];

    s[1 + 4 * 2] = tmp[2 + 4 * 2];
    s[2 + 4 * 2] = tmp[4 + 4 * 2];
    s[3 + 4 * 2] = tmp[1 + 4 * 2];
    s[4 + 4 * 2] = tmp[3 + 4 * 2];

    s[1 + 4 * 5] = tmp[2 + 4 * 5];
    s[2 + 4 * 5] = tmp[4 + 4 * 5];
    s[3 + 4 * 5] = tmp[1 + 4 * 5];
    s[4 + 4 * 5] = tmp[3 + 4 * 5];

    return s;
}
string leftright(string s){
    string tmp = s;
    s[1 + 4 * 1] = tmp[2 + 4 * 5]; s[2 + 4 * 1] = tmp[1 + 4 * 5];
    s[3 + 4 * 1] = tmp[4 + 4 * 5]; s[4 + 4 * 1] = tmp[3 + 4 * 5];

    s[1 + 4 * 2] = tmp[1 + 4 * 1]; s[2 + 4 * 2] = tmp[2 + 4 * 1];
    s[3 + 4 * 2] = tmp[3 + 4 * 1]; s[4 + 4 * 2] = tmp[4 + 4 * 1];

    s[1 + 4 * 4] = tmp[2 + 4 * 2]; s[2 + 4 * 4] = tmp[1 + 4 * 2];
    s[3 + 4 * 4] = tmp[4 + 4 * 2]; s[4 + 4 * 4] = tmp[3 + 4 * 2];

    s[1 + 4 * 5] = tmp[1 + 4 * 4]; s[2 + 4 * 5] = tmp[2 + 4 * 4];
    s[3 + 4 * 5] = tmp[3 + 4 * 4]; s[4 + 4 * 5] = tmp[4 + 4 * 4];    

    s[1 + 4 * 0] = tmp[2 + 4 * 0];
    s[2 + 4 * 0] = tmp[4 + 4 * 0];
    s[3 + 4 * 0] = tmp[1 + 4 * 0];
    s[4 + 4 * 0] = tmp[3 + 4 * 0];

    s[1 + 4 * 3] = tmp[2 + 4 * 3];
    s[2 + 4 * 3] = tmp[4 + 4 * 3];
    s[3 + 4 * 3] = tmp[1 + 4 * 3];
    s[4 + 4 * 3] = tmp[3 + 4 * 3];

    return s;
}
bool dfs(string now, int cnt){
    if(cnt == 7)
        return !s1.count(now);
    bool flag = !s1.count(now);
    flag &= dfs(updown(now), cnt + 1);
    flag &= dfs(leftright(now), cnt + 1);
    return flag;
}
bool check(string now){
    return dfs(now, 0);
}
string change1(string s){
    string tmp = s;
    
    s[1] = tmp[3 + 4 * 4];
    s[3] = tmp[1 + 4 * 4];
    
    s[1 + 4] = tmp[1];
    s[3 + 4] = tmp[3];
    
    s[1 + 4 * 3] = tmp[3 + 4];
    s[3 + 4 * 3] = tmp[1 + 4];
    
    s[1 + 4 * 4] = tmp[1 + 4 * 3];
    s[3 + 4 * 4] = tmp[3 + 4 * 3];
    
    s[1 + 4 * 5] = tmp[2 + 4 * 5];
    s[3 + 4 * 5] = tmp[1 + 4 * 5];
    s[4 + 4 * 5] = tmp[3 + 4 * 5];
    s[2 + 4 * 5] = tmp[4 + 4 * 5];

    return s;
}
string change2(string s){
    string tmp = s;
    
    s[1 + 4 * 1] = tmp[2 + 4 * 5];
    s[2 + 4 * 1] = tmp[1 + 4 * 5];
    
    s[1 + 4 * 2] = tmp[1 + 4 * 1];
    s[2 + 4 * 2] = tmp[2 + 4 * 1];

    s[1 + 4 * 4] = tmp[2 + 4 * 2];
    s[2 + 4 * 4] = tmp[1 + 4 * 2];

    s[1 + 4 * 5] = tmp[1 + 4 * 4];
    s[2 + 4 * 5] = tmp[2 + 4 * 4];
    
    s[1] = tmp[2];
    s[3] = tmp[1];
    s[4] = tmp[3];
    s[2] = tmp[4];
    
    return s;
}
string change3(string s){
    string tmp = s;
    
    s[3] = tmp[3 + 4 * 5];
    s[4] = tmp[1 + 4 * 5];
    
    s[1 + 4 * 2] = tmp[3];
    s[3 + 4 * 2] = tmp[4];

    s[3 + 4 * 3] = tmp[3 + 4 * 2];
    s[4 + 4 * 3] = tmp[1 + 4 * 2];

    s[1 + 4 * 5] = tmp[3 + 4 * 3];
    s[3 + 4 * 5] = tmp[4 + 4 * 3];
    
    s[1 + 4] = tmp[3 + 4];
    s[2 + 4] = tmp[1 + 4];
    s[3 + 4] = tmp[4 + 4];
    s[4 + 4] = tmp[2 + 4];
    
    return s;
}
void bfs(){
    string sta = "#YYYYOOOOGGGGOOOOYYYYGGGG";
    //string sta = "#AAAABBBBCCCCDDDDEEEEFFFF";
    q1.push(sta); s1.insert(sta);
    while (!q1.empty())
    {
        string now = q1.front(); q1.pop();
        ans++;
        string tmp;
        tmp = change1(now);
        if(!s1.count(tmp) && check(tmp))
            s1.insert(tmp), q1.push(tmp);
        tmp = change2(now);
        if(!s1.count(tmp) && check(tmp))
            s1.insert(tmp), q1.push(tmp);
        tmp = change3(now);       
        if(!s1.count(tmp) && check(tmp))
            s1.insert(tmp), q1.push(tmp);
        if(ans % 10000 == 0)
            printf("%d\n", ans);
    }
}
int main(void)
{
    bfs();
    printf("%d\n", ans);
    return 0;
}
