
// Generated by slyft.io
// This code part has been generated on an "as is" basis, without warranties or conditions of any kind.


#include "Arduino.h"

#include "state.h"
#include "mpack/mpack.h"
#include "mpack/mpack-platform.h"

void TUT4__state_clean(struct TUT4__state *self) {

	self->switch_on = false;
	mpack_memset(self->led1,0,sizeof(self->led1));
}

void TUT4__state_parse_next(struct TUT4__state *self, mpack_reader_t *reader) {

	char	buf_key[10];
	mpack_expect_utf8_cstr(reader, buf_key, sizeof(buf_key));


	if (mpack_memcmp("switch_on",(const char*)buf_key,9) == 0) {
		self->switch_on = mpack_expect_bool(reader);
	}

	if (mpack_memcmp("led1",(const char*)buf_key,4) == 0) {
		mpack_expect_utf8_cstr(reader, self->led1, sizeof(self->led1));
	}


}

int TUT4__state_parse(struct TUT4__state *self, const uint8_t *input_buf, size_t sz_input_buf) {
		mpack_reader_t reader;
    mpack_error_t error;

    mpack_reader_init_data(&reader,(const char *)input_buf, sz_input_buf);
    self->TUT4__state_parse_mpack(self, &reader);

    error = mpack_reader_destroy(&reader);
    if ( error != mpack_ok) {
        return 1;
    } else {
        return 0;
    }

}

void TUT4__state_parse_mpack(struct TUT4__state *self, mpack_reader_t *reader) {

    int count = mpack_expect_map_range(reader, 0, 2);
    for (int i = 0; i < count; i++) {
        TUT4__state_parse_next(self, reader);
    }

    mpack_done_map(reader);
}

size_t TUT4__state_serialize(const struct TUT4__state *self, uint8_t *output_buf, size_t sz_output_buf) {
		struct mpack_writer_t writer;
    mpack_writer_init(&writer,(char*)output_buf,sz_output_buf);

		self->TUT4__state_serialize_mpack(self, &writer);

    mpack_writer_flush_message(&writer);
    size_t used = mpack_writer_buffer_used(&writer);

    // if all is ok, return length of used bytes. Otherwise 0
    if (mpack_writer_destroy(&writer) == mpack_ok) {
        return used;
    } else {
        return (size_t)0;
    }
}

void TUT4__state_serialize_mpack(const struct TUT4__state *self, mpack_writer_t *writer) {
    mpack_start_map(writer, 2);

	mpack_write_cstr(writer, "switch_on"); mpack_write_bool(writer, self->switch_on);
	mpack_write_cstr(writer, "led1"); mpack_write_cstr(writer, self->led1);

    mpack_finish_map(writer);
}

void TUT4__state_init(struct TUT4__state *self) {
    self->TUT4__state_clean = &TUT4__state_clean;
    self->TUT4__state_parse = &TUT4__state_parse;
    self->TUT4__state_parse_mpack = &TUT4__state_parse_mpack;
    self->TUT4__state_serialize = &TUT4__state_serialize;
    self->TUT4__state_serialize_mpack = &TUT4__state_serialize_mpack;
    self->TUT4__state_clean(self);
}

//
