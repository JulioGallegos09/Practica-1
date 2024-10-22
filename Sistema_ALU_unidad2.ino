  int EstadoA = 0;
  int EstadoB = 0;

  int w = 0;
  int x = 0;
  int y = 0;
  int z = 0;

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
  pinMode(13, OUTPUT);
  //ACARREO
  pinMode(12, OUTPUT);
  //SIGNO
  pinMode(11, OUTPUT);
  //INDEFINIDO
  pinMode(10, OUTPUT);
  //INFINITO
  pinMode(9, OUTPUT);
}

void loop() {

  EstadoA = digitalRead(2); // Leer valor de A
  EstadoB = digitalRead(3); // Leer valor de B
  w = digitalRead(4);
  x = digitalRead(5);
  y = digitalRead(6);
  z = digitalRead(7);

  // SUMA
  if ((EstadoA ^ EstadoB)&&(!z && !y && !x && w)) {
    digitalWrite(13, HIGH); // SALIDA DE SUMA
  }
  // ACARREO
  if ((EstadoA && EstadoB)&&(!z && !y && !x && w)) {
    digitalWrite(12, HIGH); // SALIDA DEL ACARREO
  }
  //RESTA
  if ((EstadoA ^ EstadoB)&&(!z && !y && x && !w)) {
    digitalWrite(13, HIGH); //SALIDA DE RESTA
  }
  // (!A AND B) SIGNO NEGATIVO DE LA RESTA
  if ((!EstadoA && EstadoB)&&(!z && !y && x && !w)) {
    digitalWrite(11, HIGH); //SALIDA DEL SIGNO NEGATIVO
  }

  //MULTIPLICACION
  if ((EstadoA && EstadoB)&&(!z && !y && x && w)) {
    digitalWrite(13, HIGH); // SALIDA DE LA MULTIPLICACIÓN
  }

  //DIVISION
  if ((EstadoA && EstadoB)&&(!z && y && !x && !w)) {
    digitalWrite(13, HIGH); // SALIDA DE LA DIVISIÓN
  }
  // (!A AND !B) INDEFINIDO
  if ((!EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    digitalWrite(10, HIGH); // SALIDA DEL INDEFINIDO
  }
  // (A AND !B) INFINITO
  if ((EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    digitalWrite(9, HIGH); // SALIDA DEL INFINITO
  }

  // COMPUERTAS LÓGICAS
  // AND
  if ((EstadoA && EstadoB) && (!z && y && !x && w)) {
    digitalWrite(13, HIGH); // SALIDA DE AND
  }

  // OR
  if ((EstadoA || EstadoB) && (!z && y && x && !w)) {
    digitalWrite(13, HIGH); // SALIDA DE OR
  }

  // NOT (solo A)
if ((!z && y && x && w)) {
    if (!EstadoA) {
      digitalWrite(13, HIGH); // NOT A
    } else {
      digitalWrite(13, LOW); // Apagar si se presiona A
    }
  }

  // XOR
  if ((EstadoA ^ EstadoB) && (z && !y && !x && !w)) {
    digitalWrite(13, HIGH); // SALIDA DE XOR
  }

  // XNOR
  if (!(EstadoA ^ EstadoB) && (z && !y && !x && w)) {
    digitalWrite(13, HIGH); // SALIDA DE XNOR
  }

  // NAND
  if (!(EstadoA && EstadoB) && (z && !y && x && !w)) {
    digitalWrite(13, HIGH); // SALIDA DE NAND
  }

  // NOR
  if (!(EstadoA || EstadoB) && (z && !y && x && w)) {
    digitalWrite(13, HIGH); // SALIDA DE NOR
  }
 
  // PARA QUE LOS LED VUELVAN A SU ESTADO OFF
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);

}
