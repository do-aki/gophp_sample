golang で php 拡張を作ってみるテスト

# environment
* CentOS release 6.7
* PHP 7.0.0RC4
* go version go1.5.1 linux/amd64

# build

```
$ phpize
$ ./configure
$ CGO_CFLAGS="-g -O0 -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1 -I. -DPHP_ATOM_INC \
-I./include -I./main \
-I`php-config --include-dir` \
-I`php-config --include-dir`/main \
-I`php-config --include-dir`/TSRM \
-I`php-config --include-dir`/Zend \
-I`php-config --include-dir`/ext \
-I`php-config --include-dir`/ext/date/lib \
-DHAVE_CONFIG_H -DCOMPILE_DL_GOPHP -fPIC -DPIC" \
CGO_LDFLAGS="-Wl,--export-dynamic -Wl,--unresolved-symbols=ignore-all" \
go build -p 1 -gcflags "-l" -buildmode=c-shared -o modules/gophp.so gophp.go export.go

```

# run

```
$ time php -d extension=`pwd`/modules/gophp.so -r 'echo go_fib(40) . PHP_EOL;'
102334155
php -d extension=`pwd`/modules/gophp.so -r 'echo go_fib(40) . PHP_EOL;'  1.87s user 0.03s system 99% cpu 1.909 total

```

# see also
http://www.slideshare.net/do_aki/writing-php-extensions-in-golang
