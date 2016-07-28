#include <pebble.h>
#include "main.h"



Window *window;
TextLayer *text_layer;
TextLayer *text_layer2;
   
void window_load(Window *window){
  text_layer = text_layer_create(GRect(3, 35, 144, 168));
  text_layer_set_text(text_layer, "ax^2+bx+c=0");
  
  text_layer_set_text_color(text_layer, GColorBlack);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28));
 
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  
  text_layer2 = text_layer_create(GRect(3, 0, 144, 40));
  text_layer_set_text(text_layer2, "STD. form");
  text_layer_set_text_color(text_layer2, GColorBlack);
  text_layer_set_font(text_layer2, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  
   layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer2));

}

void window_unload(Window *window){
  
}

int main(){
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers){
    .load = window_load,
    .unload = window_unload
   
  });
  window_stack_push(window, true);
  app_event_loop();
}