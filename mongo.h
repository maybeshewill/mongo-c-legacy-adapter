#ifndef _LEGACY_ADAPTER_MONGO_
#define _LEGACY_ADAPTER_MONGO_

#include <mongoc.h>

#define BSON_EOO        BSON_TYPE_EOD 
#define BSON_DOUBLE     BSON_TYPE_DOUBLE
#define BSON_STRING     BSON_TYPE_UTF8
#define BSON_OBJECT     BSON_TYPE_DOCUMENT
#define BSON_ARRAY      BSON_TYPE_ARRAY
#define BSON_BINDATA    BSON_TYPE_BINARY
#define BSON_UNDEFINED  BSON_TYPE_UNDEFINED
#define BSON_OID        BSON_TYPE_OID
#define BSON_BOOL       BSON_TYPE_BOOL
#define BSON_DATE       BSON_TYPE_DATE_TIME
#define BSON_NULL       BSON_TYPE_NULL
#define BSON_REGEX      BSON_TYPE_REGEX
#define BSON_DBREF      BSON_TYPE_DBREF
#define BSON_CODE       BSON_TYPE_CODE
#define BSON_SYMBOL     BSON_TYPE_SYMBOL
#define BSON_CODEWSCOPE BSON_TYPE_CODEWSCOPE
#define BSON_INT        BSON_TYPE_INT32
#define BSON_TIMESTAMP  BSON_TYPE_TIMESTAMP
#define BSON_LONG       BSON_TYPE_INT64
#define BSON_MAXKEY     BSON_TYPE_MAXKEY
#define BSON_MINKEY     BSON_TYPE_MINKEY

#define BSON_BIN_BINARY BSON_SUBTYPE_BINARY
#define BSON_BIN_FUNC   BSON_SUBTYPE_FUNCTION
#define BSON_BIN_BINARY_OLD BSON_SUBTYPE_BINARY_DEPRECATED
#define BSON_BIN_UUID   BSON_SUBTYPE_UUID
#define BSON_BIN_MD5    BSON_SUBTYPE_MD5
#define BSON_BIN_USER   BSON_SUBTYPE_USER

#define bson bson_t
#define bson_type bson_type_t
#define bson_iterator bson_iter_t
#define bson_date_t int64_t

#define mongo mongoc_client_t
#define mongo_cursor mongoc_cursor_t
#define mongo_destroy mongoc_client_destroy
#define mongo_cursor_destroy mongoc_cursor_destroy
#define mongo_cursor_next mongoc_cursor_next
#define mongo_cursor_bson mongoc_cursor_current

#define bson_iterator_init bson_iter_init
#define bson_iterator_next bson_iter_next
#define bson_iterator_key  bson_iter_key
#define bson_iterator_type bson_iter_type
#define bson_iterator_subiterator bson_iter_recurse

#define bson_iterator_bool bson_iter_bool
#define bson_iterator_oid bson_iter_oid
#define bson_iterator_double bson_iter_double
#define bson_iterator_string(x) bson_iter_utf8(x, NULL)
#define bson_iterator_int bson_iter_int32
#define bson_iterator_long bson_iter_int64
#define bson_iterator_date bson_iter_date_time

#define bson_iterator_array_length bson_iter_array_length

#define bson_alloc bson_new
#define bson_finish (void)
#define bson_append_null(b, name) bson_append_null(b, name, -1)
#define bson_append_double(b, name, val) bson_append_double(b, name, -1, val)
#define bson_append_string(b, name, val) bson_append_utf8(b, name, -1, val, -1)
#define bson_append_string_n(b, name, val, val_len) bson_append_utf8(b, name, -1, val, val_len)
#define bson_append_bool(b, name, val) bson_append_bool(b, name, -1, val)
#define bson_append_date(b, name, val) bson_append_date_time(b, name, -1, val)
#define bson_append_oid(b, name, val) bson_append_oid(b, name, -1, val)
#define bson_append_binary(b, name, type, bin, bin_len) bson_append_binary(b, name, -1, type, bin, bin_len)
#define bson_append_int(b, name, val) bson_append_int32(b, name, -1, val)
#define bson_append_long(b, name, val) bson_append_int64(b, name, -1, val)
#define bson_append_time_t(b, name, val) bson_append_time_t(b, name, -1, val)

#define bson_oid_from_string bson_oid_init_from_string

uint32_t bson_iter_array_length(const bson_iter_t *iter); 

bool bson_iterator_subobject_init(const bson_iter_t *iter, bson_t *child,
                                  int copyData);

bson_subtype_t bson_iterator_bin_type(const bson_iter_t *iter);

bool bson_find(bson_iter_t *iter, const bson_t *obj, const char* name);

#endif
