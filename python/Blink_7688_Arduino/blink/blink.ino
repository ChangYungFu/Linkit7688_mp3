//https://labs.mediatek.com/fileMedia/download/87c801b5-d1e6-4227-9a29-b5421f2955ac#nameddest=ConfigTools
void setup() {
  Serial.begin(115200); // open serial connection to USB Serial port(connected to your computer)
  Serial1.begin(57600); // open internal serial connection to MT7688AN
  // in MT7688AN, this maps to device
  pinMode(13, OUTPUT);
}
void loop() {
  int c = Serial1.read(); // read from MT7688AN
  if (c != -1) {
    switch (c) {
      case '0': // turn off D13 when receiving "0"
        digitalWrite(13, 0);
        Serial.println("turn off D13 when receiving 0");
        break;
      case '1': // turn off D13 when receiving "1"
        digitalWrite(13, 1);
        Serial.println("turn on D13 when receiving 1");
        break;
    }
  }
}

