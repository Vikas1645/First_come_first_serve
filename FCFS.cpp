#include <stdio.h>
int main()
{
  int n, i, j, bt[10], at[10], ct[10], wt[10];
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) 
  {
    printf("Enter the burst time of process %d: ", i + 1);
    scanf("%d", &bt[i]);

    printf("Enter the arrival time of process %d: ", i + 1);
    scanf("%d", &at[i]);
  }
  wt[0] = 0;
  for (i = 1; i < n; i++) 
  {
    wt[i] = bt[i - 1] + wt[i - 1];
  }
  ct[0] = bt[0];
  for (i = 1; i < n; i++) 
  {
    ct[i] = ct[i - 1] + bt[i];
  }
  float avg_wt = 0, avg_tat = 0;
  for (i = 0; i < n; i++) 
  {
    avg_wt += wt[i];
    avg_tat += ct[i];
  }
  avg_wt /= n;
  avg_tat /= n;
  printf("Process\tBT\tAT\tWT\tCT\n");
  for (i = 0; i < n; i++) 
  {
    printf("%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], at[i], wt[i], ct[i]);
  }
  printf("Average waiting time = %f\n", avg_wt);
  printf("Average turnaround time = %f\n", avg_tat);
  return 0;
}

