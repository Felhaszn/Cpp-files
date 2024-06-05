#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <iostream>
#include "memtrace.h"

class bigint {
private:
	std::string num;
public:
	void set(std::string n);

	const std::string get() const;

	bigint();

	bigint(std::string n);

	bigint(long long int n);

	std::string pow(bigint k, long long int n);

	bool maybePrime();

	~bigint();

	bool operator==(long long n);

	bool operator==(bigint n);

	bool operator<=(bigint other);

	bool operator>=(bigint other);

	bool operator<=(long long other);

	bool operator>=(long long other);

	bool operator<(bigint other);

	bool operator<(long long other);

	bool operator>(bigint other);

	bool operator>(long long other);

	bigint& operator=(long long int n);

	bigint& operator=(std::string n);

	bigint& operator=(bigint& n);

	bigint& operator-(long long int n);

	bigint& operator+(long long int n);

	bigint& operator+(bigint n);

	bigint& operator*(long long int n);

	bigint& operator*(bigint n);

	bigint& operator/(long long int n);

	bigint& operator/(bigint num);

	std::string operator%(long long int n);

	bigint& operator%(bigint num);
};


std::ostream& operator<<(std::ostream& os, const bigint& n);

#endif
