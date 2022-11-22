// Program to blink led and sound buzzer for sending the Morse code of given message
// LED: direction matters. long leg (anode) goes to positive.
// BUZZER: direction matters. long leg (anode) goes to positive.
// Ciruit Diagram: placed in same folder.

// TODO: modify this code to read

// message to be sent
String message = "Skand Kulshrestha";

// led connection
#define LED 13

// buzzer connection
#define BUZZER 12

// unit time duration
#define UNIT_TIME 100

// time durations for different gaps
#define SHORT_MARK_TIME (1 * UNIT_TIME)           // dit duration
#define LONG_MARK_TIME (3 * UNIT_TIME)            // dah duration
#define INTER_ELEMENT_GAP (1 * UNIT_TIME)         // gap between consecutive dit/dah
#define SHORT_GAP (3 * UNIT_TIME)                 // gap between consecutive letter
#define MEDIUM_GAP (7 * UNIT_TIME)                // gap between consecutive word

//
// HIGH/LOW
//

void digitalWriteHIGH(void)
{
  digitalWrite(LED, HIGH);
  digitalWrite(BUZZER, HIGH);
}

void digitalWriteLOW(void)
{
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);
}

//
// DIT/DAH/GAP
//

void inter_element_gap(void)
{
  digitalWriteLOW();
  delay(INTER_ELEMENT_GAP);
}

void short_gap(void)
{
  digitalWriteLOW();
  delay(SHORT_GAP);
}

void medium_gap(void)
{
  digitalWriteLOW();
  delay(MEDIUM_GAP);
}

void dit(void)
{
  digitalWriteHIGH();
  delay(SHORT_MARK_TIME);
}

void dah(void)
{
  digitalWriteHIGH();
  delay(LONG_MARK_TIME);
}

//
// DIT/DAH with GAP
//

void dit_gap(void)
{
  dit();
  inter_element_gap();
}

void dah_gap(void)
{
  dah();
  inter_element_gap();
}

void send_character(char c)
{
  switch(c)
  {
    case ' ': medium_gap(); break;
    case 'A': case 'a': dit_gap(); dah(); break;
    case 'B': case 'b': dah_gap(); dit_gap(); dit_gap(); dit(); break;
    case 'C': case 'c': dah_gap(); dit_gap(); dah_gap(); dit(); break;
    case 'D': case 'd': dah_gap(); dit_gap(); dit(); break;
    case 'E': case 'e': dit(); break;
    case 'F': case 'f': dit_gap(); dit_gap(); dah_gap(); dit(); break;
    case 'G': case 'g': dah_gap(); dah_gap(); dit(); break;
    case 'H': case 'h': dit_gap(); dit_gap(); dit_gap(); dit(); break;
    case 'I': case 'i': dit_gap(); dit(); break;
    case 'J': case 'j': dit_gap(); dah_gap(); dah_gap(); dah(); break;
    case 'K': case 'k': dah_gap(); dit_gap(); dah(); break;
    case 'L': case 'l': dit_gap(); dah_gap(); dit_gap(); dit(); break;
    case 'M': case 'm': dah_gap(); dah(); break;
    case 'N': case 'n': dah_gap(); dit(); break;
    case 'O': case 'o': dah_gap(); dah_gap(); dah(); break;
    case 'P': case 'p': dit_gap(); dah_gap(); dah_gap(); dit(); break;
    case 'Q': case 'q': dah_gap(); dah_gap(); dit_gap(); dah(); break;
    case 'R': case 'r': dit_gap(); dah_gap(); dit(); break;
    case 'S': case 's': dit_gap(); dit_gap(); dit(); break;
    case 'T': case 't': dah(); break;
    case 'U': case 'u': dit_gap(); dit_gap(); dah(); break;
    case 'V': case 'v': dit_gap(); dit_gap(); dit_gap(); dah(); break;
    case 'W': case 'w': dit_gap(); dah_gap(); dah(); break;
    case 'X': case 'x': dah_gap(); dit_gap(); dit_gap(); dah(); break;
    case 'Y': case 'y': dah_gap(); dit_gap(); dah_gap(); dah(); break;
    case 'Z': case 'z': dah_gap(); dah_gap(); dit_gap(); dit(); break;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < message.length(); i++)
  {
    // get character from message and play sequence of dit(s)/dah(s) associated with it
    send_character(message.charAt(i));

    // check whether the gap is between letters or words
    if (i + 1 < message.length())
    {
      char c = message.charAt(i + 1);

      // turn off the led
      if (c == ' ')
      {
        medium_gap();
        i++;
      }
      else
      {
        short_gap();
      }
    }
  }

  // turn off the led for gap between words to repeat the same message
  medium_gap();
}
