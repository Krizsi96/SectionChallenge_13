#include "Movies.h"

Movies::Movies() : movie_list{} {}

Movies::Movies(Movies &source) : movie_list{source.movie_list} {}