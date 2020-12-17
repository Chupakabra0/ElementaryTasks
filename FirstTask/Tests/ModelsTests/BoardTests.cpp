//
// Created by Александр Сафиюлин on 17.12.2020.
//

#include <gtest/gtest.h>
#include <Board/Board.hpp>

// ---------------------- HELPER TEST CLASSES ---------------------------------

struct BoardCharFixture : public testing::Test {
 public:
  BoardCharFixture()
	  : rowsCount(8), columnsCount(8),
	  blackSymbol('*'), whiteSymbol(' '),
		board(new(std::nothrow) task::first::Board<char>
			    (this->rowsCount, this->columnsCount, this->blackSymbol,
				this->whiteSymbol)) {}

  ~BoardCharFixture() override = default;

  unsigned short rowsCount;
  unsigned short columnsCount;

  char blackSymbol;
  char whiteSymbol;

  std::unique_ptr<task::first::Board<char>> board;
};

struct BoardIntFixture : public testing::Test {
 public:
  BoardIntFixture()
	  : rowsCount(8), columnsCount(8),
		blackSymbol(1), whiteSymbol(0),
		board(new(std::nothrow) task::first::Board<int>
				  (this->rowsCount, this->columnsCount, this->blackSymbol,
				   this->whiteSymbol)) {}

  ~BoardIntFixture() override = default;

  unsigned short rowsCount;
  unsigned short columnsCount;

  int blackSymbol;
  int whiteSymbol;

  std::unique_ptr<task::first::Board<int>> board;
};

//---------------------------- CTOR TESTS -------------------------------------

TEST(BoardCtorTests, CharCtorTest) {
  const unsigned short rowsCount = 1;
  const unsigned short columnsCount = 1;
  const auto blackSymbol = '*';
  const auto whiteSymbol = ' ';

  const std::unique_ptr<task::first::Board<char>> board
	  (new(std::nothrow) task::first::Board<char>(rowsCount, columnsCount,
											   blackSymbol, whiteSymbol));

  ASSERT_NE(nullptr, board);
  ASSERT_EQ(board->GetRowsCount(), rowsCount);
  ASSERT_EQ(board->GetColumnsCount(), columnsCount);
  ASSERT_EQ(board->GetBlackSymbol(), blackSymbol);
  ASSERT_EQ(board->GetWhiteSymbol(), whiteSymbol);
}

TEST(BoardCtorTests, IntCtorTest) {
  const unsigned short rowsCount = 1;
  const unsigned short columnsCount = 1;
  const auto blackSymbol = 1;
  const auto whiteSymbol = 0;

  const std::unique_ptr<task::first::Board<char>> board
	  (new(std::nothrow) task::first::Board<char>(rowsCount, columnsCount,
												  blackSymbol, whiteSymbol));

  ASSERT_NE(nullptr, board);
  ASSERT_EQ(board->GetRowsCount(), rowsCount);
  ASSERT_EQ(board->GetColumnsCount(), columnsCount);
  ASSERT_EQ(board->GetBlackSymbol(), blackSymbol);
  ASSERT_EQ(board->GetWhiteSymbol(), whiteSymbol);
}

//-------------------------- GETTERS TESTS -----------------------------------

TEST_F(BoardCharFixture, BlackSymbolGetterTest) {
  ASSERT_EQ(this->board->GetBlackSymbol(), this->blackSymbol);
}

TEST_F(BoardCharFixture, WhiteSymbolGetterTest) {
  ASSERT_EQ(this->board->GetWhiteSymbol(), this->whiteSymbol);
}

TEST_F(BoardCharFixture, RowsCountGetterTest) {
  ASSERT_EQ(this->board->GetRowsCount(), this->rowsCount);
}

TEST_F(BoardCharFixture, ColumnsCountGetterTest) {
  ASSERT_EQ(this->board->GetColumnsCount(), this->columnsCount);
}

TEST_F(BoardIntFixture, BlackSymbolGetterTest) {
  ASSERT_EQ(this->board->GetBlackSymbol(), this->blackSymbol);
}

TEST_F(BoardIntFixture, WhiteSymbolGetterTest) {
  ASSERT_EQ(this->board->GetWhiteSymbol(), this->whiteSymbol);
}

TEST_F(BoardIntFixture, RowsCountGetterTest) {
  ASSERT_EQ(this->board->GetRowsCount(), this->rowsCount);
}

TEST_F(BoardIntFixture, ColumnsCountGetterTest) {
  ASSERT_EQ(this->board->GetColumnsCount(), this->columnsCount);
}

//-------------------------- SETTERS TESTS -----------------------------------

