#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_FACTORIALS 10000
#define NUM_FACTS 100

struct FactorialResults
{
    double results[MAX_FACTORIALS];
    int numResults;
};

double factorial(const int n)
{
    if (n >= 1)
    {
        double result = 1.0;
        for (int i = 1; i <= n; i++)
        {
            result *= (double)i;
        }
        return result;
    }
    else
    {
        return 1.0;
    }
}

int countDigits(double value)
{
    if (value < 0)
    {
        value = -value; // Handle negative values
    }
    int count = 0;
    while (value >= 1.0)
    {
        value /= 10.0;
        count++;
    }
    return count;
}

void printFormattedNumber(int index, double value)
{
    int exponent = (int)log10(value);
    double mantissa = value / pow(10.0, exponent);

    if (countDigits(mantissa) >= 16) // Use scientific notation if mantissa has 16 or more digits
    {
        printf("%2d %.1fe%d\n", index, mantissa, exponent);
    }
    else
    {
        printf("%2d %.0f\n", index, value); // Print as an integer if not in scientific notation
    }
}

void computeFactorials(struct FactorialResults* results, int numFactorials)
{
    int i;
    for (i = 0; i < numFactorials; i++)
    {
        results->results[i] = factorial(i);
    }
    results->numResults = numFactorials;
}

int main(void)
{
    struct FactorialResults results = { {0.0}, 0 };
    int i;

    computeFactorials(&results, NUM_FACTS);

    for (i = 1; i < NUM_FACTS; i++)
    {
        double value = results.results[i];
        printFormattedNumber(i, value);
    }
    return 0;
}