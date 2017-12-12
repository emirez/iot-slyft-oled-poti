// Generated by slyft.io
// This code part has been generated on an "as is" basis, without warranties or conditions of any kind.

// endpoints

#include "microcoap/coap.h"


static const coap_endpoint_path_t TUT4__tutorial4__paths_get_well_known_core = {2, {".well-known", "core"}};

int TUT4__tutorial4__handle_get_well_known_core(coap_rw_buffer_t *scratch,
const coap_packet_t *inpkt, coap_packet_t *outpkt,
uint8_t id_hi, uint8_t id_lo);



// enumerate all single resources as endpoint_path types

static const coap_endpoint_path_t TUT4__tutorial4__paths__state = {1, {"state"}};
static const coap_endpoint_path_t TUT4__tutorial4__paths__config = {1, {"config"}};
static const coap_endpoint_path_t TUT4__tutorial4__paths__oled = {1, {"oled"}};

// define handler functions

int TUT4__tutorial4__handle_get___state(coap_rw_buffer_t *scratch,
    const coap_packet_t *inpkt, coap_packet_t *outpkt,
    uint8_t id_hi, uint8_t id_lo);

int TUT4__tutorial4__handle_get___config(coap_rw_buffer_t *scratch,
    const coap_packet_t *inpkt, coap_packet_t *outpkt,
    uint8_t id_hi, uint8_t id_lo);

int TUT4__tutorial4__handle_post___config(coap_rw_buffer_t *scratch,
    const coap_packet_t *inpkt, coap_packet_t *outpkt,
    uint8_t id_hi, uint8_t id_lo);

int TUT4__tutorial4__handle_post___oled(coap_rw_buffer_t *scratch,
    const coap_packet_t *inpkt, coap_packet_t *outpkt,
    uint8_t id_hi, uint8_t id_lo);


// define array with all endpoints
extern const coap_endpoint_t endpoints[] =
{

    {COAP_METHOD_GET, TUT4__tutorial4__handle_get_well_known_core, &TUT4__tutorial4__paths_get_well_known_core, "ct=40"},

    {COAP_METHOD_GET, TUT4__tutorial4__handle_get___state, &TUT4__tutorial4__paths__state, "ct=0"},	/* Return device state */
    {COAP_METHOD_GET, TUT4__tutorial4__handle_get___config, &TUT4__tutorial4__paths__config, "ct=0"},	/* Return device configuration */
    {COAP_METHOD_POST, TUT4__tutorial4__handle_post___config, &TUT4__tutorial4__paths__config, "ct=0"},	/* Update device configuration */
    {COAP_METHOD_POST, TUT4__tutorial4__handle_post___oled, &TUT4__tutorial4__paths__oled, "ct=0"},	/* Update OLED configuration */
    {(coap_method_t)0, NULL, NULL, NULL}
};