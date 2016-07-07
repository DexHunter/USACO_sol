/*
ID: dixingx1
LANG: C
PROG: friday
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int n, num[8];
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
	int xx = 1;
	for (int year = 1900; year <= 1900 + N - 1; year++)
	{
		for (int month = 1; month <= 12; month++)
		{
			int tem;
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				tem = 31;
			else if (month == 4 || month == 6 || month == 9 || month == 11)
				tem = 30;
			else if (month == 2 && is_leap(year))
				tem = 29;
			else if (month == 2 && !is_leap(year))
				tem = 28;
			int tag = (xx + 12) % 7 == 0 ? 7 : (xx + 12) % 7;
			xx = (xx + tem) % 7 == 0 ? 7 : (xx + tem) % 7;
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
	FILE *fout = fopen("friday.out", "w");
	int N; // The number of passing year
	fscanf(fin, "%d", &N);
	solve(N);
	return 0;
}
