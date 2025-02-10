


typedef struct {
    int aux=NULL;
    int seatNumber=NULL;
    int totalReservas=NULL;
    int reservas[];
} SeatManager;

int main(){
  SeatManager* obj = seatManagerCreate(n);
  int param_1 = seatManagerReserve(obj);
 
  seatManagerUnreserve(obj, seatNumber);
 
  seatManagerFree(obj);
}

SeatManager* seatManagerCreate(int n) {
    //alocar vetor de reservas, inicializar ponteiros, preencher cada mesa com o seu respectivo número;
    obj = (int *)malloc(sizeof(struct SeatManager) + sizeof(int)*n);
    aux = *reservas;
    *totalReservas = n;

    for(int i=1; i <= n; i++){
        reservas[i] = i;
    }
}

int seatManagerReserve(SeatManager* obj) {
    //percorrer vetor comparando até achar o menor valor diferente de 0, reserva ele e retorna o valor;
    for(int i=0; i < seatNumber; i++){
        if(reservas[i] != 0){
            return reservas[i];
            reservas[i] = 0;
            break;
        }
    }
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {
    //percorrer vetor comparando até achar o valor, desreserva ele;
    for(int i=1; i <= totalReservas; i++){
        if(i == seatNumber){
            reservas[i] = i;
            break;
        }

    }
}

void seatManagerFree(SeatManager* obj) {
    //dá free na instancia;
    *obj=free();
    *seatNumber=NULL;
    *totalReservas=NULL;
    *reservas[]=NULL;
}

/**
 * Your SeatManager struct will be instantiated and called as such:
 * SeatManager* obj = seatManagerCreate(n);
 * int param_1 = seatManagerReserve(obj);
 
 * seatManagerUnreserve(obj, seatNumber);
 
 * seatManagerFree(obj);
*/