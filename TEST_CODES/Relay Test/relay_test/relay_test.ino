#define LED1 4
#define LED2 5
#define LED3 6
#define LED4 7
#define LED5 8
#define LED6 9
#define LED7 10
#define LED8 11
#define LED9 12
#define LED10 13

void setup() {
  Serial.begin(9600); // Initialize Serial
  // initial output pins
  int LED_out = 4;
  for(LED_out; LED_out <= 13; LED_out++){
    pinMode(LED_out, OUTPUT);
  }
  

}

void loop() {
  // put your main code here, to run repeatedly: 
  char input;
  while(Serial.available() > 0){
  input = Serial.read();
  }
  switch(input){
    case 'a':
      digitalWrite(LED1, HIGH);
      break;
    case 's':
      digitalWrite(LED2, HIGH);
      break;
    case 'd':
      digitalWrite(LED3, HIGH);
      break;
    case 'f':
      digitalWrite(LED4, HIGH);
      break;
    case 'g':
      digitalWrite(LED5, HIGH);
      break;
    case 'h':
      digitalWrite(LED6, HIGH);
      break;
    case 'j':
      digitalWrite(LED7, HIGH);
      break;
    case 'k':
      digitalWrite(LED8, HIGH);
      break;
    case 'l':
      digitalWrite(LED9, HIGH);
      break;
    case ';':
      digitalWrite(LED10, HIGH);
      break;
    case 'z':
      digitalWrite(LED1, LOW);
      break;
    case 'x':
      digitalWrite(LED2, LOW);
      break;
    case 'c':
      digitalWrite(LED3, LOW);
      break;
    case 'v':
      digitalWrite(LED4, LOW);
      break;
    case 'b':
      digitalWrite(LED5, LOW);
      break;
    case 'n':
      digitalWrite(LED6, LOW);
      break;
    case 'm':
      digitalWrite(LED7, LOW);
      break;
    case ',':
      digitalWrite(LED8, LOW);
      break;
    case '.':
      digitalWrite(LED9, LOW);
      break;
    case '/':
      digitalWrite(LED10, LOW);
      break;
    default:
      Serial.println("Not an valid input");
  }
}
