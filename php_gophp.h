
#ifndef PHP_GOPHP_H
#define PHP_GOPHP_H

extern zend_module_entry gophp_module_entry;
#define phpext_gophp_ptr &gophp_module_entry

#define PHP_GOPHP_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_GOPHP_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_GOPHP_API __attribute__ ((visibility("default")))
#else
#	define PHP_GOPHP_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(gophp)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(gophp)
*/

/* Always refer to the globals in your function as GOPHP_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define GOPHP_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(gophp, v)

#if defined(ZTS) && defined(COMPILE_DL_GOPHP)
ZEND_TSRMLS_CACHE_EXTERN();
#endif

PHP_FUNCTION(go_fib);

#endif	/* PHP_GOPHP_H */

