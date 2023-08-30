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
#include "mathutils.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
    ZEND_PARSE_PARAMETERS_START(0, 0) \
    ZEND_PARSE_PARAMETERS_END()
#endif


// ------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////
// 							Vector2f class
/////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------

static zend_class_entry *vector2f_ce;

zend_class_entry *get_vector2f_ce() {
	return vector2f_ce;
}

static zend_object_handlers vector2f_handlers;

/**
 * @brief Creates a new Vector2f object. Allocates memory for the object and initializes it
 * 		  with default values. The default values are 0.0f for x and y.
 *
 * @param zend_class_entry* ce
 * @return vector2f_object*
 */
static vector2f_object *create_vector2f_object(zend_class_entry *ce)
{
    vector2f_object *obj_ptr;

    obj_ptr = ecalloc(1, sizeof(vector2f_object) + zend_object_properties_size(ce));

    zend_object_std_init(&obj_ptr->std, ce);
    obj_ptr->std.handlers = &vector2f_handlers;

    obj_ptr->x = 0.0;
    obj_ptr->y = 0.0;

    return obj_ptr;
}

/**
 * @brief Creates handler for Vector2f class. Is called when a new Vector2f object is created.
 *        Responsible for allocating memory for the object and initializing the object.
 *
 * @param zend_class_entry* class_type
 * @return zend_object*
 */
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

/**
 * @brief Read property handler for Vector2f class. Is called when a property is read from the Vector2f object.
 * 		  Responsible for returning the value of the property. Only the properties 'x' and 'y' are allowed.
 * 		  Trying to access any other property will result in a exception.
 * 		  Type of the property is always double.
 *
 * @param zend_object* object
 * @param zend_string* member
 * @param int type
 * @param void** cache_slot
 * @param zval* rv
 * @return zval*
 */
