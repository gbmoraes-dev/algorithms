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

void populateTable(athlete_t *athlet, int size) {
  srand(time(NULL));

  char firstNames[QNT_NAME][MAX_NAME] = {"Miguel", "Davi", "Gabriel", "Arthur", "Lucas", "Matheus", "Pedro", "Guilherme", "Gustavo", "Rafael", "Felipe", "Bernardo", "Enzo", "Nicolas", "João Pedro", "Cauã", "Vitor", "Eduardo", "Daniel", "Henrique", "Murilo", "Vinicius", "Samuel", "Pietro", "João Vitor", "Leonardo", "Caio", "Heitor", "Lorenzo", "Isaac", "Lucca", "Thiago", "João Gabriel", "João"};

  char lastNames[QNT_NAME][MAX_NAME] = {"Silva", "Santos", "Oliveira", "Souza", "Rodrigues", "Ferreira", "Alves", "Pereira", "Lima", "Gomes", "Costa", "Ribeiro", "Martins", "Carvalho", "Almeida", "Lopes", "Soares", "Fernandes", "Vieira", "Barbosa", "Rocha", "Dias", "Nascimento", "Andrade", "Moreira", "Nunes", "Marques", "Machado", "Mendes", "Freitas", "Cardoso", "Ramos", "Gonçalves", "Santana", "Teixeira"};

  char teams[QNT_TEAM][MAX_TEAM] = {"América-MG", "Athletico-PR", "Atlético-MG", "Bahia", "Botafogo", "Bragantino", "Corinthians", "Coritiba", "Cruzeiro", "Cuiabá", "Flamengo", "Fluminense", "Fortaleza", "Goiás", "Grêmio", "Internacional", "Palmeiras", "Santos", "São Paulo", "Vasco"};

  //char *positions[5] = { "Goalkepper", "Defender", "Midfielder", "Striker", "Sweeper" };

  for (int i = 0; i < size; i++) {
    int firstNameIndex = rand() % QNT_NAME;
    int lastNameIndex = rand() % QNT_NAME;
    int teamIndex = rand() % QNT_TEAM;

    athlet[i].id = i + 1;
    strcpy(athlet[i].firstName, firstNames[firstNameIndex]);
    strcpy(athlet[i].lastName, lastNames[lastNameIndex]);
    athlet[i].age = (rand() % (MAX_AGE - MIN_AGE + 1)) + MIN_AGE;
    strcpy(athlet[i].team, teams[teamIndex]);
    athlet[i].position = rand() % 5;
    athlet[i].marketValue = (rand() % (MAX_MARKETVALUE - MIN_MARKETVALUE + 1)) + MIN_MARKETVALUE;
    athlet[i].strength = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlet[i].speed = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlet[i].resistance = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlet[i].willpower = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlet[i].criativity = MIN_POTENTIAL + rand() % MAX_POTENTIAL;
    athlet[i].leadership = rand() % 2;
    athlet[i].injured = rand() % 2 ? "Yes" : "No";
    // TODO: athlet[i].daysForRecovery = (rand() % 12) + 1;
  }

  for (int i = 0; i < size; i++) {
    printf("ID: %d\n", athlet[i].id);
    printf("First Name: %s\n", athlet[i].firstName);
    printf("Last Name: %s\n", athlet[i].lastName);
    printf("Age: %d\n", athlet[i].age);
    printf("Team: %s\n", athlet[i].team);
    //printf("Position: %s\n", positions[athlet[i].position]);
    printf("Market Value: %i\n", athlet[i].marketValue);
    printf("Overral: %d\n", (athlet[i].strength + athlet[i].speed + athlet[i].resistance + athlet[i].willpower + athlet[i].criativity) / 5);
    printf("Strength: %d\n", athlet[i].strength);
    printf("Speed: %d\n", athlet[i].speed);
    printf("Resistance: %d\n", athlet[i].resistance);
    printf("Willpower: %d\n", athlet[i].willpower);
    printf("Criativity: %d\n", athlet[i].criativity);
    printf("Leadership: %s\n", athlet[i].leadership ? "Yes" : "No");
    printf("Injured: %s\n", athlet[i].injured);
  }
}

int main() {
  athlete_t *athlet = malloc(MAX_DECK * sizeof(athlete_t));

  populateTable(athlet, MAX_DECK);

  return 0;
}