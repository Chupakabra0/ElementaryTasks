//
// Created by Александр Сафиюлин on 17.12.2020.
//

#include <gtest/gtest.h>
#include <Board/BoardCreator.hpp>

// ---------------------- HELPER TEST CLASSES ---------------------------------

struct BoardCreatorCharFixture : public testing::Test {
 public:
  BoardCreatorCharFixture()
	  : blackSymbol('*'), whiteSymbol(' '),
		boardCreator
			(new(std::nothrow) task::first::BoardCreator(this->blackSymbol, this->whiteSymbol)
			) {}

  ~BoardCreatorCharFixture() override = default;

  char blackSymbol;
  char whiteSymbol;

  std::unique_ptr<task::first::BoardCreator<char>> boardCreator;
};

struct BoardCreatorIntFixture : public testing::Test {
 public:
  BoardCreatorIntFixture()
	  : blackSymbol(1), whiteSymbol(0),
	  boardCreator
	  (new(std::nothrow) task::first::BoardCreator(this->blackSymbol, this->whiteSymbol)
	  ) {}

  ~BoardCreatorIntFixture() override = default;

  int blackSymbol;
  int whiteSymbol;

  std::unique_ptr<task::first::BoardCreator<int>> boardCreator;
};

//---------------------------- CTOR TESTS ------------------------------------

TEST(BoardCreatorCtorTests, CharCtorTest) {
  const auto blackSymbol = '*';
  const auto whiteSymbol = ' ';

  std::unique_ptr<task::first::BoardCreator<char>> boardCreator
	  (new(std::nothrow) task::first::BoardCreator<char>(blackSymbol, whiteSymbol));

  ASSERT_NE(nullptr, boardCreator);
  ASSERT_EQ(boardCreator->GetBlackSymbol(), blackSymbol);
  ASSERT_EQ(boardCreator->GetWhiteSymbol(), whiteSymbol);
}

TEST(BoardCreatorCtorTests, IntCtorTest) {
  const auto blackSymbol = 1;
  const auto whiteSymbol = 0;

  std::unique_ptr<task::first::BoardCreator<int>> boardCreator
	  (new(std::nothrow) task::first::BoardCreator<int>(blackSymbol, whiteSymbol));

  ASSERT_NE(nullptr, boardCreator);
  ASSERT_EQ(boardCreator->GetBlackSymbol(), blackSymbol);
  ASSERT_EQ(boardCreator->GetWhiteSymbol(), whiteSymbol);
}

//-------------------------- GETTERS TESTS -----------------------------------

TEST_F(BoardCreatorCharFixture, BlackSymbolGetterTest) {
  ASSERT_EQ(this->boardCreator->GetBlackSymbol(), this->blackSymbol);
}

TEST_F(BoardCreatorIntFixture, BlackSymbolGetterTest) {
  ASSERT_EQ(this->boardCreator->GetBlackSymbol(), this->blackSymbol);
}

TEST_F(BoardCreatorCharFixture, WhiteSymbolGetterTest) {
  ASSERT_EQ(this->boardCreator->GetWhiteSymbol(), this->whiteSymbol);
}

TEST_F(BoardCreatorIntFixture, WhiteSymbolGetterTest) {
  ASSERT_EQ(this->boardCreator->GetWhiteSymbol(), this->whiteSymbol);
}

//-------------------------- SETTERS TESTS -----------------------------------

TEST_F(BoardCreatorCharFixture, BlackSymbolSetterTest) {
  const char valuesToSet[]{
	  std::numeric_limits<char>::max(),
	  std::numeric_limits<char>::min(),
	  std::numeric_limits<char>::epsilon()
  };

  for (const auto &i : valuesToSet) {
	this->boardCreator->SetBlackSymbol(i);
	ASSERT_EQ(i, this->boardCreator->GetBlackSymbol());
  }
}

