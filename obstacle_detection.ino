int incoming = 0;

int la=8;
int lb=9;
int ra=10;
int rb=11;
int ir=7;

void setup() {
   Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);  // Assuming an LED is connected to pin 13
   pinMode(la, OUTPUT);
   pinMode(lb, OUTPUT);
   pinMode(ra, OUTPUT);
   pinMode(rb, OUTPUT);
   pinMode(ir, INPUT);
}

void loop() {
   incoming = Serial.read();  // Read the incoming byte from the serial port
   int a=digitalRead(ir);
    digitalWrite(la, HIGH);
    digitalWrite(lb, LOW);
    digitalWrite(ra, HIGH);
    digitalWrite(rb, LOW);
   if (incoming != -1) {
      if (incoming == '0'){
        digitalWrite(la, HIGH);
    digitalWrite(lb, LOW);
    digitalWrite(ra, HIGH);
    digitalWrite(rb, LOW);
      }
      if (incoming == '1') {
         digitalWrite(LED_BUILTIN, HIGH);  // Turn on LED or perform other actions
         digitalWrite(la, LOW);
         digitalWrite(lb, LOW);
         digitalWrite(ra, LOW);
         digitalWrite(rb, LOW);
         delay(100);
         digitalWrite(la, LOW);
         digitalWrite(lb, HIGH);
         digitalWrite(ra, LOW);
         digitalWrite(rb, HIGH);
         delay(500);
         digitalWrite(la, LOW);
         digitalWrite(lb, LOW);
         digitalWrite(ra, HIGH);
         digitalWrite(rb, LOW);
         delay(400);
      }
      if (a==0){
        digitalWrite(la, LOW);
         digitalWrite(lb, LOW);
         digitalWrite(ra, LOW);
         digitalWrite(rb, LOW);
         delay(100);
         digitalWrite(la, LOW);
         digitalWrite(lb, HIGH);
         digitalWrite(ra, LOW);
         digitalWrite(rb, HIGH);
         delay(500);
         digitalWrite(la, LOW);
         digitalWrite(lb, LOW);
         digitalWrite(ra, HIGH);
         digitalWrite(rb, LOW);
         delay(400);
      }
      Serial.println(incoming);  // Print the received value for debugging
   } else {
      digitalWrite(LED_BUILTIN, LOW);  // If no data is received, keep LED on
      digitalWrite(la, HIGH);
      digitalWrite(lb, LOW);
      digitalWrite(ra, HIGH);
      digitalWrite(rb, LOW);
      if (a==0){
        digitalWrite(la, LOW);
         digitalWrite(lb, LOW);
         digitalWrite(ra, LOW);
         digitalWrite(rb, LOW);
         delay(100);
         digitalWrite(la, LOW);
         digitalWrite(lb, LOW);
         digitalWrite(ra, HIGH);
         digitalWrite(rb, LOW);
         delay(100);
      }
   }

   Serial.flush();  // Ensure all data is sent
}
