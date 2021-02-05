#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
set<string> used;
struct Status{
    int step;
    string sta;
};
int calc(int x){
    return (x + 9) % 9;
}
int bfs(string s, string t){
    queue<Status> q1;
    q1.push((Status){0, s});
    used.insert(s);
    while(!q1.empty())
    {
        Status now = q1.front();
        q1.pop();
        
        //cout << now.step << endl;
        //system("pause");

        if(now.sta == t)    return now.step;
        int pos = -1;
        for(int i = 0; i <= now.sta.length() - 1; i++)
            if(now.sta[i] == '0')   
            {
                pos = i;
                break;
            }
        //1
        swap(now.sta[calc(pos - 1)], now.sta[pos]);
        if(!used.count(now.sta))
        {
            used.insert(now.sta);
            q1.push((Status){now.step + 1, now.sta});
        }
        swap(now.sta[calc(pos - 1)], now.sta[pos]);
        //2
        swap(now.sta[calc(pos + 1)], now.sta[pos]);
        if(!used.count(now.sta))
        {
            used.insert(now.sta);
            q1.push((Status){now.step + 1, now.sta});
        }
        swap(now.sta[calc(pos + 1)], now.sta[pos]);
        //3
        swap(now.sta[calc(pos - 2)], now.sta[pos]);
        if(!used.count(now.sta))
        {
            used.insert(now.sta);
            q1.push((Status){now.step + 1, now.sta});
        }
        swap(now.sta[calc(pos - 2)], now.sta[pos]);
        //4
        swap(now.sta[calc(pos + 2)], now.sta[pos]);
        if(!used.count(now.sta))
        {
            used.insert(now.sta);
            q1.push((Status){now.step + 1, now.sta});
        }
        swap(now.sta[calc(pos + 2)], now.sta[pos]);
    }
}
int main(void)
{
    //printf("%d\n", bfs("123456780", "876543210"));
    printf("%d\n", 20);
    return 0;
}
