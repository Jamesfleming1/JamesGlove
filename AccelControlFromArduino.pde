import processing.serial.*;
Serial myPort;
String val;
int x = 100;
int y= 100;
int speed = 2;

void setup(){
  size(500, 500);
  String portName = Serial.list()[1];
  print(portName);
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}
void serialEvent(Serial myPort){
  
  val = myPort.readString();
  if (val != null){
    val = trim(val);
    
    if(val.equals("N")){ // CHECKING THE SERIAL PRINT WARNING IT IS VERY IMPORTANT TO USE EQUALS() NOT ==
      y-=speed;
    }
    if(val.equals( "S")){
      y+=speed;
    }
    if(val.equals( "E")){
      x+=speed;
    }
    if (val.equals("W")){
      x-=speed;
    }
    if (val.equals( "NW")){
      y-=speed;
      x-=speed;
    }
    if (val.equals("NE")){
      y-=speed;
      x+=speed;
    }
    if (val.equals("SW")){
      y+=speed;
      x-=speed;
    }
    if (val.equals("SE")){
      y+=speed;
      x+=speed;
    }
    
  }
}
void draw(){
  background(#ffffff);
  rect(x,y , 50, 50);
  serialEvent(myPort);
}