#include <string>
#include <iostream>
#include <sstream>

#include "bigint.h"

//setter
void bigint::set(std::string n) {
	num = n;
}

//getter
const std::string bigint::get() const {
	return num;
}

//Paraméter nélküli konstruktor, default értéke 0
bigint::bigint() { num = "0"; }

bigint::bigint(std::string n) { this->num = n; }

bigint::bigint(long long int n) { num = std::to_string(n); }

//Hatványozás
//@param bigint k - hatványalap
//@param long long int n - hatványkitevő
std::string bigint::pow(bigint k, long long int n) {
	long long int c = std::stoi(k.get(), nullptr, 10);
	for (long long int i = 0; i < n - 1; i++) {
		k = k * c;
	}
	return k.get();
}

bool bigint::maybePrime() {
	if (num.back() == '5' || num.back() == '0' || num.back() == '2' ||
		num.back() == '4' || num.back() == '6' || num.back() == '8') return false;
	return true;
}

//Destruktor
bigint::~bigint() {}

//Egyenlőek-e
bool bigint::operator==(long long n) {
	std::string number = std::to_string(n);

	return this->num == number;
}

//Egyenlőek-e
bool bigint::operator==(bigint n) {
	return this->num == n.num;
}

bool bigint::operator<=(bigint other) {
	// Két szám hosszának összehasonlítása
	if (num.length() < other.num.length()) {
		return true;
	}
	if (num.length() > other.num.length()) {
		return false;
	}

	// Ha ugyanolyan hosszúak, akkor megvizsgáljuk a számokat
	for (size_t i = 0; i < num.length(); ++i) {
		if (num[i] < other.num[i]) {
			return true;
		}
		if (num[i] > other.num[i]) {
			return false;
		}
	}

	// Ha mindegyik számjegy ugyanaz, akkor egyenlőek
	return true;
}

bool bigint::operator<=(long long other) {
	// long long bigintre konvertálása
	bigint otherBigint;
	otherBigint.num = std::to_string(other);
	return *this <= otherBigint;
}

bool bigint::operator>=(bigint other) {
	// Két szám hosszának összehasonlítása
	if (num.length() < other.num.length()) {
		return false;
	}
	if (num.length() > other.num.length()) {
		return true;
	}

	// Ha ugyanolyan hosszúak, akkor megvizsgáljuk a számokat
	for (size_t i = 0; i < num.length(); ++i) {
		if (num[i] < other.num[i]) {
			return false;
		}
		if (num[i] > other.num[i]) {
			return true;
		}
	}

	// Ha mindegyik számjegy ugyanaz, akkor egyenlőek
	return true;
}

bool bigint::operator>=(long long other) {
	// long long bigintre konvertálása
	bigint otherBigint; 
	otherBigint.num = std::to_string(other);
	return *this >= otherBigint;
}

bool bigint::operator<(bigint other) {
	// Két szám hosszának összehasonlítása
	if (num.length() < other.num.length()) {
		return true;
	}
	if (num.length() > other.num.length()) {
		return false;
	}

	// Ha ugyanolyan hosszúak, akkor megvizsgáljuk a számokat
	for (size_t i = 0; i < num.length(); ++i) {
		if (num[i] < other.num[i]) {
			return true;
		}
		if (num[i] > other.num[i]) {
			return false;
		}
	}

	// Ha mindegyik számjegy ugyanaz, akkor egyenlőek
	return false;
}

bool bigint::operator<(long long other) {
	// long long bigintre konvertálása
	bigint otherBigint;
	otherBigint.num = std::to_string(other);
	return *this < otherBigint;
}

bool bigint::operator>(bigint other) {
	// Két szám hosszának összehasonlítása
	if (num.length() < other.num.length()) {
		return false;
	}
	if (num.length() > other.num.length()) {
		return true;
	}

	// Ha ugyanolyan hosszúak, akkor megvizsgáljuk a számokat
	for (size_t i = 0; i < num.length(); ++i) {
		if (num[i] < other.num[i]) {
			return false;
		}
		if (num[i] > other.num[i]) {
			return true;
		}
	}

	// Ha mindegyik számjegy ugyanaz, akkor egyenlőek
	return false;
}

bool bigint::operator>(long long other) {
	// long long bigintre konvertálása
	bigint otherBigint;
	otherBigint.num = std::to_string(other);
	return *this > otherBigint;
}

//Értékadás operátor
bigint& bigint::operator=(long long int n) {
	num = std::to_string(n);
	return *this;
}

bigint& bigint::operator=(std::string n) {
	num = n;
	return *this;
}

//Értékadás operátor
bigint& bigint::operator=(bigint& other) {
	if (this != &other) { // Önmagába másolás ellenőrzése
		this->num = other.num;
	}
	return *this;
}