static zval *vector2f_read_prop_handler(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(object);

	if (type != BP_VAR_R && type != BP_VAR_IS) {
		zend_throw_error(NULL, "Properties are virtual and cannot be referenced!");

		rv = &EG(uninitialized_zval);
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

/**
 * @brief Write property handler for Vector2f class. Is called when a property is written to the Vector2f object.
 * 		  Responsible for writing the value to the property. Only the properties 'x' and 'y' are allowed.
 * 		  Trying to write to any other property will result in a exception.
 * 		  Type of the assigned value must be long or double. Otherwise an exception is thrown.
 *
 * @param zend_object* object
 * @param zend_string* member
 * @param zval* value
 * @param void** cache_slot
 * @return zval*
 */
static zval *vector2f_write_prop_handler(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
    if (Z_TYPE_P(value) == IS_LONG) {
        convert_to_double(value);
    }

    if (Z_TYPE_P(value) != IS_DOUBLE) {
		zend_throw_error(NULL, "Inside Vector2f only int and float values can be stored. '$vec[int] = float' or '$vec[int] = int']");
        return value;
    } else {
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

/**
 * @brief Debug info handler for Vector2f class. Is called when a Vector2f object is printed.
 * 		  Responsible for returning the debug info of the Vector2f object.
 * 		  The debug info is an array with the keys 'x' and 'y' and the corresponding values.
 *
 * @param zend_object* object
 * @param int* is_temp
 * @return HashTable*
 */
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

/**
 * @brief Array get handler for Vector2f class. Is called when a Vector2f object is accessed as an array.
 * 		  Responsible for returning the value of the array offset. Only the offsets 0 and 1 are allowed.
 * 		  Trying to access any other offset will result in a exception.
 * 		  Type of the offset is always long.
 *
 * @param zend_object* object
 * @param zval* offset
 * @param int type
 * @param zval* rv
 * @return zval*
 */
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

/**
 * @brief Array set handler for Vector2f class. Is called when a Vector2f object is written to as an array.
 * 		  Responsible for writing the value to the array offset. Only the offsets 0 and 1 are allowed.
 * 		  Trying to write to any other offset will result in a exception.
 * 		  Type of the offset is always long.
 * 		  Type of the assigned value must be long or double. Otherwise an exception is thrown.
 *
 * @param zend_object* object
 * @param zval* offset
 * @param zval* value
 * @return void
 */
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

/**
 * @brief Construct a new php method object. Is called when a new Vector2f object is created.
 * 		  Responsible for initializing the Vector2f object.
 * 		  The constructor takes 0, 1 or 2 arguments. If 0 arguments are passed, the Vector2f object is initialized with 0.0f.
 * 		  If 1 argument is passed, the Vector2f object is initialized with the passed value for x and y.
 * 		  If 2 arguments are passed, the Vector2f object is initialized with the passed values for x and y.
 */
PHP_METHOD(Vector2f, __construct)
{
    zval *obj;
    vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

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

/**
 * @brief Convert Vector2f object to string.
 * 		  Responsible for returning the string representation of the Vector2f object.
 * 		  The string representation is 'vec2(x, y)'.
 *		  The values of x and y are stringified up to 5 decimal places by default.
 * 		  The precision can be changed by passing a argument to the method. Goes up to maximum digits of the value.
 *
 * @param int ?precision
 * @return void
 */
PHP_METHOD(Vector2f, toString)
{
	int precision = 5;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "|l", &precision) == FAILURE) {
        RETURN_NULL();
    }

	if (precision++ < 0) {
		zend_throw_error(NULL, "Precision must be a positive integer!");
		RETURN_NULL();
	}

	vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	smart_str buf = {0};

	smart_str_appends(&buf, "(");
	smart_str_append_double(&buf, obj_ptr->x, precision, true);
	smart_str_appends(&buf, ", ");
	smart_str_append_double(&buf, obj_ptr->y, precision, true);
	smart_str_appends(&buf, ")");
	smart_str_0(&buf);

	RETURN_STRINGL(buf.s->val, buf.s->len);

	smart_str_free(&buf);
}

/**
 * @brief Calculate the length of the Vector2f object.
 * 		  Responsible for returning the length of the Vector2f object.
 * 		  The length is calculated with the formula: sqrt(x^2 + y^2).
 *
 * @return double
 */
PHP_METHOD(Vector2f, length)
{
	vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	RETURN_DOUBLE(VECTOR2_LENGTH(obj_ptr));
}

/**
 * @brief Calculate the squared length of the Vector2f object.
 * 		  Responsible for returning the squared length of the Vector2f object.
 * 		  The squared length is calculated with the formula: x^2 + y^2.
 *
 * @return double
 */
PHP_METHOD(Vector2f, lengthSquared)
{
	vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	RETURN_DOUBLE(VECTOR2_SQUARE_LENGTH(obj_ptr));
}

/**
 * @brief Convert Vector2f object to array.
 * 		  Responsible for returning the array representation of the Vector2f object.
 * 		  The array representation is [0 => x, 1 => y].
 *
 * @return array
 */
PHP_METHOD(Vector2f, toArray)
{
	vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	array_init(return_value);

	add_next_index_double(return_value, obj_ptr->x);
	add_next_index_double(return_value, obj_ptr->y);
}

/**
 * @brief Convert Vector2f object to JSON string.
 * 		  Responsible for returning the JSON string representation of the Vector2f object.
 * 		  The JSON string representation is { "x": x, "y": y }.
 *		  The values of x and y are stringified up to 5 decimal places by default.
 * 		  The precision can be changed by passing a argument to the method. Goes up to maximum digits of the value.
 *
 * @param int ?precision
 * @return string
 */
PHP_METHOD(Vector2f, toJSON)
{
	int precision = 5;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "|l", &precision) == FAILURE) {
        RETURN_NULL();
    }

	if (precision++ < 0) {
		zend_throw_error(NULL, "Precision must be a positive integer!");
		RETURN_NULL();
	}

	vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	smart_str buf = {0};

	smart_str_appends(&buf, "{ \"x\": ");
	smart_str_append_double(&buf, obj_ptr->x, precision, true);
	smart_str_appends(&buf, ", \"y\": ");
	smart_str_append_double(&buf, obj_ptr->y, precision, true);
	smart_str_appends(&buf, " }");
	smart_str_0(&buf);

	RETURN_STRINGL(buf.s->val, buf.s->len);

	smart_str_free(&buf);
}

/**
 * @brief Negate the Vector2f object.
 * 		  Responsible for negating the Vector2f object.
 * 		  The negation is calculated with the formula: Vector2f(-x, -y).
 *
 * @return void
 */
PHP_METHOD(Vector2f, negate)
{
	vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	VECTOR2_NEGATE(obj_ptr);
}

/**
 * @brief Return new negated Vector2f object.
 * 		  Responsible for negating the Vector2f object.
 * 		  The negation is calculated with the formula: Vector2f(-x, -y).
 *
 * @param Vector2f vec_to_negate
 * @return Vector2f
 */
PHP_METHOD(Vector2f, negated)
{
    zval *vec_to_negate;
    vector2f_object *obj_ptr, *new_obj_ptr;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_negate, vector2f_ce) == FAILURE) {
        RETURN_NULL();
    }

    obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_negate));

    new_obj_ptr = create_vector2f_object(vector2f_ce);

    new_obj_ptr->x = -obj_ptr->x;
    new_obj_ptr->y = -obj_ptr->y;

    RETURN_OBJ(&new_obj_ptr->std);
}

