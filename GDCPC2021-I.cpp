#include <bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;
int inX(int x,int y,int z ){
    if (y*y + z*z <= 1000 * abs(x)){
        if (x>0) {
            return 1;
        }
        else {
            return 2;
        }
    }
    return 0;
}
int inY(int x,int y,int z ){
    if (z*z + x*x <= 1000 * abs(y)){
        if (y>0) {
            return 3;
        }
        else {
            return 4;
        }
    }
    return 0;
}
int inZ(int x,int y,int z ){
    if (y*y + x*x <= 1000 * abs(z)){
        if (z>0) {
            return 5;
        }
        else {
            return 6;
        }
    }
    return 0;
}

void judge(int x,int y,int z){
    printf("%lld\n",inX(x,y,z));
    printf("%lld\n",inY(x,y,z));
    printf("%lld\n",inZ(x,y,z));
}
int t, x_1, y_1, z_1, x2, y2, z2;
signed main(void)
{
    //freopen("out.txt", "w", stdout);
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &x_1, &y_1, &z_1);
        scanf("%lld %lld %lld", &x2, &y2, &z2);
        // judge(x_1, y_1, z_1); putchar('\n');
        // judge(x2, y2, z2); putchar('\n');
        if (
            inX(x_1,y_1,z_1) == inX(x2,y2,z2) && 
            inY(x_1,y_1,z_1) == inY(x2,y2,z2) && 
            inZ(x_1,y_1,z_1) == inZ(x2,y2,z2)
        ) {
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
}