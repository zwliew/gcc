/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized" } */

unsigned int f(unsigned int x) {
  return 1 / x;
}

/* { dg-final { scan-tree-dump "return x == 1;" "optimized" } } */