/**
 * @brief Normalize the Vector2f object.
 * 		  Responsible for normalizing the Vector2f object.
 * 		  The normalization is calculated with the formula: Vector2f(x / length, y / length).
 *
 */
PHP_METHOD(Vector2f, normalize)
{
	vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	VECTOR2_NORMALIZE(obj_ptr);
}

/**
 * @brief Return new normalized Vector2f object.
 * 		  Responsible for normalizing the Vector2f object.
 * 		  The normalization is calculated with the formula: Vector2f(x / length, y / length).
 *
 * @param Vector2f vec_to_normalize
 * @return Vector2f
 */
PHP_METHOD(Vector2f, normalized)
{
	zval *vec_to_normalize;
	vector2f_object *obj_ptr, *new_obj_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_normalize, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_normalize));

	new_obj_ptr = create_vector2f_object(vector2f_ce);

	new_obj_ptr->x = obj_ptr->x;
	new_obj_ptr->y = obj_ptr->y;

	VECTOR2_NORMALIZE(new_obj_ptr);

	RETURN_OBJ(&new_obj_ptr->std);
}

/**
 * @brief Absolute the Vector2f object.
 * 		  Responsible for absolute the Vector2f object.
 * 		  The absolute is calculated with the formula: Vector2f(abs(x), abs(y)).
 *
 * @return void
 */
PHP_METHOD(Vector2f, absolute)
{
	vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	VECTOR2_ABSOLUTE(obj_ptr);
}

/**
 * @brief Return new absoluted Vector2f object.
 * 		  Responsible for absolute the Vector2f object.
 * 		  The absolute is calculated with the formula: Vector2f(abs(x), abs(y)).
 *
 * @param Vector2f vec_to_absolute
 * @return Vector2f
 */
PHP_METHOD(Vector2f, absoluted)
{
	zval *vec_to_absolute;
	vector2f_object *obj_ptr, *new_obj_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_absolute, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_absolute));

	new_obj_ptr = create_vector2f_object(vector2f_ce);

	new_obj_ptr->x = obj_ptr->x;
	new_obj_ptr->y = obj_ptr->y;

	VECTOR2_ABSOLUTE(new_obj_ptr);

	RETURN_OBJ(&new_obj_ptr->std);
}

/**
 * @brief Dot the Vector2f object.
 * 		  Responsible for dot the Vector2f object.
 * 		  The dot is calculated with the formula: x * x + y * y.
 *
 * @param Vector2f vec_to_dot
 * @return double
 */
PHP_METHOD(Vector2f, dot)
{
	zval *vec_to_dot;
	vector2f_object *vec_to_dot_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_dot, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_dot_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_dot));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	RETURN_DOUBLE(VECTOR2_DOT(this_obj_ptr, vec_to_dot_ptr));
}