TEST_F(BoardCharFixture, BlackSymbolSetterTest) {
  const char valuesToSet[]{
	  std::numeric_limits<char>::max(),
	  std::numeric_limits<char>::min(),
	  std::numeric_limits<char>::epsilon()
  };

  for (const auto &i : valuesToSet) {
	const auto temp = *this->board;
  	this->board->SetBlackSymbol(i);
  	
	ASSERT_EQ(i, this->board->GetBlackSymbol());
	ASSERT_EQ(this->board->GetMap(), temp.GetMap());
  }
}

TEST_F(BoardCharFixture, WhiteSymbolSetterTest) {
  const char valuesToSet[]{
	  std::numeric_limits<char>::max(),
	  std::numeric_limits<char>::min(),
	  std::numeric_limits<char>::epsilon()
  };

  for (const auto &i : valuesToSet) {
	const auto temp = *this->board;
	this->board->SetWhiteSymbol(i);
  	
	ASSERT_EQ(i, this->board->GetWhiteSymbol());
	ASSERT_EQ(this->board->GetMap(), temp.GetMap());
  }
}

TEST_F(BoardIntFixture, BlackSymbolSetterTest) {
  const int valuesToSet[]{
	  std::numeric_limits<int>::max(),
	  std::numeric_limits<int>::min(),
	  std::numeric_limits<int>::epsilon()
  };

  for (const auto &i : valuesToSet) {
	const auto temp = *this->board;
	this->board->SetBlackSymbol(i);
  	
	ASSERT_EQ(i, this->board->GetBlackSymbol());
	ASSERT_EQ(this->board->GetMap(), temp.GetMap());
  }
}

TEST_F(BoardIntFixture, WhiteSymbolSetterTest) {
  const int valuesToSet[]{
	  std::numeric_limits<int>::max(),
	  std::numeric_limits<int>::min(),
	  std::numeric_limits<int>::epsilon()
  };

  for (const auto &i : valuesToSet) {
	const auto temp = *this->board;
	this->board->SetWhiteSymbol(i);
  	
	ASSERT_EQ(i, this->board->GetWhiteSymbol());
	ASSERT_EQ(this->board->GetMap(), temp.GetMap());

  }
}

//------------------------- ASSIGNMENTS TESTS ------------------------------

TEST_F(BoardCharFixture, AssignmentTest) {
  const auto copyBoard = *this->board;

  ASSERT_EQ(copyBoard.GetRowsCount(), this->board->GetRowsCount());
  ASSERT_EQ(copyBoard.GetColumnsCount(), this->board->GetColumnsCount());
  ASSERT_EQ(copyBoard.GetWhiteSymbol(), this->board->GetWhiteSymbol());
  ASSERT_EQ(copyBoard.GetBlackSymbol(), this->board->GetBlackSymbol());
  ASSERT_EQ(copyBoard.GetMap(), this->board->GetMap());

  const std::pair<char, char> symbols('A', 'S');
	
  this->board->SetBlackSymbol(symbols.first);
  this->board->SetWhiteSymbol(symbols.second);
  this->board->Insert(symbols.first);

  ASSERT_NE(copyBoard.GetWhiteSymbol(), this->board->GetWhiteSymbol());
  ASSERT_NE(copyBoard.GetBlackSymbol(), this->board->GetBlackSymbol());
  ASSERT_NE(copyBoard.GetMap(), this->board->GetMap());
}

TEST_F(BoardIntFixture, AssignmentTest) {
  const auto copyBoard = *this->board;

  ASSERT_EQ(copyBoard.GetRowsCount(), this->rowsCount);
  ASSERT_EQ(copyBoard.GetColumnsCount(), this->columnsCount);
  ASSERT_EQ(copyBoard.GetWhiteSymbol(), this->whiteSymbol);
  ASSERT_EQ(copyBoard.GetBlackSymbol(), this->blackSymbol);
  ASSERT_EQ(copyBoard.GetMap(), this->board->GetMap());

  const std::pair<int, int> symbols(10, 4);

  this->board->SetBlackSymbol(symbols.first);
  this->board->SetWhiteSymbol(symbols.second);
  this->board->Insert(symbols.first);

  ASSERT_NE(copyBoard.GetWhiteSymbol(), this->board->GetWhiteSymbol());
  ASSERT_NE(copyBoard.GetBlackSymbol(), this->board->GetBlackSymbol());
  ASSERT_NE(copyBoard.GetMap(), this->board->GetMap());
}

//---------------------------- INSERT TESTS --------------------------------

