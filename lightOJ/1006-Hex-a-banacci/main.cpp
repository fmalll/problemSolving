#include <bits/stdc++.h>
using namespace std;
int caculated;
int a, b, c, d, e, f;
long fnAr[10006];
long fn( int n ) {
    if(n    <=caculated) return  fnAr[n];
    fnAr[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) )%10000007;
    caculated = n;
    return fnAr[n];
}
int main() {

    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        caculated = 5;fnAr[0] = a;fnAr[1] = b;fnAr[2] = c;fnAr[3] = d;fnAr[4] = e;fnAr[5] = f;
        printf("Case %d: %ld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}