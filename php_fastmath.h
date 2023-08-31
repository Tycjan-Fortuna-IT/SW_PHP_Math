/* fastmath extension for PHP */

#ifndef PHP_FASTMATH_H
# define PHP_FASTMATH_H

extern zend_module_entry fastmath_module_entry;
# define phpext_fastmath_ptr &fastmath_module_entry

# define PHP_FASTMATH_VERSION "0.1.0"

// ------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////
// 							Vector2f class
/////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------

typedef struct _vector2f_object {
    double x;
	double y;
    zend_object std;
} vector2f_object;

zend_always_inline vector2f_object *vector2f_objptr_from_zend_objptr(zend_object *obj) {
	return (vector2f_object *)((char *)obj - XtOffsetOf(vector2f_object, std));
}

zend_class_entry *get_vector2f_ce();


// ------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////
// 							Vector3f class
/////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------

typedef struct _vector3f_object {
	double x;
	double y;
	double z;
	zend_object std;
} vector3f_object;

zend_always_inline vector3f_object *vector3f_objptr_from_zend_objptr(zend_object *obj) {
	return (vector3f_object *)((char *)obj - XtOffsetOf(vector3f_object, std));
}

zend_class_entry *get_vector3f_ce();


# if defined(ZTS) && defined(COMPILE_DL_FASTMATH)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_FASTMATH_H */
