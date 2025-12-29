#include <stdio.h>
#include <stdlib.h>

#define MAXN 200010

int n, x, p[MAXN], i, j, ans;
int have_gondola_yet[MAXN];
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void solve() {
    scanf("%d %d", &n, &x);
    
    for (i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
    }
    qsort(p, n, sizeof(int), compare);

    i = 0;
    j = n - 1;
    ans = 0;
    
    while (i < j) {
        if (p[i] + p[j] > x) {
            --j;
        } else {
            ++ans;
            have_gondola_yet[i] = have_gondola_yet[j] = 1;
            ++i;
            --j; 
        }
    }
    
    for (i = 0; i < n; ++i) {
        ans += (have_gondola_yet[i] == 0);
    }

    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}
