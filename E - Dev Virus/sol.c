#include <stdio.h>

int main()
{
    int t, n, x, a, s, f, h, i;

    // Read the number of test cases
    scanf("%d", &t);

    while (t--)
    {
        // Read the values of n and x for the current test case
        scanf("%d%d", &n, &x);

        h = f = s = 0;

        for (i = 0; i < n; ++i)
        {
            // Read each value of a
            scanf("%d", &a);

            // Update flags and sums
            h |= (x == a);
            f |= (x != a);
            s += a;
        }

        // Print the result based on conditions
        printf("%d\n", (n * x == s) ? f : 2 - h);
    }

    return 0;
}