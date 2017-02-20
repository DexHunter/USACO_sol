#include<stdio.h>
#include<math.h>
long long int row,column,capture_size;
void total_stone()
{
    long long int c=0;
    long long int remaining_column=column;
    if(capture_size==1)printf("%I64d\n",row*column);
    else
    {
        while(remaining_column>0)
        {
            c++;
            remaining_column-=capture_size;
        }
 
        printf("%I64d\n",((long long int)(ceil)((double)row/capture_size))*c);
    }
}
int main()
{
    while(scanf("%I64d %I64d %I64d",&row,&column,&capture_size)!=EOF)
    {
        total_stone();
    }
    return 0;
}