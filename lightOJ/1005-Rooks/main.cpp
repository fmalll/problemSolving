#include <bits/stdc++.h>
using namespace std;
long combinationals[31][31];
long factorials[30];
long factorial(int m){

    if(factorials[m]>0) return factorials[m];
    factorials[m] = factorial(m-1)*m;
    return factorials[m];
}
long combination(int m , int n){
    if(m<n) return 0;
    if(combinationals[m][n]!=0)return combinationals[m][n];
    if(n==m or n==0 )return 1;
    if(n==1) return m;
    else {
        combinationals[m][n] = combination (m-1,n-1) + combination(m-1 , n) ;
        return combinationals[m][n];
    }
}

int main() {
    factorials[0] = 1;
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        int m,n;
        scanf("%d %d",&m,&n);
        long solve = combination(m,n);
        long p = solve * solve * factorial(n);
        printf("Case %d: %ld\n",i+1,p);
    }
}