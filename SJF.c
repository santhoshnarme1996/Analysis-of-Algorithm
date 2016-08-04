#include <stdio.h>
int BT[20], AT[20], pCount, AWT, ATT, temp, i, j;
struct{
  int start;
  int end;
}AS[100];
void swap( int i, int j);
int main()
{
    printf("\nEnter number of processes:");
    scanf("%d",&pCount);
    printf("\nEnter the burst time and arrival time of each process one by one respectively\n\n");
    for (i = 0; i < pCount; i++) {
      for (j = 0; j < 2; j++) {
        if(j%2 == 0){
          printf("BT[%d]:",i);
            scanf("%d",&BT[i]);
          }
        else{
          printf("AT[%d]",i);
            scanf("%d",&AT[i]);
        }
      }
    }
    for(i = 0; i < pCount; i++){
      for (j = i+1; j < pCount; j++) {
        if(AT[i] > AT[j]){
          swap(i,j);
        }
      }

      for(i = 0; i < pCount; i++){
        for (j = i+1; j < pCount; j++){
          if(AT[i] == AT[j]){
            if(BT[i] > BT[j]){
                swap(i,j);
            }
          }
        }
    }
    for(i =  0; i < pCount; i++){
      printf("%d  %d\n",AT[i],BT[i]);
    }
  }
  for(i = 0; i < pCount; i++){
    if(i == 0){
      
    }
  }
}

void swap(int i , int j){
    temp=AT[i];
    AT[i]=AT[j];
    AT[j]=temp;

    temp=BT[i];
    BT[i]=BT[j];
    BT[j]=temp;
}
