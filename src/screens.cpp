#include "display.h"
#include "constants.h"
#include "state.h"
#include "utils.h"

//TODO: Вынести в функциях длинные переменные в отдельные переменные, чтобы не писать длинные выражения в скобках (Использовать указатель!)
void draw_home() {
  u8g2.drawStr(5, UI::default_y + (current_option * UI::menu_y_offset), ">"); // cursor

  for (int oi = 0; oi <= Options::max_menu_option_index ; oi++) { // Menu Options
        u8g2.drawStr(15, UI::default_y + (UI::menu_y_offset * oi), String(Options::menu_options[oi]).c_str());
    }
}

void draw_counter() {
    String text = "Counter: " + String(counter_value);
    u8g2.drawStr(5, UI::default_y, text.c_str());
}


void draw_settings() {
    u8g2.drawStr(5, UI::default_y + (current_settings_option * UI::menu_y_offset), ">"); // cursor

    for (int oi = 0; oi <= Options::max_settings_option_index ; oi++) { // Settings Options
          String text = String(Options::settings_options[oi].name) + ": " + String(Options::settings_options[oi].value);
          u8g2.drawStr(15, UI::default_y + (UI::menu_y_offset * oi), text.c_str());
      }
}

void draw_about() {
    const int start_x = 5;
    const int default_y = 15;
    int iteration = 1;

    String temp = UI::about_text;

    while (temp.length() > 0) {

      int text_width = u8g2.getStrWidth(temp.c_str());

      if (text_width + start_x <= 128) {
          u8g2.drawStr(start_x, default_y * iteration, temp.c_str());
          break;
      }

      String temp_2 = temp;

      do {
        temp_2.remove(temp_2.length() - 1, 1);
        text_width = u8g2.getStrWidth(temp_2.c_str());
      } while (text_width + start_x > 123);

      u8g2.drawStr(start_x, default_y * iteration, temp_2.c_str());

      temp.replace(temp_2, ""); // удалить уже нарисованную часть

      iteration++;
    }
}

void draw_screen() {
  // switch screen state
        switch (current_screen) {
            case Screen::Home:  draw_home(); break;
            case Screen::Counter: draw_counter(); break;
            case Screen::Settings: draw_settings(); break;
            case Screen::About: draw_about(); break;
        }
}

void draw_title() {
  const char* title = getScreenName();
  const int title_x = calculate_text_center(title);

  u8g2.drawStr(title_x, UI::default_y_title, title); // Title
}

void render_display() {
    if (!update_display) 
        return; // No need to update the display if nothing has changed

    u8g2.firstPage();

    do {
        u8g2.setFont(u8g2_font_luBIS08_tf);
        
        draw_title();

        draw_screen();

      } while ( u8g2.nextPage() );

    update_display = false; // Reset the flag after updating the display
}