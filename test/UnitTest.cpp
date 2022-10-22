#include <gtest/gtest.h>

#include <string>

#include "../Movie.h"

TEST(MovieClassTests, FunctionTest_initialization_without_watch_count_number) {
  // initialize
  std::string expected_name_value = "TEST";
  int expected_watch_number_value = 0;

  Movie test_movie{expected_name_value};

  int initialized_watch_number_value = test_movie.get_watch_number();
  std::string initialized_name_value = test_movie.get_name();

  EXPECT_EQ(initialized_watch_number_value, expected_watch_number_value);
  EXPECT_EQ(initialized_name_value, expected_name_value);
}

TEST(MovieClassTests, FunctionTest_initialization_with_watch_count_number) {
  // initialize
  std::string expected_name_value = "TEST";
  int expected_watch_number_value = 1000;

  Movie test_movie{expected_name_value, expected_watch_number_value};

  int initialized_watch_number_value = test_movie.get_watch_number();
  std::string initialized_name_value = test_movie.get_name();

  EXPECT_EQ(initialized_watch_number_value, expected_watch_number_value);
  EXPECT_EQ(initialized_name_value, expected_name_value);
}

TEST(MovieClassTests, FunctionTest_incrementing_watch_count_number) {
  // initialize
  std::string expected_name_value = "TEST";

  Movie test_movie{expected_name_value};

  for (int i{0}; i < 10; i++) {
    int expected_watch_number_value = i;
    int watch_number_value = test_movie.get_watch_number();
    EXPECT_EQ(watch_number_value, expected_watch_number_value);
    test_movie.increment_watch_number();
  }
}

/* TEST(MovieClassTests, ExceptionTest_watch_count_number_is_private) {
  // initialize
  std::string expected_name_value = "TEST";

  Movie test_movie{expected_name_value};

  bool test_result_f = false;
  // try to access watch count number
  try {
    test_movie.watch_number = 10;
  } catch (...) {
    test_result_f = true;
  }
} */

/* TEST(MovieClassTests,
     ExceptionTest_incrementing_watch_count_number_of_unknown_movie) {} */