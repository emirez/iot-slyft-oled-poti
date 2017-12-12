

// Generated by slyft.io
// This code part has been generated on an "as is" basis, without warranties or conditions of any kind.

// slyftlet=c99-generic-msgpack

#ifndef tut4_CONFIG_H
#define tut4_CONFIG_H

#include "mpack/mpack.h"

struct TUT4__config {
  int32_t	lower_bound;
  int32_t	upper_bound;

  /**
  * Wipes contents to \0
  * @param self      pointer to target struct TUT4__config
  */
  void (*TUT4__config_clean)(struct TUT4__config *self);

  /**
  * Given an input buffer and its size, this functions parses the elements
  * of struct TUT4__config
  * @param self          pointer to target struct TUT4__config
  * @param input_buf     input buffer
  * @param sz_input_buf  size of input buffer
  * @return 0=success, 1=error
  */
  int (*TUT4__config_parse)(struct TUT4__config *self, const uint8_t *input_buf, size_t sz_input_buf);

  /**
  * Given a msgpack reader, this functions parses the elements
  * of struct TUT4__config
  * @param self          pointer to target struct TUT4__config
  * @param reader        pointer to mpack reader struct
  */
  void (*TUT4__config_parse_mpack)(struct TUT4__config *self, mpack_reader_t *reader);

  /**
  * Given a struct TUT4__config, this function serializes it into given output buffer.
  * @param self              pointer to source struct TUT4__config
  * @param output_buf        output buffer
  * @param sz_output_buf     size of output buffer
  * @return Length of output buf (0=error)
  */
  size_t (*TUT4__config_serialize)(const struct TUT4__config *self, uint8_t *output_buf, size_t sz_output_buf);

  /**
  * Given a struct TUT4__config, this function serializes it into given mpack writer.
  * @param self              pointer to source struct TUT4__config
  * @param writer 	         pointer to mpack writer struct
  */
  void (*TUT4__config_serialize_mpack)(const struct TUT4__config *self, mpack_writer_t *writer);

};

/**
 * Initializes struct struct TUT4__config. empties fields, sets function pointers
 * @param self  struct TUT4__config
 */
void TUT4__config_init(struct TUT4__config *self);


/* ORIGINAL SCHEMA
{"$schema"=>"http://json-schema.org/draft-04/schema#", "id"=>"config", "title"=>"Device config", "description"=>"", "type"=>"object", "properties"=>{"lower_bound"=>{"type"=>"integer", "minimum"=>0, "maximum"=>1023}, "upper_bound"=>{"type"=>"integer", "minimum"=>0, "maximum"=>1023}}, "required"=>["lower_bound", "upper_bound"]}
 */
#endif		//tut4_CONFIG_H
