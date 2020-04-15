

//Constantes
const float vout0 = 400;   //  Voltaje de salida del sensor en mV a 0°C
const float tc = 19.53;   // mV por °C MCP9701/A

// Variables
int i, f;
float vout, vout_avg, ta;


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);           
  analogReference(DEFAULT);
}

void loop() {
  vout_avg = 0;
  for (i = 0; i < 1024; i++) {                    //Ciclo para obtener promedio
    vout = analogRead(A0) * (4976.30 / 1023);
    vout_avg = vout_avg + vout;
  }
  vout = vout_avg / 1024;
  ta = (vout - vout0) / tc;
  Serial.print("Temperatura(C) = " );
  Serial.println(ta);
  delay (1000);
}
