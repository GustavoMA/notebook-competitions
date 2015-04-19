#include <bits/stdc++.h>

using namespace std;

int arr[100];
int test[100];

int main() {
    int n, b;
    while(true) {
        memset(test, 0, sizeof test);
        scanf(" %d %d", &n, &b);
        if (n == 0 && b == 0)
            break;
            
        for (int i = 0; i < b; i++) {
            scanf(" %d", &arr[i]);      
        }
        
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < b; j++) {
                test[ abs(arr[i] - arr[j]) ]++;         
            }       
        }
        int flag = 1;
        //for (int i = 0; i <= n; i++)
        //  printf("%d ", test[i]);
        //printf("\n");
        for (int i = 0; i <= n; i++) {
            if (!test[i]) {
                printf("N\n");
                flag = 0;
                break;          
            }       
        }
        
        if(flag) printf("Y\n");
    }   
    return 0;
}