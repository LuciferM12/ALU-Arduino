const int S0 = 5, S1 = 4, S2 = 3, S3 = 2, Cn = A4, M = A5;
const int a[4] = {13,12,11,10}, b[4] = {9,8,7,6};
const int F0 = A0, F1 = A1, F2 = A2, F3 = A3, TX = 1, RX = 0; 
int aux = 0, op = 0;
void setup() {
  for(int i = 0; i < 4; i++){
    pinMode(a[i], OUTPUT);
    pinMode(b[i], OUTPUT);
  }
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(M, OUTPUT);
  pinMode(Cn, INPUT);
  pinMode(F0, INPUT);
  pinMode(F1, INPUT);
  pinMode(F2, INPUT);
  pinMode(F3, INPUT);
  pinMode(TX, INPUT);
  pinMode(RX, INPUT);
  Serial.begin(9600);
}

void loop() {
  int arreglo[5];
  int arreglo2[5];
  int cont = 0;
  if(Serial.available() > 0){
    Serial.println("Introduce un valor para A: ");
    aux = Serial.parseInt();
    while(aux > 0){
      arreglo[cont] = aux % 2;
      cont++;
      aux /= 2;
    }
    cont = 0;
    Serial.println("Introduce un valor para B: ");
    aux = Serial.parseInt();
    while(aux > 0){
      arreglo2[cont] = aux % 2;
      cont++;
      aux /= 2;
    }
    for(int i = 0; i < 4; i++){
      digitalWrite(a[0],arreglo[3-i]);
      digitalWrite(b[0],arreglo2[3-i]);
    }
    Serial.println("Que desea realizar: 1.Suma, 2.Resta, 3.AND, 4.OR");
    op = Serial.parseInt();
    if(op == 1){
      digitalWrite(M,0);
      digitalWrite(S0,1);
      digitalWrite(S1,0);
      digitalWrite(S2,0);
      digitalWrite(S3,1);
    }else if(op == 2){
      digitalWrite(M,0);
      digitalWrite(S0,0);
      digitalWrite(S1,1);
      digitalWrite(S2,1);
      digitalWrite(S3,0);
    }else if(op == 3){
      digitalWrite(M,1);
      digitalWrite(S0,0);
      digitalWrite(S1,1);
      digitalWrite(S2,1);
      digitalWrite(S3,1);
    }else if(op == 4){
      digitalWrite(M,1);
      digitalWrite(S0,1);
      digitalWrite(S1,1);
      digitalWrite(S2,0);
      digitalWrite(S3,1);
    }
  }  
}
