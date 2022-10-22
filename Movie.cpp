#include "Movie.h"

Movie::Movie(std::string init_name, std::string init_rating,
             int init_watch_counter)
    : name{init_name}, rating{init_rating}, watch_counter{init_watch_counter} {
  for (int i{0}; i < size(ratings); i++) {
    if (init_rating == ratings[i]) {
      rating = init_rating;
      break;
    } else {
      rating = "N/A";
    }
  }
}

Movie::Movie(const Movie &source)
    : Movie{source.name, source.rating, source.watch_counter} {}