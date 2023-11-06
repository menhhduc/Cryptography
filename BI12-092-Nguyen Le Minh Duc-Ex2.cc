#include <iostream>

long long square_and_multiply(long long x, unsigned long long e, int n) {
    long long result = 1;
    x = x % n;  

    if (x == 0) return 0;

    while (e > 0) {
        if (e & 1)
            result = (result*x) % n;

        e = e >> 1; // e = e/2
        x = (x*x) % n;
    }
    return result;
}

int main() {
    long long x = 856;
    unsigned long long e = 25;
    int n = 7;
    std::cout << "The result of " << x << "^" << e << " mod " << n << " is " << square_and_multiply(x, e, n);
    return 0;
}

/** Manual Calculation 
 * Convert 25(10) to binary
 * 25(10) = 11001(2)
 
 * Then create a table
     25(2) | c0 = 1
     1 | c1 = 1^2 * 856 = 856 mod 7 = 2
     1 | c2 = 2^2 * 856 = 4 * 856 = 3424 mod 7 = 1
     0 | c3 = 1^2 * 856^0 = 1 mod 7 = 1
     0 | c4 = 1^2 * 856^0 = 1 mod 7 = 1
     1 | c5 = 1^2 * 856 = 856 mod 7 = 2
 * Therefore:
 * 856^25 mod 7 = 2
*/