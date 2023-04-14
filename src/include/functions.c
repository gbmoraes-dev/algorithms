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
    strcpy(athlete[i].fullName, firstNames[firstNameIndex]);
    strcpy(athlete[i].fullName, strcat(athlete[i].fullName, athlete[i].lastName));
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

void saveTableInCSV(athlete_t *athlete, int size, char *arquiveName) {
  char *positions[5] = {"Goalkepper", "Sweeper", "Defender", "Midfielder", "Striker"};

  FILE *arquive = fopen(arquiveName, "w");

  if (arquive != NULL) {
    fprintf(arquive, FILE_HEADER);
    for (int i = 0; i < size; i++) {
      fprintf(arquive, FILE_FORMAT, athlete[i].id, athlete[i].firstName, athlete[i].lastName, athlete[i].fullName, athlete[i].age, athlete[i].team, positions[athlete[i].position], athlete[i].marketValue, athlete[i].overall, athlete[i].strength, athlete[i].speed, athlete[i].resistance, athlete[i].willpower, athlete[i].criativity, athlete[i].leadership ? "Yes" : "No", athlete[i].injured ? "Yes" : "No", athlete[i].monthsForRecovery);
    }
    fclose(arquive);
  }
}

node_t *createNode(athlete_t *athlete) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->dataAthlete = athlete;
  new_node->next = NULL;
  return new_node;
}

void addNode(node_t **head, athlete_t *athlete) {
  node_t *new_node = createNode(athlete);

  if(new_node == NULL) {
    printf("ERROR!\n");
    exit(1);
  }

  new_node->next = *head;
  *head = new_node;
}

void addNodeInFinal(node_t **head, athlete_t *athlete) {
  node_t *new_node = createNode(athlete);
  node_t *next = *head;
  if(*head == NULL) {
    *head = new_node;
    return;
  }
  while(next->next != NULL) {
    next = next->next;
  }
  next->next = new_node;
}

void createExtraPlayers(athlete_t *athlete, int size) {
  srand(time(NULL));

  char firstNames[QNT_NAME][MAX_NAME] = {FIRST_NAME};

  char lastNames[QNT_NAME][MAX_NAME] = {LAST_NAME};

  char teams[QNT_TEAM][MAX_TEAM] = {TEAM_NAME};

  char *positions[5] = {"Goalkepper", "Sweeper", "Defender", "Midfielder", "Striker"};

  for (int i = 0; i < size; i++) {
    int firstNameIndex = rand() % QNT_NAME;
    int lastNameIndex = rand() % QNT_NAME;
    int teamIndex = rand() % QNT_TEAM;

    athlete[i].id = (i + MAX_DECK);
    strcpy(athlete[i].firstName, firstNames[firstNameIndex]);
    strcpy(athlete[i].lastName, lastNames[lastNameIndex]);
    strcpy(athlete[i].fullName, firstNames[firstNameIndex]);
    strcpy(athlete[i].fullName, strcat(athlete[i].fullName, athlete[i].lastName));
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

void readCSV(athlete_t *playerCSV, int size, char *arquiveName) {
  char line[1024];
  int j = 0;

  FILE *arquive = fopen(arquiveName, "r");
  fgets(line, sizeof(line), arquive);

  while((fgets(line, sizeof(line), arquive)) != NULL) {
    char *token = strtok(line, ",");
    
    playerCSV[j].id = atoi(token);
    token = strtok(NULL, ",");

    for(int i = 0; i < 2; i++) {
      token = strtok(NULL, ",");
    }

    strcpy(playerCSV[j].fullName, token);

    for(int i = 0; i < 13; i++) {
      token = strtok(NULL, ",");
    }
    j++;
  }
  fclose(arquive);
}

void insertionSort(node_t **head) {
  node_t *ordained = NULL;
  node_t *current = *head;

  while(current != NULL) {
    node_t *next = current->next;
    if(ordained == NULL || strcmp(ordained->dataAthlete->fullName, current->dataAthlete->fullName) > 0) {
      current->next = ordained;
      ordained = current;
    } else {
      node_t *temp = ordained;
      while(temp->next != NULL && strcmp(temp->next->dataAthlete->fullName, current->dataAthlete->fullName) < 0) {
        temp = temp->next;
      }
      current->next = temp->next;
      temp->next = current;
    }
    current = next;
  }
  *head = ordained;
}

void printNode(node_t *head) {
  node_t *current = head;
  while(current != NULL) {
    printf("[%d] - ", current->dataAthlete->id);
    printf("%s\n ", current->dataAthlete->fullName);
    current = current->next;
  }
}