#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, ed, mp[maxn], all[maxn];
char st[10];
int hash_it(char *str){
    int len = strlen(str);
    int sum = 0;
    for(int i = 0; i <= len - 1; i++)
        sum = sum * 10 + (str[i] - '0');
    return sum;
}
struct Node{
    int data;
    char add[10];
    char nxt[10];
} N[maxn];
int main(void)
{
    scanf("%s %d", st, &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s %d %s", N[i].add, &N[i].data, N[i].nxt);
        mp[hash_it(N[i].add)] = i;
    }
    int stt = mp[hash_it(st)];
    //printf("*********\n");
    while(stt != -1)
    {
        all[++all[0]] = hash_it(N[stt].add);
        //printf("%s %d %s\n", N[stt].add, N[stt].data, N[stt].nxt);
        if(strcmp(N[stt].nxt, "-1"))
        {
            stt = mp[hash_it(N[stt].nxt)];
        }
        else
        {
            ed = hash_it(N[stt].add);
            mp[ed] = stt;
            stt = -1;
        }
    } 
    //printf("*********\n");
    
    for(int i = 1; i <= all[0]; i++)
        printf("%s\n", N[mp[all[i]]].add);
    
    int flag = 1, lf = 1, rt = all[0], now = mp[ed], cnt = 0;
    while(cnt < all[0])
    {
        printf("%s %d %s\n", N[now].add, N[now].data, cnt == all[0] - 1 ? "-1" : N[mp[all[flag ? lf : rt]]].add);
        now = mp[all[flag ? lf : rt]];
        flag ? rt-- : lf++;
        flag ^= 1;
        cnt++;
    }
    return 0;
}
