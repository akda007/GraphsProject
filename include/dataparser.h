#ifndef DATAPARSER_H
#define DATAPARSER_H

#include "datatypes.h"
#include "actorsdata.h"
#include "moviesdata.h"

void parse_movies_file(const char* file_path, movies_array_t* movies_array);
void parse_actors_file(const char* file_path, actors_array_t* data_array, movies_array_t* movies);

#endif