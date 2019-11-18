#import "FSWrapper.h"

void setup() {
  Serial.begin(115200);
  Serial.println();
  FSWrapper fsw(true);
  fsw.Open(); //open file system
  delay(500);

  fsw.WriteParameter("name", "Isaac Vitor");
  Serial.println(fsw.ReadParameter("name"));
}

void loop() {
  // put your main code here, to run repeatedly:

}