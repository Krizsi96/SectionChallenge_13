#include <gtest/gtest.h>

#include <string>

#include "../Movie.h"
#include "../Movies.h"

TEST(
    MovieClassTests,
    FunctionTest_initialization_without_watch_count_number_should_result_0_watch_count_number) {
  // initialise
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";
  int expected_watch_number_value = 0;

  Movie test_movie{expected_name_value, expected_rating_value};

  // test
  int real_watch_number_value = test_movie.get_watch_counter();
  std::string real_rating_value = test_movie.get_rating();
  std::string real_name_value = test_movie.get_name();

  EXPECT_EQ(real_watch_number_value, expected_watch_number_value);
  EXPECT_EQ(real_rating_value, expected_rating_value);
  EXPECT_EQ(real_name_value, expected_name_value);
}

TEST(
    MovieClassTests,
    FunctionTest_initialization_with_watch_count_number_should_add_watch_count_number) {
  // initialise
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";
  int expected_watch_number_value = 1000;

  Movie test_movie{expected_name_value, expected_rating_value,
                   expected_watch_number_value};

  // test
  int real_watch_number_value = test_movie.get_watch_counter();
  std::string real_rating_value = test_movie.get_rating();
  std::string real_name_value = test_movie.get_name();

  EXPECT_EQ(real_watch_number_value, expected_watch_number_value);
  EXPECT_EQ(real_rating_value, expected_rating_value);
  EXPECT_EQ(real_name_value, expected_name_value);
}

TEST(MovieClassTests, FunctionTest_incrementing_watch_count_number) {
  // initialise
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";

  Movie test_movie{expected_name_value, expected_rating_value};

  // test
  for (int i{0}; i < 10; i++) {
    int expected_watch_number_value = i;
    int watch_number_value = test_movie.get_watch_counter();
    EXPECT_EQ(watch_number_value, expected_watch_number_value);
    test_movie.increment_watch_counter();
  }
}

TEST(MovieClassTests,
     FunctionTest_initialization_with_valid_rating_values_should_add_rating) {
  const std::string ratings[4] = {"G", "PG", "PG-13", "R"};

  for (int i{0}; i < size(ratings); i++) {
    // initialise
    std::string expected_name_value = "TEST";
    std::string expected_rating_value = ratings[i];
    int expected_watch_number_value = 0;

    Movie *test_movie = new Movie{expected_name_value, expected_rating_value,
                                  expected_watch_number_value};

    // test
    std::string real_rating_value = (*test_movie).get_rating();
    EXPECT_EQ(real_rating_value, expected_rating_value);

    delete test_movie;
  }
}

TEST(
    MovieClassTests,
    FunctionTest_initialization_with_invalid_valid_rating_values_should_result_NA_rating) {
  // initialise
  std::string expected_name_value = "TEST";
  std::string init_rating_value = "ASD";
  std::string expected_rating_value = "N/A";
  int expected_watch_number_value = 1000;

  Movie test_movie{expected_name_value, init_rating_value,
                   expected_watch_number_value};

  // test
  std::string real_rating_value = test_movie.get_rating();
  EXPECT_EQ(real_rating_value, expected_rating_value);
}

TEST(MoviesClassTests,
     FunctionTest_initialization_with_0_element_should_result_0_object) {
  // initialise
  Movies test_movies;
  int expected_size{0};

  // test size
  std::vector<Movie> init_movie_list = test_movies.get_movies();
  ASSERT_EQ(expected_size, init_movie_list.size());
}

TEST(MoviesClassTests,
     FunctionTest_add_new_movie_to_the_list_should_add_new_movie) {
  // initialise
  Movies test_movies;
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";
  int expected_watch_number_value = 1000;

  bool isAdded = test_movies.add_movie(
      expected_name_value, expected_rating_value, expected_watch_number_value);

  EXPECT_TRUE(isAdded);

  // test addition
  std::vector<Movie> real_movie_list = test_movies.get_movies();
  std::string real_name_value = real_movie_list.at(0).get_name();
  std::string real_rating_value = real_movie_list.at(0).get_rating();
  int real_watch_number_value = real_movie_list.at(0).get_watch_counter();

  EXPECT_EQ(expected_name_value, real_name_value);
  EXPECT_EQ(expected_rating_value, real_rating_value);
  EXPECT_EQ(expected_watch_number_value, real_watch_number_value);
}

TEST(MoviesClassTests,
     FunctionTest_add_existing_movie_to_the_list_should_give_an_error) {
  // initialise
  Movies test_movies;
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";
  int expected_watch_number_value = 1000;

  test_movies.add_movie(expected_name_value, expected_rating_value,
                        expected_watch_number_value);

  // test readdition
  bool isAdded = test_movies.add_movie(
      expected_name_value, expected_rating_value, expected_watch_number_value);
  EXPECT_FALSE(isAdded);
}

TEST(
    MoviesClassTests,
    FunctionTest_incrementing_existing_movie_watch_counter_should_increase_watch_counter_by_1) {  // initialise
  Movies test_movies;
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";
  int expected_watch_number_value = 1000;

  test_movies.add_movie(expected_name_value, expected_rating_value,
                        expected_watch_number_value);

  // test increment
  bool isIncremented =
      test_movies.increment_movie_watch_counter(expected_name_value);
  EXPECT_TRUE(isIncremented);
}

TEST(
    MoviesClassTests,
    FunctionTest_incrementing_not_existing_movie_watch_counter_should_give_an_error) {  // initialise
  Movies test_movies;
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";
  int expected_watch_number_value = 1000;

  test_movies.add_movie(expected_name_value, expected_rating_value,
                        expected_watch_number_value);

  // test increment
  bool isIncremented = test_movies.increment_movie_watch_counter("NOT_CORRECT");
  EXPECT_FALSE(isIncremented);
}