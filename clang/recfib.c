#include <stdio.h>

int generate_fibo(int fibopp, int fibop, int count, int slen) {
  int fibo = fibopp + fibop;
  printf("%d ", fibo);

  if (count == slen) {  // TERMINAL CONDITION
    return fibo;        // for the nth Fibonacci number
  }

  // prepare to generate the next in sequence
  fibopp = fibop;
  fibop = fibo;
  return generate_fibo(fibopp, fibop, count + 1, slen);
}

main(int argc, char** argv) {
  int seq_length = atoi(argv[1]);
  if (seq_length <= 2) return 1;

  printf("The fibonacci sequence (%d) is ", seq_length);

  int fibo1 = 0, fibo2 = 1;
  printf("%d %d ", fibo1, fibo2);
  int fibFinal = generate_fibo(fibo1, fibo2, 3, seq_length);

  printf("\nThe %d in fibonacci sequence is %d\n", seq_length, fibFinal);

  return 0;
}