TEST_F(BoardCreatorIntFixture, BlackSymbolSetterTest) {
  const int valuesToSet[]{
	  std::numeric_limits<int>::max(),
	  std::numeric_limits<int>::min(),
	  std::numeric_limits<int>::epsilon()
  };

  for (const auto &i : valuesToSet) {
	this->boardCreator->SetBlackSymbol(i);
	ASSERT_EQ(i, this->boardCreator->GetBlackSymbol());
  }
}

TEST_F(BoardCreatorCharFixture, WhiteSymbolSetterTest) {
  const char valuesToSet[]{
	  std::numeric_limits<char>::max(),
	  std::numeric_limits<char>::min(),
	  std::numeric_limits<char>::epsilon()
  };

  for (const auto &i : valuesToSet) {
	this->boardCreator->SetWhiteSymbol(i);
	ASSERT_EQ(i, this->boardCreator->GetWhiteSymbol());
  }
}

TEST_F(BoardCreatorIntFixture, WhiteSymbolSetterTest) {
  const int valuesToSet[]{
	  std::numeric_limits<int>::max(),
	  std::numeric_limits<int>::min(),
	  std::numeric_limits<int>::epsilon()
  };

  for (const auto &i : valuesToSet) {
	this->boardCreator->SetWhiteSymbol(i);
	ASSERT_EQ(i, this->boardCreator->GetWhiteSymbol());
  }
}

//------------------------- CREATE BOARD TESTS ------------------------------

TEST_F(BoardCreatorCharFixture, CreateNullptrBoardTest) {
  ASSERT_EQ(nullptr, this->boardCreator->CreateBoard(0, 0));
  ASSERT_EQ(nullptr, this->boardCreator->CreateBoard(1, 0));
  ASSERT_EQ(nullptr, this->boardCreator->CreateBoard(0, 1));
}

TEST_F(BoardCreatorIntFixture, CreateNullptrBoardTest) {
  ASSERT_EQ(nullptr, this->boardCreator->CreateBoard(0, 0));
  ASSERT_EQ(nullptr, this->boardCreator->CreateBoard(1, 0));
  ASSERT_EQ(nullptr, this->boardCreator->CreateBoard(0, 1));
}

TEST_F(BoardCreatorCharFixture, CreateBoardTest) {
  auto rows = 1;
  auto columns = 1;
  auto board = this->boardCreator->CreateBoard(rows, columns);

  ASSERT_NE(nullptr, board);
  ASSERT_EQ(' ', board->GetWhiteSymbol());
  ASSERT_EQ('*', board->GetBlackSymbol());
  ASSERT_EQ(rows, board->GetRowsCount());
  ASSERT_EQ(columns, board->GetColumnsCount());

  rows = 123;
  board = this->boardCreator->CreateBoard(rows, columns);

  ASSERT_NE(nullptr, board);
  ASSERT_EQ(' ', board->GetWhiteSymbol());
  ASSERT_EQ('*', board->GetBlackSymbol());
  ASSERT_EQ(rows, board->GetRowsCount());
  ASSERT_EQ(columns, board->GetColumnsCount());

  columns = 123;
  board = this->boardCreator->CreateBoard(rows, columns);

  ASSERT_NE(nullptr, board);
  ASSERT_EQ(' ', board->GetWhiteSymbol());
  ASSERT_EQ('*', board->GetBlackSymbol());
  ASSERT_EQ(rows, board->GetRowsCount());
  ASSERT_EQ(columns, board->GetColumnsCount());
}

TEST_F(BoardCreatorIntFixture, CreateBoardTest) {
  auto rows = 1;
  auto columns = 1;
  auto board = this->boardCreator->CreateBoard(rows, columns);

  ASSERT_NE(nullptr, board);
  ASSERT_EQ(this->whiteSymbol, board->GetWhiteSymbol());
  ASSERT_EQ(this->blackSymbol, board->GetBlackSymbol());
  ASSERT_EQ(rows, board->GetRowsCount());
  ASSERT_EQ(columns, board->GetColumnsCount());

  rows = 123;
  board = this->boardCreator->CreateBoard(rows, columns);

  ASSERT_NE(nullptr, board);
  ASSERT_EQ(this->whiteSymbol, board->GetWhiteSymbol());
  ASSERT_EQ(this->blackSymbol, board->GetBlackSymbol());
  ASSERT_EQ(rows, board->GetRowsCount());
  ASSERT_EQ(columns, board->GetColumnsCount());

  columns = 123;
  board = this->boardCreator->CreateBoard(rows, columns);

  ASSERT_NE(nullptr, board);
  ASSERT_EQ(this->whiteSymbol, board->GetWhiteSymbol());
  ASSERT_EQ(this->blackSymbol, board->GetBlackSymbol());
  ASSERT_EQ(rows, board->GetRowsCount());
  ASSERT_EQ(columns, board->GetColumnsCount());
}

