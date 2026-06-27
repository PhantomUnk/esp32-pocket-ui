#include "utils.h"
#include "display.h"
#include "state.h"
#include "constants.h"

const char* getScreenName() {
    switch (current_screen) {
        case Screen::Home:     return "Home";
        case Screen::Counter:  return "Counter";
        case Screen::Settings: return "Settings";
        case Screen::About:    return "About";
        default:               return "Unknown";
    }
}

int calculate_text_center(const char* text) {
  int text_width = u8g2.getStrWidth(text); 
  // 2. Считаем идеальный X: (128 / 2) - (ширина текста / 2)
  return 64 - (text_width / 2);
}

void change_settings_value() {
    int &value = Options::settings_options[current_settings_option].value;

    if (current_settings_option == 0) { // Brightness
        value += 15; // Increase brightness by 15
        if (value > 255) value = 0; // Wrap around to 0 if it exceeds 255
        u8g2.setContrast(value); // Apply brightness change
    } 
    else if (current_settings_option == 1) { // Speed
        value += 1; // Increase speed by 1
        if (value > 10) value = 1; // Wrap around to 1 if it exceeds 10
    }
}
