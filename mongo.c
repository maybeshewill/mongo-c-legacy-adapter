#include "mongo.h"

#define ITER_TYPE(i) (bson_type_t) *((i)->raw + (i)->type)

uint32_t
bson_iter_array_length(const bson_iter_t *iter)
{
    bson_iter_t arr_iter;
    uint32_t arr_sz = 0;
    if (bson_iter_recurse(iter, &arr_iter)) {
        while (bson_iter_next(&arr_iter)) {
            arr_sz++;
        }
    }
    return arr_sz;
}

bool
bson_iterator_subobject_init(const bson_iter_t *iter,
                             bson_t            *child,
                             int                copyData /*for compatibility */)
{
    uint32_t object_len;
    const uint8_t *object_buf;

    bson_iter_document(iter, &object_len, &object_buf);
    return bson_init_static(child, object_buf, object_len);
}


bool
bson_find(bson_iter_t *iter, const bson *obj, const char *name)
{
    return bson_iter_init_find(iter, obj, name);
}

bson_subtype_t
bson_iterator_bin_type(const bson_iter_t *iter)
{
    if (ITER_TYPE(iter) == BSON_TYPE_BINARY) {
        return ((bson_subtype_t) *(iter->raw + iter->d2));
    }
    return BSON_SUBTYPE_BINARY;
}