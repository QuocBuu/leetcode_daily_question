static int countl_zero64(uint64_t x)
{
    if (x == 0)
        return 64;

    int n = 0;

    if ((x >> 32) == 0) {
        n += 32;
        x <<= 32;
    }
    if ((x >> 48) == 0) {
        n += 16;
        x <<= 16;
    }
    if ((x >> 56) == 0) {
        n += 8;
        x <<= 8;
    }
    if ((x >> 60) == 0) {
        n += 4;
        x <<= 4;
    }
    if ((x >> 62) == 0) {
        n += 2;
        x <<= 2;
    }
    if ((x >> 63) == 0) {
        n++;
    }

    return n;
}

static int bit_width(__uint128_t x)
{
    uint64_t hi = (uint64_t)(x >> 64);

    if (hi)
        return 128 - countl_zero64(hi);

    return 64 - countl_zero64((uint64_t)x);
}

char *shortestBeautifulSubstring(char *s, int k)
{
    int n = strlen(s);
    int start = n;

    __uint128_t curr = 0;
    __uint128_t best = ~((__uint128_t)0);

    for (int i = 0; i < n; i++) {
        int bit = s[i] & 1;

        /* Append bit */
        curr = (curr << 1) | bit;
        k -= bit;

        /* Too many ones: remove most significant bit */
        if (k < 0) {
            k = 0;

            int width = bit_width(curr);

            if (width > 1)
                curr &= (((__uint128_t)1 << (width - 1)) - 1);
            else
                curr = 0;
        }

        /* Exactly k ones */
        if (k == 0 && curr < best) {
            int width = bit_width(curr);

            start = i - width + 1;
            best = curr;
        }
    }

    if (start == n) {
        char *result = malloc(1);
        result[0] = '\0';
        return result;
    }

    int len = bit_width(best);

    char *result = malloc((size_t)len + 1);

    memcpy(result, s + start, len);
    result[len] = '\0';

    return result;
}