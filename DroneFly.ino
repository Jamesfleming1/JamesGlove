#include <SPI.h> // we need this library
byte rotation = B00000000; // addresses of the digital potentiometers
byte  altitude= B00010000;
int CS= 10; //chip select pin
int startY; // defining variables for the accelerometer 
int startX;
const int yPin = A0;
const int xPin = A1;
const int sens = 20;
int resistX = 512/2; // initial resistances
int resistY = 512/2; 
void setup()
{
startY = analogRead(yPin); // get an initial reading of the
startX = analogRead(xPin);// accelerometer values
pinMode (CS, OUTPUT); // select the chips 
SPI.begin(); // Start the Serial Peripheral Interface aka
// How we communicate to the digital potentiometer chips
Serial.begin(9600);
}
void loop()
{
int dataY = analogRead(yPin); // check the new values of the accelerometer
int dataX = analogRead(xPin);
bool UP = (dataY < startY -sens); // find the difference of initial value vs current value to see
bool RIGHT = (dataX< startX-sens);// if the accelerometer has been tilted
bool DOWN = (dataY > startY + sens); // and in what direction
bool LEFT = (dataX > (startX +sens));

// Checking to see which direction the hand is tilted and changing our resistance accordingly
if (resistY < 512 ){if (UP){resistY+=1;}} 
if (resistY > 0){if (DOWN){resistY-=1;}} 
if (resistX < 512){if (LEFT){resistX+=1;}}
if (resistX >0){if (RIGHT){resistX-=1;}}
//mapping our larger range of values to a smaller range for the digital pot
int resistyy = map(resistY, 0, 512, 0, 128);
int resistxx = map(resistX, 0, 512, 0, 128);
Serial.print(resistyy);
// outputting our desired resistance to the appropriate chip
digitalPotWrite(resistyy, altitude); 
digitalPotWrite(resistxx, rotation);
//digitalPotWrite(100, altitude);
//digitalPotWrite(100, altitude);

}
int digitalPotWrite(int value, byte address) 
{ // a function for delivering information to the digital pots
digitalWrite(CS, LOW);
SPI.transfer(address);
SPI.transfer(value);
digitalWrite(CS, HIGH);
}
