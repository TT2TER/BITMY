#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
const int Max = 1e4 + 1;
int totalNum;
struct node
{
    int l, r;
};
node Node[Max];
struct tr
{
    char key; // key=0 空  key=1 慢
    pair<int, int> find(int);
};
tr tree[Max * 6];
int num[Max * 3];
bool flag;
int nn;

void build(int left, int Right, int k)
{
    tree[k].key = '0';
    if (left == Right)
        return;
    int mid = (left + Right) / 2;
    build(left, mid, k * 2);
    build(mid + 1, Right, k * 2 + 1);
}

pair<int, int> tr::find(int k)
{
    if (k == 1)
        return {1, nn};
    pair<int, int> parent = find(k / 2);
    int l = parent.first, r = parent.second;
    int mid = (l + r) / 2;
    if (k % 2 == 0)
        return {l, mid};
    else
        return {mid + 1, r};
}

int search(int ll, int rr, int k)
{
    int l = ll, r = rr;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (num[mid] == k)
            return mid;
        else if (num[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return 0;
}

void update(int l, int r, int k) // l~r是序列, k是一段长度
{
    if (tree[k].key == '1')
    {
        return;
    }
    else if (tree[k].key == '0')
    {
        if (l == tree[k].find(k).first && r == tree[k].find(k).second)
        {
            tree[k].key = '1';
            flag = 1;
            int q = k / 2;
            while (q > 0)
            {
                if (tree[q * 2].key == '1' && tree[q * 2 + 1].key == '1')
                {
                    tree[q].key = '1';
                }
                q /= 2;
            }
            return;
        }
        int mid = (tree[k].find(k).first + tree[k].find(k).second) / 2;
        if (l <= mid)
        {
            update(l, min(r, mid), k * 2);
        }
        if (mid + 1 <= r)
        {
            update(max(l, mid + 1), r, k * 2 + 1);
        }
    }
}

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        totalNum = 0;
        memset(Node, 0, sizeof(Node));
        memset(tree, 0, sizeof(tree));
        memset(num, 0, sizeof(num));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            int aa, bb;
            scanf("%d %d", &aa, &bb);
            Node[i].l = aa;
            Node[i].r = bb;
            num[i * 3 - 2] = aa;
            num[i * 3 - 1] = bb;
            num[i * 3] = bb + 1;
        }
        //离散化处理
        sort(num + 1, num + 1 + 3 * n);
        nn = unique(num + 1, num + 1 + 3 * n) - num - 1;
        for (int i = 1; i <= n; ++i)
        {
            Node[i].l = search(1, nn, Node[i].l);
            Node[i].r = search(1, nn, Node[i].r);
        }
        //线段树处理
        build(1, nn, 1);
        for (int i = n; i > 0; --i)
        {
            flag = 0;
            update(Node[i].l, Node[i].r, 1);
            if (flag == 1)
                totalNum++;
        }
        printf("%d\n", totalNum);
    }
    return 0;
}