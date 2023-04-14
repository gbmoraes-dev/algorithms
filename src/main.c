#include "include/funtions.h"

int main() {
  node_t *head = NULL;

  athlete_t *athlete = malloc(MAX_DECK * sizeof(athlete_t));
  athlete_t *extraAthlete = malloc(EXTRA_DECK * sizeof(athlete_t));
  athlete_t *playerCSV = malloc(MAX_DECK * sizeof(athlete_t));

  populateTable(athlete, MAX_DECK);

  createExtraPlayers(athlete, EXTRA_DECK);

  saveTableInCSV(athlete, MAX_DECK, "PlayersList.csv");

  readCSV(athlete, MAX_DECK, "PlayersList.csv");

  for(int i = 0; i < MAX_DECK; i++) {
    addNodeInFinal(&head, &athlete[i]);
    insertionSort(&head);
  }

  for (int i = 0; i < EXTRA_DECK; i++) {
    addNodeInFinal(&head, &extraAthlete[i]);
    insertionSort(&head);
  }

  printf("----- Players List -----\n");
  printNode(head);

  free(playerCSV);
  free(extraAthlete);
  free(athlete);
  free(head);

  return 0;
}