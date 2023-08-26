
// ------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////
// 							Vector2f class
/////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f__construct, 0, 0, 1)
    ZEND_ARG_INFO(0, x)
    ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_toString, 0, 0, 0)
    ZEND_ARG_INFO(0, precision)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_length, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Vector2f, __construct);
ZEND_METHOD(Vector2f, toString);
ZEND_METHOD(Vector2f, length);

static zend_function_entry vector2f_methods[] = {
    PHP_ME(Vector2f, __construct, arginfo_Vector2f__construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(Vector2f, toString, arginfo_Vector2f_toString, ZEND_ACC_PUBLIC)
    PHP_ME(Vector2f, length, arginfo_Vector2f_length, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
// ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 1, 0.0)

static const zend_function_entry ext_functions[] = {
	ZEND_FE_END
};
