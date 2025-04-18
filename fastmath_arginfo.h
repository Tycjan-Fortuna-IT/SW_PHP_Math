// Macro info
//  ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(identifier, return_reference, required_num_args, type, allow_null)
//  ZEND_BEGIN_ARG_INFO_EX(identifier, pass_rest_by_reference, return_reference, required_num_args)



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

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_negated, 0, 1, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_to_negate, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_normalize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_normalized, 0, 1, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_to_normalize, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_absolute, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_absoluted, 0, 1, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_to_absolute, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_dot, 0, 1, IS_DOUBLE, 0)
    ZEND_ARG_OBJ_INFO(0, vector_to_dot, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_dotted, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_dot, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_dot, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_angleBetween, 0, 1, IS_DOUBLE, 0)
    ZEND_ARG_OBJ_INFO(0, vector_to_angle, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_angleBetweenVectors, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_angle, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_angle, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_angleBetweenDeg, 0, 1, IS_DOUBLE, 0)
    ZEND_ARG_OBJ_INFO(0, vector_to_angle, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_angleBetweenVectorsDeg, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_angle, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_angle, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_equals, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, vector_to_compare, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_equalVectors, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_compare, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_compare, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_distanceBetween, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, vector_to_distance, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_distanceBetweenVectors, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_distance, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_distance, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_distanceBetweenSquared, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, vector_to_distance, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Vector2f_distanceBetweenVectorsSquared, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_distance, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_distance, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_scale, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, scale, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_scaled, 0, 2, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_to_scale, SW\\Math\\Vector2f, 0)
	ZEND_ARG_TYPE_INFO(0, scale, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_lerp, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, vector_lerp, SW\\Math\\Vector2f, 0)
	ZEND_ARG_TYPE_INFO(0, t, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_lerped, 0, 3, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_lerp, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_lerp, SW\\Math\\Vector2f, 0)
	ZEND_ARG_TYPE_INFO(0, t, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_slerp, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, vector_slerp, SW\\Math\\Vector2f, 0)
	ZEND_ARG_TYPE_INFO(0, t, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_slerped, 0, 3, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_slerp, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_slerp, SW\\Math\\Vector2f, 0)
	ZEND_ARG_TYPE_INFO(0, t, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, vector_to_add, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_added, 0, 2, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_add, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_add, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_sub, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, vector_to_sub, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_subtracted, 0, 2, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_sub, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_sub, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_mul, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, vector_to_mul, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_multiplied, 0, 2, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_mul, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_mul, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector2f_div, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, vector_to_div, SW\\Math\\Vector2f, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Vector2f_divided, 0, 2, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_first_div, SW\\Math\\Vector2f, 0)
	ZEND_ARG_OBJ_INFO(0, vector_second_div, SW\\Math\\Vector2f, 0)
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
ZEND_METHOD(Vector2f, absolute);
ZEND_METHOD(Vector2f, absoluted);
ZEND_METHOD(Vector2f, dot);
ZEND_METHOD(Vector2f, dotted);
ZEND_METHOD(Vector2f, angleBetween);
ZEND_METHOD(Vector2f, angleBetweenVectors);
ZEND_METHOD(Vector2f, angleBetweenDeg);
ZEND_METHOD(Vector2f, angleBetweenVectorsDeg);
ZEND_METHOD(Vector2f, equals);
ZEND_METHOD(Vector2f, equalVectors);
ZEND_METHOD(Vector2f, distanceBetween);
ZEND_METHOD(Vector2f, distanceBetweenVectors);
ZEND_METHOD(Vector2f, distanceBetweenSquared);
ZEND_METHOD(Vector2f, distanceBetweenVectorsSquared);
ZEND_METHOD(Vector2f, scale);
ZEND_METHOD(Vector2f, scaled);
ZEND_METHOD(Vector2f, lerp);
ZEND_METHOD(Vector2f, lerped);
ZEND_METHOD(Vector2f, slerp);
ZEND_METHOD(Vector2f, slerped);
ZEND_METHOD(Vector2f, add);
ZEND_METHOD(Vector2f, added);
ZEND_METHOD(Vector2f, sub);
ZEND_METHOD(Vector2f, subtracted);
ZEND_METHOD(Vector2f, mul);
ZEND_METHOD(Vector2f, multiplied);
ZEND_METHOD(Vector2f, div);
ZEND_METHOD(Vector2f, divided);

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
	PHP_ME(Vector2f, absolute, arginfo_Vector2f_absolute, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, absoluted, arginfo_Vector2f_absoluted, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, dot, arginfo_Vector2f_dot, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, dotted, arginfo_Vector2f_dotted, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, angleBetween, arginfo_Vector2f_angleBetween, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, angleBetweenVectors, arginfo_Vector2f_angleBetweenVectors, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, angleBetweenDeg, arginfo_Vector2f_angleBetweenDeg, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, angleBetweenVectorsDeg, arginfo_Vector2f_angleBetweenVectorsDeg, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, equals, arginfo_Vector2f_equals, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, equalVectors, arginfo_Vector2f_equalVectors, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, distanceBetween, arginfo_Vector2f_distanceBetween, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, distanceBetweenVectors, arginfo_Vector2f_distanceBetweenVectors, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, distanceBetweenSquared, arginfo_Vector2f_distanceBetweenSquared, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, distanceBetweenVectorsSquared, arginfo_Vector2f_distanceBetweenVectorsSquared, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, scale, arginfo_Vector2f_scale, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, scaled, arginfo_Vector2f_scaled, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, lerp, arginfo_Vector2f_lerp, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, lerped, arginfo_Vector2f_lerped, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, slerp, arginfo_Vector2f_slerp, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, slerped, arginfo_Vector2f_slerped, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, add, arginfo_Vector2f_add, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, added, arginfo_Vector2f_added, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, sub, arginfo_Vector2f_sub, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, subtracted, arginfo_Vector2f_subtracted, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, mul, arginfo_Vector2f_mul, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, multiplied, arginfo_Vector2f_multiplied, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(Vector2f, div, arginfo_Vector2f_div, ZEND_ACC_PUBLIC)
	PHP_ME(Vector2f, divided, arginfo_Vector2f_divided, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_FE_END
};


// ------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////
// 							Vector3f class
/////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------

ZEND_BEGIN_ARG_INFO_EX(arginfo_Vector3f__construct, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

PHP_METHOD(Vector3f, __construct);

static zend_function_entry vector3f_methods[] = {
	PHP_ME(Vector3f, __construct, arginfo_Vector3f__construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_FE_END
};

static const zend_function_entry ext_functions[] = {
	ZEND_FE_END
};
