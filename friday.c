/*
ID: dixingx1
LANG: C
PROG: friday
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}
void solve(int N)
{
	FILE *fout = fopen("friday.out", "w");
	memset(num, 0, sizeof(num));
	int fd = 1; //first day, eg. 1990.1.1 is Monday thus, fd corresponding to 1
	int num[8];
	for (int year = 1900; year <= 1900 + N - 1; year++)
	{
		for (int month = 1; month <= 12; month++)
		{
			int days;
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				days= 31;
			else if (month == 4 || month == 6 || month == 9 || month == 11)
				days = 30;
			else if (month == 2 && is_leap(year))
				days = 29;
			else if (month == 2 && !is_leap(year))
				days = 28;
			int tag = (fd + 12) % 7 == 0 ? 7 : (fd + 12) % 7; 
			fd = (fd + days) % 7 == 0 ? 7 : (fd + days) % 7;
			num[tag]++;
		}
	}
	fprintf(fout, "%d %d", num[6], num[7]);
	for (int i = 1; i <= 5; i++)
		fprintf(fout, " %d", num[i]);
	fputs("\n",fout);
	
}
int main()
{
	FILE *fin = fopen("friday.in", "r");
	int N; // The number of passing year
	fscanf(fin, "%d", &N);
	solve(N);
	return 0;
}
