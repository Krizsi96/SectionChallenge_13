#include <gtest/gtest.h>

#include <string>

#include "../Movie.h"
#include "../Movies.h"

//////////////////////////////////////////////////////
//              Movie Class Tests                   //
//////////////////////////////////////////////////////

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
  int expected_watch_number_value = 0;

  Movie test_movie{expected_name_value, expected_rating_value,
                   expected_watch_number_value};

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

//////////////////////////////////////////////////////
//              Movies Class Tests                  //
//////////////////////////////////////////////////////

TEST(MoviesClassTests,
     FunctionTest_initialization_with_0_element_should_result_0_object) {
  // initialise
  Movies test_movies;
  int expected_size{0};

  // test size
  std::vector<std::string> init_movie_list = test_movies.get_movies();
  ASSERT_EQ(expected_size, init_movie_list.size());
}

TEST(
    MoviesClassTests,
    FunctionTest_ask_down_movies_should_give_a_vector_of_strings_with_all_the_movies_in_the_list) {
  // initialise
  Movies test_movies;
  test_movies.add_movie("TEST1", "G");
  test_movies.add_movie("TEST2", "G");
  test_movies.add_movie("TEST3", "G");

  // check list
  std::vector<std::string> movie_list = test_movies.get_movies();
  std::string test1 = movie_list.at(0);
  std::string test2 = movie_list.at(1);
  std::string test3 = movie_list.at(2);

  EXPECT_EQ("TEST1", test1);
  EXPECT_EQ("TEST2", test2);
  EXPECT_EQ("TEST3", test3);
}

TEST(
    MoviesClassTests,
    FunctionTest_ask_down_rating_by_movie_name_in_the_list_should_give_the_rating_back) {
  // initialise
  Movies test_movies;
  test_movies.add_movie("TEST1", "G");

  // test
  std::vector<std::string> movie = test_movies.get_movies();
  std::string movie_name = movie.at(0);
  std::string movie_rating = test_movies.get_movie_rating(movie_name);
  EXPECT_EQ("G", movie_rating);
}

TEST(
    MoviesClassTests,
    ExceptionTest_ask_down_rating_by_movie_name_not_in_the_list_should_give_empty_rating_back) {
  // initialise
  Movies test_movies;
  test_movies.add_movie("TEST1", "G");

  // test
  std::string movie_rating = test_movies.get_movie_rating("movie_name");
  EXPECT_EQ("", movie_rating);
}

TEST(
    MoviesClassTests,
    FunctionTest_ask_down_watch_number_by_movie_name_in_the_list_should_give_the_watch_number_back) {
  // initialise
  Movies test_movies;
  test_movies.add_movie("TEST1", "G", 100);

  // test
  std::vector<std::string> movie = test_movies.get_movies();
  std::string movie_name = movie.at(0);
  int movie_watch_number = test_movies.get_movie_watch_counter(movie_name);
  EXPECT_EQ(100, movie_watch_number);
}

TEST(
    MoviesClassTests,
    ExceptionTest_ask_down_watch_number_by_movie_name_not_in_the_list_should_give_minus_one_back) {
  // initialise
  Movies test_movies;
  test_movies.add_movie("TEST1", "G", 100);

  // test
  int movie_watch_number = test_movies.get_movie_watch_counter("movie_name");
  EXPECT_EQ(-1, movie_watch_number);
}

TEST(
    MoviesClassTests,
    FunctionTest_add_new_movie_to_the_list_with_watch_number_should_add_new_movie) {
  // initialise
  Movies test_movies;
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";
  int expected_watch_number_value = 1000;

  bool isAdded = test_movies.add_movie(
      expected_name_value, expected_rating_value, expected_watch_number_value);

  EXPECT_TRUE(isAdded);

  // test addition
  std::string real_name_value = test_movies.get_movies().at(0);
  std::string real_rating_value =
      test_movies.get_movie_rating(expected_name_value);
  int real_watch_number_value =
      test_movies.get_movie_watch_counter(expected_rating_value);

  EXPECT_EQ(expected_name_value, real_name_value);
  EXPECT_EQ(expected_rating_value, real_rating_value);
  EXPECT_EQ(expected_watch_number_value, real_watch_number_value);
}

TEST(
    MoviesClassTests,
    FunctionTest_add_new_movie_to_the_list_without_watch_number_should_add_new_movie_with_0_watch_number) {
  // initialise
  Movies test_movies;
  std::string expected_name_value = "TEST";
  std::string expected_rating_value = "G";
  int expected_watch_number_value = 0;

  bool isAdded =
      test_movies.add_movie(expected_name_value, expected_rating_value);

  EXPECT_TRUE(isAdded);

  // test addition
  std::string real_name_value = test_movies.get_movies().at(0);
  std::string real_rating_value =
      test_movies.get_movie_rating(expected_name_value);
  int real_watch_number_value =
      test_movies.get_movie_watch_counter(expected_rating_value);

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