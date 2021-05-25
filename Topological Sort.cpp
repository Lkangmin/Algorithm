#include<iostream>
#include<stack>
using namespace std;

int N , flag = 1;
int adj[1001][1001];
int f[1001];
int end[1001];
stack<int> sorted;


void dfs(int x) {
    if (f[x]) {
        flag = 0;
        return;
    }
    f[x] = 1;

    for (int i = 1; i <= N; i++) {
        if (adj[x][i] && !end[i]) {
            dfs(i);
        }
    }
    end[x] = 1;
    sorted.push(x);
}

int main() {
    int E;
    cin >> N >> E;
    while (E) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        E--;
    }
    for (int i = 1; i <= N; i++) {
        if (!end[i]) {
            dfs(i);
        }
    }
    if (sorted.size() != N) flag = 0;

    cout << flag << '\n';
    if (flag) {
        while (!sorted.empty()) {
            cout << sorted.top()<<' ';
            sorted.pop();
        }
        cout << '\n';
    }

    return 0;
}