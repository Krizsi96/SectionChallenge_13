#include <gtest/gtest.h>

#include <string>

#include "../Movie.h"

TEST(MovieClassTests, FunctionTest_initialization_without_watch_count_number) {
  // initialize
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";
  int expected_watch_number_value = 0;

  Movie test_movie{expected_name_value, expected_rating_value};

  int real_watch_number_value = test_movie.get_watch_number();
  std::string real_rating_value = test_movie.get_rating();
  std::string real_name_value = test_movie.get_name();

  EXPECT_EQ(real_watch_number_value, expected_watch_number_value);
  EXPECT_EQ(real_rating_value, expected_rating_value);
  EXPECT_EQ(real_name_value, expected_name_value);
}

TEST(MovieClassTests, FunctionTest_initialization_with_watch_count_number) {
  // initialize
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";
  int expected_watch_number_value = 1000;

  Movie test_movie{expected_name_value, expected_rating_value,
                   expected_watch_number_value};

  int real_watch_number_value = test_movie.get_watch_number();
  std::string real_rating_value = test_movie.get_rating();
  std::string real_name_value = test_movie.get_name();

  EXPECT_EQ(real_watch_number_value, expected_watch_number_value);
  EXPECT_EQ(real_rating_value, expected_rating_value);
  EXPECT_EQ(real_name_value, expected_name_value);
}

TEST(MovieClassTests, FunctionTest_incrementing_watch_count_number) {
  // initialize
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";

  Movie test_movie{expected_name_value, expected_rating_value};

  for (int i{0}; i < 10; i++) {
    int expected_watch_number_value = i;
    int watch_number_value = test_movie.get_watch_number();
    EXPECT_EQ(watch_number_value, expected_watch_number_value);
    test_movie.increment_watch_number();
  }
}

TEST(MovieClassTests, FunctionTest_initialization_with_valid_rating_values) {
  const std::string ratings[4] = {"G", "PG", "PG-13", "R"};

  for (int i{0}; i < size(ratings); i++) {
    // initialize
    std::string expected_name_value = "TEST";
    std::string expected_rating_value = ratings[i];
    int expected_watch_number_value = 0;

    Movie *test_movie = new Movie{expected_name_value, expected_rating_value,
                                  expected_watch_number_value};

    std::string real_rating_value = (*test_movie).get_rating();
    EXPECT_EQ(real_rating_value, expected_rating_value);

    delete test_movie;
  }
}

TEST(MovieClassTests,
     FunctionTest_initialization_with_invalid_valid_rating_values) {
  // initialize
  std::string expected_name_value = "TEST";
  std::string init_rating_value = "ASD";
  std::string expected_rating_value = "N/A";
  int expected_watch_number_value = 1000;

  Movie test_movie{expected_name_value, init_rating_value,
                   expected_watch_number_value};

  std::string real_rating_value = test_movie.get_rating();
  EXPECT_EQ(real_rating_value, expected_rating_value);
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