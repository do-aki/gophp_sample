
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_gophp.h"

/* If you declare any globals in php_gophp.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(gophp)
*/

/* True global resources - no need for thread safety here */
static int le_gophp;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("gophp.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_gophp_globals, gophp_globals)
    STD_PHP_INI_ENTRY("gophp.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_gophp_globals, gophp_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_gophp_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_gophp_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "gophp", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_gophp_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_gophp_init_globals(zend_gophp_globals *gophp_globals)
{
	gophp_globals->global_value = 0;
	gophp_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(gophp)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(gophp)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(gophp)
{
#if defined(COMPILE_DL_GOPHP) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(gophp)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(gophp)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "gophp support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ gophp_functions[]
 *
 * Every user visible function must have an entry in gophp_functions[].
 */
const zend_function_entry gophp_functions[] = {
	PHP_FE(confirm_gophp_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in gophp_functions[] */
};
/* }}} */

/* {{{ gophp_module_entry
 */
zend_module_entry gophp_module_entry = {
	STANDARD_MODULE_HEADER,
	"gophp",
	gophp_functions,
	PHP_MINIT(gophp),
	PHP_MSHUTDOWN(gophp),
	PHP_RINIT(gophp),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(gophp),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(gophp),
	PHP_GOPHP_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GOPHP
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(gophp)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
