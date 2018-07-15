#include <bits/stdc++.h>
using namespace std;
int gcc(int a,int b){
    if(b == 1)return -1;
    if(b == 0) return a;
    return gcc(b,a%b);
}
int solve(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(max(a,b)%min(a,b) == 0)return abs(a-b)/gcc(min(a,b),max(a,b)%min(a,b));
    else if(gcc(a,b) == -1)return -1;
    return abs(a-b)/gcc(a,b);
}
int main() {
    printf("%d\n",gcc(6,4));
    int t;
    scanf("%d",&t);
    for(int i = 0 ;i < t;i++){
        printf("Case %d: %d",i+1,solve());
    }
}