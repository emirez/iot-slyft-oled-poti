
// Generated by slyft.io
// This code part has been generated on an "as is" basis, without warranties or conditions of any kind.


#include "Arduino.h"

#include "oled.h"
#include "mpack/mpack.h"
#include "mpack/mpack-platform.h"

void TUT4__oled_clean(struct TUT4__oled *self) {

	self->OLED_stat = false;
	mpack_memset(self->oled_display,0,sizeof(self->oled_display));
}

void TUT4__oled_parse_next(struct TUT4__oled *self, mpack_reader_t *reader) {

	char	buf_key[13];
	mpack_expect_utf8_cstr(reader, buf_key, sizeof(buf_key));


	if (mpack_memcmp("OLED_stat",(const char*)buf_key,9) == 0) {
		self->OLED_stat = mpack_expect_bool(reader);
	}

	if (mpack_memcmp("oled_display",(const char*)buf_key,12) == 0) {
		mpack_expect_utf8_cstr(reader, self->oled_display, sizeof(self->oled_display));
	}


}

int TUT4__oled_parse(struct TUT4__oled *self, const uint8_t *input_buf, size_t sz_input_buf) {
		mpack_reader_t reader;
    mpack_error_t error;

    mpack_reader_init_data(&reader,(const char *)input_buf, sz_input_buf);
    self->TUT4__oled_parse_mpack(self, &reader);

    error = mpack_reader_destroy(&reader);
    if ( error != mpack_ok) {
        return 1;
    } else {
        return 0;
    }

}

void TUT4__oled_parse_mpack(struct TUT4__oled *self, mpack_reader_t *reader) {

    int count = mpack_expect_map_range(reader, 0, 2);
    for (int i = 0; i < count; i++) {
        TUT4__oled_parse_next(self, reader);
    }

    mpack_done_map(reader);
}

size_t TUT4__oled_serialize(const struct TUT4__oled *self, uint8_t *output_buf, size_t sz_output_buf) {
		struct mpack_writer_t writer;
    mpack_writer_init(&writer,(char*)output_buf,sz_output_buf);

		self->TUT4__oled_serialize_mpack(self, &writer);

    mpack_writer_flush_message(&writer);
    size_t used = mpack_writer_buffer_used(&writer);

    // if all is ok, return length of used bytes. Otherwise 0
    if (mpack_writer_destroy(&writer) == mpack_ok) {
        return used;
    } else {
        return (size_t)0;
    }
}

void TUT4__oled_serialize_mpack(const struct TUT4__oled *self, mpack_writer_t *writer) {
    mpack_start_map(writer, 2);

	mpack_write_cstr(writer, "OLED_stat"); mpack_write_bool(writer, self->OLED_stat);
	mpack_write_cstr(writer, "oled_display"); mpack_write_cstr(writer, self->oled_display);

    mpack_finish_map(writer);
}

void TUT4__oled_init(struct TUT4__oled *self) {
    self->TUT4__oled_clean = &TUT4__oled_clean;
    self->TUT4__oled_parse = &TUT4__oled_parse;
    self->TUT4__oled_parse_mpack = &TUT4__oled_parse_mpack;
    self->TUT4__oled_serialize = &TUT4__oled_serialize;
    self->TUT4__oled_serialize_mpack = &TUT4__oled_serialize_mpack;
    self->TUT4__oled_clean(self);
}

//