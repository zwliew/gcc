/* PR tree-optimization/103855 */
/* { dg-options "-O -fdump-tree-optimized" } */

unsigned int f(unsigned int a, unsigned int b) {
    unsigned long long all = a;
    return all / b;
}

/* { dg-final { scan-tree-dump-not "\\\(long long unsigned int\\\)" "optimized" } } */