bigint& bigint::operator-(long long int n) {
	std::string temp = std::to_string(n);
	int length_n = temp.size();
	int length_num = num.size();

	int borrow = 0;

	// Ha a második szám hosszabb, akkor felcseréli őket és előjel problémákat kezeljük
	if (length_n > length_num || (length_n == length_num && temp > num)) {
		std::string s = num;
		num = temp;
		temp = s;

		int k = length_num;
		length_num = length_n;
		length_n = k;
	}

	// Számjegyenkénti kivonás
	for (int i = 0; i < length_num; i++) {
		int a = int(num[length_num - 1 - i]) - '0';
		int b = (length_n - 1 - i >= 0) ? int(temp[length_n - 1 - i]) - '0' : 0;
		a -= borrow;

		if (a < b) {
			a += 10;
			borrow = 1;
		}
		else {
			borrow = 0;
		}

		num[length_num - 1 - i] = char(a - b + '0');
	}

	// Eltávolítjuk a vezető nullákat, ha vannak
	while (num.size() > 1 && num[0] == '0') {
		num.erase(0, 1);
	}

	return *this;
}


//Összeadás long long inttel
//@param bigint n - a másik szám
bigint& bigint::operator+(long long int n) {
	std::string temp = std::to_string(n);
	int length_n = temp.size();
	int length_num = num.size();

	int m = 0;

	//Ha a második szám hosszabb, akkor felcseréli őket
	if (length_n > length_num) {
		std::string s = num;
		num = temp;
		temp = s;

		int k = length_num;
		length_num = length_n;
		length_n = k;
	}

	//Számjegyenkénti összeadás
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
		//Ha a maradék nem nulla, akkor hozzáadjuk
		else if (m != 0) {

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
	//Ha nullával kezdődik (Azaz több számjegy, mint amennyi eredetileg volt), akkor hozzáad egy egyest az elejére
	//Akkor is, ha a maradék nem adódott hozzá a végén
	if (num[0] == '0' || m != 0) {
		num.resize(num.size() + 1);
		num = '1' + num.substr(0, length_num);
	}
	return *this;
}

//Ugyanaz, mint long long int esetében, csak itt egy másik biginttel
//@param bigint n - a másik szám
bigint& bigint::operator+(bigint n) {
	std::string temp = n.num;
	int length_n = temp.size();
	int length_num = num.size();

	int m = 0;

	//Ha a második szám hosszabb, akkor felcseréli őket
	if (length_n > length_num) {
		std::string s = num;
		num = temp;
		temp = s;

		int k = length_num;
		length_num = length_n;
		length_n = k;
	}

	//Számjegyenkénti összeadás
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
		//Ha a maradék nem nulla, akkor hozzáadjuk
		else if (m != 0) {

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
	//Ha nullával kezdődik (Azaz több számjegy, mint amennyi eredetileg volt), akkor hozzáad egy egyest az elejére
	//Akkor is, ha a maradék nem adódott hozzá a végén
	if (num[0] == '0' || m != 0) {
		num.resize(num.size() + 1);
		num = '1' + num.substr(0, length_num);
	}
	return *this;
}

//Írásbeli szorzás megvalósítása
//@param long long int n - szorzás ezzel a számmal
bigint& bigint::operator*(long long int n) {
	std::string temp = std::to_string(n);

	int n_len = temp.length();
	int num_len = num.length();

	// Ha nagyobb az n, akkor csere
	if (n_len > num_len) {
		std::swap(num, temp);
		std::swap(num_len, n_len);
	}

	std::string result(num_len + n_len, '0');

	for (int i = n_len - 1; i >= 0; --i) {
		int carry = 0;
		for (int j = num_len - 1; j >= 0; --j) {
			int product = (temp[i] - '0') * (num[j] - '0') + (result[i + j + 1] - '0') + carry;
			carry = product / 10;
			result[i + j + 1] = (product % 10) + '0';
		}
		result[i] += carry;
	}

	// Vezető nullák eltávolítása
	size_t startpos = result.find_first_not_of("0");
	if (std::string::npos != startpos) {
		result = result.substr(startpos);
	}
	else {
		result = "0";
	}

	num = result;
	return *this;
}

//Ugyanaz, mint long long int esetében, csak itt egy másik biginttel
//@param bigint n - szorzás ezzel a számmal
bigint& bigint::operator*(bigint n) {
	std::string temp = n.get();

	int n_len = temp.length();
	int num_len = num.length();

	// Ha nagyobb az n, akkor csere
	if (n_len > num_len) {
		std::swap(num, temp);
		std::swap(num_len, n_len);
	}

	std::string result(num_len + n_len, '0');

	for (int i = n_len - 1; i >= 0; --i) {
		int carry = 0;
		for (int j = num_len - 1; j >= 0; --j) {
			int product = (temp[i] - '0') * (num[j] - '0') + (result[i + j + 1] - '0') + carry;
			carry = product / 10;
			result[i + j + 1] = (product % 10) + '0';
		}
		result[i] += carry;
	}

	// vezető nullák eltávolítása
	size_t startpos = result.find_first_not_of('0');
	if (std::string::npos != startpos) {
		result = result.substr(startpos);
	}
	else {
		result = "0";
	}

	num = result;
	return *this;
}

//Írásbeli osztás, nem számol maradékkal
//@param long long int n - a másik szám
bigint& bigint::operator/(long long int n) {
	try {										//Nullával osztás csekkolása
		if (n == 0)
			throw ("Dividing by zero!");

	}

	catch (const char* err) {					//Kivételkezelés
		this->num = err;
		return *this;
	}

	std::string final = "";
	std::string s = this->num;
	int s_len = s.length();
	long long int m = 0;

	for (int i = 0; i < s_len; ++i) {
		m = m * 10 + (s[i] - '0');
		if (m >= n) {
			final += (m / n) + '0';
			m = m % n;
		}
		else if (!final.empty()) {
			final += '0';
		}
	}

	// Ha az eredmény üres, azaz a szám kisebb volt, mint n
	if (final.empty()) {
		final = "0";
	}

	this->num = final;
	return *this;
}

//Ugyanaz, mint long long int esetében, csak itt egy másik biginttel
//Figyelem! Csak átváltja a bigintet long long-ra. Előfordulhat integer overflow.
//@param bigint num - osztás biginttel
bigint& bigint::operator/(bigint num) {
	std::string final = "0";			//Végleges eredmény
	std::string s = this->num;			//Elmentjük az eredeti számot rosszabb időkre

	const char* numC = (num.num.c_str());

	int s_len = s.length();				//s hossza
	int m = 0;							//Maradék
	int mv = 0;							//Ha a maradék kisebb, mint amivel osztunk, akkor ez felel azért, 
	//hogy a számok ne csússzanak el a stringben
	long long int n = 0;

	int length = num.num.length();
	for (int i = 0; i < length; i++) {
		n = 10 * n + int(numC[i] - '0');
	}

	try {										//Nullával osztás csekkolása
		if (n == 0)
			throw ("Dividing by zero!");

	}

	catch (const char* err) {					//Kivételkezelés
		this->num = err;
		return *this;
	}

	/*long long int temp = int(*this->num.c_str() - '0');
	if (temp == n) {
		*this = 1;
		return *this;
	}*/

	for (int i = 0; i < s_len; i++) {
		m = m * 10 + int(s[i] - '0');
		if (m > n) {
			final[final.size() - 1 - mv] = char(m / n + '0');		//Ha m nagyobb, oszt, majd a maradékot kiszámolja
			m = m % n;
		}
		else if (m == 0) {
			final[i] = char(m / n + '0');		//Ha m = 0, akkor leírja m/n-t
		}
		else if (m == n) {
			final[final.size() - 1 - mv] = '1';		//Ha m = n, akkor 1-et ír
			m = 0;
		}
		else if (m < n) {
			mv++;						//Ennek a leírását lásd fent a deklarálásnál
		}

		if (i < s_len - 1)
			final.resize(final.size() + 1);
	}

	//Esetleges '\0' karakterek levágása (a resize() függvény okozza)
	std::string newfinal;
	int final_size = final.size();
	for (int i = 0; i < final_size && final[i] != '\0'; i++) {
		newfinal += final[i];
	}

	this->num = newfinal;
	return *this;
}

//Maradék meghatározása
//@param long long int n - modulus megadása
std::string bigint::operator%(long long int n) {
	std::string s = this->num;  // Elmentjük az eredeti számot
	int s_len = s.length();     // s hossza
	int m = 0;                  // Maradék

	// Nullával osztás csekkolása
	if (n == 0) {
		throw std::invalid_argument("Dividing by zero!");
	}
	if (n == 2) {
		if (this->num.back() == '0' || this->num.back() == '2' || this->num.back() == '4' || this->num.back() == '6' || this->num.back() == '8')
			return "0";
		return "1";
	}

	for (int i = 0; i < s_len; i++) {
		m = m * 10 + int(s[i] - '0');		// Maradék frissítése
		if (m >= n) {
			m = m % n;						// Maradék kiszámítása
		}
	}

	// A maradék visszaadása string formában
	std::string retvalue = std::to_string(m);
	return retvalue;
}

//Maradék meghatározása
//@param bigint num - modulus megadása
bigint& bigint::operator%(bigint n) {
	if (n.get() == "0") {
		throw std::invalid_argument("Dividing by zero!");
	}
	long long int dividend = std::stoll(num);
	long long int divisor = std::stoll(n.get());
	long long int result = dividend % divisor;
	num = std::to_string(result);
	return *this;
}

//Kiírás megvalósítása
std::ostream& operator<<(std::ostream& os, const bigint& n) {
	return os << n.get();
}
