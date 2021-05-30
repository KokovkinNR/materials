int a = 0;
int b = 0;
int c = 0;
int d = 0;

unsigned long nowTime;
unsigned long preTime;


void MyClock() {
  Serial.println('\t');
  Serial.print("|");
  Serial.print(a);
  Serial.print("|");
  Serial.print(b);
  Serial.print("|");
  Serial.print(":");
  Serial.print("|");
  Serial.print(c);
  Serial.print("|");
  Serial.print(d);
  Serial.print("|");
}

void Clock() {    //  | - | - | - | Clock | - | - | - |
  ++d;
  if (d == 10) {
    d = 0;
    ++c;
  }
  if (c == 6) {
    c = 0;
    d = 0;
    ++b;
  }
  if (b == 9) {
    c = 0;
    d = 0;
    b = 0;
    ++a;
  }
  if (a == 2) {
    d = 0;
    c = 0;
    b = 0;
    a = 0;
  }

}

void Rank(int r) {

  int x = r % 100 - r % 10;
  int y = r % 1000 - x;


  a = r / 1000;
  b = y / 100 ;
  c = x / 10;
  d = r % 10;


  Serial.println('\t');
  Serial.print("|");
  Serial.print(a);
  Serial.print("|");
  Serial.print(b);
  Serial.print("|");
  Serial.print(":");
  Serial.print("|");
  Serial.print(c);
  Serial.print("|");
  Serial.print(d);
  Serial.print("|");
}

void setup() {
  Serial.begin(115200);
}
void loop() {
  nowTime = millis();
  if (nowTime - preTime == 1000) {
    preTime = nowTime;
    //    Clock();
    //    MyClock();
    Rank(2568);
  }
}
