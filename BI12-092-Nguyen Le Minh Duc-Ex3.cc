#include <iostream>
#include <math.h>

using namespace std;

int gcd(int x, int y)
{
    int temp;
    while (1)
    {
        temp = x % y;
        if (temp == 0)
            return y;
        x = y;
        y = temp;
    }
}

int main()
{
    double p;
    cout << "Enter p: ";
    cin >> p;
    double q;
    cout << "Enter q: ";
    cin >> q;

    double n = p * q;

    double e;
    cout << "Enter e: ";
    cin >> e;
    double phi = (p - 1) * (q - 1);
    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    int k = 2; // Is used to find d, can be any number
    double d = (1 + (k * phi)) / e;

    double msg;
    cout << "Enter Message: ";
    cin >> msg;
    cout << "Message data = " << msg;

    double c = pow(msg, e);
    c = fmod(c, n);
    cout << "\nEncrypted data = " << c;

    double m = pow(c, d);
    m = fmod(m, n);
    cout << "\nOriginal Message Sent = " << m;

    return 0;
}

// Manual Calculation
/** With p = 5, q = 11, c = 3, M = 9
 * Calculate n = p * q = 5 * 11 = 55
 * Calculate phi = (p - 1) * (q - 1) = 4 * 10 = 40
 * Generate Public Key => n = 55, e = 3
 * Calculate d = (1 + (k * phi)) / e = (1 + (2 * 40)) / 3 = 81 / 3 = 27
 * Generate Private Key => n = 55, d = 27
 * Encrypt Message, c = M^e mod n = 9^3 mod 55 = 729 mod 55 = 14
 * Therefore, the encrypted message is 14
 * 
 * 
 * With p = 3, q = 11, e = 7, M = 5
 * n = p * q = 3 * 11 = 33
 * phi = (p - 1) * (q - 1) = 2 * 10 = 20
 * Public Key: n = 33, e = 7
 * Private Key: n = 33, d = 3
 * Encrypt Message, c = M^e mod n = 5^7 mod 33 = 78125 mod 33 = 14
 * Therefore, the encrypted message is 14
*/