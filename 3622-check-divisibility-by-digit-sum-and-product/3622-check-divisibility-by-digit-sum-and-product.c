bool checkDivisibility(int n) {
    int sum = 0;
    int plusPro = 1;
    int k = n;
    while (k) {
        int val = k % 10;
        sum += val;
        plusPro *= val;

        k /= 10;
    }

    int sumDigit = plusPro + sum; 
    if (sumDigit == 0) {
        return false;
    }

    return (n % sumDigit) == 0;
}