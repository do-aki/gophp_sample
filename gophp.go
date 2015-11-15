package main

/*
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_gophp.h"

static int le_gophp;

PHP_MINIT_FUNCTION(gophp)
{
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(gophp)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(gophp)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "gophp support", "enabled");
	php_info_print_table_end();
}

const zend_function_entry gophp_functions[] = {
	PHP_FE(go_fib,	NULL)
	PHP_FE_END
};

zend_module_entry gophp_module_entry = {
	STANDARD_MODULE_HEADER,
	"gophp",
	gophp_functions,
	PHP_MINIT(gophp),
	PHP_MSHUTDOWN(gophp),
	NULL,
	NULL,
	PHP_MINFO(gophp),
	PHP_GOPHP_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_GOPHP
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(gophp)
#endif

extern unsigned int fib(unsigned int n);

PHP_FUNCTION(go_fib)
{
    zend_long n;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &n) == FAILURE) {
        return;
    }

    RETURN_LONG(fib(n));

}
*/
import "C"

func main(){}

