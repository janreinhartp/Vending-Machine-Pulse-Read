// Declaration for bill Acceptor
unsigned int currentAmount = 0; 
volatile unsigned long time = 0;
volatile unsigned long durationSet = 20; // Timer for the Pulse
int sensor = 2;

void setup() {
    pinMode(sensor, INPUT_PULLUP); // Setup pin for Bill Acceptor
    attachInterrupt(digitalPinToInterrupt(sensor), pulseRead, CHANGE); // Call interrupt function for Bill Acceptor
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(100);
}

// Bill Acceptor Pulse Read Function
void pulseRead(){
    if ((millis() - time) > durationSet)
    {
        if(!digitalRead(sensor))
        {
            currentAmount = currentAmount +10;
           Serial.print("Credit:");
           Serial.println(currentAmount);
        }
        time = millis();
    }
}
