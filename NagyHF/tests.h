#include "Account.h"
#include "Layout.h"
#include "Date.h"
#include "gtest_lite.h"
#include "RSA.h"

#ifndef TESTS_H
#define TESTS_H

void bigintTest() {
	//integerekkel való tesztelés
	TEST(bigintTeszt1, operatorok) {
		bigint a;
		a = 15;
		std::string number = "15";
		EXPECT_EQ(number, a.get());

		number = "1500";
		a = a * 100;
		EXPECT_EQ(number, a.get());

		number = "15";
		a = a / 100;
		EXPECT_EQ(number, a.get());

		number = "115";
		a = a + 100;
		EXPECT_EQ(number, a.get());
	} END
	

	//bigint és bigint közti tesztelés
	TEST(bigintTeszt2, operatorok) {
		bigint a;
		a = 15;
		bigint b;
		b = 100;
		std::string number = "1500";
		a = a * b;
		EXPECT_EQ(number, a.get());

		number = "15";
		a = a / b;
		EXPECT_EQ(number, a.get());

		number = "115";
		a = a + b;
		EXPECT_EQ(number, a.get());
	} END
	
	TEST(bigintTeszt3, nullavalosztas) {
		bigint a;
		a = 15;

		std::string number = "Dividing by zero!";
		a = a / 0;
		EXPECT_EQ(number, a.get());
	} END
	
	TEST(bigintTeszt3, maradek) {
		bigint a = 20;
		std::string number = "5";

		std::string asd = a % 15;
		EXPECT_EQ(number, asd);
	} END
}

void dateTest() {
	TEST(DateTest, cout) {
		Date d;
		std::string date = "22:04:2003";

		d.setYear(2003);
		d.setMonth(4);
		d.setDay(22);
		EXPECT_EQ(d.getDate(), date);
	} END
	
}

void rsaTest() {
	TEST(RSATest, Encoding) {
		RSA a(353, 359);
		bigint message = 123;
		bigint code;
		code = a.Encode(message).get();
		code = a.Decode(code).get();
		EXPECT_EQ(message, code);
	} END
}

#endif