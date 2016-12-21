#include <stdio.h>

int gcd(int n, int m)
{
    if (m == 0)    return n;
    return gcd(m, n % m);
}

int main()
{
    int t;
    int n;
    int i, j;
    long long int sum;
    int num[101];

    scanf("%d", &t);

    while (t--) {

        sum = 0;

        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }

        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                sum += gcd(num[i], num[j]);
            }
        }
        printf("%lld\n", sum);
    }

    return 0;
}
