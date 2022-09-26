#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
using namespace std;
struct words
{
    int end;
    bool did;
    int step;
};
int main()
{
    int m;
    scanf("%d", &m);

    //可以用map来存一个开头对应的所有结尾
    map<int, vector<words>> word;
    //用队列来确定搜索顺序
    queue<words> search;

    for (int i = 0; i < m; i++) //读进来每个数字并存在map中
    {
        int t1, t2, t3, t4;
        scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
        words temp;
        temp.did = false;
        temp.end = t4;
        temp.step = -1;
        word[t1].push_back(temp);
    }

    //读入开头结尾
    int kaishi[4], jiewei[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &kaishi[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &jiewei[i]);
    }
    words s, e;
    s.did = true;
    s.end = kaishi[3];
    s.step = 1;
    search.push(s);
    e.did = false;
    e.end = jiewei[3];
    e.step = -1;
    int ans=jiewei[0];
    //下面开始比较、
    //先去掉开头结尾相同
    bool flag=false;
    if (kaishi[0] == jiewei[0] && kaishi[3] == jiewei[3] && kaishi[1] == jiewei[1] && kaishi[2] == jiewei[2])
    {
        printf("1\n");
        flag=true;
    }
    else
    {
        while (!search.empty())
        {
            
            for (auto x : word[search.front().end])
            {
                if(!x.did)
                {
                    x.did=true; x.step=search.front().step+1;search.push(x);
                    if(x.end==e.end&&search.front().end==ans)
                    {
                        printf("%d\n",x.step);
                        flag=true;
                    }
                }
            }
            search.pop();
            if(flag)
            {break;}
        }
    }
    if(!flag)
    {
        printf("-1\n");
    }
return 0;
}