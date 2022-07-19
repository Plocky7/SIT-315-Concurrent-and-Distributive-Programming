// M1.T1P
// Components
int LED1 = 13;
int PIR1 = 2;

// init vars
int state = LOW;
int val  = 0;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(PIR1, INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(PIR1); //val == motion sensor output
  if (val == HIGH)
  {
    digitalWrite(LED1, HIGH);
    delay(1000);

    if (state == LOW)
    {
      Serial.println("Motion Detected");
      state = HIGH;
    }
  }

  else
  {
    digitalWrite(LED1, LOW);

    if (state == HIGH)
    {
      Serial.println("No Motion");
      state = LOW;
    }
  }
}
