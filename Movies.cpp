#include "Movies.h"

Movies::Movies() : movie_list{} {}

Movies::Movies(Movies &source) : movie_list{source.movie_list} {}

bool Movies::add_movie(const std::string name, const std::string rating,
                       const int watch_counter) {
  bool isMovieAdded = false;

  for (int i{0}; i < movie_list.size(); i++) {
    if (name == movie_list.at(i).get_name()) {
      isMovieAdded = true;
    }
  }

  if (!isMovieAdded) {
    Movie temp_movie{name, rating, watch_counter};
    movie_list.push_back(temp_movie);
  }

  return !isMovieAdded;
}