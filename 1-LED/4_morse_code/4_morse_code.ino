// Program to blink led for sending the Morse code of given message
// LED: direction matters. long leg (anode) goes to positive.
// Ciruit Diagram: placed in same folder.

// message to be sent
String message = "Skand Kulshrestha";

// led connection
#define LED 13

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
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < message.length(); i++)
  {
    // get character from message and play sequence of dit(s)/dah(s) associated with it
    switch(message.charAt(i))
    {
      case ' ': digitalWrite(LED, LOW); delay(MEDIUM_GAP); break;
      case 'A': case 'a': dit_gap(LED); dah(LED); break;
      case 'B': case 'b': dah_gap(LED); dit_gap(LED); dit_gap(LED); dit(LED); break;
      case 'C': case 'c': dah_gap(LED); dit_gap(LED); dah_gap(LED); dit(LED); break;
      case 'D': case 'd': dah_gap(LED); dit_gap(LED); dit(LED); break;
      case 'E': case 'e': dit(LED); break;
      case 'F': case 'f': dit_gap(LED); dit_gap(LED); dah_gap(LED); dit(LED); break;
      case 'G': case 'g': dah_gap(LED); dah_gap(LED); dit(LED); break;
      case 'H': case 'h': dit_gap(LED); dit_gap(LED); dit_gap(LED); dit(LED); break;
      case 'I': case 'i': dit_gap(LED); dit(LED); break;
      case 'J': case 'j': dit_gap(LED); dah_gap(LED); dah_gap(LED); dah(LED); break;
      case 'K': case 'k': dah_gap(LED); dit_gap(LED); dah(LED); break;
      case 'L': case 'l': dit_gap(LED); dah_gap(LED); dit_gap(LED); dit(LED); break;
      case 'M': case 'm': dah_gap(LED); dah(LED); break;
      case 'N': case 'n': dah_gap(LED); dit(LED); break;
      case 'O': case 'o': dah_gap(LED); dah_gap(LED); dah(LED); break;
      case 'P': case 'p': dit_gap(LED); dah_gap(LED); dah_gap(LED); dit(LED); break;
      case 'Q': case 'q': dah_gap(LED); dah_gap(LED); dit_gap(LED); dah(LED); break;
      case 'R': case 'r': dit_gap(LED); dah_gap(LED); dit(LED); break;
      case 'S': case 's': dit_gap(LED); dit_gap(LED); dit(LED); break;
      case 'T': case 't': dah(LED); break;
      case 'U': case 'u': dit_gap(LED); dit_gap(LED); dah(LED); break;
      case 'V': case 'v': dit_gap(LED); dit_gap(LED); dit_gap(LED); dah(LED); break;
      case 'W': case 'w': dit_gap(LED); dah_gap(LED); dah(LED); break;
      case 'X': case 'x': dah_gap(LED); dit_gap(LED); dit_gap(LED); dah(LED); break;
      case 'Y': case 'y': dah_gap(LED); dit_gap(LED); dah_gap(LED); dah(LED); break;
      case 'Z': case 'z': dah_gap(LED); dah_gap(LED); dit_gap(LED); dit(LED); break;
    }

    // check whether the gap is between letters or words
    if (i + 1 < message.length())
    {
      char c = message.charAt(i + 1);

      // turn off the led
      digitalWrite(LED, LOW);
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

  // turn off the led for gap between words to repeat the same message
  digitalWrite(LED, LOW);
  delay(MEDIUM_GAP);
}
