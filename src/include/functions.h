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
#define LAST_NAME " Silva", " Santos", " Oliveira", " Souza", " Rodrigues", " Ferreira", " Alves", " Pereira", " Lima", " Gomes", " Costa", " Ribeiro", " Martins", " Carvalho", " Almeida", " Lopes", " Soares", " Fernandes", " Vieira", " Barbosa", " Rocha", " Dias", " Nascimento", " Andrade", " Moreira", " Nunes", " Marques", " Machado", " Mendes", " Freitas", " Cardoso", " Ramos", " Gonçalves", " Santana", " Teixeira"
#define TEAM_NAME "América-MG", "Athletico-PR", "Atlético-MG", "Bahia", "Botafogo", "Bragantino", "Corinthians", "Coritiba", "Cruzeiro", "Cuiabá", "Flamengo", "Fluminense", "Fortaleza", "Goiás", "Grêmio", "Internacional", "Palmeiras", "Santos", "São Paulo", "Vasco"
#define FILE_HEADER "ID, First Name, Last Name, Full Name, Age, Team, Position, Market Value, Overall, Strength, Speed, Resistance, WillPower, Criativity, Leadership, Injured, Months For Recovery\n"
#define FILE_FORMAT "%d, %s, %s, %s, %d, %s, %s, %d, %d, %d, %d, %d, %d, %d, %s, %s, %d\n"

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
  char fullName[MAX_NAME * 2];
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

typedef struct node {
  athlete_t *dataAthlete;
  struct node *next;
} node_t;

typedef struct {
  int id;
  char fullName[MAX_NAME * 2];
} playerCSV_t;

void populateTable(athlete_t *athlete, int size);
void saveTableInCSV(athlete_t *athlete, int size, char *arquiveName);
void addNode(node_t **head, athlete_t *athlete);
void createExtraPlayers(athlete_t *athlete, int size);
void readCSV(athlete_t *athlete, node_t **head, int size, char *arquiveName);
void addNodeInFinal(node_t **head, athlete_t *athlete);
void insertionSort(node_t **head);
void printNode(node_t *head);

#endif