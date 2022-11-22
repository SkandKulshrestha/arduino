// Program to read from and write to the Serial monitor
// Circuit Diagram: No external circuit

String name;
int i;
float f;

void setup() {
  // put your setup code here, to run once:
  // Open Serial port with baud rate 115200
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // write integer to Serial port with newline
  Serial.println(5);

  // write decimal to Serial port with newline
  Serial.println(5.6);

  // write string to Serial port without newline
  Serial.print("My name is ");

  // write string to Serial port with newline
  Serial.println("Skand Kulshrestha");

  Serial.println("What is your name?");

  // wait for data to be available on Serial port
  while(Serial.available() == 0);

  // read string from Serial port
  name = Serial.readString();
  Serial.print("Hello, ");
  Serial.println(name);

  Serial.println("Enter an integer:");
  while(Serial.available() == 0);

  // read integer from Serial port
  i = Serial.parseInt();
  Serial.print("You've entered ");
  Serial.println(i);

  Serial.println("Enter a decimal number:");
  while(Serial.available() == 0);

  // read decimal from Serial port
  f = Serial.parseFloat();
  Serial.print("You've entered ");
  Serial.println(f);

  delay(1000);
}
