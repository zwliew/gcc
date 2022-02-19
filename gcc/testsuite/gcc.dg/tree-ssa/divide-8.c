/* PR tree-optimization/103855 */
/* { dg-options "-O -fdump-tree-optimized" } */

unsigned int f1(unsigned int a, unsigned int b) {
	unsigned long long all = a;
	return all / b;
}

unsigned int f2(unsigned char a, unsigned int b) {
	unsigned long long all = a;
	return all / b;
}

unsigned int f3(unsigned int a, unsigned char b) {
	unsigned long long all = a;
	return all / b;
}

int f4(char a, int b) {
	long long all = a;
	return all / b;
}

unsigned int f5(unsigned int a) {
	unsigned long long all = a;
	return all / 123456789;
}

unsigned int f6(unsigned int b) {
	unsigned long long bll = b;
	return 123456789 / bll;
}

int f7(int a) {
  long long all = a;
	return all / 123456789;
}

int f8(int b) {
	long long bll = b;
	return 123456789 / bll;
}

/* { dg-final { scan-tree-dump-not "\\\(long long unsigned int\\\)" "optimized" } } */
/* { dg-final { scan-tree-dump-not "\\\(long long int\\\)" "optimized" } } */
