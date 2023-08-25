#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_fastmath.h"
#include "fastmath_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
    ZEND_PARSE_PARAMETERS_START(0, 0) \
    ZEND_PARSE_PARAMETERS_END()
#endif

static zend_class_entry *math_vector2f_ce;

// ------------------------------------------------------------------
// Vector2f class
// ------------------------------------------------------------------

PHP_METHOD(Vector2f, __construct)
{
    double x, y;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    zend_object *obj = Z_OBJ_P(ZEND_THIS);
    zend_update_property_double(math_vector2f_ce, obj, "x", sizeof("x") - 1, x);
    zend_update_property_double(math_vector2f_ce, obj, "y", sizeof("y") - 1, y);
}

static zend_function_entry vector2f_methods[] = {
    PHP_ME(Vector2f, __construct, arginfo_math_vector2f_construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_FE_END
};

// ------------------------------------------------------------------
// Module initialization
// ------------------------------------------------------------------
PHP_MINIT_FUNCTION(fastmath)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "SW\\Math", "Vector2f", vector2f_methods);
    math_vector2f_ce = zend_register_internal_class(&ce);

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
