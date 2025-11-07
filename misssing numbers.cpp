#include <stdio.h>
#define MAX 10000

void missingNumbers(int* a, int n, int* b, int m) {
    int fa[MAX] = {0}, fb[MAX] = {0};

    for (int i = 0; i < n; i++) fa[a[i]]++;
    for (int i = 0; i < m; i++) fb[b[i]]++;

    for (int i = 0; i < MAX; i++) {
        if (fb[i] > fa[i]) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    scanf("%d", &m);
    int b[m];
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    missingNumbers(a, n, b, m);
    return 0;
}

