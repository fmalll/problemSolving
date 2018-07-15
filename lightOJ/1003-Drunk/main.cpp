#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
map<string,int> nodes;
vector<int> G[MAX];
vector<int> H[MAX];
stack<int> topNodes;
int marked[MAX];
int edges;

void input(){
    scanf("%d",&edges);
    string s1,s2;
    int v1,v2;

    while(edges --){
        cin>>s1>>s2;
    if(nodes.find(s1) == nodes.end()) {
        v1 = nodes.size();
        nodes[s1] = v1;
    }
    else {
        v1 = nodes[s1];
    }
    if(nodes.find(s2) == nodes.end()){

        v2 = nodes.size();
        nodes[s2] = v2;
    }
    else {
        v2 = nodes[s2];
    }
    G[v1].push_back(v2);
    H[v2].push_back(v1);}
}
int dfs(int node){
    if(marked[node] == 1)return false;
    marked[node] = 1;
    for(int i = 0;i<G[node].size();i++){
        if(!dfs(G[node][i])) return false;
    }
    return true;
}
int solve(){
    for(int i = 0;i<nodes.size();i++){
        if(H[i].size() == 0) topNodes.push(i);
    }
    if(topNodes.empty()) return false;
    for(int i = 0;i<nodes.size();i++)marked[i] = 0;
    while(!topNodes.empty()){
        if(!dfs(topNodes.top()))return false;
        for(int i = 0;i<nodes.size();i++)marked[i] = 0;
        topNodes.pop();
    }
    return true;
}
void clear(){
    for(int i = 0 ;i< nodes.size();i++){
        marked[i] = 0;
        G[i].clear();
        H[i].clear();
    }
    nodes.clear();
    while(!topNodes.empty()) topNodes.pop();
}
int main() {
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        input();
        if(solve()) printf("Case %d: Yes\n",i+1);
        else  printf("Case %d: No\n",i+1);
        clear();
    }
}