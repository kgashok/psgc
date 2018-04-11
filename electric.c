#include <stdio.h>

struct cust_info {
  int customerID;
  float powerConsumed;
  float powerBill;
} customers[10];

typedef struct cust_info Customer;

void calculateBill(Customer c[10]) {
  FILE* fileOut = fopen("ebill.txt", "w");
  int i;

  for (i = 0; i < 10; i++) {
    if (c[i].customerID) {
      int units = c[i].powerConsumed;
      c[i].powerBill = 0;

      if (units > 400) {
        c[i].powerBill = 230 + (units - 400) * 0.80;
      } else if (units > 200) {
        c[i].powerBill = 100 + (units - 200) * 0.65;
      } else if (units <= 200) {
        c[i].powerBill += units * 0.50;
      }

      fprintf(fileOut, "%d %.2f\n", c[i].customerID, c[i].powerBill);
    } else
      break;  // no more customer IDs to process
  }
  fflush(fileOut);
  fclose(fileOut);
}

int main() {
  FILE* fileIn = fopen("cust.txt", "r");

  Customer* cp = customers;
  while (1) {
    int n = fscanf(fileIn, "%d %f", &cp->customerID, &cp->powerConsumed);
    if (n == -1) break;
    cp++;
  }
  fclose(fileIn);

  calculateBill(customers);

  return 0;
}