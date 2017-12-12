
// Generated by slyft.io
// This code part has been generated on an "as is" basis, without warranties or conditions of any kind.

// application-part header



    #include "Arduino.h"

#include "microcoap/coap.h"

// include data structure headers
#include "config.h"
#include "oled.h"
#include "state.h"

// struct TUT4__state
#include "state.h"
// struct TUT4__config
#include "config.h"
// struct TUT4__oled
#include "oled.h"



//
// CoAP Application level handlers
//

// -- GET  /state

struct TUT4__tutorial4__get___state_req {
    struct {

    } data;
};

struct TUT4__tutorial4__get___state_resp {
    coap_responsecode_t  response_code;
    struct {

  
        // data struct for response code 205
        struct TUT4__state  state_205;

    } data;
};

// -- Application level handler for GET to /state
bool TUT4__tutorial4__get___state(
    struct TUT4__tutorial4__get___state_req *req,
    struct TUT4__tutorial4__get___state_resp *resp);


// -- GET  /config

struct TUT4__tutorial4__get___config_req {
    struct {

    } data;
};

struct TUT4__tutorial4__get___config_resp {
    coap_responsecode_t  response_code;
    struct {

  
        // data struct for response code 205
        struct TUT4__config  config_205;

    } data;
};

// -- Application level handler for GET to /config
bool TUT4__tutorial4__get___config(
    struct TUT4__tutorial4__get___config_req *req,
    struct TUT4__tutorial4__get___config_resp *resp);


// -- POST  /config

struct TUT4__tutorial4__post___config_req {
    struct {

        struct TUT4__config  config;

    } data;
};

struct TUT4__tutorial4__post___config_resp {
    coap_responsecode_t  response_code;
    struct {

    } data;
};

// -- Application level handler for POST to /config
bool TUT4__tutorial4__post___config(
    struct TUT4__tutorial4__post___config_req *req,
    struct TUT4__tutorial4__post___config_resp *resp);


// -- POST  /oled

struct TUT4__tutorial4__post___oled_req {
    struct {

        struct TUT4__oled  oled;

    } data;
};

struct TUT4__tutorial4__post___oled_resp {
    coap_responsecode_t  response_code;
    struct {

    } data;
};

// -- Application level handler for POST to /oled
bool TUT4__tutorial4__post___oled(
    struct TUT4__tutorial4__post___oled_req *req,
    struct TUT4__tutorial4__post___oled_resp *resp);


