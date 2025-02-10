#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int capacidade;
   int tamanho;
   int *heap;
} SeatManager;

SeatManager* seatManagerCreate(int n);
int seatManagerReserve(SeatManager* obj);
void seatManagerUnreserve(SeatManager* obj, int seatNumber);
void seatManagerFree(SeatManager* obj);

void minHeapify(int *heap, int n, int i);
void inserirHeap(SeatManager* obj, int valor);
int removerMin(SeatManager* obj);

int main(){

    int n = 10;
    SeatManager* obj = seatManagerCreate(n);

    if (obj == NULL) {
        printf("Erro ao criar SeatManager.\n");
        return 1;
    }

    printf("SeatManager criado com sucesso!\n");

    // Reservar alguns assentos
    printf("Assento reservado: %d\n", seatManagerReserve(obj));
    printf("Assento reservado: %d\n", seatManagerReserve(obj));
    
    // Desreservar um assento
    seatManagerUnreserve(obj, 1);
    printf("Assento 1 desreservado.\n");

    // Reservar novamente
    printf("Assento reservado: %d\n", seatManagerReserve(obj));

    // Liberar memória
    seatManagerFree(obj);

    return 0;
 
}

SeatManager* seatManagerCreate(int n) {
    
    SeatManager *Manager = (SeatManager*)malloc(sizeof(SeatManager)); //primeiro tive que alocar espaço pra struct
    if(Manager==NULL){
        return NULL;
    }
      Manager->capacidade = n;
      Manager->tamanho = n;
      Manager->heap = (int *)malloc(sizeof(int)*n);
      

      if(!Manager->heap){
        free(Manager);
        return NULL;
      }

    for(int i=0; i < n; i++){
        Manager->heap[i] = i+1;
    }

    for(int i = (n/2)- 1; i>=0; i--){       //minheap
        minHeapify(Manager->heap, n, i);
    }

    return Manager;
}

int seatManagerReserve(SeatManager* obj) {
    
   if(obj->tamanho == 0) return -1;
   return removerMin(obj);
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {
    
    
    inserirHeap(obj, seatNumber);
}

void seatManagerFree(SeatManager* obj) {
    
    free(obj->heap);
    free(obj);

}

int removerMin(SeatManager* obj){               
    //remove a raíz e substitui pela última folha, que é o último elemento do array.
    if(obj->tamanho == 0) return -1;

    int raiz = obj->heap[0];
    obj->heap[0] = obj->heap[obj->tamanho-1];
    obj->tamanho--; //reduz total em 1, pois a folha substitui a raíz
    minHeapify(obj->heap, obj->tamanho, 0); 

    return raiz;
}

void inserirHeap(SeatManager* obj, int valor){
    if(obj->tamanho == obj->capacidade) return; //checagem heap cheia

    int i = obj->tamanho;
    obj->heap[i] = valor; //coloca novo valor na última posição da heap
    obj->tamanho++;

    while (i > 0 && obj->heap[(i-1)/2] > obj->heap[i]){
        int temp = obj->heap[i];
        obj->heap[i] = obj->heap[(i-1)/2];      //vai subindo o valor na árvore enquanto ele for menor que o valor pai dele na árvore; 
        obj->heap[(i-1)/2] = temp;                  //basicamente um minHeap ao contrário;
        i = (i - 1)/2;
    }
}

void minHeapify(int *heap, int n, int i){
    //checa se o nó é menor que os seus filhos. caso não, realiza a troca dos valores e testa novamente.
    int menor = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if(esquerda < n && heap[esquerda] < heap[menor]) menor = esquerda;
    if(direita < n && heap[direita] < heap[menor]) menor = direita;

    if(menor != i){
        int temp = heap[i];
        heap[i] = heap[menor];
        heap[menor] = temp;
        minHeapify(heap, n, menor);
    }

}

