int cm;
 
long read_Sensor(int trigger_pin, int echo_pin)
{
pinMode(trigger_pin, OUTPUT);
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  pinMode(echo_pin, INPUT);
  return pulseIn(echo_pin, HIGH);
}
 
void setup()
{
  Serial.begin(9600);
  pinMode(12,OUTPUT);
}
 
void loop()
{
cm = 0.01723 * read_Sensor(7,7);
Serial.print("Distance : ");
Serial.println(cm);
if(cm<50)
{
  digitalWrite(12,LOW);
}
  else
  {
    digitalWrite(12,HIGH);
  }
}
