// int check (int *arr, int k) {
//     int h = 0;
//     int l = 0;

//     // for (int i = k; i >= 0; i--) {
//     //     printf("%d", arr[i]);
//     // }
//     // printf("\n");

//     for (int i = 1; i < k-1; i++) {
//         if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
//             h++;
//         }
//         else if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
//             l++;
//         }
//     }

//     return h+l;
// }

// long long totalWaviness(long long num1, long long num2) {
//     long long ret = 0;
//     if (num2 <= 100) {
//         return 0;
//     }

//     if (num1 <= 100) {
//         num1 = 101;
//     }

//     long long x = num2 - num1;
//     int *array = malloc(sizeof(int) * 16);
//     memset(array, 0, sizeof(int)*16);
//     int k = 0;
//     while (num1) {
//         array[k] = (int) num1 % 10;
//         num1 /= 10;
//         k++;
//     }

//     while (x >= 0) {
//         ret += check(array, k);

//         int a = 0;
//         int b = 1;
//         while (b) {
//             if (array[a] == 9) {
//                 // printf("a = 9\n");
//                 array[a] = 0;
//                 a++;
//             }
//             else {
//                 array[a]++;
//                 b = 0;
//             }

//             if (a >= k) {
//                 k = a + 1;
//             }
//         }
//         x--;
//     }

//     free(array);
//     return ret;
// }   

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int getDir(int a, int b) {
    if (a < b) return 0;
    if (a == b) return 1;
    return 2;
}

bool matchDir(int dir1, int dir2) {
    return (dir1 == 0 && dir2 == 2) || (dir1 == 2 && dir2 == 0);
}

int getIndex(int pos, int tie, int lastDir, int lastDigit) {
    return ((pos * 2 + tie) * 3 + lastDir) * 10 + lastDigit;
}

long long helper(long long num) {
    if (num <= 0) 
        return 0;

    int digits[20];
    int m = 0;

    while (num > 0) {
        digits[m++] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < m / 2; i++) {
        int temp = digits[i];
        digits[i] = digits[m - 1 - i];
        digits[m - 1 - i] = temp;
    }
    int size = m * 2 * 3 * 10;
    long long* totalWaviness = (long long*)calloc(size, sizeof(long long));
    long long* totalWays = (long long*)calloc(size, sizeof(long long));

    for (int firstPos = 0; firstPos < m; firstPos++) {
        int maxFirstDigit = (firstPos == 0) ? digits[0] : 9;

        for (int firstDigit = 1; firstDigit <= maxFirstDigit; firstDigit++) {
            int tie = (firstPos == 0) ? (firstDigit < digits[0]) : 1;
            int lastDir = 1;
            int idx = getIndex(firstPos, tie, lastDir, firstDigit);
            totalWays[idx]++;
        }
    }

    for (int pos = 0; pos + 1 < m; pos++) {
        for (int tie = 0; tie < 2; tie++) {
            for (int lastDir = 0; lastDir < 3; lastDir++) {
                for (int lastDigit = 0; lastDigit < 10; lastDigit++) {
                    int idx = getIndex(pos, tie, lastDir, lastDigit);

                    if (totalWays[idx] == 0)
                        continue;

                    int maxNextDigit = tie ? 9 : digits[pos + 1];

                    for (int nextDigit = 0; nextDigit <= maxNextDigit; nextDigit++) {
                        int newTie = tie || (nextDigit < digits[pos + 1]);
                        int newDir = getDir(lastDigit, nextDigit);
                        int newIdx = getIndex(pos + 1, newTie, newDir, nextDigit);
                        totalWaviness[newIdx] += totalWaviness[idx] + totalWays[idx] * matchDir(lastDir, newDir);
                        totalWays[newIdx] += totalWays[idx];
                    }
                }
            }
        }
    }

    long long ans = 0;

    for (int tie = 0; tie < 2; tie++) {
        for (int lastDir = 0; lastDir < 3; lastDir++) {
            for (int lastDigit = 0; lastDigit < 10; lastDigit++) {
                int idx = getIndex(m - 1, tie, lastDir, lastDigit);
                ans += totalWaviness[idx];
            }
        }
    }
    free(totalWaviness);
    free(totalWays);
    return ans;
}

long long totalWaviness(long long num1, long long num2) {
    return helper(num2) - helper(num1 - 1);
}