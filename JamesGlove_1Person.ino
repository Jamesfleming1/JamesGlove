int startY;
int startX; 
const int xPin = A1; // Attach Accelerometer X and Y to these pins
const int yPin = A0;
const int Bpin = 2; //Attach LED to these pins
const int Fpin = 4;
const int Rpin = 7;
const int Lpin = 8;
const int sens = 20;// This will be the sensitivity of the program ready the accelerometer analog values (aka looking for values in the range of +- this value)
String direct = " ";
void setup() {
  Serial.begin(9600);
  startX = analogRead(xPin); // These are the two values that the accelerometer will be calibrated to
  startY = analogRead(yPin);
  pinMode(Fpin, OUTPUT); // Declare the LED pins as outputs
  pinMode(Bpin, OUTPUT); 
  pinMode(Lpin, OUTPUT);
  pinMode(Rpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int dataX = analogRead(xPin);
  int dataY = analogRead(yPin);
  bool South = (dataY > startY + sens);
  bool North = (dataY < startY - sens);
  bool West = (dataX > (startX + sens));
  bool East = (dataX < (startX - sens));
  if (North && not East && not West){
  direct = "N";
  Serial.print(direct);
  digitalWrite(Fpin, HIGH); // Turn on desired led and turn off the others
  digitalWrite(Bpin, LOW);
  digitalWrite(Lpin, LOW);
  digitalWrite(Rpin, LOW);
  }
  else if (South && not East && not West){
  direct = "S";
  Serial.print(direct);
  digitalWrite(Fpin, LOW); // Turn on desired led and turn off the others
  digitalWrite(Bpin, HIGH);
  digitalWrite(Lpin, LOW);
  digitalWrite(Rpin, LOW);
  }
  else if(West && not North && not South){
  direct = "W"; 
  Serial.print(direct);
  digitalWrite(Fpin, LOW); // Turn on desired led and turn off the others
  digitalWrite(Bpin, LOW);
  digitalWrite(Lpin, HIGH);
  digitalWrite(Rpin, LOW);
  }
  else if(East && not North && not South){
    direct = "E";
   Serial.print(direct);
  digitalWrite(Fpin, LOW); // Turn on desired led and turn off the others
  digitalWrite(Bpin, LOW);
  digitalWrite(Lpin, LOW);
  digitalWrite(Rpin, HIGH);
  }
  else if (North && West){
    direct = "NW";
  Serial.print(direct);
   digitalWrite(Fpin, HIGH); // Turn on desired led and turn off the others
  digitalWrite(Bpin, LOW);
  digitalWrite(Lpin, HIGH);
  digitalWrite(Rpin, LOW);
  }
  else if (North && East){
    direct = "NE";
  Serial.print(direct);
   digitalWrite(Fpin, HIGH); // Turn on desired led and turn off the others
  digitalWrite(Bpin, LOW);
  digitalWrite(Lpin, LOW);
  digitalWrite(Rpin, HIGH);
  }
  else if (South && West){
    direct = "SW";
  Serial.print(direct);
  digitalWrite(Fpin, LOW); // Turn on desired led and turn off the others
  digitalWrite(Bpin, HIGH);
  digitalWrite(Lpin, HIGH);
  digitalWrite(Rpin, LOW);
  }
  else if(South && East){
  Serial.print("SE");
  digitalWrite(Fpin, LOW); // Turn on desired led and turn off the others
  digitalWrite(Bpin, HIGH);
  digitalWrite(Lpin, LOW);
  digitalWrite(Rpin, HIGH);
  }else if (not South && not North && not West && not East){
    direct= " ";
  digitalWrite(Fpin, LOW); // Turn on desired led and turn off the others
  digitalWrite(Bpin, LOW);
  digitalWrite(Lpin, LOW);
  digitalWrite(Rpin, LOW);
  
  }
  delay(20);
}
