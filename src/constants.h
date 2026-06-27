#pragma once
#include <Arduino.h>
namespace Pins {
    inline constexpr int BTN_UP = 12;
    inline constexpr int BTN_DOWN = 13;
    inline constexpr int BTN_ENTER = 33;
    inline constexpr int BTN_CANCEL = 19;
    inline constexpr int BTN_COUNTER = 4;
}

inline constexpr int DEBOUNCE_DELAY = 100;

namespace UI {
    inline constexpr int menu_y_offset = 15; // Y offset between 2 options
    inline constexpr int default_y = 39; // Y offset where option start's
    inline constexpr int default_y_title = 15;
    inline constexpr const char* about_text = "This is a simple menu system for ESP32 with OLED display.\n\nCreated by Mark.\n\n2026.";
}

namespace Options {
    struct Setting {
        const char* name;
        int value;
    };

    inline constexpr const char* menu_options[] = {"Counter", "Settings", "About"};
    inline constexpr size_t max_menu_option_index = (sizeof(menu_options) / sizeof(menu_options[0])) - 1;

    inline Setting settings_options[] = {{"Brightness", 255}, {"Speed", 1}}; // is not constexpr because values can change at runtime
    inline constexpr size_t max_settings_option_index = (sizeof(settings_options) / sizeof(settings_options[0])) - 1; // size_t is used for array size, not int because it is more appropriate for indexing and size representation in C++.
}