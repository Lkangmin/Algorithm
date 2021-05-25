#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node
{
    int start;
    int end;
    int weight;
    bool valid;
}Node;

vector<Node> set;
int g[1001], cnt;

bool cmp(const Node& temp1, const Node& temp)
{
    if (temp1.weight != temp.weight)
        return temp1.weight < temp.weight;
    if (temp1.start != temp.start)
        return temp1.start < temp.start;
    else
        return temp1.end < temp.end;
}


int find_set(int x)
{
    int r = x;
    while (g[r] > 0)
    {
        r = g[r];
    }
    return r;
}

void union_set(int a, int b)
{
    if (g[a] < g[b]) g[b] = a;
    else
    {
        if (g[a] == g[b]) g[b]--;
        g[a] = b;
    }
}

int main()
{
    int n, e;
    int x, y, w;
    scanf("%d %d", &n, &e);
    while (e) {
        scanf("%d %d %d", &x, &y, &w);
        Node node;
        if (x < y) {
            node.start = x;
            node.end = y;
        }
        else {
            node.start = y;
            node.end = x;
        }
        node.weight = w; node.valid = false;
        set.push_back(node);
        e--;
    }
    sort(set.begin(), set.end(), cmp);
    for (int i = 0; i < set.size(); ++i) {
        if (find_set(set[i].start) != find_set(set[i].end)) {
            union_set(find_set(set[i].start), find_set(set[i].end));
            cnt++; set[i].valid = true;
        }
    }
    printf("%\d\n",cnt);
    for (int i = 0; i < set.size(); ++i)
        if (set[i].valid)
            printf("%d %d %d\n", set[i].start, set[i].end, set[i].weight);
    return 0;
}