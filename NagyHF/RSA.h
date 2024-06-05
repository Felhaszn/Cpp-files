#ifndef RSA_H
#define RSA_H
#include "bigint.h"
#include "memtrace.h"

class RSA {
private:
	bigint p;
	bigint q;
	bigint a;
	bigint b;
public:
	bigint N = p * q;

	bigint fiN = a*b;

	long int const e();

	//Konstruktor, default értéket ad a két prímnek
	RSA() :p(generatePrime()), q(generatePrime()), a(bigint(p)-1), b(bigint(q)-1) { }

	RSA(bigint x, bigint y) :p(x), q(y), a(x-1), b(y-1) {  }

	std::string generatePublicKey();

	std::string generatePrivateKey();

	bigint mod_exp(bigint base, bigint exp, const bigint& mod);

	bool isPrime(bigint szam, int k);

	bigint generatePrime();

	bigint RepSqr(bigint a, bigint b);

	bigint Encode(bigint a);

	bigint D_Key();

	bigint Decode(bigint m);

	virtual ~RSA() {};
};

#endif
