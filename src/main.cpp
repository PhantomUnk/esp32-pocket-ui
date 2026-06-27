#include <Arduino.h>

#include "input.h"
#include "display.h"
#include "screens.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  init_display(); // Initialize the display

  init_input(); // Initialize input pins

}

void loop() {
  get_input();

  render_display();
}