// Program to send the Morse code of given message using buzzer
// BUZZER: direction matters. long leg (anode) goes to positive.
// Ciruit Diagram: placed in same folder.

// message to be sent
String message = "Skand Kulshrestha";

// buzzer connection
#define BUZZER 8

// unit time duration
#define UNIT_TIME 100

// time durations for different gaps
#define SHORT_MARK_TIME (1 * UNIT_TIME)           // dit duration
#define LONG_MARK_TIME (3 * UNIT_TIME)            // dah duration
#define INTER_ELEMENT_GAP (1 * UNIT_TIME)         // gap between consecutive dit/dah
#define SHORT_GAP (3 * UNIT_TIME)                 // gap between consecutive letter
#define MEDIUM_GAP (7 * UNIT_TIME)                // gap between consecutive word

void dit(int pin)
{
  digitalWrite(pin, HIGH);
  delay(SHORT_MARK_TIME);
}

void dah(int pin)
{
  digitalWrite(pin, HIGH);
  delay(LONG_MARK_TIME);
}

void dit_gap(int pin)
{
  digitalWrite(pin, HIGH);
  delay(SHORT_MARK_TIME);
  digitalWrite(pin, LOW);
  delay(INTER_ELEMENT_GAP);
}

void dah_gap(int pin)
{
  digitalWrite(pin, HIGH);
  delay(LONG_MARK_TIME);
  digitalWrite(pin, LOW);
  delay(INTER_ELEMENT_GAP);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < message.length(); i++)
  {
    // get character from message and play sequence of dit(s)/dah(s) associated with it
    switch(message.charAt(i))
    {
      case ' ': digitalWrite(BUZZER, LOW); delay(MEDIUM_GAP); break;
      case 'A': case 'a': dit_gap(BUZZER); dah(BUZZER); break;
      case 'B': case 'b': dah_gap(BUZZER); dit_gap(BUZZER); dit_gap(BUZZER); dit(BUZZER); break;
      case 'C': case 'c': dah_gap(BUZZER); dit_gap(BUZZER); dah_gap(BUZZER); dit(BUZZER); break;
      case 'D': case 'd': dah_gap(BUZZER); dit_gap(BUZZER); dit(BUZZER); break;
      case 'E': case 'e': dit(BUZZER); break;
      case 'F': case 'f': dit_gap(BUZZER); dit_gap(BUZZER); dah_gap(BUZZER); dit(BUZZER); break;
      case 'G': case 'g': dah_gap(BUZZER); dah_gap(BUZZER); dit(BUZZER); break;
      case 'H': case 'h': dit_gap(BUZZER); dit_gap(BUZZER); dit_gap(BUZZER); dit(BUZZER); break;
      case 'I': case 'i': dit_gap(BUZZER); dit(BUZZER); break;
      case 'J': case 'j': dit_gap(BUZZER); dah_gap(BUZZER); dah_gap(BUZZER); dah(BUZZER); break;
      case 'K': case 'k': dah_gap(BUZZER); dit_gap(BUZZER); dah(BUZZER); break;
      case 'L': case 'l': dit_gap(BUZZER); dah_gap(BUZZER); dit_gap(BUZZER); dit(BUZZER); break;
      case 'M': case 'm': dah_gap(BUZZER); dah(BUZZER); break;
      case 'N': case 'n': dah_gap(BUZZER); dit(BUZZER); break;
      case 'O': case 'o': dah_gap(BUZZER); dah_gap(BUZZER); dah(BUZZER); break;
      case 'P': case 'p': dit_gap(BUZZER); dah_gap(BUZZER); dah_gap(BUZZER); dit(BUZZER); break;
      case 'Q': case 'q': dah_gap(BUZZER); dah_gap(BUZZER); dit_gap(BUZZER); dah(BUZZER); break;
      case 'R': case 'r': dit_gap(BUZZER); dah_gap(BUZZER); dit(BUZZER); break;
      case 'S': case 's': dit_gap(BUZZER); dit_gap(BUZZER); dit(BUZZER); break;
      case 'T': case 't': dah(BUZZER); break;
      case 'U': case 'u': dit_gap(BUZZER); dit_gap(BUZZER); dah(BUZZER); break;
      case 'V': case 'v': dit_gap(BUZZER); dit_gap(BUZZER); dit_gap(BUZZER); dah(BUZZER); break;
      case 'W': case 'w': dit_gap(BUZZER); dah_gap(BUZZER); dah(BUZZER); break;
      case 'X': case 'x': dah_gap(BUZZER); dit_gap(BUZZER); dit_gap(BUZZER); dah(BUZZER); break;
      case 'Y': case 'y': dah_gap(BUZZER); dit_gap(BUZZER); dah_gap(BUZZER); dah(BUZZER); break;
      case 'Z': case 'z': dah_gap(BUZZER); dah_gap(BUZZER); dit_gap(BUZZER); dit(BUZZER); break;
    }

    // check whether the gap is between letters or words
    if (i + 1 < message.length())
    {
      char c = message.charAt(i + 1);

      // turn off the buzzer
      digitalWrite(BUZZER, LOW);
      if (c == ' ')
      {
        delay(MEDIUM_GAP);
        i++;
      }
      else
      {
        delay(SHORT_GAP);
      }
    }
  }

  // turn off the buzzer for gap between words to repeat the same message
  digitalWrite(BUZZER, LOW);
  delay(MEDIUM_GAP);
}
