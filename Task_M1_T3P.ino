//Kanika Kukreja
//2110994766
// C++ code

//Defining some variables 
float temp;
float tempC = 0;
float tempF = 0;
int buzzer = 7;
int interruptPin = 2; 
const int pirPin = 3;

void setup()
{
  pinMode(A0, INPUT);//defining pin mode A0 of temerature sensor as an input
  pinMode(buzzer, OUTPUT);//defining the buzzer pin as an output pin
  pinMode (pirPin, INPUT);//defining the motion senor pin
  
  Serial.begin(9600);//beginning the serial communication

  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pirPin), motioninterrupt, CHANGE);
}

void loop()
{
  temp = analogRead(A0);
  temp =((temp*5)/1024);
  tempC = ((temp-0.5)*100);
  tempF = ((tempC)* 9/5 + 32);
  Serial.print("Temperature = ");
  Serial.print(tempC);
  Serial.print(" C , ");
  Serial.print(tempF);
  Serial.println(" F ");
  Serial.println("Motion Detected");
}

void interruptFunction()
{
  if (temp <=22)
  {
    noTone(buzzer);
    delay(1000);
  }
  if (temp >= 18 && temp <= 22)
  {
    noTone(buzzer);
    delay(1000);
  }
  if (temp > 23)
  {
    tone(7, 1000);
    delay(200);
  }
}

void motioninterrupt()
{
  
}
