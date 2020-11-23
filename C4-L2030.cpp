#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m, used[maxn];
struct Person{
    int fa, sex;
    string fir, sec;
} P[maxn];
map<string, int> mp;
map<pair<string, string>, int> mps;
int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> P[i].fir >> P[i].sec;
        mp[P[i].fir] = i;
        if(P[i].sec[P[i].sec.size()-1] == 'm')  P[i].sex = 1;
        if(P[i].sec[P[i].sec.size()-1] == 'f')  P[i].sex = 0;
        if(P[i].sec.find("sson") != -1)       P[i].sex = 1;
        if(P[i].sec.find("sdottir") != -1)    P[i].sex = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        if(P[i].sec[P[i].sec.size()-1] == 'm' || P[i].sec[P[i].sec.size()-1] == 'f')  
        {
            P[i].fa = -1;
            mps[make_pair(P[i].fir, P[i].sec.substr(0, P[i].sec.size()-1))] = 1;
        }
        if(P[i].sec.find("sson") != -1)
        {
            string fa = P[i].sec.substr(0, P[i].sec.size()-4);
            P[i].fa = mp[fa];
            mps[make_pair(P[i].fir, fa)] = 1;
        }
        if(P[i].sec.find("sdottir") != -1)
        {
            string fa = P[i].sec.substr(0, P[i].sec.size()-7);
            P[i].fa = mp[fa];
            mps[make_pair(P[i].fir, fa)] = 1;
        }
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        memset(used, 0, sizeof(used));

        string name1f, name1s, name2f, name2s;
        cin >> name1f >> name1s >> name2f >> name2s;
        //if(!mp.count(name1f) || !mp.count(name2f))
        if(!mps.count(make_pair(name1f, name1s)) || !mps.count(make_pair(name2f, name2s)))
        {
            cout << "NA" << endl;
            continue;
        }
        if(P[mp[name1f]].sex == P[mp[name2f]].sex)
        {
            cout << "Whatever" << endl;
            continue;
        }

        int flag = 0, cnt = 1, now;
        
        now = mp[name1f];
        used[now] = 1;
        while(P[now].fa != -1)
        {
            //cout << P[now].fir << endl;
            used[P[now].fa] = cnt + 1;
            now = P[now].fa;
            cnt++;
        }     

        cnt = 1;
        now = mp[name2f];
        if(used[now])   flag = 1;
        used[now] = 1;
        while(P[now].fa != -1)
        {
            //cout << P[now].fa << endl;
            if(used[P[now].fa])    
            {
                //cout << used[P[now].fa] << " " << cnt << endl;
                flag = (used[P[now].fa] <= 4 || cnt <= 3) ? 1 : 0;
                break;
            }
            used[P[now].fa] = 1;
            now = P[now].fa;
            cnt++;
        }
        cout << (flag ? "No" : "Yes") << endl;       
    }
    return 0;
}