#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "Zend/zend_smart_str.h"
#include "ext/standard/info.h"
#include "ext/standard/php_var.h"
#include "zend_smart_str_public.h"
#include "php_fastmath.h"
#include "fastmath_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
    ZEND_PARSE_PARAMETERS_START(0, 0) \
    ZEND_PARSE_PARAMETERS_END()
#endif


// ------------------------------------------------------------------
// Vector2f class
// ------------------------------------------------------------------

static zend_class_entry *vector2f_ce;

zend_class_entry *get_vector2f_ce() {
	return vector2f_ce;
}

static zend_object_handlers vector2f_handlers;

zend_object *vector2f_create_handler(zend_class_entry *class_type)
{
    size_t block_len = sizeof(vector2f_object) + zend_object_properties_size(class_type);
    vector2f_object *intern = emalloc(block_len);

    memset(intern, 0, block_len);

	intern->x = 0.0f;
	intern->y = 0.0f;

    zend_object_std_init(&intern->std, class_type);
    object_properties_init(&intern->std, class_type);

    intern->std.handlers = &vector2f_handlers;

    return &intern->std;
}

static zval *vector2f_read_prop_handler(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(object);

	if (type != BP_VAR_R && type != BP_VAR_IS) {
		zend_throw_error(NULL, "Properties are virtual and cannot be referenced!");

		rv = &EG( uninitialized_zval );
	} else {

        if (zend_string_equals_literal(member, "x")) {
		    ZVAL_DOUBLE(rv, obj_ptr->x);
        }
        else if (zend_string_equals_literal(member, "y")) {
		    ZVAL_DOUBLE(rv, obj_ptr->y);
        }
        else {
            ZVAL_NULL(rv);
        }
	}

	return rv;
}

static zval *vector2f_write_prop_handler(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
    if (Z_TYPE_P(value) == IS_LONG) {
        convert_to_double(value);
    }

    if (Z_TYPE_P(value) != IS_DOUBLE) {
		zend_throw_error(NULL, "Inside Vector2f only int and float values can be stored. '$vec[int] = float' or '$vec[int] = int']");
        return value;
    }
    else {
        vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(object);

        if (zend_string_equals_literal(member, "x")) {
		    obj_ptr->x = Z_DVAL_P(value);
        }
        else if (zend_string_equals_literal(member, "y")) {
		    obj_ptr->y = Z_DVAL_P(value);
        }
        else {
		    zend_throw_error(NULL, "Trying to write into a invalid property!");
        }
    }

	return value;
}

static HashTable *vector2f_debug_info_handler(zend_object *object, int *is_temp)
{
    vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(object);
    zval zv;
    HashTable *ht;

    ht = zend_new_array(2);
    *is_temp = 1;

    ZVAL_DOUBLE(&zv, obj_ptr->x);
    zend_hash_str_update(ht, "x", sizeof("x") - 1, &zv);
    ZVAL_DOUBLE(&zv, obj_ptr->y);
    zend_hash_str_update(ht, "y", sizeof("y") - 1, &zv);

    return ht;
}

zval *vector2f_array_get_handler(zend_object *object, zval *offset, int type, zval *rv)
{
	if(offset == NULL) {
        zend_throw_error(NULL, "Cannot apply [] to Vector2f object!");
	}

    vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(object);

    if (Z_TYPE_P(offset) == IS_LONG) {
		size_t index = (size_t)Z_LVAL_P(offset);

		if (index == 0) {
			ZVAL_DOUBLE(rv, obj_ptr->x);
		} else if (index == 1) {
			ZVAL_DOUBLE(rv, obj_ptr->y);
		} else {
			ZVAL_NULL(rv);
		}
	} else {
        zend_throw_error(NULL, "Only a int offset '$vec[int]' can be used with the Vector2f object");
		ZVAL_NULL(rv);
	}

	return rv;
}

void vector2f_array_set_handler(zend_object *object, zval *offset, zval *value)
{
	if (Z_TYPE_P(value) == IS_LONG) {
        convert_to_double(value);
    } else if (Z_TYPE_P(value) != IS_DOUBLE) {
		zend_throw_error(NULL, "Inside Vector2f only int and float values can be stored. '$vec[int] = float' or '$vec[int] = int']"); return;
	}

    vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(object);

	if (offset == NULL || Z_TYPE_P(offset) != IS_LONG || Z_LVAL_P(offset) < 0 || Z_LVAL_P(offset) >= 2) {
        zend_throw_error(NULL, "Vector2f offset must be a int '$vec[int]', 0 or 1!"); return;
	}

	if ((size_t)Z_LVAL_P(offset) == 0) {
		obj_ptr->x = Z_DVAL_P(value);
	} else {
		obj_ptr->y = Z_DVAL_P(value);
	}
}

PHP_METHOD(Vector2f, __construct)
{
    zval *obj;
    obj = getThis();
    vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(obj));

    double x = 0.0;
    double y = 0.0;
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "|dd", &x, &y) == FAILURE) {
        return;
    }

    if (ZEND_NUM_ARGS() == 0) {
        return;
    }
    else if (ZEND_NUM_ARGS() == 1) {
        obj_ptr->x = x;
        obj_ptr->y = x;

        return;
    }

    obj_ptr->x = x;
    obj_ptr->y = y;
}

// ------------------------------------------------------------------
// Module initialization
// ------------------------------------------------------------------
PHP_MINIT_FUNCTION(fastmath)
{
	zend_class_entry tmp_ce;

	INIT_NS_CLASS_ENTRY(tmp_ce, "SW\\Math", "Vector2f", vector2f_methods);
    vector2f_ce = zend_register_internal_class(&tmp_ce);
    vector2f_ce->create_object = vector2f_create_handler;

    memcpy(&vector2f_handlers, zend_get_std_object_handlers(), sizeof(vector2f_handlers));
    vector2f_handlers.get_debug_info = vector2f_debug_info_handler;
    vector2f_handlers.read_dimension = vector2f_array_get_handler;
    vector2f_handlers.write_dimension = vector2f_array_set_handler;

    vector2f_handlers.read_property = vector2f_read_prop_handler;
    vector2f_handlers.write_property = vector2f_write_prop_handler;
    // vector2f_handlers.do_operation = vector2f_do_op_handler;
    vector2f_handlers.offset = XtOffsetOf(vector2f_object, std);

    return SUCCESS;
}

// ------------------------------------------------------------------
// Module info
// ------------------------------------------------------------------
PHP_MINFO_FUNCTION(fastmath)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "fastmath support", "enabled");
    php_info_print_table_end();
}

// ------------------------------------------------------------------
// Module entry
// ------------------------------------------------------------------
zend_module_entry fastmath_module_entry = {
    STANDARD_MODULE_HEADER,
    "fastmath",
    ext_functions,
    PHP_MINIT(fastmath), // Module initialization
    NULL, // Module shutdown
    NULL, // Request initialization
    NULL, // Request shutdown
    PHP_MINFO(fastmath), // Module info
    PHP_FASTMATH_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_FASTMATH
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(fastmath)
#endif