/**
 * @brief Dotted the Vector2f object.
 * 		  Responsible for dotted the Vector2f object.
 * 		  The dot is calculated with the formula: x1 * x2 + y1 * y2.
 *
 * @param Vector2f vec_first_dot
 * @param Vector2f vec_second_dot
 * @return double
 */
PHP_METHOD(Vector2f, dotted)
{
	zval *vec_first_dot, *vec_second_dot;
	vector2f_object *vec_first_dot_ptr, *vec_second_dot_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OO", &vec_first_dot, vector2f_ce, &vec_second_dot, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_dot_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_dot));
	vec_second_dot_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_dot));

	RETURN_DOUBLE(VECTOR2_DOT(vec_first_dot_ptr, vec_second_dot_ptr));
}

/**
 * @brief Angle between this and the second Vector2f object.
 * 		  Responsible for angle between this vector and second passed Vector2f object.
 * 		  The angle is calculated with the formula: acos(dot(this, vec) / (length(this) * length(vec))).
 * 		  The angle is returned in radians.
 *
 * @param Vector2f vec_to_angle
 * @return double
 */
PHP_METHOD(Vector2f, angleBetween)
{
	zval* vec_to_angle;
	vector2f_object *vec_to_angle_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_angle, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_angle_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_angle));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	RETURN_DOUBLE(VECTOR2_ANGLE_BETWEEN(this_obj_ptr, vec_to_angle_ptr));
}

/**
 * @brief Angle between the first and second Vector2f object.
 * 		  Responsible for angle between first and second passed Vector2f object.
 * 		  The angle is calculated with the formula: acos(dot(vec1, vec2) / (length(vec1) * length(vec2))).
 * 		  The angle is returned in radians.
 *
 * @param Vector2f vec_first_angle
 * @param Vector2f vec_second_angle
 * @return double
 */
PHP_METHOD(Vector2f, angleBetweenVectors)
{
	zval* vec_first_angle, *vec_second_angle;
	vector2f_object *vec_first_angle_ptr, *vec_second_angle_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OO", &vec_first_angle, vector2f_ce, &vec_second_angle, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_angle_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_angle));
	vec_second_angle_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_angle));

	RETURN_DOUBLE(VECTOR2_ANGLE_BETWEEN(vec_first_angle_ptr, vec_second_angle_ptr));
}

/**
 * @brief Angle between this and the second Vector2f object.
 * 		  Responsible for angle between this vector and second passed Vector2f object.
 * 		  The angle is calculated with the formula: acos(dot(this, vec) / (length(this) * length(vec))).
 * 		  The angle is returned in degrees.
 *
 * @param Vector2f vec_to_angle
 * @return double
 */
PHP_METHOD(Vector2f, angleBetweenDeg)
{
	zval* vec_to_angle;
	vector2f_object *vec_to_angle_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_angle, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_angle_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_angle));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	RETURN_DOUBLE(RAD_TO_DEG(VECTOR2_ANGLE_BETWEEN(this_obj_ptr, vec_to_angle_ptr)));
}

/**
 * @brief Angle between the first and second Vector2f object.
 * 		  Responsible for angle between first and second passed Vector2f object.
 * 		  The angle is calculated with the formula: acos(dot(vec1, vec2) / (length(vec1) * length(vec2))).
 * 		  The angle is returned in degrees.
 *
 * @param Vector2f vec_first_angle
 * @param Vector2f vec_second_angle
 * @return double
 */
PHP_METHOD(Vector2f, angleBetweenVectorsDeg)
{
	zval* vec_first_angle, *vec_second_angle;
	vector2f_object *vec_first_angle_ptr, *vec_second_angle_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OO", &vec_first_angle, vector2f_ce, &vec_second_angle, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_angle_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_angle));
	vec_second_angle_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_angle));

	RETURN_DOUBLE(RAD_TO_DEG(VECTOR2_ANGLE_BETWEEN(vec_first_angle_ptr, vec_second_angle_ptr)));
}

