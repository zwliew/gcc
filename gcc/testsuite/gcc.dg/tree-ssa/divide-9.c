/* PR tree-optimization/103855 */
/* { dg-options "-O -fdump-tree-optimized" } */

unsigned long long f(unsigned int a, unsigned int b) {
    unsigned long long all = a;
    return all / b;
}

/* { dg-final { scan-tree-dump-times "\\\(long long unsigned int\\\)" 1 "optimized" } } */
