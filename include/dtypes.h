#ifndef DATATYPES
#define DATATYPES

typedef struct actors {
    int id;
	char* primaryName;
	int birthYear;
	int deathYear;
	char* primaryProfession;
	//knownForTitles
} actors_t;

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
} movies_t;

#endif