/**
 * @brief Check if the Vector2f object is equal to the second Vector2f object.
 * 		  Responsible for checking if the Vector2f object is equal to the second Vector2f object. (Dont use == operator)
 * 		  The equality is calculated with the formula: x1 == x2 && y1 == y2.
 *
 * @param Vector2f vec_to_check
 * @return bool
 */
PHP_METHOD(Vector2f, equals)
{
	zval* vec_to_check;
	vector2f_object *vec_to_check_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_check, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_check_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_check));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	RETURN_BOOL(VECTOR2_EQUALS(this_obj_ptr, vec_to_check_ptr));
}

/**
 * @brief Check if the first Vector2f object is equal to the second Vector2f object.
 * 		  Responsible for checking if the first Vector2f object is equal to the second Vector2f object. (Dont use == operator)
 * 		  The equality is calculated with the formula: x1 == x2 && y1 == y2.
 *
 * @param Vector2f vec_first_check
 * @param Vector2f vec_second_check
 * @return bool
 */
PHP_METHOD(Vector2f, equalVectors)
{
	zval* vec_first_check, *vec_second_check;
	vector2f_object *vec_first_check_ptr, *vec_second_check_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OO", &vec_first_check, vector2f_ce, &vec_second_check, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_check_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_check));
	vec_second_check_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_check));

	RETURN_BOOL(VECTOR2_EQUALS(vec_first_check_ptr, vec_second_check_ptr));
}

/**
 * @brief Calculate the distance between this and the second Vector2f object.
 * 		  Responsible for calculating the distance between this and the second Vector2f object.
 * 		  The distance is calculated with the formula: sqrt((x1 - x2)^2 + (y1 - y2)^2).
 *
 * @param Vector2f vec_to_distance
 * @return double
 */
PHP_METHOD(Vector2f, distanceBetween)
{
	zval* vec_to_distance;
	vector2f_object *vec_to_distance_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_distance, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_distance_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_distance));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	RETURN_DOUBLE(VECTOR2_DISTANCE_BETWEEN(this_obj_ptr, vec_to_distance_ptr));
}

/**
 * @brief Calculate the distance between the first and second Vector2f object.
 * 		  Responsible for calculating the distance between the first and second Vector2f object.
 * 		  The distance is calculated with the formula: sqrt((x1 - x2)^2 + (y1 - y2)^2).
 *
 * @param Vector2f vec_first_distance
 * @param Vector2f vec_second_distance
 * @return double
 */
PHP_METHOD(Vector2f, distanceBetweenVectors)
{
	zval* vec_first_distance, *vec_second_distance;
	vector2f_object *vec_first_distance_ptr, *vec_second_distance_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OO", &vec_first_distance, vector2f_ce, &vec_second_distance, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_distance_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_distance));
	vec_second_distance_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_distance));

	RETURN_DOUBLE(VECTOR2_DISTANCE_BETWEEN(vec_first_distance_ptr, vec_second_distance_ptr));
}

/**
 * @brief Calculate the squared distance between this and the second Vector2f object.
 * 		  Responsible for calculating the squared distance between this and the second Vector2f object.
 * 		  The squared distance is calculated with the formula: (x1 - x2)^2 + (y1 - y2)^2.
 *
 * @param Vector2f vec_to_distance
 * @return double
 */
PHP_METHOD(Vector2f, distanceBetweenSquared)
{
	zval* vec_to_distance;
	vector2f_object *vec_to_distance_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_distance, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_distance_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_distance));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	RETURN_DOUBLE(VECTOR2_DISTANCE_BETWEEN_SQUARED(this_obj_ptr, vec_to_distance_ptr));
}

/**
 * @brief Calculate the squared distance between the first and second Vector2f object.
 * 		  Responsible for calculating the squared distance between the first and second Vector2f object.
 * 		  The squared distance is calculated with the formula: (x1 - x2)^2 + (y1 - y2)^2.
 *
 * @param Vector2f vec_first_distance
 * @param Vector2f vec_second_distance
 * @return double
 */
