#define LEDVERDE 2      
#define LEDAMARILLO 3
#define LEDROJO 4
#define ANALOGPILA 0

int analogValor = 0;  
float voltaje = 0;    
int ledDelay = 800;

float maximo = 1.5;  
float medio = 1.3;
float minimo = 0.3;

void setup() {     
  Serial.begin(9600);

  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAMARILLO, OUTPUT);
  pinMode(LEDROJO, OUTPUT);

}

void loop() {
  analogValor = analogRead(ANALOGPILA);   
  voltaje = 0.0048 * analogValor; 
  Serial.print("Voltaje: ");   
  Serial.println(voltaje);

  if (voltaje >= maximo)                                  
  {
    digitalWrite(LEDVERDE, HIGH);
    delay(ledDelay);
    digitalWrite(LEDVERDE, LOW);
  }
  else if (voltaje < maximo && voltaje > medio)
  {
    digitalWrite(LEDAMARILLO, HIGH);
    delay(ledDelay);
    digitalWrite(LEDAMARILLO, LOW);
  }
  else if (voltaje < medio && voltaje > minimo)
  {
    digitalWrite(LEDROJO, HIGH);
    delay(ledDelay);
    digitalWrite(LEDROJO, LOW);
  }
  digitalWrite(LEDVERDE, LOW);
  digitalWrite(LEDAMARILLO, LOW);
  digitalWrite(LEDROJO, LOW);
}