//------------------------- ASSIGNMENTS TESTS ------------------------------

TEST_F(BoardCreatorCharFixture, AssignmentTest) {
  const auto copyBoardCreator = *this->boardCreator;

  ASSERT_EQ(copyBoardCreator.GetWhiteSymbol(), this->whiteSymbol);
  ASSERT_EQ(copyBoardCreator.GetBlackSymbol(), this->blackSymbol);

  const auto rows = 1;
  const auto columns = 1;
  const auto firstBoard = copyBoardCreator.CreateBoard(rows, columns);

  ASSERT_EQ(firstBoard->GetWhiteSymbol(), copyBoardCreator.GetWhiteSymbol());
  ASSERT_EQ(firstBoard->GetBlackSymbol(), copyBoardCreator.GetBlackSymbol());
  ASSERT_EQ(firstBoard->GetRowsCount(), rows);
  ASSERT_EQ(firstBoard->GetColumnsCount(), columns);

  const std::pair<char, char> symbols('S', 'A');

  this->boardCreator->SetBlackSymbol(symbols.first);
  this->boardCreator->SetWhiteSymbol(symbols.second);

  ASSERT_NE(copyBoardCreator.GetWhiteSymbol(), this->boardCreator->GetWhiteSymbol());
  ASSERT_NE(copyBoardCreator.GetBlackSymbol(), this->boardCreator->GetBlackSymbol());

  const auto secondBoard = this->boardCreator->CreateBoard(rows, columns);

  ASSERT_NE(firstBoard->GetWhiteSymbol(), secondBoard->GetWhiteSymbol());
  ASSERT_NE(firstBoard->GetBlackSymbol(), secondBoard->GetBlackSymbol());
}

TEST_F(BoardCreatorIntFixture, AssignmentTest) {
	const auto copyBoardCreator = *this->boardCreator;

	ASSERT_EQ(copyBoardCreator.GetWhiteSymbol(), this->boardCreator->GetWhiteSymbol());
	ASSERT_EQ(copyBoardCreator.GetBlackSymbol(), this->boardCreator->GetBlackSymbol());

	const auto rows = 1;
	const auto columns = 1;
	const auto firstBoard = copyBoardCreator.CreateBoard(rows, columns);

	ASSERT_EQ(firstBoard->GetWhiteSymbol(), copyBoardCreator.GetWhiteSymbol());
	ASSERT_EQ(firstBoard->GetBlackSymbol(), copyBoardCreator.GetBlackSymbol());
	ASSERT_EQ(firstBoard->GetRowsCount(), rows);
	ASSERT_EQ(firstBoard->GetColumnsCount(), columns);

	const std::pair<int, int> symbols(10, 4);

	this->boardCreator->SetBlackSymbol(symbols.first);
	this->boardCreator->SetWhiteSymbol(symbols.second);

	ASSERT_NE(copyBoardCreator.GetWhiteSymbol(), this->boardCreator->GetWhiteSymbol());
	ASSERT_NE(copyBoardCreator.GetBlackSymbol(), this->boardCreator->GetBlackSymbol());

	const auto secondBoard = this->boardCreator->CreateBoard(rows, columns);

	ASSERT_NE(firstBoard->GetWhiteSymbol(), secondBoard->GetWhiteSymbol());
	ASSERT_NE(firstBoard->GetBlackSymbol(), secondBoard->GetBlackSymbol());
}