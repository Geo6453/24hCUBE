const int VRx = 3;
const int VRy = 2;
const int joystick = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(21, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(joystick, INPUT_PULLUP);
}

void loop()
{
  
  if (digitalRead(21) == LOW)
    Serial.println("Le bouton Rouge est appuyé");
  if (digitalRead(20) == LOW)
    Serial.println("Le bouton Bleu est appuyé");
  if (digitalRead(8) == LOW)
    Serial.println("Le bouton Vert est appuyé");
  if (digitalRead(9) == LOW)
    Serial.println("Le bouton Jaune est appuyé");
  if (digitalRead(10) == LOW)
    Serial.println("Le bouton Blanc est appuyé");
    int xVal = analogRead(VRx);
    int yVal = analogRead(VRy);
    //bool buttonPressed = digitalRead(joystick) == LOW;

    Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Y: ");
  Serial.println(yVal);

  delay(1000);

}
