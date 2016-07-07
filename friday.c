/*#include <stdio.h>
#include <string.h>


struct week{
	int days;
	char* weekdays;
};

void thirtydaymonth(char* week, ){
	//April, June, September and Novermber
	start
	
	
	
}

void leap(int year, int N){
	int ctr;
	for (int i=0; i<N;i++){
	year = 1990 + i;
		if (year%4 == 0){
			if(year%100 == 0){
				if(year%400 != 0){
					//do nothing since 1700,1800,1900 are not leap years
				}
				else{
					ctr++;
				}
			}	
			else {
				ctr++;
				}
			}
		}
}

void Feb(void)
{
	
}

int main(){
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");
	int N; // The number of passing year
	fscanf(fin, "%d", N);
	
	char* week = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
	
} */
#include <stdio.h>
#include <string.h>

int n, num[8];
bool is_leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}
void solve()
{
	memset(num, 0, sizeof(num));
	int xx = 1;
	for (int year = 1900; year <= 1900 + n - 1; year++)
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
	printf("%d %d", num[6], num[7]);
	for (int i = 1; i <= 5; i++)
		printf(" %d", num[i]);
	puts("");
}
int main()
{
	while (~scanf("%d", &n))
		solve();
	return 0;
}
