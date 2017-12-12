#include "Arduino.h"

#include "microcoap/coap.h"
#include "tutorial4_app.h"

// include data structure headers
#include "config.h"
#include "state.h"

// OLED Libs Start
#include <Wire.h>
#include <SeeedGrayOLED.h>
#include <pgmspace.h>
// OLED Libs End

int __upper_bound = 300;
int __lower_bound = 700;
int __led1_state = LOW;
int __led2_state = LOW;
bool __oled_state = false;

void update_led() {
  digitalWrite(D5, __led1_state);
}

bool get_switch_state() {
  return digitalRead(D3);
}

void app_loop() {
  int v = analogRead(A0);
  Serial.println(v);
  if ( v <= __lower_bound || v >= __upper_bound)  {
    __led1_state = HIGH;
  } else {
    __led1_state = LOW;
  }
  update_led();
  delay(100);

  //OLED Start
  if(__oled_state == true){
    SeeedGrayOled.clearDisplay();     //Clear Display.
  }
  //OLED End
}


//
// CoAP Application level handlers
//

// -- Application level handler for GET to /state
bool TUT4__tutorial4__get___state(
    struct TUT4__tutorial4__get___state_req *req,
    struct TUT4__tutorial4__get___state_resp *resp) {
      Serial.println("TUT4__tutorial4__get___state");
      strcpy(resp->data.state_205.led1, (__led1_state?"ON":"OFF"));
      resp->data.state_205.switch_on = get_switch_state();
      resp->response_code = COAP_RSPCODE_CONTENT;

    return true;
}


// -- Application level handler for GET to /config
bool TUT4__tutorial4__get___config(
    struct TUT4__tutorial4__get___config_req *req,
    struct TUT4__tutorial4__get___config_resp *resp) {

      Serial.println("TUT4__tutorial4__get___config");

      resp->data.config_205.lower_bound = __lower_bound;
      resp->data.config_205.upper_bound = __upper_bound;
      resp->response_code = COAP_RSPCODE_CONTENT;

    // YOUR CODE GOES HERE ----------- END

    return true;
}


// -- Application level handler for POST to /config
bool TUT4__tutorial4__post___config(
    struct TUT4__tutorial4__post___config_req *req,
    struct TUT4__tutorial4__post___config_resp *resp) {

      Serial.println("TUT4__tutorial4__post___config");

      __lower_bound = req->data.config.lower_bound;
      __upper_bound = req->data.config.upper_bound;
      resp->response_code = COAP_RSPCODE_CHANGED;

      Serial.print( "Changed lower_bound="); Serial.println( __lower_bound);
      Serial.print( "Changed upper_bound="); Serial.println( __upper_bound);

    return true;
}


// -- Application level handler for POST to /oled
bool TUT4__tutorial4__post___oled(
    struct TUT4__tutorial4__post___oled_req *req,
    struct TUT4__tutorial4__post___oled_resp *resp) {

      Serial.println("TUT4__tutorial4__post___oled");

      __oled_state = (bool) req->data.oled.OLED_stat;
      resp->response_code = COAP_RSPCODE_CHANGED;

      Serial.print( "Changed OLED_stat="); Serial.println( __oled_state);

    return true;
}
