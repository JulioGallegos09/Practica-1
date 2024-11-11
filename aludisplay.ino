int EstadoA = 0;
int EstadoB = 0;

int w = 0;
int x = 0;
int y = 0;
int z = 0;

void encender(int a, int b, int c, int d, int e, int f, int g)
{
  //Asigna un segmento del display a cada pin
  digitalWrite(22, a);  //Asigna el segmento 'a' al pin 22
  digitalWrite(23, b);  //Asigna el segmento 'b' al pin 23
  digitalWrite(24, c);  //Asigna el segmento 'c' al pin 24
  digitalWrite(25, d);  //Asigna el segmento 'd' al pin 25
  digitalWrite(26, e);  //Asigna el segmento 'e' al pin 26
  digitalWrite(27, f);  //Asigna el segmento 'f' al pin 27
  digitalWrite(28, g);  //Asigna el segmento 'g' al pin 28
}
void encender2(int a2, int b2, int c2, int d2, int e2, int f2, int g2)
{
  //Asigna un segmento del display a cada pin
  digitalWrite(29, a2);  //Asigna el segmento 'a' al pin 29
  digitalWrite(30, b2);  //Asigna el segmento 'b' al pin 30
  digitalWrite(31, c2);  //Asigna el segmento 'c' al pin 31
  digitalWrite(32, d2);  //Asigna el segmento 'd' al pin 32
  digitalWrite(33, e2);  //Asigna el segmento 'e' al pin 33
  digitalWrite(34, f2);  //Asigna el segmento 'f' al pin 34
  digitalWrite(35, g2);  //Asigna el segmento 'g' al pin 35
}

void setup() {
  //Pines de entrada para A, B, w, x, y, z
  pinMode(2, INPUT); 
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  //Pines de salida para cada operación
  //SUMA, RESTA, DIVISION, MULTIPLICACION
  pinMode(22, OUTPUT); //'a'
  pinMode(23, OUTPUT); //'b' 
  pinMode(24, OUTPUT); //'c' 
  pinMode(25, OUTPUT); //'d'
  pinMode(26, OUTPUT); //'e'
  pinMode(27, OUTPUT); //'f'
  pinMode(28, OUTPUT); //'g'
  pinMode(29, OUTPUT); //'a2'
  pinMode(30, OUTPUT); //'b2' 
  pinMode(31, OUTPUT); //'c2' 
  pinMode(32, OUTPUT); //'d2'
  pinMode(33, OUTPUT); //'e2'
  pinMode(34, OUTPUT); //'f2'
  pinMode(35, OUTPUT); //'g2'
}

