//https://labs.mediatek.com/fileMedia/download/87c801b5-d1e6-4227-9a29-b5421f2955ac#nameddest=ConfigTools
//python  /IoT/Arduino_7688/SerialExecSysCommand.py  >  /dev/ttyS0
void setup() {
  Serial.begin(57600); // open serial connection to USB Serial port(connected to your computer)
  Serial1.begin(57600); // open internal serial connection to MT7688AN
  // in MT7688AN, this maps to device

}
void loop() {
   if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }
}

