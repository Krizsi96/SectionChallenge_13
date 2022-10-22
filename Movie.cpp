#include "Movie.h"

Movie::Movie(std::string name_value, int watch_number_value)
    : name{name_value}, watch_number{watch_number_value} {}

Movie::Movie(const Movie &source) : Movie{source.name, source.watch_number} {}