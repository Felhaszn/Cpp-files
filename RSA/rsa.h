#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <cmath>
#include <random>

class RSA {
private:
    long long p, q, n, phi, e, d;

    //Greates Common Divisor, useful for later
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    //Exponentiation by squaring
    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    //a*x MOD m == 1
    long long modInverse(long long a, long long m) {
        long long m0 = m, t, q;
        long long x0 = 0, x1 = 1;
        if (m == 1) return 0;
        while (a > 1) {
            q = a / m;
            t = m;
            m = a % m, a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        return (x1 + m0) % m0;
    }

    //Simple brute-force finding of primes, not good for greater numbers
    long long generatePrime() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<long long> dist(100, 500);
        long long num;
        do {
            num = dist(gen);
            bool isPrime = true;
            for (long long i = 2; i * i <= num; ++i) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) return num;
        } while (true);
    }

public:
    RSA() {
        p = generatePrime();
        q = generatePrime();
        n = p * q;
        phi = (p - 1) * (q - 1);
        e = 2;
        while (e < phi && gcd(e, phi) != 1) {
            e++;
        }
        d = modInverse(e, phi);
    }

    long long encrypt(long long message) {
        return modExp(message, e, n);
    }

    long long decrypt(long long ciphertext) {
        return modExp(ciphertext, d, n);
    }

    void printKeys() {
        std::cout << "Your Public Key: (" << e << ", " << n << ")\n";
        std::cout << "Your Private Key: (" << d << ", " << n << ")\n";
    }
};

#endif