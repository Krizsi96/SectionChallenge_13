#include "Movies.h"

bool Movies::increment_watched(std::string name) {
  bool isMovieIncremented = false;

  for (size_t i{0}; i < movie_list.size(); i++) {
    Movie* movie = &movie_list.at(i);

    if (name == (*movie).get_name()) {
      (*movie).increment_watch_number();
      isMovieIncremented = true;
    }
  }
  return isMovieIncremented;
}