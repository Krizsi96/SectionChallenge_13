#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <string>
#include <vector>

#include "Movie.h"

class Movies {
 private:
  std::vector<Movie> movie_list;
  bool is_movie_in_the_list(const std::string name) const;
  int movie_location_in_the_list(const std::string name) const;

 public:
  // Getters
  std::vector<std::string> get_movies() const;
  std::string get_movie_rating(const std::string name) const;
  int get_movie_watch_counter(const std::string name) const;

  bool add_movie(const std::string name, const std::string rating,
                 const int watch_counter = 0);
  bool increment_movie_watch_counter(const std::string name);

  // Constructor
  Movies();
  // Copy Constructor
  Movies(Movies &source);
};

#endif  // _MOVIES_H_