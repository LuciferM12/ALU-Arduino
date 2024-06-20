const int S0 = 5, S1 = 4, S2 = 3, S3 = 2, Cn = A4, M = A5;
const int a[4] = {10,11,12,13}, b[4] = {6,7,8,9};
const int f[4] = {A0, A1, A2, A3};
const int TX = 1, RX = 0; 
int aux = 0, op = 0, aux2 = 0;
void setup() 
{
  for(int i = 0; i < 4; i++)
  {
    pinMode(a[i], OUTPUT);
    pinMode(b[i], OUTPUT);
    pinMode(f[i], INPUT);
  }
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(M, OUTPUT);
  pinMode(Cn, OUTPUT);
  pinMode(TX, INPUT);
  pinMode(RX, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int arreglo[4] = {0,0,0,0};
  int arreglo2[4] = {0,0,0,0};
  int result[5] = {0,0,0,0,0}; 
  int cont = 0;
  int tot = 0;
  int exp = 8;
  if(Serial.available() > 0)
  {
    Serial.println("Introduce un valor para A: ");
    aux = Serial.parseInt();
    Serial.println((String) "El numero ingresado es: " + aux);
    while (Serial.available() > 0) 
    {
      Serial.read(); //Limpia el buffer
    }
    /*
  */
    Serial.println("Introduce un valor para B: ");
    while (Serial.available() == 0) {
      // Espera a que haya datos disponibles
    }
    aux2 = Serial.parseInt();
    /**/
    Serial.println((String) "El numero ingresado es: " + aux2);
    while (Serial.available() > 0) {
      Serial.read(); //Limpia el buffer
    }

    Serial.println("Que desea realizar: 1.Suma, 2.Resta, 3.AND, 4.OR");
    while (Serial.available() == 0) {
      // Espera a que haya datos disponibles
    }
    op = Serial.parseInt();
    while (Serial.available() > 0) {
      Serial.read(); //Limpia el buffer
    }

    Serial.println((String) "El numero ingresado es: " + op);
    if(op == 1)
    {
      digitalWrite(M,0);
      digitalWrite(S0,1);
      digitalWrite(S1,0);
      digitalWrite(S2,0);
      digitalWrite(S3,1);
      digitalWrite(Cn,1);
    }else if(op == 2)
    {
      digitalWrite(M,0);
      digitalWrite(S0,0);
      digitalWrite(S1,1);
      digitalWrite(S2,1);
      digitalWrite(S3,0);
      digitalWrite(Cn,0);
    }else if(op == 4)
    {
      digitalWrite(M,1);
      digitalWrite(S0,0);
      digitalWrite(S1,1);
      digitalWrite(S2,1);
      digitalWrite(S3,1);
      digitalWrite(Cn,1);
    }else if(op == 3)
    {
      digitalWrite(M,1);
      digitalWrite(S0,1);
      digitalWrite(S1,1);
      digitalWrite(S2,0);
      digitalWrite(S3,1);
      digitalWrite(Cn,1);
    }





    //Inicio de los cálculos
    if(aux2 == 1)
    {
      arreglo2[0] = 1;
    }
    else
    {
      if(aux2 == 2)
      {
        arreglo2[1] = 1;
      }
      else
      {
        if(aux2 == 3)
        {
          arreglo2[0] = 1;
          arreglo2[1] = 1;
        }
        else
        {
          while(aux2 > 0)
          {
            arreglo2[cont] = aux2 % 2;
            cont++;
            aux2 /= 2;
          }
        }
      }
    }
    
    cont = 0;
    if(aux == 1)
    {
      arreglo[0] = 1;
    }
    else
    {
      if(aux == 2)
      {
        arreglo[1] = 1;
      }
      else
      {
        if(aux == 3)
        {
          arreglo[0] = 1;
          arreglo[1] = 1;
        }
        else
        {
          while(aux > 0)
          {
            arreglo[cont] = aux % 2;
            cont++;
            aux /= 2;
          }
        }
      }
    }
    /*for(int i = 3; i>=0 ;i--)
    {
      Serial.print(arreglo[i]); 
    }
    Serial.println();
    for(int i = 3; i>=0 ;i--)
    {
      Serial.print(arreglo2[i]); 
    }
    Serial.println();*/
    for(int i = 0; i < 4; i++)
    {
      digitalWrite(a[i],arreglo[3-i]);
      digitalWrite(b[i],arreglo2[3-i]);
    }

    for(int i = 0; i < 4; i++)
    {
      //result[i] = digitalRead(f[3-i]);
      tot += digitalRead(f[3-i])*exp;
      exp /=2;
      
    }
    Serial.print((String) "El resultado es: " + tot );
    Serial.println();
    tot = 0;
  }  
}
