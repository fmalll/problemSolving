#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        int a;
        scanf("%d",&a);
        if(a == 20){
            printf("10 10\n");
            continue;
        }
        int b = a%10;
        printf("%d %d\n",b,a - b);

    }
}