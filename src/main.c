#include "actorsdata.h"
#include "moviesdata.h"
#include "string.h"
#include "dotwriter.h"
#include "dataparser.h"
#include <stdio.h>


int main() {
    actors_array_t* a_array = actors_array_create();
    movies_array_t* m_array = movies_array_create();

    printf("Parsing file\n");

    parse_movies_file("title.basics.tsv", m_array);
    parse_actors_file("name.basics.tsv", a_array, m_array);

    write_file("graph.dot", m_array);

    actors_array_free(&a_array);
    movies_array_free(&m_array);
    return 0;
}
