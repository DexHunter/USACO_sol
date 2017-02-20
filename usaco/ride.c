/*
ID: dixingx1
LANG: C
PROG: ride
*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 10

int main(){
	FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
	
	char comet[MAX_LEN];
	char group[MAX_LEN];
	int m=1;
	int n=1;
	
	fscanf(fin, "%s/n", comet);
	fscanf(fin, "%s", group);
	
	for(int i=0; comet[i] != '\0'; i++){ //calculate total value of comet
		comet[i] -= 64;
		m = comet[i]*m;
	}
	for(int j=0; group[j] != '\0';j++){ //calculate total value of group
		group[j] -= 64;
		n = group[j] *n;
	}
	if(m%47==n%47){ //compare 
		fprintf(fout, "GO\n");
	}
	else{
		fprintf(fout, "STAY\n");
	}
	
}

