const int sA = 2;
const int sB = 3;
const int sC = 4;
const int sD = 5;
const int sE = 6;
const int sF = 7;
const int sG = 8;

const int sDA = 9;
const int sDB = 10;
const int sDC = 11;
const int sDD = 12;
const int sDE = 13;
const int sDF = A4;
const int sDG = A5 ;

void setup() {
  Serial.begin(9600);

  pinMode(sA, OUTPUT);
  pinMode(sB, OUTPUT);
  pinMode(sC, OUTPUT);
  pinMode(sD, OUTPUT);
  pinMode(sE, OUTPUT);
  pinMode(sF, OUTPUT);
  pinMode(sG, OUTPUT);

  pinMode(sDA, OUTPUT);
  pinMode(sDB, OUTPUT);
  pinMode(sDC, OUTPUT);
  pinMode(sDD, OUTPUT);
  pinMode(sDE, OUTPUT);
  pinMode(sDF, OUTPUT);
  pinMode(sDG, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int operand1 = Serial.parseInt();
    char operation = Serial.read();
    int operand2 = Serial.parseInt();
    int operand3 = Serial.parseInt();

    int result = 0;

    switch (operation) {
      case '+':
        result = operand1 + operand2+operand3;
        break;
      case '-':
        result = operand1 - operand2-operand3;
        break;
      case '*':
        result = operand1*operand2;
        break;
      case '/':
        if (operand2 != 0) {
          result = operand1 / operand2;
        } else {
          Serial.println("Error: División por cero");
          return;
        }
        break;
    }

    if (result <= 99) {
      if (result > 9) {
        int units = result % 10;
        int tens = result / 10;
        displayNumber(units, sDA, sDB, sDC, sDD, sDE, sDF, sDG);
        displayNumber(tens, sA, sB, sC, sD, sE, sF, sG);
      } else {
        displayNumber(result, sDA, sDB, sDC, sDD, sDE, sDF, sDG);
      }
      Serial.println(result);
    } else {
      Serial.println("Resultado demasiado grande");
    }

    delay(9000);
    clearDisplay(); 
  }
}

void displayNumber(int number, int segA, int segB, int segC, int segD, int segE, int segF, int segG) {
  switch(number) {
    case 0:
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
      break;
    case 1:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 2:
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, LOW);
      break;
    case 3:
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, LOW);
      break;
    case 4:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      break;
    case 5:
      digitalWrite(segA, LOW);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      break;
    case 6:
      digitalWrite(segA, LOW);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      break;
    case 7:
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, LOW);
      break;
    case 8:
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      break;
    case 9:
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      break;
    default:
      
      break;
  }
}

void clearDisplay() {
  digitalWrite(sA, HIGH);
  digitalWrite(sB, HIGH);
  digitalWrite(sC, HIGH);
  digitalWrite(sD, HIGH);
  digitalWrite(sE, HIGH);
  digitalWrite(sF, HIGH);
  digitalWrite(sG, HIGH);

  digitalWrite(sDA, HIGH);
  digitalWrite(sDB, HIGH);
  digitalWrite(sDC, HIGH);
  digitalWrite(sDD, HIGH);
  digitalWrite(sDE, HIGH);
  digitalWrite(sDF, HIGH);
  digitalWrite(sDG, HIGH);
}