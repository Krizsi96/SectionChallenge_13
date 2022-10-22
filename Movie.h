#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

class Movie {
 private:
  std::string name;
  std::string rating;
  const std::string ratings[4] = {"G", "PG", "PG-13", "R"};
  int watch_counter;

 public:
  std::string get_name() const { return name; }
  std::string get_rating() const { return rating; }
  int get_watch_number() const { return watch_counter; }
  void increment_watch_number() { watch_counter++; }

  // Constructor
  Movie(std::string init_name, std::string init_rating,
        int watch_number_value = 0);
  // Copy Constructor
  Movie(const Movie &source);
};

#endif  // _MOVIE_H_