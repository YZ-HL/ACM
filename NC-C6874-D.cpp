#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000005
#define int long long
using namespace std;
int n, q, a[maxn];
struct tree{
	int left;
	int right;
	int minn;
    int maxx;
    int num;
    int lazy_sum;
}tree[maxn];
void Build(int x, int left, int right){
	tree[x].left = left;
	tree[x].right = right;
	if(left == right)
	{
        tree[x].num = a[left];
        tree[x].minn = a[left];
        tree[x].maxx = a[left];
		return;
	}
	int mid = (left+right)>>1;
	Build((x<<1), left, mid);
	Build((x<<1)+1, mid+1, right);
    tree[x].num = tree[(x<<1)].num+tree[(x<<1)+1].num;
	tree[x].minn = min(tree[(x<<1)].minn, tree[(x<<1)+1].minn);
    tree[x].maxx = max(tree[(x<<1)].maxx, tree[(x<<1)+1].maxx);
}
void PushDown(int x){
    
	tree[(x<<1)].num += tree[x].lazy_sum;
	tree[(x<<1)+1].num += tree[x].lazy_sum;
    
    tree[(x<<1)].minn += tree[x].lazy_sum;
	tree[(x<<1)+1].minn += tree[x].lazy_sum;
    tree[(x<<1)].maxx += tree[x].lazy_sum;
	tree[(x<<1)+1].maxx += tree[x].lazy_sum;
	
    tree[(x<<1)].lazy_sum += tree[x].lazy_sum;
	tree[(x<<1)+1].lazy_sum += tree[x].lazy_sum;
	tree[x].lazy_sum = 0;
}
void UpDate(int x, int left, int right, int k){
	if(tree[x].left >= left && tree[x].right <= right)
	{
		tree[x].minn += k;
        tree[x].maxx += k;
        tree[x].num += k;
        tree[x].lazy_sum += k;
		return;
	}
	if(tree[x].left > right || tree[x].right < left)
		return;
	if(tree[x].lazy_sum)	PushDown(x);
	UpDate((x<<1), left, right, k);
	UpDate((x<<1)+1, left, right, k);

	tree[x].num = tree[(x<<1)].num+tree[(x<<1)+1].num;
    tree[x].minn = min(tree[(x<<1)].minn, tree[(x<<1)+1].minn);
    tree[x].maxx = max(tree[(x<<1)].maxx, tree[(x<<1)+1].maxx);
}
int Query_minn(int x, int left, int right){
	PushDown(x);
	if(tree[x].left >= left && tree[x].right <= right)
		return tree[x].minn;
	if(tree[x].left > right || tree[x].right < left)
		return (1<<30);
	return min(Query_minn((x<<1), left, right),Query_minn((x<<1)+1, left, right));
}
int Query_maxx(int x, int left, int right){
	PushDown(x);
	if(tree[x].left >= left && tree[x].right <= right)
		return tree[x].maxx;
	if(tree[x].left > right || tree[x].right < left)
		return -1;
	return max(Query_maxx((x<<1), left, right),Query_maxx((x<<1)+1, left, right));
}
int Query(int x, int left, int right){
	PushDown(x);
	if(tree[x].left >= left && tree[x].right <= right)
        return tree[x].num;
    if(tree[x].left > right || tree[x].right < left)
		return 0;
	return Query((x<<1), left, right)+Query((x<<1)+1, left, right);
}
signed main(void)
{
    scanf("%lld %lld", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    Build(1, 1, n);
    for(int i = 1; i <= q; i++)
    {
        int op, in1, in2;
        scanf("%lld %lld %lld", &op, &in1, &in2);
        if(op == 1)
        {
            UpDate(1, in1, in1, in2-a[in1]);
            a[in1] = in2;
        }
        else
        {
            int sum = Query(1, in1, in2);
            int minn = Query_minn(1, in1, in2);
            int maxx = Query_maxx(1, in1, in2);
            //printf("DEBUG: %lld %lld %lld\n", sum, minn, maxx);
            int len = in2 - in1 + 1;
            printf((maxx - minn + 1 == len && len * (minn + maxx) / 2 == sum) ? "YES\n" : "NO\n");
        }
    }
    //system("pause");
    return 0;
}