void loop() {

  EstadoA = digitalRead(2); // Leer valor de A
  EstadoB = digitalRead(3); // Leer valor de B
  w = digitalRead(4);
  x = digitalRead(5);
  y = digitalRead(6);
  z = digitalRead(7);

  //CERO INICIAL
  if ((!EstadoA && !EstadoB)&&(!w && !x && !y && !z)){
    encender (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
  }
  if ((!EstadoA && !EstadoB)&&(!w && !x && !y && !z)){
    encender2 (1, 1, 1, 1, 1, 1, 1); //Display 2 apagado
  }
  if ((!EstadoA && !EstadoB)&&(w && !x && !y && !z)){
    encender (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
  }
  // SUMA
  if ((EstadoA ^ EstadoB)&&(!z && !y && !x && w)) {
    encender (1, 0, 0, 1, 1, 1, 1); //muestra un 1
  }
  // ACARREO
  if ((EstadoA && EstadoB)&&(!z && !y && !x && w)) {
    encender (0, 0, 1, 0, 0, 1, 0); //Muestra un 2
    //digitalWrite(12, HIGH); // SALIDA DEL ACARREO
  }
  //RESTA
  if ((!EstadoA && !EstadoB)&&(!z && !y && x && !w)) {
    encender (0, 0, 0, 0, 0, 0, 1);
    encender2 (1, 1, 1, 1, 1, 1, 1);
  }
  if ((EstadoA && EstadoB)&&(!z && !y && x && !w)) {
    encender (0, 0, 0, 0, 0, 0, 1); //cero
  }

  if ((EstadoA && !EstadoB)&&(!z && !y && x && !w)) {
    encender (1, 0, 0, 1, 1, 1, 1);//muestra 1
  }
  if ((!EstadoA && EstadoB)&&(!z && !y && x && !w)) {
    encender (1, 0, 0, 1, 1, 1, 1);//muestra 1
    encender2(1, 1, 1, 1, 1, 1, 0);// muestra signo menos
  }

  //MULTIPLICACION
  
  if ((EstadoA && EstadoB)&&(!z && !y && x && w)) {
    encender (1, 0, 0, 1, 1, 1, 1); //muestra 1
  }
  if ((!EstadoA && !EstadoB)&&(w && x && !y && !z)){
    encender (0, 0, 0, 0, 0, 0, 1); //muestra 0
  }

  //DIVISION
  if ((EstadoA && EstadoB)&&(!z && y && !x && !w)) {
    encender (1, 0, 0, 1, 1, 1, 1); //muestra 1
    encender2(1, 1, 1, 1, 1, 1, 1);
  }
  // (!A AND !B) INDEFINIDO
  if ((!EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    encender2 (1, 0, 0, 1, 1, 1, 1); //muestra I SALIDA DEL INDEFINIDO
    encender (1, 1, 0, 1, 0, 1, 0); //muestra la n de indefinido
  }
  // (A AND !B) INFINITO
  if ((EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    encender2(1, 1, 0, 0, 0, 1, 0);//Muestra la parte del infinito display izquierdo
    encender (1, 1, 0, 0, 0, 1, 0);//Muestra la parte del infinito display derecho
    // SALIDA DEL INFINITO
  }

  // COMPUERTAS LÓGICAS
  // AND
  if ((!EstadoA && !EstadoB)&&(w && !x && y && !z)){
    encender (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
    encender2(1,1,1,1,1,1,1);
  }
  if ((EstadoA && EstadoB) && (!z && y && !x && w)) {
    encender (1, 0, 0, 1, 1, 1, 1); //muestra 1 // SALIDA DE AND
  }

  // OR
  if ((!EstadoA && !EstadoB)&&(!w && x && y && !z)){
    encender (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
    encender2(1,1,1,1,1,1,1);
  }
  if ((EstadoA || EstadoB) && (!z && y && x && !w)) {
    encender (1, 0, 0, 1, 1, 1, 1); //muestra 1 // SALIDA DE OR
  }

  // NOT (solo A)
  if ((!z && y && x && w)) {
    if (!EstadoA) {
      encender (1, 0, 0, 1, 1, 1, 1); //muestra 1 // NOT A
    } else {
      encender (0, 0, 0, 0, 0, 0, 1); //muestra 0 // Apagar si se presiona A
    }
  }

  // XOR
  if ((!EstadoA && !EstadoB)&&(!w && !x && !y && z)){
    encender (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
  }
  if ((EstadoA ^ EstadoB) && (z && !y && !x && !w)) {
    encender (1, 0, 0, 1, 1, 1, 1); //muestra 1 // SALIDA DE XOR
  }
  if ((EstadoA && EstadoB)&&(!w && !x && !y && z)){
    encender (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
  }

  // XNOR
  if ((!EstadoA && !EstadoB)&&(w && !x && !y && z)){
    encender (1, 0, 0, 1, 1, 1, 1); //Muestra el numero 1
    encender2 (1,1,1,1,1,1,1);
  }
  if ((!EstadoA && EstadoB) && (z && !y && !x && w)) {
    encender (0, 0, 0, 0, 0, 0, 1); //muestra 0 // SALIDA DE XNOR
  }
  if ((EstadoA && !EstadoB) && (z && !y && !x && w)) {
    encender (0, 0, 0, 0, 0, 0, 1); //muestra 0 // SALIDA DE XNOR
  }
  if ((EstadoA && EstadoB)&&(w && !x && !y && z)){
    encender (1, 0, 0, 1, 1, 1, 1); //Muestra el numero 1
  }

  // NAND
  if ((EstadoA && EstadoB) && (z && !y && x && !w)) {
    encender (0, 0, 0, 0, 0, 0, 1); //muestra 1 // SALIDA DE NAND
  }
  if ((!EstadoA && EstadoB) && (z && !y && x && !w)) {
    encender (1, 0, 0, 1, 1, 1, 1); //muestra 0 // SALIDA DE NAND
  }
  if ((EstadoA && !EstadoB) && (z && !y && x && !w)) {
    encender (1, 0, 0, 1, 1, 1, 1); //muestra 0 // SALIDA DE NAND
  }
  if ((!EstadoA && !EstadoB) && (z && !y && x && !w)) {
    encender (1, 0, 0, 1, 1, 1, 1); //muestra 0 // SALIDA DE NAND
    encender2(1, 1, 1, 1, 1, 1, 1);
  }

  // NOR
  if ((!EstadoA && !EstadoB) && (z && !y && x && w)) {
    encender (1, 0, 0, 1, 1, 1, 1); //muestra 1 // SALIDA DE NOR
    encender2(1, 1, 1, 1, 1, 1, 1);
  }
  if ((!EstadoA && EstadoB) && (z && !y && x && w)) {
    encender (0, 0, 0, 0, 0, 0, 1); //muestra 0 // SALIDA DE NOR
  }
  if ((EstadoA && !EstadoB) && (z && !y && x && w)) {
    encender (0, 0, 0, 0, 0, 0, 1); //muestra 0 // SALIDA DE NOR
  }
  if ((EstadoA && EstadoB) && (z && !y && x && w)) {
    encender (0, 0, 0, 0, 0, 0, 1); //muestra 0 // SALIDA DE NOR
  }
 

}