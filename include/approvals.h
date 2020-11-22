/***********************************************************************
 * ApprovalTests.c - Approval Tests for C99.
 * Copyright (c) 2020, Peter Kofler. All rights reserved.
 * BSD3 licensed.
 */

/*
 * These headers or their equivalents MUST be included prior to including
 * this header file.
 * @code
 * #include <stdlib.h>
 * @endcode
*/
extern const char* __approvals_approve(const char* received,
                                       const char* full_file_name,
                                       const char* test_name,
                                       const char* extension_no_dot);

extern const char* __approvals_xml_format(const char* xml);

#define verify_xml(xml)                                                             \
    const char* __got = __approvals_xml_format(xml);                                \
    const char* __approved = __approvals_approve(__got, __FILE__, __func__, "xml"); \
    __approval_assert_equals(__approved, __got);                                    \
    free((void*)__got);                                                             \
    free((void*)__approved);

#define verify_txt(__got)                                                             \
    const char* __approved = __approvals_approve((__got), __FILE__, __func__, "txt"); \
    __approval_assert_equals(__approved, (__got));                                    \
    free((void*)__approved);
