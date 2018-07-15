#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        int num;
        scanf("%d",&num);
        int number1 = 0; 
        while(num>0){
            if(num%2 == 1) number1 ++;
            num = num/2;
        }
        if(number1%2 == 1)printf("Case %d: odd\n",i+1);
        else printf("Case %d: even\n",i+1);
    }
}