/* fastmath extension for PHP */

#ifndef PHP_FASTMATH_H
# define PHP_FASTMATH_H

extern zend_module_entry fastmath_module_entry;
# define phpext_fastmath_ptr &fastmath_module_entry

# define PHP_FASTMATH_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_FASTMATH)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_FASTMATH_H */
