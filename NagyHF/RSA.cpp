#include <math.h>
#include "RSA.h"
#include "bigint.h"
#include <time.h>

long int const RSA::e() {
    return 7;
}

std::string RSA::generatePublicKey() {
    std::string publickey = N.get();
    return publickey;
}

//Beállítja p-t és q-t
std::string RSA::generatePrivateKey() {
    p = generatePrime().get();
    q = generatePrime().get();
    std::string privatekey = p.get() + ',' + q.get() + ',' + D_Key().get();

    return privatekey;
}

bigint RSA::mod_exp(bigint base, bigint exp, const bigint& mod) {
    bigint result = 1;
    base = base % mod;

    while (exp > 0) {
        if ((exp % 2) == "1") {
            result = (result * base) % mod;
        }

        exp = exp / 2;
        base = (base * base) % mod;
    }

    return result;
}

//Megmondja egy számról, hogy prím-e, Miller-Rabin teszttel
bool RSA::isPrime(bigint szam, int k) {
    if (!szam.maybePrime()) return false;

    if (szam <= 1) return false;
    if (szam <= 3) return true;
    if (szam % 2 == "0") return false;

    bigint d = szam - 1;
    bigint r = 0;

    while (d % 2 == "0") {
        d = d / 2;
        r = r + 1;
    }

    for (int i = 0; i < k; ++i) {
        bigint a = rand() + 1000000;
        bigint x = mod_exp(a, d, szam);
        if (x == 1 || szam + 1 == x) continue;

        bool continueLoop = false;
        for (bigint j = 0; j < r - 1; j = j + 1) {
            x = (x * x) % szam;
            if (x == szam - 1) {
                continueLoop = true;
                break;
            }
        }
        if (continueLoop) continue;
        return false;
    }
    return true;
}

//Létrehoz egy prímszámot
bigint RSA::generatePrime() {
    bigint szam;
    szam = rand() % (100 - 1000 + 1) + 100;
    if(szam % 2 == "0")
        szam = szam - 1;

    while (!isPrime(szam, 2)) {
        szam = rand() % (100 - 1000 + 1) + 100;
    } 
    return szam;
}

/*Ismételt négyzetre emelés*/
bigint RSA::RepSqr(bigint a, bigint b) {
    bigint alap = a;
    bigint maradek = 1;

    while (b > 0) {
        if (b % 2 == "1") {
            maradek = (maradek * alap) % N;
        }
        alap = (alap * alap) % N;
        b = b / 2;
    }

    return maradek;
}

/*Üzenet kódolása*/
bigint RSA::Encode(bigint a) {
    bigint c = RepSqr(a, e());
    return c % N;
}

/*d visszafejtõ kulcs elkészítése*/
bigint RSA::D_Key() {
    bigint d;
    bigint fi;
    for (int k = 1; fiN > k; k++) {
        fi = fiN;
        if ((fi * k + 1) % e() == "0") {
            d = fi / e();                   //Megj.: mivel fi értéke változik a szorzás hatására, ezért
            return d;                       //       kell d-nek azt visszaadni, nem pedig a számolást.
        }
    }

    return -1;
}

/*Az üzenet dekódolása*/
bigint RSA::Decode(bigint c) {
    bigint d = D_Key();
    bigint message = RepSqr(c, d);
    return message;
}