#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <string>
#include <vector>

#include "Movie.h"

class Movies {
 private:
  std::vector<Movie> movie_list;

 public:
  std::vector<Movie> get_movies() const { return movie_list; }
  // Constructor
  Movies();
  // Copy Constructor
  Movies(Movies &source);
};

#endif  // _MOVIES_H_