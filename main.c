#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DECK 1
#define MAX_NAME 21
#define MAX_TEAM 21
#define QNT_NAME 35
#define QNT_TEAM 20
#define MIN_AGE 16
#define MAX_AGE 40
#define MIN_POTENTIAL 1
#define MAX_POTENTIAL 99
#define MIN_MARKETVALUE 1000
#define MAX_MARKETVALUE 10000

typedef enum {
  Goalkepper,
  Defender,
  Midfielder,
  Striker,
  Sweeper
} position_t;

typedef struct {
  int id;
  char firstName[MAX_NAME];
  char lastName[MAX_NAME];
  int age;
  char team[MAX_TEAM];
  int marketValue;
  int overall;
  int strength;
  int speed;
  int resistance;
  int willpower;
  int criativity;
  bool leadership;
  bool injured;
  int daysForRecovery;
  position_t position;
} athlete_t;

void populateTable(athlete_t *athlete, int size) {
  srand(time(NULL));

  char firstNames[QNT_NAME][MAX_NAME] = {"Miguel", "Davi", "Gabriel", "Arthur", "Lucas", "Matheus", "Pedro", "Guilherme", "Gustavo", "Rafael", "Felipe", "Bernardo", "Enzo", "Nicolas", "João Pedro", "Cauã", "Vitor", "Eduardo", "Daniel", "Henrique", "Murilo", "Vinicius", "Samuel", "Pietro", "João Vitor", "Leonardo", "Caio", "Heitor", "Lorenzo", "Isaac", "Lucca", "Thiago", "João Gabriel", "João"};

  char lastNames[QNT_NAME][MAX_NAME] = {"Silva", "Santos", "Oliveira", "Souza", "Rodrigues", "Ferreira", "Alves", "Pereira", "Lima", "Gomes", "Costa", "Ribeiro", "Martins", "Carvalho", "Almeida", "Lopes", "Soares", "Fernandes", "Vieira", "Barbosa", "Rocha", "Dias", "Nascimento", "Andrade", "Moreira", "Nunes", "Marques", "Machado", "Mendes", "Freitas", "Cardoso", "Ramos", "Gonçalves", "Santana", "Teixeira"};

  char teams[QNT_TEAM][MAX_TEAM] = {"América-MG", "Athletico-PR", "Atlético-MG", "Bahia", "Botafogo", "Bragantino", "Corinthians", "Coritiba", "Cruzeiro", "Cuiabá", "Flamengo", "Fluminense", "Fortaleza", "Goiás", "Grêmio", "Internacional", "Palmeiras", "Santos", "São Paulo", "Vasco"};

  //char *positions[5] = { "Goalkepper", "Defender", "Midfielder", "Striker", "Sweeper" };

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
    athlete[i].overall = (athlete[i].strength + athlete[i].speed + athlete[i].resistance + athlete[i].willpower + athlete[i].criativity) / 5;
    athlete[i].strength = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlete[i].speed = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlete[i].resistance = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlete[i].willpower = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlete[i].criativity = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlete[i].leadership = rand() % 2;
    athlete[i].injured = rand() % 2 ? "Yes" : "No";
    // TODO: athlete[i].daysForRecovery = (rand() % 12) + 1;
  }

  for (int i = 0; i < size; i++) {
    printf("ID: %d\n", athlete[i].id);
    printf("First Name: %s\n", athlete[i].firstName);
    printf("Last Name: %s\n", athlete[i].lastName);
    printf("Age: %d\n", athlete[i].age);
    printf("Team: %s\n", athlete[i].team);
    //printf("Position: %s\n", positions[athlete[i].position]);
    printf("Market Value: %i\n", athlete[i].marketValue);
    printf("Overral: %d\n", (athlete[i].strength + athlete[i].speed + athlete[i].resistance + athlete[i].willpower + athlete[i].criativity) / 5);
    printf("Strength: %d\n", athlete[i].strength);
    printf("Speed: %d\n", athlete[i].speed);
    printf("Resistance: %d\n", athlete[i].resistance);
    printf("Willpower: %d\n", athlete[i].willpower);
    printf("Criativity: %d\n", athlete[i].criativity);
    printf("Leadership: %s\n", athlete[i].leadership ? "Yes" : "No");
    printf("Injured: %s\n", athlete[i].injured);
  }
}

void saveTableInCSV(athlete_t *athlete, int size, const char *arquiveName) {
  char *positions[5] = { "Goalkepper", "Defender", "Midfielder", "Striker", "Sweeper" };

  FILE *arquive = fopen(arquive, "w");
  
  if(arquive != NULL) {
    fprintf(arquive, "ID,First Name,Last Name,Age,Team,Position,Market Value,Overall,Strength,Speed,Resistance,WillPower,Criativity,Leadership,Injured\n");
    for (int i = 0; i < size; i++) {
      fprintf(arquive, "%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d,%d,%d,%s,%s\n", athlete[i].id, athlete[i].firstName, athlete[i].lastName, athlete[i].age, athlete[i].team, positions[athlete[i].position], athlete[i].marketValue, athlete[i].overall, athlete[i].strength, athlete[i].speed, athlete[i].resistance, athlete[i].willpower, athlete[i].criativity, athlete[i].leadership ? "Yes" : "No", athlete[i].injured);
    }

    fclose(arquive);
  }
}

int main() {
  athlete_t *athlete = malloc(MAX_DECK * sizeof(athlete_t));

  populateTable(athlete, MAX_DECK);

  saveTableInCSV(athlete, MAX_DECK, "PlayersList.csv");

  free(athlete);

  return 0;
}