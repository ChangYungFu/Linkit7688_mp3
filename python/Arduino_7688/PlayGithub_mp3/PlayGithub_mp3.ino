//https://labs.mediatek.com/fileMedia/download/87c801b5-d1e6-4227-9a29-b5421f2955ac#nameddest=ConfigTools
//yunbridge 必須禁止 disable
//python  /IoT/Arduino_7688/SerialExecSysCommand.py  >  /dev/ttyS0
String Music1 = "curl -k https://raw.githubusercontent.com/ChangYungFu/Audio/master/";
String Music2 = "0030_我可能不會愛你.mp3";
String Music3 = " |  madplay - -a+5 -o wave:-  | aplay -D  plughw:1";
String Music ;

void setup() {
  Serial.begin(57600); // open serial connection to USB Serial port(connected to your computer)
  Serial1.begin(57600); // open internal serial connection to MT7688AN
  // in MT7688AN, this maps to device
  Music2 = urlencode(Music2);
  Music2.replace("%2E", ".");
  Music = Music1 + Music2 + Music3;
  Serial1.print(Music); Serial1.print("\n");
}
void loop() {

  if (Serial.available()) {
    char ch = Serial.read();
    if (ch == 's') {
      Serial1.print("killall curl");
      Serial1.print("\n");
    }
    else {
      switch (ch) {
        //http://meyerweb.com/eric/tools/dencoder/
        case '0': Music2 = "0006_土耳其進行曲.mp3"; break;
        case '1': Music2 = "0007_三寸天堂.mp3"; break;
        case '2': Music2 = "0013_其實你不懂我的心(童安格).mp3"; break;
        case '3': Music2 = "0008_下一个天亮.mp3"; break;
        case '4': Music2 = "0010_世紀情歌2-許茹芸-如果雲知道-1.mp3"; break;
        case '5': Music2 = "0016_台語歌曲-江蕙-落雨聲.mp3"; break;
        case '6': Music2 = "0022_四十一歲的席琳狄翁 - YouTube (Audio).mp3"; break;
        case '8': Music2 = "0029_恰似你的温柔.mp3"; break;
        case '9': Music2 = "0030_我可能不會愛你.mp3"; break;
      }
      Music2 = urlencode(Music2);
      Music2.replace("%2E", ".");//％2Emp3==>錯誤，因此=>.mp3 OK
      Music = Music1 + Music2 + Music3;
      Serial1.print(Music); Serial1.print("\n");
    }
  }
  //------------------------------------------------
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
}
//https://github.com/zenmanenergy/ESP8266-Arduino-Examples/blob/master/helloWorld_urlencoded/urlencode.ino
String urldecode(String str)
{
  String encodedString = "";
  char c;
  char code0;
  char code1;
  for (int i = 0; i < str.length(); i++) {
    c = str.charAt(i);
    if (c == '+') {
      encodedString += ' ';
    } else if (c == '%') {
      i++;
      code0 = str.charAt(i);
      i++;
      code1 = str.charAt(i);
      c = (h2int(code0) << 4) | h2int(code1);
      encodedString += c;
    } else {

      encodedString += c;
    }

    yield();
  }

  return encodedString;
}

String urlencode(String str)
{
  String encodedString = "";
  char c;
  char code0;
  char code1;
  char code2;
  for (int i = 0; i < str.length(); i++) {
    c = str.charAt(i);
    if (c == ' ') {
      encodedString += '+';
    } else if (isalnum(c)) {
      encodedString += c;
    } else {
      code1 = (c & 0xf) + '0';
      if ((c & 0xf) > 9) {
        code1 = (c & 0xf) - 10 + 'A';
      }
      c = (c >> 4) & 0xf;
      code0 = c + '0';
      if (c > 9) {
        code0 = c - 10 + 'A';
      }
      code2 = '\0';
      encodedString += '%';
      encodedString += code0;
      encodedString += code1;
      //encodedString+=code2;
    }
    yield();
  }
  return encodedString;

}

unsigned char h2int(char c)
{
  if (c >= '0' && c <= '9') {
    return ((unsigned char)c - '0');
  }
  if (c >= 'a' && c <= 'f') {
    return ((unsigned char)c - 'a' + 10);
  }
  if (c >= 'A' && c <= 'F') {
    return ((unsigned char)c - 'A' + 10);
  }
  return (0);
}

