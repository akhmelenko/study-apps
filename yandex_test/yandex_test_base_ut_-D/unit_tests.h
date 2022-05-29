/**
 * @file unit_tests.h
 * @author Anton Khmelenko (akhmelenko@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <cstdlib>

#include "allocator.h"
#include "config.h"

bool CorrectUseTest(size_t);
bool IncorrectUseTest();

#endif  // UNIT_TESTS_H
