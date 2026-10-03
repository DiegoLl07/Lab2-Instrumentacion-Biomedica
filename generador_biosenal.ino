const int pwmPin = 9;       // Pin que genera la señal
const int analogPin = A0;   // Pin que lee la señal del nodo sumador
const float freq = 2.0;     // Frecuencia de 2 Hz

void setup() {
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600);       // Inicio del Serial Plotter
}

void loop() {
  unsigned long currentMillis = millis();
  float t = currentMillis / 1000.0;
  int pwmValue = (sin(2 * PI * freq * t) + 1.0) * 60; 
  analogWrite(pwmPin, pwmValue);
  
  // Leemos el nodo sumador desde el pin A0
  int rawValue = analogRead(analogPin);
  
  // Convertimos el valor digital (0-1023) a voltaje real (0-5V)
  float voltage = rawValue * (5.0 / 1023.0);
  
  // Envía el voltaje final al Serial Plotter
  Serial.println(voltage);
  delay(10); 
}