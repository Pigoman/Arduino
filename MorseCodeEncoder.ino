/* Arduino Morse Code Encoder
 * 
 * Sean Curran
 * 
 * This sketch is intended to have an Arduino Uno act as a morse code encoder
 * The words to be encoded will be entered in the Serial communication on the
 * computer connected to the Arduino and the Arduino will activate a LED and
 * a small speaker to translate the words to morse code.
 */

// Declare Constants
const int SERIAL_RATE = 9600;
const int LED = 13;
const int SPEAKER = 11;
const int TIME_UNIT = 200;
const int SPEAKER_PITCH = 3000; // in hertz 5587 <- for buzzer

// Declare variables
char theMessage;

// put your setup code here, to run once:
void setup() {
  // Set pins for LED and speaker
  pinMode(LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  
  // Connect to USB serial connection
  Serial.begin(SERIAL_RATE);

  // Wait for connection
  while(!Serial)
  {
    // Wait one half of a second for connection
    delay(500);
  }

  // Connection is established
  Serial.print("Serial Connection Established at ");
  Serial.print(SERIAL_RATE, DEC);
  Serial.println("bps");
}

// put your main code here, to run repeatedly:
void loop() {
  // If serial is disconnected, end sketch
  if(!Serial)
  {
    digitalWrite(LED, HIGH);
    return;
  }

  theMessage = Serial.read();

  if(theMessage != -1) {
    Serial.println(theMessage);
    theMessage = tolower(theMessage);
    switch(theMessage) {
      case 'a': a(); break;
      case 'b': b(); break;
      case 'c': c(); break;
      case 'd': d(); break;
      case 'e': e(); break;
      case 'f': f(); break;
      case 'g': g(); break;
      case 'h': h(); break;
      case 'i': i(); break;
      case 'j': j(); break;
      case 'k': k(); break;
      case 'l': l(); break;
      case 'm': m(); break;
      case 'n': n(); break;
      case 'o': o(); break;
      case 'p': p(); break;
      case 'q': q(); break;
      case 'r': r(); break;
      case 's': s(); break;
      case 't': t(); break;
      case 'u': u(); break;
      case 'v': v(); break;
      case 'w': w(); break;
      case 'x': x(); break;
      case 'y': y(); break;
      case 'z': z(); break;
      case '1': one(); break;
      case '2': two(); break;
      case '3': three(); break;
      case '4': four(); break;
      case '5': five(); break;
      case '6': six(); break;
      case '7': seven(); break;
      case '8': eight(); break;
      case '9': nine(); break;
      case '0': zero(); break;
      case ' ': space(); break;
      default: Serial.println("^ Invalid Character"); space(); break;
    }
  }
}

// Dot for Morse code
void dot() {
  digitalWrite(LED, HIGH);
  tone(SPEAKER, SPEAKER_PITCH);
  delay(TIME_UNIT);
  digitalWrite(LED, LOW);
  noTone(SPEAKER);
  delay(TIME_UNIT);
}

// Dash for Morse code
void dash() {
  digitalWrite(LED, HIGH);
  tone(SPEAKER, SPEAKER_PITCH);
  delay(3 * TIME_UNIT);
  digitalWrite(LED, LOW);
  noTone(SPEAKER);
  delay(3 * TIME_UNIT);
}

// End of letter
void endLetter() {
  delay(3 * TIME_UNIT);
}

// End of word
void space() {
  delay(7 * TIME_UNIT);
}

// Letters
void a() {
  dot(); dash();
  endLetter();
}

void b() {
  dash(); dot(); dot(); dot();
  endLetter();
}

void c() {
  dash(); dot(); dash(); dot();
  endLetter();
}

void d() {
  dash(); dot(); dot();
  endLetter();
}

void e() {
  dot();
  endLetter();
}

void f() {
  dot(); dot(); dash(); dot();
  endLetter();
}

void g() {
  dash(); dash(); dot();
  endLetter();
}

void h() {
  dot(); dot(); dot(); dot();
  endLetter();
}

void i() {
  dot(); dot();
  endLetter();
}

void j() {
  dot(); dash(); dash(); dash();
  endLetter();
}

void k() {
  dash(); dot(); dash();
  endLetter();
}

void l() {
  dot(); dash(); dot(); dot();
  endLetter();
}

void m() {
  dash(); dash();
  endLetter();
}

void n() {
  dash(); dot();
  endLetter();
}

void o() {
  dash(); dash(); dash();
  endLetter();
}

void p() {
  dot(); dash(); dash(); dot();
  endLetter();
}

void q() {
  dash(); dash(); dot(); dash();
  endLetter();
}

void r() {
  dot(); dash(); dot();
  endLetter();
}

void s() {
  dot(); dot(); dot();
  endLetter();
}

void t() {
  dash();
  endLetter();
}

void u() {
  dot(); dot(); dash();
  endLetter();
}

void v() {
  dot(); dot(); dot(); dash();
  endLetter();
}

void w() {
  dot(); dash(); dash();
  endLetter();
}

void x() {
  dash(); dot(); dot(); dash();
  endLetter();
}

void y() {
  dash(); dot(); dash(); dash();
  endLetter();
}

void z() {
  dash(); dash(); dot(); dot();
  endLetter();
}

void one() {
  dot(); dash(); dash(); dash(); dash();
  endLetter();
}

void two() {
  dot(); dot(); dash(); dash(); dash();
  endLetter();
}

void three() {
  dot(); dot(); dot(); dash(); dash();
  endLetter();
}

void four() {
  dot(); dot(); dot(); dot(); dash();
  endLetter();
}

void five() {
  dot(); dot(); dot(); dot(); dot();
  endLetter();
}

void six() {
  dash(); dot(); dot(); dot(); dot();
  endLetter();
}

void seven() {
  dash(); dash(); dot(); dot(); dot();
  endLetter();
}

void eight() {
  dash(); dash(); dash(); dot(); dot();
  endLetter();
}

void nine() {
  dash(); dash(); dash(); dash(); dot();
  endLetter();
}

void zero() {
  dash(); dash(); dash(); dash(); dash();
  endLetter();
}
