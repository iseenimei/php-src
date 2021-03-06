/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) 1998-2015 Zend Technologies Ltd. (http://www.zend.com) |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.zend.com/license/2_00.txt.                                |
   | If you did not receive a copy of the Zend license and are unable to  |
   | obtain it through the world-wide-web, please send a note to          |
   | license@zend.com so we can mail you a copy immediately.              |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@zend.com>                                |
   |          Marcus Boerger <helly@php.net>                              |
   |          Sterling Hughes <sterling@php.net>                          |
   |          Zeev Suraski <zeev@zend.com>                                |
   +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef ZEND_EXCEPTIONS_H
#define ZEND_EXCEPTIONS_H

BEGIN_EXTERN_C()

extern ZEND_API zend_class_entry *zend_ce_throwable;
extern ZEND_API zend_class_entry *zend_ce_division_by_zero_error;

ZEND_API void zend_exception_set_previous(zend_object *exception, zend_object *add_previous);
ZEND_API void zend_exception_save(void);
ZEND_API void zend_exception_restore(void);

ZEND_API void zend_throw_exception_internal(zval *exception);

void zend_register_default_exception(void);

ZEND_API zend_class_entry *zend_get_exception_base(zval *object);
ZEND_API zend_class_entry *zend_exception_get_default(void);
ZEND_API zend_class_entry *zend_get_error_exception(void);
ZEND_API zend_class_entry *zend_get_error(void);
ZEND_API zend_class_entry *zend_get_parse_error(void);
ZEND_API zend_class_entry *zend_get_type_error(void);
ZEND_API void zend_register_default_classes(void);

/* exception_ce   NULL or zend_exception_get_default() or a derived class
 * message        NULL or the message of the exception */
ZEND_API zend_object *zend_throw_exception(zend_class_entry *exception_ce, const char *message, zend_long code);
ZEND_API zend_object *zend_throw_exception_ex(zend_class_entry *exception_ce, zend_long code, const char *format, ...);
ZEND_API void zend_throw_exception_object(zval *exception);
ZEND_API void zend_clear_exception(void);

ZEND_API zend_object *zend_throw_error_exception(zend_class_entry *exception_ce, const char *message, zend_long code, int severity);

extern ZEND_API void (*zend_throw_exception_hook)(zval *ex);

/* show an exception using zend_error(severity,...), severity should be E_ERROR */
ZEND_API void zend_exception_error(zend_object *exception, int severity);

/* do not export, in php it's available thru spprintf directly */
size_t zend_spprintf(char **message, size_t max_len, const char *format, ...);
zend_string *zend_strpprintf(size_t max_len, const char *format, ...);

END_EXTERN_C()

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
