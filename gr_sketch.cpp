/*GR-SAKURA Sketch Template Version: V1.08*/
#include <rxduino.h>

#include "mruby.h"
#include <mruby/irep.h>
#include <mruby/string.h>

#include "sample.c"

extern const uint8_t code[];

//digitalWrite function
mrb_value cdigitalWrite(mrb_state *mrb, mrb_value self){
  mrb_int pin;
  mrb_int val;

  mrb_get_args(mrb, "ii", &pin, &val);
  digitalWrite(pin, val);
  return mrb_nil_value();
}

void setup(){

  pinMode(PIN_LED0,OUTPUT);
  pinMode(PIN_LED1,OUTPUT);
  pinMode(PIN_LED2,OUTPUT);
  pinMode(PIN_LED3,OUTPUT);

  mrb_state *mrb = mrb_open();

  mrb_define_method(mrb, mrb->object_class, "cdigitalWrite", cdigitalWrite, ARGS_REQ(2));

  mrb_load_irep( mrb, code);
 }

void loop(){
}
