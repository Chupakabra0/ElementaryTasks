#include <gtest/gtest.h>
#include <LuckyTicketCounter/LuckyTicketCounter.hpp>

// ---------------------- HELPER TEST CLASSES ---------------------------------

struct LuckyTicketCounterFixture : public testing::Test {
 public:
  LuckyTicketCounterFixture()
	  : numberCount(3u),
		ltc(std::make_unique<task::sixth::LuckyTicketCounter>(this->numberCount)) {}

  ~LuckyTicketCounterFixture() override = default;

  unsigned int numberCount;

  std::unique_ptr<task::sixth::LuckyTicketCounter> ltc;
};

//---------------------------- CTOR TESTS ------------------------------------

TEST(LuckyTicketCounterTest, CtorTests1) {
  const auto numberCount = 1u;

  const std::unique_ptr<task::sixth::LuckyTicketCounter> ltc
	  (new(std::nothrow) task::sixth::LuckyTicketCounter(numberCount));

  ASSERT_NE(nullptr, ltc);
  ASSERT_EQ(numberCount, ltc->GetCountNumbers());
}

TEST(LuckyTicketCounterTest, CtorTests2) {
  const std::unique_ptr<task::sixth::LuckyTicketCounter> ltc
	  (new(std::nothrow) task::sixth::LuckyTicketCounter());

  ASSERT_NE(nullptr, ltc);
}

//-------------------------- GETTERS TESTS -----------------------------------

TEST_F(LuckyTicketCounterFixture, CountNumberGetterTest) {
  ASSERT_EQ(this->numberCount, this->ltc->GetCountNumbers());
}

//-------------------------- SETTERS TESTS -----------------------------------

TEST_F(LuckyTicketCounterFixture, CountNumberSetterTest) {
  ASSERT_EQ(this->numberCount, this->ltc->GetCountNumbers());
}

//----------------------- COUNT MOSCOW TESTS ---------------------------------

TEST_F(LuckyTicketCounterFixture, CountMoscowType1) {
  const auto ticketType = task::sixth::LuckyTicketType::MOSCOW;
  this->ltc->SetCountNumbers(2u);
  ASSERT_EQ(670ull, this->ltc->GetLuckyTicketsCount(ticketType));
}

TEST_F(LuckyTicketCounterFixture, CountMoscowType2) {
  const auto ticketType = task::sixth::LuckyTicketType::MOSCOW;
  this->ltc->SetCountNumbers(3u);
  ASSERT_EQ(55252ull, this->ltc->GetLuckyTicketsCount(ticketType));
}

TEST_F(LuckyTicketCounterFixture, CountMoscowType3) {
  const auto ticketType = task::sixth::LuckyTicketType::MOSCOW;
  this->ltc->SetCountNumbers(4u);
  ASSERT_EQ(4816030ull, this->ltc->GetLuckyTicketsCount(ticketType));
}

TEST_F(LuckyTicketCounterFixture, CountMoscowType4) {
  const auto ticketType = task::sixth::LuckyTicketType::MOSCOW;
  this->ltc->SetCountNumbers(5u);
  ASSERT_EQ(432457640ull, this->ltc->GetLuckyTicketsCount(ticketType));
}

TEST_F(LuckyTicketCounterFixture, CountMoscowType5) {
  const auto ticketType = task::sixth::LuckyTicketType::MOSCOW;
  this->ltc->SetCountNumbers(6u);
  ASSERT_EQ(39581170420ull, this->ltc->GetLuckyTicketsCount(ticketType));
}

//------------------------ COUNT PITER TESTS -----------------------------------

TEST_F(LuckyTicketCounterFixture, CountPiterType1) {
  const auto ticketType = task::sixth::LuckyTicketType::PITER;
  this->ltc->SetCountNumbers(2u);
  ASSERT_EQ(670ull, this->ltc->GetLuckyTicketsCount(ticketType));
}

TEST_F(LuckyTicketCounterFixture, CountPiterType2) {
  const auto ticketType = task::sixth::LuckyTicketType::PITER;
  this->ltc->SetCountNumbers(3u);
  ASSERT_EQ(55252ull, this->ltc->GetLuckyTicketsCount(ticketType));
}

TEST_F(LuckyTicketCounterFixture, CountPiterType3) {
  const auto ticketType = task::sixth::LuckyTicketType::PITER;
  this->ltc->SetCountNumbers(4u);
  ASSERT_EQ(4816030ull, this->ltc->GetLuckyTicketsCount(ticketType));
}
