/***********************************************************************
 * ApprovalTests.c - micro Approval Tests for C99.
 * Copyright (c) 2020, Peter Kofler. All rights reserved.
 * BSD3 licensed.
 */

/*
#include <cmocka.h>
#include <stdlib.h>
*/

extern const char* __approvals_verify(const char* received,
                                      const char* full_file_name,
                                      const char* test_name,
                                      const char* extension_no_dot);

#define verify_xml(xml, testName)                                                  \
    const char* __got = (xml);                                                     \
    const char* __approved = __approvals_verify(__got, __FILE__, testName, "xml"); \
    assert_string_equal(__approved, __got);                                        \
    free((void*)__approved);

#define verify_txt(txt, testName)                                                  \
    const char* __got = (txt);                                                     \
    const char* __approved = __approvals_verify(__got, __FILE__, testName, "txt"); \
    assert_string_equal(__approved, __got);                                        \
    free((void*)__approved);
