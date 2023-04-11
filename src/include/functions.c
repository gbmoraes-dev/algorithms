#include "functions.h"

void populateTable(athlete_t *athlete, int size) {
  srand(time(NULL));

  char firstNames[QNT_NAME][MAX_NAME] = {FIRST_NAME};

  char lastNames[QNT_NAME][MAX_NAME] = {LAST_NAME};

  char teams[QNT_TEAM][MAX_TEAM] = {TEAM_NAME};

  char *positions[5] = {"Goalkepper", "Sweeper", "Defender", "Midfielder", "Striker"};

  for (int i = 0; i < size; i++) {
    int firstNameIndex = rand() % QNT_NAME;
    int lastNameIndex = rand() % QNT_NAME;
    int teamIndex = rand() % QNT_TEAM;

    athlete[i].id = i + 1;
    strcpy(athlete[i].firstName, firstNames[firstNameIndex]);
    strcpy(athlete[i].lastName, lastNames[lastNameIndex]);
    athlete[i].age = (rand() % (MAX_AGE - MIN_AGE + 1)) + MIN_AGE;
    strcpy(athlete[i].team, teams[teamIndex]);
    athlete[i].position = rand() % 5;
    athlete[i].marketValue = (rand() % (MAX_MARKETVALUE - MIN_MARKETVALUE + 1)) + MIN_MARKETVALUE;
    athlete[i].strength = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlete[i].speed = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlete[i].resistance = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlete[i].willpower = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlete[i].criativity = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlete[i].overall = (athlete[i].strength + athlete[i].speed + athlete[i].resistance + athlete[i].willpower + athlete[i].criativity) / 5;
    athlete[i].leadership = rand() % 2;
    athlete[i].injured = rand() % 2;
    if (athlete[i].injured == true) {
      athlete[i].monthsForRecovery = 1 + rand() % 12;
    } else {
      athlete[i].monthsForRecovery = 0;
    }
  }
}

void saveTableInCSV(athlete_t *athlete, int size, const char *arquiveName) {
  char *positions[5] = {"Goalkepper", "Sweeper", "Defender", "Midfielder", "Striker"};

  FILE *arquive = fopen(arquiveName, "w");

  if (arquive != NULL) {
    fprintf(arquive, FILE_HEADER);
    for (int i = 0; i < size; i++) {
      fprintf(arquive, FILE_FORMAT, STATS_FORMAT);
    }
    fclose(arquive);
  }
}