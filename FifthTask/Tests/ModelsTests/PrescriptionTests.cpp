//
// Created by Александр Сафиюлин on 19.12.2020.
//

#include <gtest/gtest.h>
#include <Prescription/English/EnglishPrescription.hpp>

// ---------------------- HELPER TEST CLASSES ---------------------------------

struct PrescriptionFixtures : public testing::Test {
	PrescriptionFixtures() : prescription
		(new(std::nothrow) task::fifth::EnglishPrescription()) {}

	~PrescriptionFixtures() override = default;

	std::unique_ptr<task::fifth::EnglishPrescription> prescription;
};

//---------------------------- CTOR TESTS ------------------------------------

TEST(PrescriptionTest, CtorTest) {
	ASSERT_NE(nullptr, std::make_unique<task::fifth::EnglishPrescription>());
}

//---------------------- SMALL LETTER PRESCRIPT ------------------------------

TEST_F(PrescriptionFixtures, SmallLetterTest0) {
	ASSERT_STREQ("zero",
		this->prescription->ToSmallPrescription(0ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest1) {
	ASSERT_STREQ("two",
		this->prescription->ToSmallPrescription(2ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest2) {
	ASSERT_STREQ("thirteen",
		this->prescription->ToSmallPrescription(13ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest3) {
	ASSERT_STREQ("twenty",
		this->prescription->ToSmallPrescription(20ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest4) {
	ASSERT_STREQ("thirty three",
		this->prescription->ToSmallPrescription(33ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest5) {
	ASSERT_STREQ("fifty six",
		this->prescription->ToSmallPrescription(56ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest6) {
	ASSERT_STREQ("one hundred",
		this->prescription->ToSmallPrescription(100ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest7) {
	ASSERT_STREQ("one hundred four",
		this->prescription->ToSmallPrescription(104ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest8) {
	ASSERT_STREQ("one hundred nineteen",
		this->prescription->ToSmallPrescription(119ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest9) {
	ASSERT_STREQ("one hundred forty",
		this->prescription->ToSmallPrescription(140ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest10) {
	ASSERT_STREQ("one hundred seventy seven",
		this->prescription->ToSmallPrescription(177ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest11) {
	ASSERT_STREQ("two hundreds",
		this->prescription->ToSmallPrescription(200ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest12) {
	ASSERT_STREQ("four hundreds ten",
		this->prescription->ToSmallPrescription(410ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest13) {
	ASSERT_STREQ("six hundreds sixty seven",
		this->prescription->ToSmallPrescription(667ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest14) {
	ASSERT_STREQ("nine hundreds eighty",
		this->prescription->ToSmallPrescription(980ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest15) {
	ASSERT_STREQ("one thousand",
		this->prescription->ToSmallPrescription(1000ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest16) {
	ASSERT_STREQ("one thousand nine",
		this->prescription->ToSmallPrescription(1009ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest17) {
	ASSERT_STREQ("one thousand one hundred nine",
		this->prescription->ToSmallPrescription(1109ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest18) {
	ASSERT_STREQ("one thousand three hundreds eighteen",
		this->prescription->ToSmallPrescription(1318ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest19) {
	ASSERT_STREQ("one thousand five hundreds seventy eight",
		this->prescription->ToSmallPrescription(1578ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest20) {
	ASSERT_STREQ("six thousands five hundreds",
		this->prescription->ToSmallPrescription(6500ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest21) {
	ASSERT_STREQ("eight thousands eight hundreds eleven",
		this->prescription->ToSmallPrescription(8811ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest22) {
	ASSERT_STREQ("ten thousands",
		this->prescription->ToSmallPrescription(10000ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest23) {
	ASSERT_STREQ("twelve thousands twenty",
		this->prescription->ToSmallPrescription(12020ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest24) {
	ASSERT_STREQ("one hundred thousands",
		this->prescription->ToSmallPrescription(100000ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest25) {
	ASSERT_STREQ("one hundred thousands fifty",
		this->prescription->ToSmallPrescription(100050ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest26) {
	ASSERT_STREQ("one hundred twenty thousands one hundred ten",
		this->prescription->ToSmallPrescription(120110ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest27) {
	ASSERT_STREQ("seven hundreds thirty one thousands two hundreds thirteen",
		this->prescription->ToSmallPrescription(731213ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest28) {
	ASSERT_STREQ("one million",
		this->prescription->ToSmallPrescription(1000000ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest29) {
	ASSERT_STREQ("one million one",
		this->prescription->ToSmallPrescription(1000001ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest30) {
	ASSERT_STREQ("one million two hundreds thousands",
		this->prescription->ToSmallPrescription(1200000ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest31) {
	ASSERT_STREQ("one million nine hundreds ninety thousands twenty two",
		this->prescription->ToSmallPrescription(1990022ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest32) {
	ASSERT_STREQ("seven millions seven hundreds eighty seven thousands seven hundreds eighty seven",
		this->prescription->ToSmallPrescription(7787787ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest33) {
	ASSERT_STREQ("twelve millions twenty three thousands eight hundreds seventy four",
		this->prescription->ToSmallPrescription(12023874ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest34) {
	ASSERT_STREQ("nine hundreds seventy two millions six hundreds sixty three thousands eight hundreds",
		this->prescription->ToSmallPrescription(972663800ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest35) {
	ASSERT_STREQ("one billion",
		this->prescription->ToSmallPrescription(1000000000ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest36) {
	ASSERT_STREQ("thirty one billions two millions",
		this->prescription->ToSmallPrescription(31002000000ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest37) {
	ASSERT_STREQ("one hundred seventy two billions thirty three millions ten thousands sixteen",
		this->prescription->ToSmallPrescription(172033010016ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest38) {
	ASSERT_STREQ("eight hundreds sixty billions one hundred forty millions one hundred thousands eight hundreds seventeen",
		this->prescription->ToSmallPrescription(860140100817ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest39) {
	ASSERT_STREQ("one billiard",
		this->prescription->ToSmallPrescription(1000000000000ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest40) {
	ASSERT_STREQ("one billiard two hundreds billions one hundred twelve millions nine hundreds ninety nine thousands eight hundreds eighty eight",
		this->prescription->ToSmallPrescription(1200112999888ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest41) {
	ASSERT_STREQ("eleven billiards three hundreds twenty billions two hundreds twelve millions three hundreds forty five thousands one hundred twenty",
		this->prescription->ToSmallPrescription(11320212345120ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest42) {
	ASSERT_STREQ("two hundreds twenty nine billiards nine hundreds thirty two billions one hundred millions nine hundreds ninety nine thousands seven hundreds seventy one",
		this->prescription->ToSmallPrescription(229932100999771ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest43) {
	ASSERT_STREQ("one trillion three hundreds billiards nine hundreds billions two hundreds millions nine hundreds thousands one hundred",
		this->prescription->ToSmallPrescription(1300900200900100ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest44) {
	ASSERT_STREQ("twenty trillions eight hundreds twenty billiards seven hundreds twenty billions two hundreds ten millions nine hundreds one thousands seven hundreds ninety three",
		this->prescription->ToSmallPrescription(20820720210901793ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest45) {
	ASSERT_STREQ("seven hundreds fifty one trillions eight hundreds thirty three billiards seven hundreds twenty one billions two hundreds ten millions two hundreds eleven thousands one hundred twenty three",
		this->prescription->ToSmallPrescription(751833721210211123ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest46) {
	ASSERT_STREQ("one trilliard eleven trillions one hundred thirteen billiards two hundreds twenty one billions two hundreds ten millions two hundreds eleven thousands nine hundreds",
		this->prescription->ToSmallPrescription(1011113221210211900ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest47) {
	ASSERT_STREQ("nine trilliards two hundreds twenty three trillions three hundreds seventy two billiards thirty six billions eight hundreds fifty four millions seven hundreds seventy five thousands eight hundreds seven",
		this->prescription->ToSmallPrescription(std::numeric_limits<long long>::max()).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest48) {
	ASSERT_STREQ("minus eight",
		this->prescription->ToSmallPrescription(-8ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest49) {
	ASSERT_STREQ("minus ninety two",
		this->prescription->ToSmallPrescription(-92ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest50) {
	ASSERT_STREQ("minus one hundred sixty",
		this->prescription->ToSmallPrescription(-160ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest51) {
	ASSERT_STREQ("minus two hundreds fifty one",
		this->prescription->ToSmallPrescription(-251ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest52) {
	ASSERT_STREQ("minus ten thousands three hundreds twenty nine",
		this->prescription->ToSmallPrescription(-10329ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest53) {
	ASSERT_STREQ("minus ten thousands three hundreds twenty nine",
		this->prescription->ToSmallPrescription(-10329ll).c_str());
}

TEST_F(PrescriptionFixtures, SmallLetterTest54) {
	ASSERT_STREQ("minus one million two hundreds twenty thousands four hundreds thirty five",
		this->prescription->ToSmallPrescription(-1220435ll).c_str());
}

//---------------------- BIG LETTER PRESCRIPT --------------------------------

TEST_F(PrescriptionFixtures, BigLetterTest0) {
	ASSERT_STREQ("Zero",
		this->prescription->ToBigPrescription(0ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest1) {
	ASSERT_STREQ("Two",
		this->prescription->ToBigPrescription(2ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest2) {
	ASSERT_STREQ("Thirteen",
		this->prescription->ToBigPrescription(13ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest3) {
	ASSERT_STREQ("Twenty",
		this->prescription->ToBigPrescription(20ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest4) {
	ASSERT_STREQ("Thirty three",
		this->prescription->ToBigPrescription(33ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest5) {
	ASSERT_STREQ("Fifty six",
		this->prescription->ToBigPrescription(56ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest6) {
	ASSERT_STREQ("One hundred",
		this->prescription->ToBigPrescription(100ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest7) {
	ASSERT_STREQ("One hundred four",
		this->prescription->ToBigPrescription(104ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest8) {
	ASSERT_STREQ("One hundred nineteen",
		this->prescription->ToBigPrescription(119ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest9) {
	ASSERT_STREQ("One hundred forty",
		this->prescription->ToBigPrescription(140ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest10) {
	ASSERT_STREQ("One hundred seventy seven",
		this->prescription->ToBigPrescription(177ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest11) {
	ASSERT_STREQ("Two hundreds",
		this->prescription->ToBigPrescription(200ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest12) {
	ASSERT_STREQ("Four hundreds ten",
		this->prescription->ToBigPrescription(410ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest13) {
	ASSERT_STREQ("Six hundreds sixty seven",
		this->prescription->ToBigPrescription(667ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest14) {
	ASSERT_STREQ("Nine hundreds eighty",
		this->prescription->ToBigPrescription(980ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest15) {
	ASSERT_STREQ("One thousand",
		this->prescription->ToBigPrescription(1000ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest16) {
	ASSERT_STREQ("One thousand nine",
		this->prescription->ToBigPrescription(1009ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest17) {
	ASSERT_STREQ("One thousand one hundred nine",
		this->prescription->ToBigPrescription(1109ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest18) {
	ASSERT_STREQ("One thousand three hundreds eighteen",
		this->prescription->ToBigPrescription(1318ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest19) {
	ASSERT_STREQ("One thousand five hundreds seventy eight",
		this->prescription->ToBigPrescription(1578ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest20) {
	ASSERT_STREQ("Six thousands five hundreds",
		this->prescription->ToBigPrescription(6500ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest21) {
	ASSERT_STREQ("Eight thousands eight hundreds eleven",
		this->prescription->ToBigPrescription(8811ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest22) {
	ASSERT_STREQ("Ten thousands",
		this->prescription->ToBigPrescription(10000ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest23) {
	ASSERT_STREQ("Twelve thousands twenty",
		this->prescription->ToBigPrescription(12020ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest24) {
	ASSERT_STREQ("One hundred thousands",
		this->prescription->ToBigPrescription(100000ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest25) {
	ASSERT_STREQ("One hundred thousands fifty",
		this->prescription->ToBigPrescription(100050ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest26) {
	ASSERT_STREQ("One hundred twenty thousands one hundred ten",
		this->prescription->ToBigPrescription(120110ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest27) {
	ASSERT_STREQ("Seven hundreds thirty one thousands two hundreds thirteen",
		this->prescription->ToBigPrescription(731213ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest28) {
	ASSERT_STREQ("One million",
		this->prescription->ToBigPrescription(1000000ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest29) {
	ASSERT_STREQ("One million one",
		this->prescription->ToBigPrescription(1000001ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest30) {
	ASSERT_STREQ("One million two hundreds thousands",
		this->prescription->ToBigPrescription(1200000ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest31) {
	ASSERT_STREQ("One million nine hundreds ninety thousands twenty two",
		this->prescription->ToBigPrescription(1990022ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest32) {
	ASSERT_STREQ("Seven millions seven hundreds eighty seven thousands seven hundreds eighty seven",
		this->prescription->ToBigPrescription(7787787ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest33) {
	ASSERT_STREQ("Twelve millions twenty three thousands eight hundreds seventy four",
		this->prescription->ToBigPrescription(12023874ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest34) {
	ASSERT_STREQ("Nine hundreds seventy two millions six hundreds sixty three thousands eight hundreds",
		this->prescription->ToBigPrescription(972663800ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest35) {
	ASSERT_STREQ("One billion",
		this->prescription->ToBigPrescription(1000000000ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest36) {
	ASSERT_STREQ("Thirty one billions two millions",
		this->prescription->ToBigPrescription(31002000000ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest37) {
	ASSERT_STREQ("One hundred seventy two billions thirty three millions ten thousands sixteen",
		this->prescription->ToBigPrescription(172033010016ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest38) {
	ASSERT_STREQ("Eight hundreds sixty billions one hundred forty millions one hundred thousands eight hundreds seventeen",
		this->prescription->ToBigPrescription(860140100817ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest39) {
	ASSERT_STREQ("One billiard",
		this->prescription->ToBigPrescription(1000000000000ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest40) {
	ASSERT_STREQ("One billiard two hundreds billions one hundred twelve millions nine hundreds ninety nine thousands eight hundreds eighty eight",
		this->prescription->ToBigPrescription(1200112999888ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest41) {
	ASSERT_STREQ("Eleven billiards three hundreds twenty billions two hundreds twelve millions three hundreds forty five thousands one hundred twenty",
		this->prescription->ToBigPrescription(11320212345120ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest42) {
	ASSERT_STREQ("Two hundreds twenty nine billiards nine hundreds thirty two billions one hundred millions nine hundreds ninety nine thousands seven hundreds seventy one",
		this->prescription->ToBigPrescription(229932100999771ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest43) {
	ASSERT_STREQ("One trillion three hundreds billiards nine hundreds billions two hundreds millions nine hundreds thousands one hundred",
		this->prescription->ToBigPrescription(1300900200900100ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest44) {
	ASSERT_STREQ("Twenty trillions eight hundreds twenty billiards seven hundreds twenty billions two hundreds ten millions nine hundreds one thousands seven hundreds ninety three",
		this->prescription->ToBigPrescription(20820720210901793ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest45) {
	ASSERT_STREQ("Seven hundreds fifty one trillions eight hundreds thirty three billiards seven hundreds twenty one billions two hundreds ten millions two hundreds eleven thousands one hundred twenty three",
		this->prescription->ToBigPrescription(751833721210211123ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest46) {
	ASSERT_STREQ("One trilliard eleven trillions one hundred thirteen billiards two hundreds twenty one billions two hundreds ten millions two hundreds eleven thousands nine hundreds",
		this->prescription->ToBigPrescription(1011113221210211900ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest47) {
	ASSERT_STREQ("Nine trilliards two hundreds twenty three trillions three hundreds seventy two billiards thirty six billions eight hundreds fifty four millions seven hundreds seventy five thousands eight hundreds seven",
		this->prescription->ToBigPrescription(std::numeric_limits<long long>::max()).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest48) {
	ASSERT_STREQ("Minus eight",
		this->prescription->ToBigPrescription(-8ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest49) {
	ASSERT_STREQ("Minus ninety two",
		this->prescription->ToBigPrescription(-92ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest50) {
	ASSERT_STREQ("Minus one hundred sixty",
		this->prescription->ToBigPrescription(-160ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest51) {
	ASSERT_STREQ("Minus two hundreds fifty one",
		this->prescription->ToBigPrescription(-251ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest52) {
	ASSERT_STREQ("Minus ten thousands three hundreds twenty nine",
		this->prescription->ToBigPrescription(-10329ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest53) {
	ASSERT_STREQ("Minus ten thousands three hundreds twenty nine",
		this->prescription->ToBigPrescription(-10329ll).c_str());
}

TEST_F(PrescriptionFixtures, BigLetterTest54) {
	ASSERT_STREQ("Minus one million two hundreds twenty thousands four hundreds thirty five",
		this->prescription->ToBigPrescription(-1220435ll).c_str());
}