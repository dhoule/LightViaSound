int num_Measure = 128 ; // Set the number of measurements   
int pinSignal = A0; // pin connected to pin O module sound sensor
int ldrPin = A1; // pin for light determination
int ne555 = 3;  //attach to the third pin of NE555
long Sound_signal;    // Store the value read Sound Sensor
int ldrStatus; // Store value read from LDR   
long sum = 0 ; // Store the total value of n measurements   
long level = 0 ; // Store the average value   
int soundlow = 80; // average size dog barks at “120 db and 500 Hz.” normal human conversation is about 60 dB

 
void setup () {   
  pinMode (pinSignal, INPUT); // Set the signal pin as input   
  pinMode(ne555, OUTPUT);  //set the ne555 as an output
  pinMode(ldrPin, INPUT); // set the LDR pin as input
//  Serial.begin (9600); 
}  
   
void loop () { 
  ldrStatus = analogRead(ldrPin);
//  Serial.print("Light Level: ");
//  Serial.println (ldrStatus); 
  if (ldrStatus <= 40) {
    // Performs 128 signal readings   
    for ( int i = 0 ; i <num_Measure; i ++) {  
      Sound_signal = analogRead (pinSignal);  
      sum =sum + Sound_signal;  
    }  
   
    level = (sum / num_Measure) - 33; // Calculate the average value   
//    Serial.print("Sound Level: ");
//    Serial.println (level); 

    if(level>soundlow) {
//      Serial.println("Intensity= Medium");
      digitalWrite(ne555, HIGH);
      delay(3000);
      digitalWrite(ne555, LOW); 
    }
    sum = 0 ; // Reset the sum of the measurement values  
  }
  delay(2000);
}
