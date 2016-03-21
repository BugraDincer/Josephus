#include <stdio.h>
#include <stdlib.h>


void createList(int *,int);
void printList(int *,int);
void play(int *,int,int);

int main()
{
    int *list;                  //Listeyi tutan array
    int M;                      //Sayma sayisi
    int N;                      //Cocuk sayisi
    printf("Çocuk sayisini giriniz : ");
    scanf("%d",&N);
    list=(int *)malloc(N*sizeof(int));
    if(list==NULL){
        printf("Yetersiz Hafiza !!");
        return -1;
    }
    printf("Sayma sayisi M'i giriniz : ");
    scanf("%d",&M);
    createList(list, N);
    play(list,N,M);
    printList(list,M);
    return 0;
}

void createList(int *list, int N){

    int i;                  // for dongusunun sayaci
    int current;            // Linked List uzerinde bulunulan konumu gosterir
    current=0;
    for(i=0;i<N-1;i++){
        list[current]=current+1;
        current=list[current];
    }
    list[current]=0;
}
void printList(int *list,int M){
    int i;                  // for dongusunun sayaci
    int current;            // Linked List uzerinde bulunulan konumu gosterir
    current=0;
    printf("Kalan cocuklar : ");
    for(i=0;i<M-1;i++){
        current=list[current];
        printf("%d " ,current);
    }
}
void play(int *list, int N, int M){
    int i;                  // Ic for dongusunun sayaci
    int current;            // Linked List uzerinde bulunulan konumu gosterir
    int count;              // Oyundan cikan oyuncu sayisini ve adim sayisini tutan degisken
    count=0;
    current=N;
    while(count<N-(M-1)){
        for(i=0;i<M-1;i++){
          current=list[current];
        }
        count+=1;
        printf("%d. adimda %d numarali cocuk elendi\n",count,list[current]);
        list[current]=list[list[current]];

    }
}
