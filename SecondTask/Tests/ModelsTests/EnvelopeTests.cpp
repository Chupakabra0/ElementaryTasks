//
// Created by Александр Сафиюлин on 18.12.2020.
//

#include <gtest/gtest.h>
#include <Envelope/EnvelopePlacer/EnvelopePlacer.hpp>

// ---------------------- HELPER TEST CLASSES ---------------------------------

struct EnvelopesFixture : public testing::Test {

	EnvelopesFixture() : firstSize(5.5, 16.1), secondSize(2.3, 50.2),
		firstEnvelope(new(std::nothrow) task::second::Envelope
		(this->firstSize.first, this->firstSize.second)),
		secondEnvelope(new(std::nothrow) task::second::Envelope
		(this->secondSize.first, this->secondSize.second))
	{}

	~EnvelopesFixture() override = default;

	std::pair<double, double> firstSize;
	std::pair<double, double> secondSize;
	
	std::unique_ptr<task::second::Envelope> firstEnvelope;
	std::unique_ptr<task::second::Envelope> secondEnvelope;
};

//---------------------------- CTOR TESTS -------------------------------------

TEST(EnvelopeTests, CtorTest1) {
	const std::pair<double, double> size(2.0, 1.0);
	const std::unique_ptr<task::second::Envelope>
		envelope(new(std::nothrow) task::second::Envelope
		(size.first, size.second));
	
	ASSERT_NE(nullptr, envelope);
	ASSERT_EQ(envelope->GetHeight(), size.first);
	ASSERT_EQ(envelope->GetWidth(), size.second);
}


TEST(EnvelopeTests, CtorTest2) {
	const auto size = 12.2;
	const std::unique_ptr<task::second::Envelope>
		envelope(new(std::nothrow) task::second::Envelope(size));

	ASSERT_NE(nullptr, envelope);
	ASSERT_EQ(envelope->GetHeight(), size);
	ASSERT_EQ(envelope->GetWidth(), size);
}

//---------------------------- GETTERS TESTS ----------------------------------

TEST_F(EnvelopesFixture, HeightGetterTest) {
	ASSERT_EQ(this->firstSize.first, this->firstEnvelope->GetHeight());
	ASSERT_EQ(this->secondSize.first, this->secondEnvelope->GetHeight());
}

TEST_F(EnvelopesFixture, WidthGetterTest) {
	ASSERT_EQ(this->firstSize.second, this->firstEnvelope->GetWidth());
	ASSERT_EQ(this->secondSize.second, this->secondEnvelope->GetWidth());
}

//-------------------------- SETTERS TESTS -----------------------------------

TEST_F(EnvelopesFixture, HeightSetterTest) {
	const double valuesToSet[]{
		std::numeric_limits<double>::min(),
		std::numeric_limits<double>::max(),
		std::numeric_limits<double>::epsilon()
	};

	for (const auto& i : valuesToSet) {
		const auto temp1 = *this->firstEnvelope;
		const auto temp2 = *this->secondEnvelope;
		
		this->firstEnvelope->SetHeight(i);
		this->secondEnvelope->SetHeight(i);
		
		ASSERT_EQ(i, this->firstEnvelope->GetHeight());
		ASSERT_EQ(i, this->secondEnvelope->GetHeight());
		
		ASSERT_NE(temp1, *this->firstEnvelope);
		ASSERT_NE(temp2, *this->secondEnvelope);

		ASSERT_DOUBLE_EQ(this->firstEnvelope->GetHeight(), this->secondEnvelope->GetHeight());
	}
}

TEST_F(EnvelopesFixture, WidthSetterTest) {
	const double valuesToSet[]{
	std::numeric_limits<double>::min(),
	std::numeric_limits<double>::max(),
	std::numeric_limits<double>::epsilon()
	};

	for (const auto& i : valuesToSet) {
		const auto temp1 = *this->firstEnvelope;
		const auto temp2 = *this->secondEnvelope;

		this->firstEnvelope->SetWidth(i);
		this->secondEnvelope->SetWidth(i);

		ASSERT_EQ(i, this->firstEnvelope->GetWidth());
		ASSERT_EQ(i, this->secondEnvelope->GetWidth());

		ASSERT_NE(temp1, *this->firstEnvelope);
		ASSERT_NE(temp2, *this->secondEnvelope);

		ASSERT_DOUBLE_EQ(this->firstEnvelope->GetWidth(), this->secondEnvelope->GetWidth());
	}
}

