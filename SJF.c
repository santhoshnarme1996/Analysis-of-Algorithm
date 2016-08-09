#include <stdio.h>
int BT[20], AT[20], pCount, AWT, ATT, temp, i, j;

struct process{
  int start;
  int end;
}AS[100];

void swap( int i, int j);
void displayGantt();
void CalculateAWT();
void CalculateATT();

int main()
{
    printf("\nEnter number of processes:");
    scanf("%d",&pCount);
    printf("\nEnter the burst time and arrival time of each process one by one respectively\n\n");
    for (i = 0 ; i < pCount ; i++) {
          printf("BT[%d]: ",i+1);
            scanf("%d",&BT[i]);
          printf("AT[%d]: ",i+1);
            scanf("%d",&AT[i]);
          printf("\n");
      }
    for(i = 0 ; i < pCount ; i++){
      for (j = i+1 ; j < pCount ; j++) {
        if(AT[i] > AT[j]){
          swap(i,j);
        }
      }
    }

    for(i = 0 ; i < pCount ; i++){
      for (j = i+1 ; j < pCount ; j++){
        if(AT[i] == AT[j]){
          if(BT[i] > BT[j]){
              swap(i,j);
          }
        }
      }
    }

    for (i = 0; i < pCount; i++) {
      if (i == 0) {
        AS[i].start = AT[0];
        AS[i].end = BT[0];
      }
      else {
        AS[i].start = AS[i-1].end;
        AS[i].end = AS[i].start + BT[i];
      }
    }
    printf("\nGantt chart\n");
    displayGantt();
    CalculateAWT();
    printf("\n");
    CalculateATT();
    printf("\n");
}

void swap(int i , int j){
    temp=AT[i];
    AT[i]=AT[j];
    AT[j]=temp;

    temp=BT[i];
    BT[i]=BT[j];
    BT[j]=temp;
}

void displayGantt(){
  int i, j;
  for (i = 0; i < pCount; i++) {
    if(i == 0)
      printf("%d  P%d  %d", AS[i].start, i+1, AS[i].end);
    else
      printf("  P%d  %d", i+1, AS[i].end);
  }
  printf("\n");
}

void CalculateAWT(){
  int i,sum=0;
  float AWT;
  for (i = 0; i < pCount; i++)
    sum += AS[i].start - AT[i];
  AWT = (float)sum / pCount;
  printf("\nAverage Waiting Time = %.3f",AWT);
}

void CalculateATT(){
  int i,sum=0;
  float ATT;
  for (i = 0; i < pCount; i++)
    sum += AS[i].end - AT[i];
  ATT = (float)sum / pCount;
  printf("\nAverage Turnaround Time = %.3f\n",ATT);
}
