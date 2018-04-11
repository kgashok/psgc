#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

typedef struct node Node;

Node* head = NULL;

Node* traverseTail(Node* np) {
  if (np == NULL)  // TERMINAL CONDITION_1
    return 0;
  if (np->next == NULL)  // TERMINAL CONDITION_2
    return np;

  return traverseTail(np->next);
}

int traverseSum(Node* np, int i) {
  if (np == NULL)  // TERMINAL CONDITION
    return 0;

  printf("node %d: %d\n", i++, np->data);
  return np->data + traverseSum(np->next, i);
}

Node* createNode(int val) {
  Node* n = (Node*)malloc(sizeof(struct node));
  n->data = val;
  n->next = NULL;

  return n;
}

int main() {
  int numbers[8] = {1, 2, 3, 4, 5, 6, 7, 8};

  // forming the linked list
  Node* head = (Node*)malloc(sizeof(struct node));
  Node* np = head;

  int i;
  for (i = 0; i < 8; i++, np = np->next) {
    np->next = createNode(numbers[i]);
  }

  int res = traverseSum(head->next, 0);
  printf("Sum of the elements in list %d\n", res);

  res = traverseTail(head)->data;
  printf("Tail data is %d\n", res);

  return 0;
}