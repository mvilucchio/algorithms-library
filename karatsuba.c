#ifndef KARATSUBA
#define KARATSUBA

#define BASE 10

#define min(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

int digit_number (unsigned long long int n) {
    int count = 0;
    while (n != 0) {
        ++count;
        n /= BASE;
    }
    return count;
}

unsigned long long int karatsuba (unsigned long long int n1, unsigned long long int n2) {
    
    if (n1 < 10 || n2 < 10)
        return n1 * n2;

    int m, m2;
    m = min(digit_number(n1), digit_number(n2));
    m2 = m / 2;

    int power = 1;
    for (int i = 0; i < m2; i++)
        power *= BASE;

    unsigned long long int low1, low2, high1, high2;

    low1 = n1 % power;
    low2 = n2 % power;
    high1 = (n1 - low1) / power;
    high2 = (n2 - low2) / power;
    
    unsigned long long int z0, z1, z2;

    z0 = karatsuba(low1, low2);
    z1 = karatsuba((low1 + high1), (low2 + high2));
    z2 = karatsuba(high1, high2);

    return (z2 * power * power) + ((z1 - z2 - z0) * power) + z0;
}

#endif