//------------------------- ASSIGNMENTS TESTS ------------------------------

TEST_F(EnvelopesFixture, AssignmentTest) {
	const std::pair<double, double> size(1.1, 2.2);
	const auto temp = *this->firstEnvelope;
	
	this->firstEnvelope->SetHeight(size.first);
	this->firstEnvelope->SetWidth(size.second);

	ASSERT_NE(*this->firstEnvelope, temp);
}

//------------------------- PLACER TESTS -----------------------------------

TEST_F(EnvelopesFixture, PlacerTest1) {
	const auto size = 10.1;
	
	this->firstEnvelope->SetHeight(size);
	this->firstEnvelope->SetWidth(size);

	this->secondEnvelope->SetHeight(size);
	this->secondEnvelope->SetWidth(size);

	ASSERT_TRUE(task::second::EnvelopePlacer::CanPlace
	(*this->firstEnvelope, *this->secondEnvelope));
	ASSERT_TRUE(task::second::EnvelopePlacer::CanPlace
	(*this->secondEnvelope, *this->firstEnvelope));
}

TEST_F(EnvelopesFixture, PlacerTest2) {
	const std::pair<double, double> size(12.0, 1.2);

	this->firstEnvelope->SetHeight(size.first);
	this->firstEnvelope->SetWidth(size.second);

	this->secondEnvelope->SetHeight(size.first);
	this->secondEnvelope->SetWidth(size.second);

	ASSERT_TRUE(task::second::EnvelopePlacer::CanPlace
	(*this->firstEnvelope, *this->secondEnvelope));
	ASSERT_TRUE(task::second::EnvelopePlacer::CanPlace
	(*this->secondEnvelope, *this->firstEnvelope));
}

TEST_F(EnvelopesFixture, PlacerTest3) {
	const std::pair<double, double> firstSize(15.0, 5.0);
	const auto secondSize = 1.0;

	this->firstEnvelope->SetHeight(firstSize.first);
	this->firstEnvelope->SetWidth(firstSize.second);

	this->secondEnvelope->SetHeight(secondSize);
	this->secondEnvelope->SetWidth(secondSize);

	ASSERT_FALSE(task::second::EnvelopePlacer::CanPlace
	(*this->firstEnvelope, *this->secondEnvelope));
	ASSERT_TRUE(task::second::EnvelopePlacer::CanPlace
	(*this->secondEnvelope, *this->firstEnvelope));
}

TEST_F(EnvelopesFixture, PlacerTest4) {
	const std::pair<double, double> firstSize(15.0, 5.0);
	const std::pair<double, double> secondSize(5.0, 15.0);

	this->firstEnvelope->SetHeight(firstSize.first);
	this->firstEnvelope->SetWidth(firstSize.second);

	this->secondEnvelope->SetHeight(secondSize.first);
	this->secondEnvelope->SetWidth(secondSize.second);

	ASSERT_TRUE(task::second::EnvelopePlacer::CanPlace
	(*this->firstEnvelope, *this->secondEnvelope));
	ASSERT_TRUE(task::second::EnvelopePlacer::CanPlace
	(*this->secondEnvelope, *this->firstEnvelope));
}

TEST_F(EnvelopesFixture, PlacerTest5) {
	const std::pair<double, double> firstSize(3.0, 25.0);
	const std::pair<double, double> secondSize(5.0, 15.0);

	this->firstEnvelope->SetHeight(firstSize.first);
	this->firstEnvelope->SetWidth(firstSize.second);

	this->secondEnvelope->SetHeight(secondSize.first);
	this->secondEnvelope->SetWidth(secondSize.second);

	ASSERT_FALSE(task::second::EnvelopePlacer::CanPlace
	(*this->firstEnvelope, *this->secondEnvelope));
	ASSERT_FALSE(task::second::EnvelopePlacer::CanPlace
	(*this->secondEnvelope, *this->firstEnvelope));
}