#include "Movies.h"

Movies::Movies() : movie_list{} {}

Movies::Movies(Movies &source) : movie_list{source.movie_list} {}

bool Movies::is_movie_in_the_list(const std::string name) {
  bool isMovieInTheList = false;

  for (int i{0}; i < movie_list.size(); i++) {
    if (name == movie_list.at(i).get_name()) {
      isMovieInTheList = true;
    }
  }

  return isMovieInTheList;
}

int Movies::movie_location_in_the_list(const std::string name) {
  int location{-1};

  for (int i{0}; i < movie_list.size(); i++) {
    if (name == movie_list.at(i).get_name()) {
      location = i;
    }
  }

  return location;
}

bool Movies::add_movie(const std::string name, const std::string rating,
                       const int watch_counter) {
  bool isMovieInTheList = is_movie_in_the_list(name);

  if (!isMovieInTheList) {
    Movie temp_movie{name, rating, watch_counter};
    movie_list.push_back(temp_movie);
  }

  return !isMovieInTheList;
}

bool Movies::increment_movie_watch_counter(const std::string name) {
  bool isMovieInTheList = is_movie_in_the_list(name);

  if (isMovieInTheList) {
    int location = movie_location_in_the_list(name);
    movie_list.at(location).increment_watch_counter();
  }

  return isMovieInTheList;
}