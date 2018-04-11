#include <stdio.h>
#include <string.h>

int is_palindrome(char* front, char* back) {
  if (*front != *back) {  // there is no match
    // printf ("front: %c != back: %c\n", *front, *back);
    return 0;
  }
  if (front >= back)  // there is nothing else to check
    return 1;

  // printf ("front: %c == back: %c\n", *front, *back);
  return is_palindrome(++front, --back);
}

int palin_rec(char* s) {
  static int i = 0;

  int front = i;
  int back = strlen(s) - i - 1;

  if (front >= back) return 1;

  printf("%c == %c? // ", s[front], s[back]);
  if (s[front] != s[back]) {
    return 0;
  }

  i++;
  return palin_rec(s);
}

int main() {
  char input[30];
  scanf("%s", input);

  char* front = input;
  char* back = input + strlen(input) - 1;

  // int res = is_palindrome(front, back);
  int res = palin_rec(input);

  printf("%s is a palindrome: %s\n ", input, (res == 1 ? "True" : "False"));

  return 0;
}