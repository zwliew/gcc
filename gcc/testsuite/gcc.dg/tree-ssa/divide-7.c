/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized" } */

int f(int x) {
  return 1 / x;
}

/* { dg-final { scan-tree-dump "return x >= -1 && x <= 1 ? x : 0;" "optimized" } } */

