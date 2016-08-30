#include <stdio.h>


typedef struct {
  char name[30];
  int population;
} Region;

typedef struct {
  int duration; // in months
  int amountOfSales;
  Region* region;
} Assignment;

typedef struct {
  int assignCount;
  Assignment assignments[3];
} SalesRep;

float avePop(SalesRep sr) {
  int total = 0;
  for (int i = 0; i < sr.assignCount; i++) {
    total += sr.assignments[i].region->population;
  }
  return (float) total / sr.assignCount;
}

float salesPerCapita(SalesRep sr) {
  float totalAmount = 0;
  int totalPop = 0;
  for (int i = 0; i < sr.assignCount; i++) {
    totalAmount = totalAmount + sr.assignments[i].amountOfSales;
    totalPop = totalPop + sr.assignments[i].region->population;
  }
  return totalAmount / totalPop;
}

int extendAss(SalesRep sr, int addmonths) {
  return sr.assignments;
}

int main() {
  Region r7 = {"Central Visayas", 6800180};
  Region r8 = {"Western Visayas", 4195000};

  Assignment asgn1 = {24, 100000, &r7};
  Assignment asgn2 = {12, 150000, &r8};

  SalesRep sr = {2, {asgn1, asgn2}};

  printf("%f\n", avePop(sr));

  r8.population = 4195001;

  printf("%.2f\n", avePop(sr));

  printf("%f\n", salesPerCapita(sr));

  return 0;
}