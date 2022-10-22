#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

class Movie {
 private:
  std::string name;
  int watch_number;

 public:
  std::string get_name() const { return name; }
  int get_watch_number() const { return watch_number; }
  void increment_watch_number() { watch_number++; }

  // Constructor
  Movie(std::string name_value, int watch_number_value = 0);
  // Copy Constructor
  Movie(const Movie &source);
};

#endif  // _MOVIE_H_