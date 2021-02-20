#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, diff, ans1[maxn], ans2[maxn];
char get_ans(){
    char ch = getchar();
    while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D')    ch = getchar();
    return ch;   
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)     ans1[i] = get_ans();
    for(int i = 1; i <= n; i++)     ans2[i] = get_ans();
    for(int i = 1; i <= n; i++)     if(ans1[i] != ans2[i])  diff++;
    printf("%d\n", 2 * n - diff);
    return 0;
}