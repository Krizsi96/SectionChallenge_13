#include "Movies.h"

Movies::Movies() : movie_list{} {}

Movies::Movies(Movies &source) : movie_list{source.movie_list} {}

bool Movies::is_movie_in_the_list(const std::string name) const {
  bool isMovieInTheList = false;

  for (int i{0}; i < movie_list.size(); i++) {
    if (name == movie_list.at(i).get_name()) {
      isMovieInTheList = true;
    }
  }

  return isMovieInTheList;
}

int Movies::movie_location_in_the_list(const std::string name) const {
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

std::string Movies::get_movie_rating(const std::string name) const {
  std::string movie_rating{""};
  bool isMovieInTheList = is_movie_in_the_list(name);

  if (isMovieInTheList) {
    int location = movie_location_in_the_list(name);
    movie_rating = movie_list.at(location).get_rating();
  }

  return movie_rating;
}

int Movies::get_movie_watch_counter(const std::string name) const {
  int movie_watch_counter{-1};
  bool isMovieInTheList = is_movie_in_the_list(name);

  if (isMovieInTheList) {
    int location = movie_location_in_the_list(name);
    movie_watch_counter = movie_list.at(location).get_watch_counter();
  }

  return movie_watch_counter;
}

std::vector<std::string> Movies::get_movies() const {
  std::vector<std::string> movies{};

  for (int i{0}; i < movie_list.size(); i++) {
    std::string movie_name = movie_list.at(i).get_name();
    movies.push_back(movie_name);
  }

  return movies;
}