PHP_METHOD(Vector2f, distanceBetweenVectorsSquared)
{
	zval* vec_first_distance, *vec_second_distance;
	vector2f_object *vec_first_distance_ptr, *vec_second_distance_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OO", &vec_first_distance, vector2f_ce, &vec_second_distance, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_distance_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_distance));
	vec_second_distance_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_distance));

	RETURN_DOUBLE(VECTOR2_DISTANCE_BETWEEN_SQUARED(vec_first_distance_ptr, vec_second_distance_ptr));
}

/**
 * @brief Scale the Vector2f object.
 * 		  Responsible for scaling the Vector2f object.
 * 		  The scaling is calculated with the formula: Vector2f(x * scale, y * scale).
 *
 * @param double scale
 * @return void
 */
PHP_METHOD(Vector2f, scale)
{
	double scale_val;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "d", &scale_val) == FAILURE) {
		RETURN_NULL();
	}

	vector2f_object *obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	VECTOR2_SCALE(obj_ptr, scale_val);
}

/**
 * @brief Return new scaled Vector2f object.
 * 		  Responsible for scaling the Vector2f object.
 * 		  The scaling is calculated with the formula: Vector2f(x * scale, y * scale).
 *
 * @param Vector2f vec_to_scale
 * @param double scale
 * @return Vector2f
 */
PHP_METHOD(Vector2f, scaled)
{
	zval *vec_to_scale;
	double scale_val;
	vector2f_object *vec_to_scale_ptr, *new_obj_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "Od", &vec_to_scale, vector2f_ce, &scale_val) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_scale_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_scale));

	new_obj_ptr = create_vector2f_object(vector2f_ce);

	new_obj_ptr->x = vec_to_scale_ptr->x;
	new_obj_ptr->y = vec_to_scale_ptr->y;

	VECTOR2_SCALE(new_obj_ptr, scale_val);

	RETURN_OBJ(&new_obj_ptr->std);
}

/**
 * @brief Lerps the Vector2f object.
 * 		  Responsible for lerping the Vector2f object.
 *
 * @param Vector2f vector_lerp
 * @param double t
 * @return void
 */
PHP_METHOD(Vector2f, lerp)
{
	zval *vec_to_lerp;
	double t;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "Od", &vec_to_lerp, vector2f_ce, &t) == FAILURE) {
		RETURN_NULL();
	}

	vector2f_object *vec_to_lerp_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_lerp));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	VECTOR2_LERP(this_obj_ptr, vec_to_lerp_ptr, t);
}

/**
 * @brief Return new lerped Vector2f object.
 * 		  Responsible for lerping the Vector2f object.
 *
 * @param Vector2f vector_first_lerp
 * @param Vector2f vector_second_lerp
 * @param double t
 * @return Vector2f
 */
PHP_METHOD(Vector2f, lerped)
{
	zval *vec_first_lerp, *vec_second_lerp;
	double t;
	vector2f_object *vec_first_lerp_ptr, *vec_second_lerp_ptr, *new_obj_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OOd", &vec_first_lerp, vector2f_ce, &vec_second_lerp, vector2f_ce, &t) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_lerp_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_lerp));
	vec_second_lerp_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_lerp));

	new_obj_ptr = create_vector2f_object(vector2f_ce);

	new_obj_ptr->x = vec_first_lerp_ptr->x;
	new_obj_ptr->y = vec_first_lerp_ptr->y;

	VECTOR2_LERP(new_obj_ptr, vec_second_lerp_ptr, t);

	RETURN_OBJ(&new_obj_ptr->std);
}

/**
 * @brief Slerps the Vector2f object.
 * 		  Responsible for slerping the Vector2f object.
 *
 * @param Vector2f vector_to_slerp
 * @param double t
 * @return void
 */
PHP_METHOD(Vector2f, slerp)
{
	zval *vec_to_slerp;
	double t;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "Od", &vec_to_slerp, vector2f_ce, &t) == FAILURE) {
		RETURN_NULL();
	}

	vector2f_object *vec_to_slerp_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_slerp));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	VECTOR2_SLERP(this_obj_ptr, vec_to_slerp_ptr, t);
}

