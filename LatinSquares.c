#include <stdio.h>

#define NUM 4

void print_squares(int a[NUM][NUM], int b[NUM][NUM], int c[NUM][NUM], int d[NUM][NUM], int e[NUM][NUM], int f[NUM][NUM]);
void print_pairs(int a[NUM][NUM], int b[NUM][NUM]);

int main()
{
        // Problem 1
        // Initialize 6 example matricies
        int A[NUM][NUM] = {{1, 2, 3, 4}, {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 3, 2, 1}};
        int B[NUM][NUM] = {{1, 4, 2, 3}, {2, 3, 1, 4}, {3, 2, 4, 1}, {4, 1, 3, 2}};
        int C[NUM][NUM] = {{1, 2, 4, 3}, {2, 1, 3, 4}, {3, 4, 2, 1}, {4, 3, 1, 2}};
        int D[NUM][NUM] = {{1, 2, 3, 4}, {2, 1, 4, 3}, {4, 3, 2, 1}, {3, 4, 1, 2}};
        int E[NUM][NUM] = {{1, 3, 2, 4}, {4, 2, 3, 1}, {3, 1, 4, 2}, {2, 4, 1, 3}};
        int F[NUM][NUM] = {{1, 3, 2, 4}, {4, 2, 3, 1}, {2, 4, 1, 3}, {3, 1, 4, 2}};

        printf("Enter a number 2 to 6 to compare the corresponding Latin square to 1\n\n");
        // Label and print matricies
        printf("1           2           3           4           5           6\n\n");
        print_squares(A, B, C, D, E, F);
        // Obtain user input for comparison to 1
        int user_input;
        printf("Compare 1 and ");
        scanf("%d", &user_input);
        printf("\n");

        // Run comparison
        switch (user_input)
        {
        case 2:
            print_pairs(A, B);
            break;
        case 3:
            print_pairs(A, C);
            break;
        case 4:
            print_pairs(A, D);
            break;
        case 5:
            print_pairs(A, E);
            break;
        case 6:
            print_pairs(A, F);
            break;
        default:
            printf("Restart program and enter a number 2 to 6\n\n");
        }

        // Problem 2

        // Initialize variables
        int b, v, k, r, lambda;

        // Obtain user input
        printf("Problem 2\n\nEnter three integers: ");
        scanf("%d %d %d", &b, &v, &k);

        r = (b * k) / v;
        lambda = (r * (k - 1)) / (v - 1);
        if (b * k != v * r || (lambda * (v - 1) != r * (k - 1)))
            printf("This is an impossible configuration!");
        else
            printf("\n(b = %d | v = %d | k = %d | r = %d | lambda = %d)\n", b, v, k, r, lambda);

    return 0;
}

// Print matricies
void print_squares(int a[NUM][NUM], int b[NUM][NUM], int c[NUM][NUM], int d[NUM][NUM], int e[NUM][NUM], int f[NUM][NUM])
{
    for (int i = 0; i < NUM; i++)
    {
        for (int g = 0; g < NUM; g++)
            printf("%d ", a[i][g]);
        printf("    ");
        for (int h = 0; h < NUM; h++)
            printf("%d ", b[i][h]);
        printf("    ");
        for (int j = 0; j < NUM; j++)
            printf("%d ", c[i][j]);
        printf("    ");
        for (int k = 0; k < NUM; k++)
            printf("%d ", d[i][k]);
        printf("    ");
        for (int l = 0; l < NUM; l++)
            printf("%d ", e[i][l]);
        printf("    ");
        for (int m = 0; m < NUM; m++)
            printf("%d ", f[i][m]);
        printf("\n");
    }
    printf("\n");

}

// Print (aij, bij)
void print_pairs(int a[NUM][NUM], int b[NUM][NUM])
{
    // Initialize array that holds count for each sum
    int sum[NUM + (NUM - 1)];
    for (int c = 0; c < NUM + (NUM -1); c++)
        sum[c] = 0;

    // Label and print all pairs (aij, bij)
    printf("(aij, bij)\n");
    for (int i = 0; i < NUM; i++)
    {
        for (int j = 0; j < NUM; j++)
        {
            printf("(%d, %d) ", a[i][j], b[i][j]);
            for (int k = 0; k < NUM + (NUM - 1); k++)
            {
                if (a[i][j] + b[i][j] == k + 2)
                    sum[k] += 1;
            }
        }
        printf("\n");
    }
    printf("\n");
    for (int p = 0; p < NUM + (NUM -1); p++)
        if (sum[p] == 1)
            printf("Sum = %d occurs %d time\n", p + 2, sum[p]);
        else
            printf("Sum = %d occurs %d times\n", p + 2, sum[p]);

    if ((sum[NUM - NUM] == 1 && sum[NUM + (NUM - 2)] == 1) &&
            (sum[NUM - (NUM - 1)] == 2 && sum[NUM + (NUM - 3)] == 2) &&
            (sum[NUM - (NUM - 2)] == 3 && sum[NUM + (NUM - 4)] == 3) &&
            sum[NUM - (NUM - 3)] == 4)
        printf("\nThese two Latin squares are mutually orthogonal\n\n");
    else
        printf("\nThese two Latin squares are not mutually orthogonal\n\n");

}


