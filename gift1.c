/*
ID: dixingx1
LANG: C
PROG: gift1
*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 15

int main(){
	int NP; //number of person
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	
	fscanf(fin, "%d\n", &NP); //get the NP

	char dudes[NP][MAX_LEN];
	int account[NP]; //everyone's account money
	for(int i=0; i<NP; i++)	//read the name for each person
	{
		fscanf(fin, "%s", dudes[i]);
		account[i] = 0; //initial everyone's account to zero
	}
	
	//greedy algorithm
	
	int NG;
	NG = NP;
	char giver[NG][MAX_LEN];
	int gm[NG], rm[NG], im[NG], fm[NG];	//given money, received money, initialized money, final money
	for(int i=0; i<NG; i++){
		fscanf(fin, "%s", giver[i]);
		fscanf(fin, "%d", &im[i]);
		int no; // initializes number of people the giver gives as zero
		fscanf(fin, "%d", &no);
		if(no==0){
			rm[i] = 0;
			fm[i] = 0;
		}
		else{
			fm[i] = im[i]%no-im[i];
			rm[i] = im[i]/no;
		}
		char receiver[no][MAX_LEN];
		for(int j=0;j<no; j++){
			fscanf(fin, "%s", receiver[j]);
			for(int k=0; k<NG;k++){
				if(strcmp(dudes[k],receiver[j]) == 0){
					account[k] += rm[i];
				}
			}
		}
		
		
		
	}
	
	//rearrange the order
	for(int i=0; i<NP; i++)
	{
		for(int j=0; j<NG; j++){
			if(strcmp(dudes[i], giver[j])==0)
			{
				account[i] += fm[j];
			}
		}
	}
	
	
	for(int i=0; i<NP; i++)	//output 
	{
		fprintf(fout, "%s %d\n", dudes[i], account[i]);
	}
	return 0;
}