/**
 * @brief Return new slerped Vector2f object.
 * 		  Responsible for slerping the Vector2f object.
 *
 * @param Vector2f vector_first_slerp
 * @param Vector2f vector_second_slerp
 * @param double t
 * @return Vector2f
 */
PHP_METHOD(Vector2f, slerped)
{
	zval *vec_first_slerp, *vec_second_slerp;
	double t;
	vector2f_object *vec_first_slerp_ptr, *vec_second_slerp_ptr, *new_obj_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OOd", &vec_first_slerp, vector2f_ce, &vec_second_slerp, vector2f_ce, &t) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_slerp_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_slerp));
	vec_second_slerp_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_slerp));

	new_obj_ptr = create_vector2f_object(vector2f_ce);

	new_obj_ptr->x = vec_first_slerp_ptr->x;
	new_obj_ptr->y = vec_first_slerp_ptr->y;

	VECTOR2_SLERP(new_obj_ptr, vec_second_slerp_ptr, t);

	RETURN_OBJ(&new_obj_ptr->std);
}

/**
 * @brief Add second Vector2f object to this Vector2f object.
 * 		  Responsible for adding second Vector2f object to this Vector2f object.
 * 		  The addition is calculated with the formula: Vector2f(x + vec.x, y + vec.y).
 *
 * @param Vector2f vec_to_add
 *
 * @return void
 */
PHP_METHOD(Vector2f, add)
{
	zval *vec_to_add;
	vector2f_object *vec_to_add_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_add, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_add_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_add));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	VECTOR2_ADD(this_obj_ptr, vec_to_add_ptr);
}

/**
 * @brief Return new added Vector2f object.
 * 		  Responsible for adding second Vector2f object to this Vector2f object.
 * 		  The addition is calculated with the formula: Vector2f(x + vec.x, y + vec.y).
 *
 * @param Vector2f vec_first_add
 * @param Vector2f vec_second_add
 *
 * @return Vector2f
 */
PHP_METHOD(Vector2f, added)
{
	zval *vec_first_add, *vec_second_add;
	vector2f_object *vec_first_add_ptr, *vec_second_add_ptr, *new_obj_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OO", &vec_first_add, vector2f_ce, &vec_second_add, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_add_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_add));
	vec_second_add_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_add));

	new_obj_ptr = create_vector2f_object(vector2f_ce);

	new_obj_ptr->x = vec_first_add_ptr->x;
	new_obj_ptr->y = vec_first_add_ptr->y;

	VECTOR2_ADD(new_obj_ptr, vec_second_add_ptr);

	RETURN_OBJ(&new_obj_ptr->std);
}

/**
 * @brief Subtract second Vector2f object from this Vector2f object.
 * 		  Responsible for subtracting second Vector2f object from this Vector2f object.
 * 		  The subtraction is calculated with the formula: Vector2f(x - vec.x, y - vec.y).
 *
 * @param Vector2f vec_to_sub
 *
 * @return void
 */
PHP_METHOD(Vector2f, sub)
{
	zval *vec_to_sub;
	vector2f_object *vec_to_sub_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_sub, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_sub_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_sub));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	VECTOR2_SUBTRACT(this_obj_ptr, vec_to_sub_ptr);
}

/**
 * @brief Return new subtracted Vector2f object.
 * 		  Responsible for subtracting second Vector2f object from this Vector2f object.
 * 		  The subtraction is calculated with the formula: Vector2f(x - vec.x, y - vec.y).
 *
 * @param Vector2f vec_first_sub
 * @param Vector2f vec_second_sub
 *
 * @return Vector2f
 */
