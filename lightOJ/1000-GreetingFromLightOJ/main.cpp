#include <bits/stdc++.h>
using namespace std;
string* getstr(string* str){
    cout<<*(str + 1)<<endl;
    return str+1;
}
int main() {
    int test;
    string str = "hooman";
    cout<<getstr(&str);
    scanf("%d", &test);
    for (int i = 0; i < test; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", i + 1, a + b);

    }
}