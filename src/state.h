#pragma once

enum class Screen {
  Home,
  Counter,
  Settings, 
  About
};

extern Screen current_screen;

extern int current_option;
extern int current_settings_option;

extern bool update_display;

extern int counter_value; 
