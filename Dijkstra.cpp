#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAX 2100000000
using namespace std;

int dis[5001];

vector<pair<int, int> > adj[5001];
priority_queue<pair<int, int> > prio_q;

int main() {
    int n,m; 
    scanf("%d %d", &n,&m);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        adj[x].push_back(make_pair(y, w));
    }

    for (int i = 1; i <= n; i++) dis[i] = MAX;

    prio_q.push(make_pair(0, 1));
    dis[1] = 0;

    while (!prio_q.empty()) {
        int now = prio_q.top().second;
        int n_dis = -prio_q.top().first;
        prio_q.pop();

        if (dis[now] < n_dis) continue;

        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i].first;
            int x_dis = n_dis + adj[now][i].second;

            if (dis[next] > x_dis) {
                dis[next] = x_dis;
                prio_q.push(make_pair(-x_dis, next));
            }
        }
    }

    int res = -MAX;
    for (int i = 1; i <= n; i++) 
        if (res < dis[i]) res = dis[i];
    printf("%d\n", res);

    return 0;
}