PHP_METHOD(Vector2f, subtracted)
{
	zval *vec_first_sub, *vec_second_sub;
	vector2f_object *vec_first_sub_ptr, *vec_second_sub_ptr, *new_obj_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OO", &vec_first_sub, vector2f_ce, &vec_second_sub, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_sub_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_sub));
	vec_second_sub_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_sub));

	new_obj_ptr = create_vector2f_object(vector2f_ce);

	new_obj_ptr->x = vec_first_sub_ptr->x;
	new_obj_ptr->y = vec_first_sub_ptr->y;

	VECTOR2_SUBTRACT(new_obj_ptr, vec_second_sub_ptr);

	RETURN_OBJ(&new_obj_ptr->std);
}

/**
 * @brief Multiply this Vector2f object by second Vector2f object.
 * 		  Responsible for multiplying this Vector2f object by second Vector2f object.
 * 		  The multiplication is calculated with the formula: Vector2f(x * vec.x, y * vec.y).
 *
 * @param Vector2f vec_to_mul
 *
 * @return void
 */
PHP_METHOD(Vector2f, mul)
{
	zval *vec_to_mul;
	vector2f_object *vec_to_mul_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_mul, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_mul_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_mul));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	VECTOR2_MULTIPLY(this_obj_ptr, vec_to_mul_ptr);
}

/**
 * @brief Return new multiplied Vector2f object.
 * 		  Responsible for multiplying this Vector2f object by second Vector2f object.
 * 		  The multiplication is calculated with the formula: Vector2f(x * vec.x, y * vec.y).
 *
 * @param Vector2f vec_first_mul
 * @param Vector2f vec_second_mul
 *
 * @return Vector2f
 */
PHP_METHOD(Vector2f, multiplied)
{
	zval *vec_first_mul, *vec_second_mul;
	vector2f_object *vec_first_mul_ptr, *vec_second_mul_ptr, *new_obj_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OO", &vec_first_mul, vector2f_ce, &vec_second_mul, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_mul_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_mul));
	vec_second_mul_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_mul));

	new_obj_ptr = create_vector2f_object(vector2f_ce);

	new_obj_ptr->x = vec_first_mul_ptr->x;
	new_obj_ptr->y = vec_first_mul_ptr->y;

	VECTOR2_MULTIPLY(new_obj_ptr, vec_second_mul_ptr);

	RETURN_OBJ(&new_obj_ptr->std);
}

/**
 * @brief Divide this Vector2f object by second Vector2f object.
 * 		  Responsible for dividing this Vector2f object by second Vector2f object.
 * 		  The division is calculated with the formula: Vector2f(x / vec.x, y / vec.y).
 *
 * @param Vector2f vec_to_div
 *
 * @return void
 */
PHP_METHOD(Vector2f, div)
{
	zval *vec_to_div;
	vector2f_object *vec_to_div_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &vec_to_div, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_to_div_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_to_div));

	vector2f_object *this_obj_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(ZEND_THIS));

	VECTOR2_DIVIDE(this_obj_ptr, vec_to_div_ptr);
}

/**
 * @brief Return new divided Vector2f object.
 * 		  Responsible for dividing this Vector2f object by second Vector2f object.
 * 		  The division is calculated with the formula: Vector2f(x / vec.x, y / vec.y).
 *
 * @param Vector2f vec_first_div
 * @param Vector2f vec_second_div
 *
 * @return Vector2f
 */
PHP_METHOD(Vector2f, divided)
{
	zval *vec_first_div, *vec_second_div;
	vector2f_object *vec_first_div_ptr, *vec_second_div_ptr, *new_obj_ptr;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "OO", &vec_first_div, vector2f_ce, &vec_second_div, vector2f_ce) == FAILURE) {
		RETURN_NULL();
	}

	vec_first_div_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_first_div));
	vec_second_div_ptr = vector2f_objptr_from_zend_objptr(Z_OBJ_P(vec_second_div));

	new_obj_ptr = create_vector2f_object(vector2f_ce);

	new_obj_ptr->x = vec_first_div_ptr->x;
	new_obj_ptr->y = vec_first_div_ptr->y;

	VECTOR2_DIVIDE(new_obj_ptr, vec_second_div_ptr);

	RETURN_OBJ(&new_obj_ptr->std);
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
