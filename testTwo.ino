
#define extraTimeStep 2
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int out1=8;
int out2=9;
int out3=10;
int out4=11;


int voltIn=A0;                //
int c1In=A1;              //
int c2In=A2;                //
int c3In=A3;              //
int c4In=A4;                //
int tempSensor=A5;
char ahmad[80]={0};
/////////////////////////////////
int voltValue;
float c1Value;
float c2Value;
float c3Value;
float c4Value;

float p1Value;
float p2Value;
float p3Value;
float p4Value;
/////////////////////////////////////////
int serialRead;


int tempValue;

int loopTick;                          //
/////////////////////////////////////////
long interval = 1000;           // interval at which to blink (milliseconds)
long previousMillis = 0;        // will store last time LED was updated
////////////////////////////////////////////////////
void setup() 
{
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
////////////////////////////////////
  digitalWrite(out1,HIGH);        //
  digitalWrite(out2,HIGH);        //
  digitalWrite(out3,HIGH);        //
  digitalWrite(out4,HIGH);        //
///////////////////////////////////////////////////  

}
void loop() 
{
///////////////////////////////////////////////////////////////////////////////  
  voltValue = (analogRead(voltIn)* 48)/100; /////
  c1Value   = (float)(analogRead(c1In)*0.4882)/100;       ////
  c2Value   = (float)(analogRead(c2In)*0.4882)/100;   /////
  c3Value   = (float)(analogRead(c3In)*0.4882)/100;       ////
  c4Value   = (float)(analogRead(c4In)*0.4882)/100;   /////

  tempValue   = (float)(analogRead(tempSensor)*0.4882);   /////


p1Value=(float)(voltValue*c1Value);
p2Value=(float)(voltValue*c2Value);
p3Value=(float)(voltValue*c3Value);
p4Value=(float)(voltValue*c4Value);
 

delay(1000);
Serial.print(" ");
Serial.print(p1Value);
Serial.print(" ");
Serial.print(p2Value);
Serial.print(" ");
Serial.print(p3Value);
Serial.print(" ");
Serial.print(p4Value);
Serial.print(" ");
Serial.println();


/////////-Interupt Delay-//////////////////////////////////////////////////////
 // unsigned long currentMillis = millis();                                    //
 // if(currentMillis - previousMillis > interval)                              //
 // {                                                                          //
  //  previousMillis = currentMillis;                                          //
 
Serial.println("///////////////////////////////////////////");  
Serial.print("Temperature :");Serial.println(tempValue);
Serial.println("///////////////////////////////////////////");
Serial.print("Wapda Volt :");Serial.println(voltValue);
Serial.print("Load 1     :");Serial.println(c1Value);
Serial.print("Load 2     :");Serial.println(c2Value);
Serial.print("Load 3     :");Serial.println(c3Value);
Serial.print("Load 4     :");Serial.println(c4Value);
Serial.println("///////////////////////////////////////////");
Serial.print("Power 1  (Watts)    :");Serial.println(p1Value/10);
Serial.print("Power 2  (Watts)   :");Serial.println(p2Value);
Serial.print("Power 3  (Watts)   :");Serial.println(p3Value);
Serial.print("Power 4  (Watts)  :");Serial.println(p4Value/10);



delay(1000);
//}

 if (Serial.available() > 0) 
 {
 
serialRead=Serial.read();
 
 switch(serialRead)
 {
 case 'a':Serial.println("Device 1 ON ");digitalWrite(out1,LOW);break;
 case 'b':Serial.println("Device 1 OFF");digitalWrite(out1,HIGH);break;
 case 'c':Serial.println("Device 2 ON ");digitalWrite(out2,LOW);break;
 case 'd':Serial.println("Device 2 OFF");digitalWrite(out2,HIGH);break;
 case 'e':Serial.println("Device 3 ON ");digitalWrite(out3,LOW);break;
 case 'f':Serial.println("Device 3 OFF");digitalWrite(out3,HIGH);break;
 case 'g':Serial.println("Device 4 ON ");digitalWrite(out4,LOW);break;
 case 'h':Serial.println("Device 4 OFF");digitalWrite(out4,HIGH);break;
 case 'i':digitalWrite(out1,LOW);digitalWrite(out2,LOW);digitalWrite(out3,LOW);digitalWrite(out4,LOW);break;
 case 'j':Serial.println("Device All OFF");digitalWrite(out1,HIGH);digitalWrite(out2,HIGH);digitalWrite(out3,HIGH);digitalWrite(out4,HIGH);break;
 
 
 
 }
 
 
 }
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////////////////////


