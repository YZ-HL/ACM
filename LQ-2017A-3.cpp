#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
string s = "#111122222222111133333333";
set<string> s1;
queue<string> q1;
string change1(string st){
    string tmp = st;
    st[1] = tmp[1 + 4 * 3];
    st[3] = tmp[3 + 4 * 3];

    st[1 + 4] = tmp[1];
    st[3 + 4] = tmp[3];
    
    st[1 + 4 * 2] = tmp[1 + 4];
    st[3 + 4 * 2] = tmp[3 + 4];

    st[1 + 4 * 3] = tmp[1 + 4 * 2];
    st[3 + 4 * 3] = tmp[3 + 4 * 2];

    return st;
}
string change2(string st){

    string tmp = st;
    st[2] = tmp[2 + 4 * 3];
    st[4] = tmp[4 + 4 * 3];

    st[2 + 4] = tmp[2];
    st[4 + 4] = tmp[4];
    
    st[2 + 4 * 2] = tmp[2 + 4];
    st[4 + 4 * 2] = tmp[4 + 4];

    st[2 + 4 * 3] = tmp[2 + 4 * 2];
    st[4 + 4 * 3] = tmp[4 + 4 * 2];

    return st;
}
string change3(string st){

    string tmp = st;

    st[1 + 4 * 4] = tmp[1 + 4];
    st[2 + 4 * 4] = tmp[2 + 4];
    
    st[1 + 4 * 3] = tmp[1 + 4 * 4];
    st[2 + 4 * 3] = tmp[2 + 4 * 4];

    st[1 + 4 * 5] = tmp[1 + 4 * 3];
    st[2 + 4 * 5] = tmp[2 + 4 * 3];

    st[1 + 4] = tmp[1 + 4 * 5];
    st[2 + 4] = tmp[2 + 4 * 5];

    return st;
}
string change4(string st){

    string tmp = st;

    st[3 + 4 * 4] = tmp[3 + 4];
    st[4 + 4 * 4] = tmp[4 + 4];
    
    st[3 + 4 * 3] = tmp[3 + 4 * 4];
    st[4 + 4 * 3] = tmp[4 + 4 * 4];

    st[3 + 4 * 5] = tmp[3 + 4 * 3];
    st[4 + 4 * 5] = tmp[4 + 4 * 3];

    st[3 + 4] = tmp[3 + 4 * 5];
    st[4 + 4] = tmp[4 + 4 * 5];

    return st;
}
string change5(string st){

    string tmp = st;

    st[3] = tmp[3 + 4 * 5];
    st[4] = tmp[4 + 4 * 5];
    
    st[3 + 4 * 3] = tmp[3];
    st[4 + 4 * 3] = tmp[4];

    st[1 + 4 * 2] = tmp[3 + 4 * 3];
    st[2 + 4 * 2] = tmp[4 + 4 * 3];

    st[3 + 4] = tmp[3 + 4 * 5];
    st[4 + 4] = tmp[4 + 4 * 5];

    return st;
}
int main(void)
{
    int cnt = 0;
    s1.insert(s);
    q1.push(s);
    while(!q1.empty())
    {
        string now = q1.front();
        q1.pop();
        cnt++;
        string tmp;
        
        tmp = change1(now);
        if(!s1.count(tmp))   q1.push(tmp), s1.insert(tmp);
                    
        tmp = change2(now);
        if(!s1.count(tmp))   q1.push(tmp), s1.insert(tmp);

        tmp = change3(now);
        if(!s1.count(tmp))   q1.push(tmp), s1.insert(tmp);
        
        tmp = change4(now);
        if(!s1.count(tmp))   q1.push(tmp), s1.insert(tmp);
    }
    printf("%d\n", cnt);
    return 0;
}
