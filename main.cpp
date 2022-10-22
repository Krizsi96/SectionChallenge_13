// Section 13
// Challenge

#include <iostream>

#include "Movies.h"

using namespace std;

// Function prototypes
void increment_watched(Movies &movies, std::string name);
void add_movie();

/******************************************************************
 * increment_watched expects a reference to a Movies object
 * and the name of the movie to increment the watched count
 *
 * If the watched count was incremented successfully it
 *  displays a success message
 *  otherwise the watched count could not be incremented
 *  because the name of the movie was not found
 * ***************************************************************/
void increment_watched(Movies &movies, std::string name) {
  if (movies.increment_watched(name)) {
    cout << "watch number for " << name << " was successfully increased"
         << endl;
  } else {
    cout << "watch number cannot be increased, " << name
         << " is not in our database" << endl;
  }
}

/******************************************************************
 * add_movie expects a reference to a Movies object
 * and the name of the movie, the rating and the watched count
 *
 * If the movie was successfully added to the movies object it
 *  displays a success message
 *  otherwise the movie was not added
 *  because the name of the movie was already in movies
 * ***************************************************************/

int main() {
  Movies my_movies;

  return 0;
}