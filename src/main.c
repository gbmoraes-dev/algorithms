#include "include/funtions.h"

int main() {
  athlete_t *athlete = malloc(MAX_DECK * sizeof(athlete_t));

  populateTable(athlete, MAX_DECK);

  saveTableInCSV(athlete, MAX_DECK, "PlayersList.csv");

  free(athlete);

  return 0;
}