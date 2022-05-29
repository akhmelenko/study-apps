/**
 * @file allocator.h
 * @author Anton Khmelenko (aklhmelenko@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ALLOCATOR_H
#define ALLOCATOR_H

bool Allocator_Init();
void *Allocator_GetBlock();
bool Allocator_FreeBlock(void *pBlock);

#endif // ALLOCATOR_H