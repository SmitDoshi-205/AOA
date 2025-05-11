#include <stdio.h>

#define N 100  // maximum size of the set

int w[N];     // weights array
int x[N];     // selection array
int n, m;     // number of elements, target sum

void SumOfSub(int s, int k, int r) {
    int i;

    // Include w[k] in subset
    x[k] = 1;
    if (s + w[k] == m) {
        // Print the current subset
        printf("{ ");
        for (i = 0; i <= k; i++) {
            if (x[i])
                printf("%d ", w[i]);
        }
        printf("}\n");
    }
    else if (s + w[k] + w[k + 1] <= m) {
        // Continue with next element
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }

    // Exclude w[k] from subset
    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k]);
    }
}

int main() {
    int i, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in non-decreasing order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &m);

    printf("Subsets that sum to %d:\n", m);
    if (w[0] <= m && sum >= m)
        SumOfSub(0, 0, sum);
    else
        printf("No solution possible.\n");

    return 0;
}