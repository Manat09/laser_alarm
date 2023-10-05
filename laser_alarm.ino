int photoresistorPin = A0; 
int threshold = 950;
int buzzerPin = 3;
const int buttonPin = 2;
int buttonState = 0;
const int buttonPin2 = 4;
int buttonState2 = 0;
int check = 1;
int flag = 0;

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int photoresistorValue = analogRead(photoresistorPin);
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  Serial.print(photoresistorValue);
  
  if (photoresistorValue < threshold || flag == 1) {
    flag = 1;
      if(check == 1){
        tone (buzzerPin, 1200);
        delay(300);
        noTone(buzzerPin);
        delay(200);
      }
    Serial.print("  Проход обнаружен!");
  }
  
  Serial.print(" ");
  Serial.print(buttonState);
  Serial.print(" ");
  Serial.print(buttonState2);
  Serial.print("\n");

  
  if (buttonState == HIGH) {
      check = 0;
      flag = 0;
      noTone(buzzerPin);
  }
  
  if (buttonState2 == HIGH) {
      check = 1;
      flag = 0;
  }

  
  delay(100);
}
