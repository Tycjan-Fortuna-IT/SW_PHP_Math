
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_lengthSquared, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_toArray, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_toJSON, 0, 0, 0)
    ZEND_ARG_INFO(0, precision)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_negate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_negated, 0, 3, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_to_negate, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_normalize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_normalized, 0, 3, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_to_normalize, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Vector2f, __construct);
ZEND_METHOD(Vector2f, toString);
ZEND_METHOD(Vector2f, length);
ZEND_METHOD(Vector2f, lengthSquared);
ZEND_METHOD(Vector2f, toArray);
ZEND_METHOD(Vector2f, toJSON);
ZEND_METHOD(Vector2f, negate);
ZEND_METHOD(Vector2f, negated);
ZEND_METHOD(Vector2f, normalize);
ZEND_METHOD(Vector2f, normalized);

static zend_function_entry vector2f_methods[] = {
    PHP_ME(Vector2f, __construct, arginfo_Vector2f__construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(Vector2f, toString, arginfo_Vector2f_toString, ZEND_ACC_PUBLIC)
    PHP_ME(Vector2f, length, arginfo_Vector2f_length, ZEND_ACC_PUBLIC)
    PHP_ME(Vector2f, lengthSquared, arginfo_Vector2f_lengthSquared, ZEND_ACC_PUBLIC)
    PHP_ME(Vector2f, toArray, arginfo_Vector2f_toArray, ZEND_ACC_PUBLIC)
    PHP_ME(Vector2f, toJSON, arginfo_Vector2f_toJSON, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, negate, arginfo_Vector2f_negate, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, negated, arginfo_Vector2f_negated, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, normalize, arginfo_Vector2f_normalize, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, normalized, arginfo_Vector2f_normalized, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_FE_END
};
// ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 1, 0.0)

static const zend_function_entry ext_functions[] = {
	ZEND_FE_END
};
