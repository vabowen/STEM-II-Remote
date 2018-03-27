// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!
 
int IRledPin =  13;    // LED connected to digital pin 13
const int buttonPin = 3;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

// The setup() method runs once, when the sketch starts
 
void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
   Serial.begin(9600);

}
 
void loop()                     
{
  Serial.println("Sending IR signal");
  buttonState = digitalRead(buttonPin);
  Serial.print(buttonState);
  if (buttonState == LOW) {
  SendChannelUpCode();
  delay(100);  // wait twenty seconds (20 seconds * 1000 milliseconds)
  }
}
 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void SendChannelUpCode() {
  // This is the code for the CHANNEL + for the downstairs TV COMCAST
  delayMicroseconds(53064); //Time off (Left Column on serial monitor)
  pulseIR(9200);           //Time on  (Right Column on serial monitor)
  delayMicroseconds(4560);
  pulseIR(520);
  delayMicroseconds(2280);
  pulseIR(500);
  delayMicroseconds(4560);
  pulseIR(520);
  delayMicroseconds(2280);
  pulseIR(500);
  delayMicroseconds(4580);
  pulseIR(520);
  delayMicroseconds(2280);
  pulseIR(500);
  delayMicroseconds(2280);
  pulseIR(520);
  delayMicroseconds(2280);
  pulseIR(520);
  delayMicroseconds(2260);
  pulseIR(520);
  delayMicroseconds(2280);
  pulseIR(520);
  delayMicroseconds(2280);
  pulseIR(500);
  delayMicroseconds(2300);
  pulseIR(500);
  delayMicroseconds(2280);
  pulseIR(520);
  delayMicroseconds(2280);
  pulseIR(500);
  delayMicroseconds(4580);
  pulseIR(520);
  delayMicroseconds(4560);
  pulseIR(500);
  delayMicroseconds(2300);
  pulseIR(500);
  delayMicroseconds(34600);
  pulseIR(9200);
  delayMicroseconds(2260);
  pulseIR(520);
}

void IR_CSV_WRITE() {
  
}

