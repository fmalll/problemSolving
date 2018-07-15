#include <bits/stdc++.h>

#define MAX 203
using namespace std;
int G[MAX][MAX];
int path[MAX][MAX];
int rowNumber;

void input(){
    int num;
    scanf("%d",&rowNumber);
    for(int i = 0;i<rowNumber;i++){
        for(int j = 0;j<i+1;j++){
            scanf("%d",&num);
            G[i][j] = num;
        }
    }
    for(int i = 0;i<rowNumber - 1 ;i++){
        for(int j = 0;j<rowNumber - i - 1;j++){
            scanf("%d",&num);
            G[i+rowNumber][j] = num;
        }
    }
    return;

}
void dfs(){
    path[0][0] = G[0][0];
    for(int i = 1 ;i<rowNumber;i++){
        for(int j = 0 ;j<=i;j++){
            if(j == 0) path[i][j] = G[i][j] + path[i-1][j];
            else if(j == i) path[i][j] = G[i][j] + path[i-1][j-1];
            else path[i][j] = max(path[i-1][j-1],path[i-1][j]) + G[i][j];
        }
    }
    for(int i = rowNumber;i<2*rowNumber;i++){
        for(int j = 0 ; j<2*rowNumber +1 - i;j++){
            path[i][j] = max(path[i-1][j],path[i-1][j+1]) + G[i][j];
        }
    }
}
int solve(){
    dfs();
    return path[2*rowNumber - 2][0];
}
void clear(){
    return;
}
int main() {

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        input();
        //cout<<i<<endl;
        printf("Case %d: %d\n", i + 1, solve());
        clear();
    }
}

