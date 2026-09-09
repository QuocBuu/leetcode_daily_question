# Simple code c - Use Range Counting - Time O(1) Space O(1)

# Intuition
The number of commas depends on how many 3-digit groups each number has. Count numbers by ranges: thousands, millions, billions, trillions, and above.

# Approach
1. Divide numbers into ranges based on powers of `1000`.
2. Count how many numbers belong to each completed range.
3. Multiply each range count by its number of commas.
4. Handle the final partial range separately.

# Complexity
- Time complexity: $$O(1)$$

- Space complexity: $$O(1)$$

# Code
```c []
#define K    (1000LL)     // 10^3
#define M    (1000LL * K) // 10^6
#define G    (1000LL * M) // 10^9
#define T    (1000LL * G) // 10^12
#define P    (1000LL * T) // 10^15

long long countCommas(long long n) {
    long long ret = 0;
    if (n < K) {
        return ret;
    }

    if (n < M) {
        ret += ((n / K) - 1) * K + (n % K + 1);
        return ret;
    }

    ret += 999 * K;
    if (n < G) {
        ret += (((n / M) - 1) * M + (n % M + 1)) * 2;
        return ret;
    }

    ret += 999 * M * 2;
    if (n < T) {
        ret += (((n / G) - 1) * G + (n % G + 1)) * 3;
        return ret;
    }

    ret += 999 * G * 3;
    if (n < P) {
        ret += (((n / T) - 1) * T + (n % T + 1)) * 4;
        return ret;
    }

    ret += 999 * T * 4;
    ret += 5;    

    return ret;
}