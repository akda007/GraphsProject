#ifndef DATATYPES
#define DATATYPES

typedef struct movies {
    int id;
	char* titleType;
	char* primaryTitle;
	char* originalTitle;
	int isAdult;
	int startYear;
	int endYear;
	int runtimeMinutes;
	char* genres;

	struct movies* neighbors;
} movies_t;

typedef struct actors {
    int id;
	char* primaryName;
	int birthYear;
	int deathYear;
	char* primaryProfession;
	
	struct actors* movies_head;
} actors_t;


#endif