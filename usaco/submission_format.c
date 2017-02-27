/*
ID
LANG: C++11
PROG: test
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout ("test.out");
	ifstream fin ("test.in");
	int a, b;
	fin >> a >> b;
	fout << a+b <<endl;
	return 0;
}

/*
ID
LANG: C
TASK: test
*/

#include <stdio.h>
main() {
	FILE *fin  = fopen("test.in", "r");
	FILE *fout = fopen("test.out", "w");
	int a, b;
	fsacnf( fin, "%d %d", &a, &b);
	fprintf(fout, "%d\n", a+b);
	exit(0);
}
