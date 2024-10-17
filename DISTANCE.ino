// Ultrasonic sensor variable
const int trigPin = 9, echoPin = 10;
float duration, distance;

//  MIDI Potentiometer variables
const int potPin = A0;

int potValue = 0;

// Button variables
const int buttonPin = 2;
int buttonState;



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buttonPin, INPUT_PULLUP);
  
  pinMode(potPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  /**************************** ULTRASONIC ****************************/

  // Ensure that the trigger pin is low.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10us so the echo pin can measure it below.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // The duration it takes for the echo pin to detect the pulse
  // will represent the distance of an object based on the speed
  // of sound (0.0343).
  // We account for the sound traveling to the colliding
  // surface and back by scaling distance by half.
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 * 0.5;

  Serial.print("Distance: "); // Header
  Serial.println(distance);   // Value

  /**************************** BUTTON ****************************/

  buttonState = digitalRead(buttonPin);

  Serial.print("Button: "); // Header
  Serial.println(buttonState);   // Value

  /**************************** POTENTIOMETER ****************************/
  potValue = analogRead(potPin);

  Serial.print("Pot: ");
  Serial.println(potValue);



  // Slow down data stream
  delay(50);
}
