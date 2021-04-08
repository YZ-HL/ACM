#include <bits/stdc++.h>
#define maxn 100005
#define INF (1 << 30)
using namespace std;
int D, P, Ti, Si;
struct Citizen{
    string name;
    string ID;
    string stime;
    int status;
    int las;
    int ct;
};
bool operator < (const Citizen &A, const Citizen &B){
    int ah = (A.stime[0] - '0') * 10 + (A.stime[1] - '0');
    int am = (A.stime[3] - '0') * 10 + (A.stime[4] - '0');
    int bh = (B.stime[0] - '0') * 10 + (B.stime[1] - '0');
    int bm = (B.stime[3] - '0') * 10 + (B.stime[4] - '0');
    if(ah == bh)
    {
        if(am == bm)    return A.ct < B.ct;
        return am < bm;
    }
    return ah < bh;
}
vector<string> susID;
map<string, Citizen> mp;
bool checkID(string str){
    int len = str.length();
    if(len != 18)   return false;
    for(int i = 0; i <= len - 1; i++)
        if(str[i] < '0' || str[i] > '9')
            return false;
    return true;
}
int main(void)
{
    //freopen("input.txt", "r", stdin);
    //freopen("debug.txt", "w", stdout);
    scanf("%d %d", &D, &P);
    for(int nD = 1; nD <= D; nD++)
    {
        scanf("%d %d", &Ti, &Si);
        //printf("DEBUG: %d %d %d\n", nD, Ti, Si);
        vector<Citizen> vday;
        vector<string> canID;
        for(int i = 1; i <= Ti; i++)
        {
            int tsta;
            string tname, tID, tstime;
            cin >> tname >> tID >> tsta >> tstime;
            //cout << "debug: " << tname << " " << tID << " " << tsta << " " << tstime << '\n';
            if(!checkID(tID))    continue;
            if(!mp.count(tID))
                mp[tID] = (Citizen){tname, tID, tstime, tsta, -INF, 0};
            //HACK 2, mp[tID]其他权值没有更新
            mp[tID].ct = i;
            mp[tID].status = tsta;
            mp[tID].stime = tstime;
            vday.push_back(mp[tID]);
            if(tsta == 1 && !count(susID.begin(), susID.end(), tID))
                susID.push_back(tID);
        }
        //if(vday.size() == 0 || Si == 0)    continue;
        
        //HACK 4, 直接sort需要记录出现次序，判断先输出哪一个
        sort(vday.begin(), vday.end());
        for(int i = 0; i < vday.size(); i++)
        {
            //HACK 1, Si == 0 放到 if(vday[i].las + P ....) 后
            if(Si == 0)    break;
            //HACK 3, 原来我这里写的是vday[i].las, 而不是mp[vday[i].ID].las
            //这不能处理一个人在一天内连续申请（WA 5）
            if(mp[vday[i].ID].las + P + 1 <= nD)
            {
                canID.push_back(vday[i].ID);
                mp[vday[i].ID].las = nD;
                Si--;
            }
        }
        //cout << "DEBUG: " << canID.size() << endl;
        //printf("+++\n");     
        for(int i = 0; i < canID.size(); i++)
            cout << mp[canID[i]].name << ' ' << canID[i] << '\n';
        //printf("+++\n");     
    }
    for(int i = 0; i < susID.size(); i++)
        cout << mp[susID[i]].name << ' ' << susID[i] << '\n';
    return 0;
}
