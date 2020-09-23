#include <stdio.h>

void swap (int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}


//bubble sort algorithm that sort elements in first array and keep its corresponding element in second array
void bubble_sort(int n, int a[], int b[]){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                swap(&a[j], &a[j + 1]);
                swap(&b[j], &b[j + 1]);
            }
        }
    }
}



int main(void) {
  int n;
  printf("Number of processes: ");
  scanf("%d", &n);
  int arT[n], brT[n];
  for (int i = 0; i < n; i++){
    printf("Enter arrival time and burst time for process%d:\n");
    scanf("%d", &arT[i]);
    scanf("%d", &brT[i]);
  }
  int coT[n], taT[n], wT[n];

  //sorting processes by arrival time
  bubble_sort(n, arT, brT);


  for (int i = 0; i < n; i++){
    if(i > 0){
      coT[i] = brT[i] + coT[i - 1];     //calculating completion time
    }
    else {
      coT[0] = brT[0];
      }
    taT[i] = coT[i] - arT[i];           //calculating turn around time
    wT[i] = taT[i] - brT[i];            //calculating waiting time
  }


  float ATT, AWT;                     //Average Turnaround time, Average waiting time
  for(int i = 0; i < n; i++){
    ATT = ATT + taT[i];             
    AWT = AWT + wT[i];              
  }

  ATT = ATT / n;                //calculating Average Turnaround time, 
  AWT = AWT / n;                //calculating Average waiting time

  for (int i = 0; i < n; i++){
    printf("For process #%d: Completion time = %d, Turn around time = %d, Waiting time = %d.\n", i, coT[i], taT[i], wT[i]);
  }
  printf("\n\n");
  printf("Average Turnaround time = %f\nAverage waiting time = %f", ATT, AWT);
  return 0;
}