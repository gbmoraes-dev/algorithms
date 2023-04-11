#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DECK 1000
#define EXTRA_DECK 100
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
#define FIRST_NAME "Miguel", "Davi", "Gabriel", "Arthur", "Lucas", "Matheus", "Pedro", "Guilherme", "Gustavo", "Rafael", "Felipe", "Bernardo", "Enzo", "Nicolas", "João Pedro", "Cauã", "Vitor", "Eduardo", "Daniel", "Henrique", "Murilo", "Vinicius", "Samuel", "Pietro", "João Vitor", "Leonardo", "Caio", "Heitor", "Lorenzo", "Isaac", "Lucca", "Thiago", "João Gabriel", "João", "Diego"
#define LAST_NAME "Silva", "Santos", "Oliveira", "Souza", "Rodrigues", "Ferreira", "Alves", "Pereira", "Lima", "Gomes", "Costa", "Ribeiro", "Martins", "Carvalho", "Almeida", "Lopes", "Soares", "Fernandes", "Vieira", "Barbosa", "Rocha", "Dias", "Nascimento", "Andrade", "Moreira", "Nunes", "Marques", "Machado", "Mendes", "Freitas", "Cardoso", "Ramos", "Gonçalves", "Santana", "Teixeira"
#define TEAM_NAME "América-MG", "Athletico-PR", "Atlético-MG", "Bahia", "Botafogo", "Bragantino", "Corinthians", "Coritiba", "Cruzeiro", "Cuiabá", "Flamengo", "Fluminense", "Fortaleza", "Goiás", "Grêmio", "Internacional", "Palmeiras", "Santos", "São Paulo", "Vasco"
#define FILE_HEADER "ID, First Name, Last Name, Age, Team, Position, Market Value, Overall, Strength, Speed, Resistance, WillPower, Criativity, Leadership, Injured, Months For Recovery\n"
#define FILE_FORMAT "%d, %s, %s, %d, %s, %s, %d, %d, %d, %d, %d, %d, %d, %s, %s, %d\n"
#define STATS_FORMAT athlete[i].id, athlete[i].firstName, athlete[i].lastName, athlete[i].age, athlete[i].team, positions[athlete[i].position], athlete[i].marketValue, athlete[i].overall, athlete[i].strength, athlete[i].speed, athlete[i].resistance, athlete[i].willpower, athlete[i].criativity, athlete[i].leadership ? "Yes" : "No", athlete[i].injured ? "Yes" : "No", athlete[i].monthsForRecovery

typedef enum {
  Goalkepper,
  Sweeper,
  Defender,
  Midfielder,
  Striker
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
  int monthsForRecovery;
  position_t position;
} athlete_t;

void populateTable(athlete_t *athlete, int size);
void saveTableInCSV(athlete_t *athlete, int size, const char *arquiveName);

#endif