#include <stdio.h>
#include <string.h>
#include <math.h>

char text[50];
char pattern[50];

void rabin_karp(char text[], char pattern[], int n, int m, int d, int q) {
    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;  // h = d^(m-1) % q
    }

    int p = 0;  // Hash value for pattern
    int t = 0;  // Hash value for text window

    // Calculate initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text
    for (int s = 0; s <= n - m; s++) {
        if (p == t) {
            // Hashes match, do a character-by-character check
            int match = 1;
            for (int j = 0; j < m; j++) {
                if (text[s + j] != pattern[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Pattern occurs with shift %d\n", s);
            }
        }

        // Calculate hash for next window
        if (s < n - m) {
            t = (d * (t - text[s] * h) + text[s + m]) % q;

            // Make sure t is positive
            if (t < 0) {
                t += q;
            }
        }
    }
}

int main() {
    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    int d = 256;  // Number of possible characters 
    int q = 101;  // A prime number for modulo

    rabin_karp(text, pattern, n, m, d, q);

    return 0;
}