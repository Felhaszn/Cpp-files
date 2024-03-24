#ifndef BIGINT_H
#define BIGINT_H

#include <string>

class bigint {
private:
	std::string num;
public:
	void set(std::string n);

	std::string get();

	bigint();

	std::string sqr(bigint k, long long int n);

	~bigint();

	bigint& operator=(long long int n);

	bigint& operator+(long long int n);

	bigint& operator*(long long int n);
};



#endif BIGINT_H
