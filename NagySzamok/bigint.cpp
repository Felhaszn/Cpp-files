#include <string>
#include <iostream>
#include <sstream>

#include "bigint.h"

void bigint::set(std::string n) {
	 num = n;
}

std::string bigint::get() {
	return num;
}

bigint::bigint() { num = "0"; }

std::string bigint::sqr(bigint k, long long int n){
	long long int c = std::stoi(k.get(), nullptr, 10);
	for (long long int i = 0; i < n-1; i++) {
		k = k * c;
	}
	return k.get();
}

bigint::~bigint() {}

//�rt�kad�s oper�tor
bigint& bigint::operator=(long long int n) {
	num = std::to_string(n);
	return *this;
}

//�sszead�s long long integerrel
bigint& bigint::operator+(long long int n) {
	std::string temp = std::to_string(n);
	int length_n = temp.size();
	int length_num = num.size();
	
	int m = 0;

	//Ha a m�sodik sz�m hosszabb, akkor felcser�li �ket
	if (length_n > length_num) {
		std::string s = num;
		num = temp;
		temp = s;

		int k = length_num;
		length_num = length_n;
		length_n = k;
	}

	//Sz�mjegyenk�nti �sszead�s
	for (int i = 0; i < length_num; i++) {
		if (m == 0 && (length_num - i - 1 < 0 || length_n - i - 1 < 0)) {
			if (m != 1) {
				return *this;
			}
			else {
				length_n++;
			}
		}

		if (length_n - i - 1 >= 0) {
			int a = int(num[length_num - 1 - i]) - '0';
			int b = int(temp[length_n - 1 - i]) - '0';
			a += m;

			if (a + b >= 10) {
				num[length_num - 1 - i] = char(a + b - 10) + '0';
				m = 1;
			}
			else {
				num[length_num - 1 - i] = char(a + b) + '0';
				m = 0;
			}
		}
		//Ha a marad�k nem nulla, akkor hozz�adjuk
		else if(m != 0){

			int a = int(num[length_num - 1 - i]) - '0';

			if (a + m >= 10) {
				m = 1;
				num[length_num - 1 - i] = char(a + m - 10) + '0';
			}
			else {
				num[length_num - 1 - i] = char(a + m) + '0';
				m = 0;
			}
		}
	}
	//Ha null�val kezd�dik (Azaz t�bb sz�mjegy, mint amennyi eredetileg volt), akkor hozz�ad egy egyest az elej�re
	//Akkor is, ha a marad�k nem ad�dott hozz� a v�g�n
	if (num[0] == '0' || m != 0) {
		num.resize(num.size() + 1);
		num = '1' + num.substr(0, length_num);
	}
	return *this;
	
}

bigint& bigint::operator*(long long int n) {
	std::string temp = std::to_string(n);
	
	int n_len = temp.length();
	int num_len = num.length();

	//Ha nagyobb az n, akkor csere
	if (n_len > num_len) {
		std::string s = num;
		num = temp;
		temp = s;

		int x = num_len;
		num_len = n_len;
		n_len = x;
	}
	std::string k = num;		//Elt�roljuk az eredeti sz�mot
	int k_len = k.length();		//�s a hossz�t
	int m = 0;					//Marad�k
	int sum = 0;
	int sm = 0;

	for (int x = 0; x != num_len; x++) {
		num[x] = '0';
	}

	for (int i = 0; i < n_len; i++) {
		m = 0; sm = 0;
		for (int j = 0; j < num_len; j++) {
			if (num_len != j) {
				int a = int(k[k_len - 1 - j]) - '0';
				int b = int(temp[n_len - 1 - i]) - '0';

				if ((a * b) + m >= 10) {
					sum = num[num_len - 1 - j] - '0';
					num[num_len - 1 - j] = char(((a * b) + m) % 10) + '0';
					sum += num[num_len - 1 - j] - '0';
					num[num_len - 1 - j] = char((sum + sm) % 10) + '0';
					if (sum+sm >= 10) {
						sm = (sum+sm) / 10;
					}
					else {
						sm = 0;
					}

					m = ((a * b) + m) / 10;
				}
				else {
					sum = num[num_len - 1 - j] - '0';
					num[num_len - 1 - j] = char((a * b) + m + '0');
					sum += num[num_len - 1 - j] - '0';
					num[num_len - 1 - j] = char((sum + sm) % 10) + '0';
					if (sum+sm >= 10) {
						sm = (sum+sm) / 10;
					}
					else {
						sm = 0;
					}
					m = 0;
				}
			}
			else {
				num.resize(num.size() + 1);
				num = char(m + '0') + num.substr(0, num_len);
				m = 0;
			}
		}
		if (n_len - i > 1) {
			num.resize(num.size() + 1);
			if (m == 0) {
				num = '0' + num.substr(0, num_len + i);
			}
			else {
				num = '1' + num.substr(0, num_len + i);
			}
			
		}
	}

	if (m != 0) {
		num.resize(num.size() + 1);
		num = char(m + '0') + num.substr(0, num.size() - 1);
	}

	return *this;
}