TEST_F(BoardCharFixture, FirstInsertTest) {
  const auto symbol = '*';
  const auto key = std::string("A1");
  const auto copyBoard = *this->board;

  this->board->Insert(symbol);

  ASSERT_NE(copyBoard.GetMap(), this->board->GetMap());
  ASSERT_EQ(this->board->GetMap().operator[](key), symbol);
}

TEST_F(BoardCharFixture, SecondInsertTest) {
  const auto symbol = '*';
  const auto copyBoard = *this->board;

  for (auto i = 0u; i < this->rowsCount * this->columnsCount; ++i) {
	this->board->Insert(symbol);
	const auto key = std::string(1u,
		static_cast<char>('A' + i / this->columnsCount)) +
		std::string(1u, static_cast<char>('0' + 1 + i % this->columnsCount));

	ASSERT_EQ(this->board->GetMap().operator[](key), symbol);
  }

  ASSERT_NE(copyBoard.GetMap(), this->board->GetMap());
}

TEST_F(BoardCharFixture, ThirdInsertTest) {
  const auto symbol = '*';

  for (auto i = 0u; i < this->rowsCount * this->columnsCount; ++i) {
	this->board->Insert(symbol);
  }
  const auto copyBoard = *this->board;

  this->board->Insert(symbol);

  ASSERT_EQ(copyBoard.GetMap(), this->board->GetMap());
}

TEST_F(BoardCharFixture, FourthInsertTest) {
	const auto symbol = 'k';
	const auto copy = *this->board;
	this->board->Insert(symbol);

	ASSERT_EQ(this->board->GetMap(), copy.GetMap());
}

TEST_F(BoardIntFixture, FirstInsertTest) {
	const auto symbol = 1;
	const auto key = std::string("A1");
	const auto copyBoard = *this->board;

	this->board->Insert(symbol);

	ASSERT_NE(copyBoard.GetMap(), this->board->GetMap());
	ASSERT_EQ(this->board->operator[](key), symbol);
}

TEST_F(BoardIntFixture, SecondInsertTest) {
	const auto symbol = 1;
	const auto copyBoard = *this->board;

	for (auto i = 0u; i < this->rowsCount * this->columnsCount; ++i) {
		this->board->Insert(symbol);
		const auto key = std::string(1u,
			static_cast<char>('A' + i / this->columnsCount)) +
			std::string(1u, static_cast<char>('0' + 1 + i % this->columnsCount));

		ASSERT_EQ(this->board->operator[](key), symbol);
	}

	ASSERT_NE(copyBoard.GetMap(), this->board->GetMap());
}

TEST_F(BoardIntFixture, ThirdInsertTest) {
	const auto symbol = 1;

	for (auto i = 0u; i < this->rowsCount * this->columnsCount; ++i) {
		this->board->Insert(symbol);
	}
	const auto copyBoard = *this->board;

	this->board->Insert(symbol);

	ASSERT_EQ(copyBoard.GetMap(), this->board->GetMap());
}

TEST_F(BoardIntFixture, FourthInsertTest) {
	const auto symbol = 5;
	const auto copy = *this->board;
	this->board->Insert(symbol);

	ASSERT_EQ(this->board->GetMap(), copy.GetMap());
}

//---------------------------- ACCESS TESTS --------------------------------

TEST_F(BoardCharFixture, FirstAccessTest) {
	const auto symbol = '*';
	const auto key = std::string("A1");
	
	this->board->Insert(symbol);

	ASSERT_EQ(symbol, this->board->operator[](key));
}

TEST_F(BoardCharFixture, SecondAccessTest) {
	const auto symbol = '*';

	for (auto i = 0u; i < this->rowsCount * this->columnsCount; ++i) {
		this->board->Insert(symbol);
		const auto key = std::string(1u,
			static_cast<char>('A' + i / this->columnsCount)) +
			std::string(1u, static_cast<char>('0' + 1 + i % this->columnsCount));

		ASSERT_EQ(this->board->operator[](key), symbol);
	}
}

TEST_F(BoardIntFixture, FirstAccessTest) {
	const auto symbol = 1;
	const auto key = std::string("A1");

	this->board->Insert(symbol);

	ASSERT_EQ(symbol, this->board->operator[](key));
}

TEST_F(BoardIntFixture, SecondAccessTest) {
	const auto symbol = 1;

	for (auto i = 0u; i < this->rowsCount * this->columnsCount; ++i) {
		this->board->Insert(symbol);
		const auto key = std::string(1u,
			static_cast<char>('A' + i / this->columnsCount)) +
			std::string(1u, static_cast<char>('0' + 1 + i % this->columnsCount));

		ASSERT_EQ(this->board->operator[](key), symbol);
	}
}