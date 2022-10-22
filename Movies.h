#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <string>
#include <vector>

#include "Movie.h"

class Movies {
 private:
  std::vector<Movie> movie_list;

 public:
  bool increment_watched(std::string name);
};

#endif  // _MOVIES_H_