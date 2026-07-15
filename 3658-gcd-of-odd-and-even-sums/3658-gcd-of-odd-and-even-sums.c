int gcdOfOddEvenSums(int n) {
    n <<= 1;

    int sumOdd = (n*n)/4;
    int sumEven = ((n + 2)*n)/4;

    // printf("%d - %d - %d\n",n, sumOdd, sumEven);

    while (sumOdd != 0) {
        int val = sumEven % sumOdd;
        sumEven = sumOdd;
        sumOdd  = val;
    }

    return sumEven;
}