#include "input.h"
#include "Arduino.h"
#include "constants.h"
#include "state.h"
#include "utils.h"

void init_input() {
  pinMode(Pins::BTN_UP, INPUT_PULLUP);
  pinMode(Pins::BTN_DOWN, INPUT_PULLUP);
  pinMode(Pins::BTN_ENTER, INPUT_PULLUP);
  pinMode(Pins::BTN_CANCEL, INPUT_PULLUP);
  pinMode(Pins::BTN_COUNTER, INPUT_PULLUP);
}

static bool read_input(int Pin) { // static to limit the scope of the function to this file
  return !digitalRead(Pin);
}

static void carousel_input(int &option, int max_option) {
  int input = read_input(Pins::BTN_UP) * (-1) + read_input(Pins::BTN_DOWN); // Like Unity Vector 2 input

  if (input != 0) { // Если хоть что-то нажато
    option += input; // Изменить опцию на основе ввода

    if (option > max_option) // Делаем карусельный эффект
      option = 0;

    else if (option < 0) // Делаем карусельный эффект
      option = max_option;

    update_display = true;
    delay(DEBOUNCE_DELAY); // Убрать дребезг 
    }
}

static bool handle_cancel() {
  if (read_input(Pins::BTN_CANCEL)) { // Cancel Button Check
    if (current_screen != Screen::Home) {
      current_screen = Screen::Home;
      update_display = true;
      return true;
    }
    delay(DEBOUNCE_DELAY);
    Serial.println("Current screen: " + String(getScreenName()));
    return true;
  }
  return false;
}

static void handle_home_input() {
  if (read_input(Pins::BTN_ENTER)) { // Enter Check
        current_screen = static_cast<Screen>(current_option + 1); // Change screen based on current option with enum
        Serial.println("Current screen: " + String(getScreenName()));
        update_display = true;
        delay(DEBOUNCE_DELAY);
        return;
      }

  carousel_input(current_option, Options::max_menu_option_index); // Round input for menu options
}

static void handle_counter_input() {
  if (read_input(Pins::BTN_COUNTER)) { // Counter button check
        counter_value++;
        update_display = true;
        delay(DEBOUNCE_DELAY);
    }
}

static void handle_settings_input() {
  if (read_input(Pins::BTN_ENTER)) { // Enter Check
      change_settings_value();
      update_display = true;
      delay(DEBOUNCE_DELAY);
      return;
    }

  carousel_input(current_settings_option, Options::max_settings_option_index); // Round input for settings options
}


void get_input() {
  if (handle_cancel()) return; // Cancel button check

  switch (current_screen) {
    case Screen::Home:
      handle_home_input();
    break;
    case Screen::Counter:
      handle_counter_input();
    break;
    case Screen::Settings:
      handle_settings_input();
    break;
  }
}