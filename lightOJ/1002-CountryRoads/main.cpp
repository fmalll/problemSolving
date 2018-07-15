#include <bits/stdc++.h>

#define MAX 505
using namespace std;
vector<pair<int, int> > G[MAX];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > distSoFar;
int finalDist[MAX];
int lastNode, nodeNumbers;
map<pair<int, int>, int> dists;

void clear() {
    for (int i = 0; i < MAX; i++) {
        G[i].clear();

    }
    dists.clear();
}

int solve() {
    while (!distSoFar.empty()) {
        pair<int, int> wn = distSoFar.top();
        distSoFar.pop();
        int node = wn.second;
        int weight = wn.first;
        if(finalDist[node] > -1 and node != lastNode) continue;
        finalDist[node] = weight;

        for (int i = 0; i < G[node].size(); i++) {
            int neighbor = G[node][i].second;
            int weightNeighbor = G[node][i].first;
            if (finalDist[neighbor] == -1) {
                distSoFar.push(make_pair(max(weightNeighbor ,weight), neighbor));
            }
        }
    }
    for (int i = 0; i < nodeNumbers; i++) {
        if (finalDist[i] == -1) printf("Impossible\n");
        else printf("%d\n", finalDist[i]);
    }
}

void input() {
    int n, m;
    scanf("\n");
    scanf("%d %d", &n, &m);
    nodeNumbers = n;


    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (dists.find(make_pair(u, v)) == dists.end()) {
            dists[make_pair(u, v)] = w;
            dists[make_pair(v, u)] = w;
        }
        else {
            dists[make_pair(u, v)] = min(w, dists[make_pair(u, v)]);
            dists[make_pair(v, u)] = min(w, dists[make_pair(u, v)]);
        }
    }
    for (map<pair<int, int>, int>::iterator iter = dists.begin(); iter != dists.end(); iter++) {
        int u = (*iter).first.first;
        int v = (*iter).first.second;
        int w = (*iter).second;
        G[u].push_back(make_pair(w, v));
    }
    scanf("%d", &lastNode);
    for (int i = 0; i < nodeNumbers; i++) {
        finalDist[i] = -1;
    }
    finalDist[lastNode] = 0;
    distSoFar.push(make_pair(0, lastNode));
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        input();
        printf("Case %d:\n", i + 1);
        solve();
        clear();
    }
}