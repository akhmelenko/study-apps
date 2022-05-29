
/**
 * @file allocator.c
 * @author Anton Khmelenko (akhmelenko@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "allocator.h"

#include "config.h"
#include "stddef.h"

struct BLOCK {
    unsigned char block[BLOCK_SIZE];
    void *pNextFree;
};

static const size_t BLOCKS_QTY = POOL_SIZE / BLOCK_SIZE;
static struct BLOCK pool[BLOCKS_QTY];
static void *pFirstFree;

/**
 * @brief Initialization of allocator
 *
 * @return true - init success
 * @return false - block size is more then pool size
 */
bool Allocator_Init() {
    // check is poolSize more or equal block size
    if (POOL_SIZE < BLOCK_SIZE)
        return false;
    // set first free PTR to first memory block
    pFirstFree = (void *)&pool[0].block;
    // init forward directed linked list of free blocks PTRs
    for (size_t i = 0; i < BLOCKS_QTY - 1; ++i)
        pool[i]
            .pNextFree = (void *)pool[i + 1].block;
    // last list element points to NULL (as last free block sign)
    pool[BLOCKS_QTY - 1].pNextFree = NULL;
    return true;
}

/**
 * @brief Getting memory block
 * 
 * @return void* - PTR to allocated block, 
 *          NULL - error: all blocks already allocated
 */
void *Allocator_GetBlock() {
    // check is all blocks allocated
    if (pFirstFree == NULL)
        return NULL;
    void *pAllocating = pFirstFree;
    // change PTR to first free block
    pFirstFree = ((struct BLOCK *)pAllocating)->pNextFree;
    // set PTR to itself (for allocated block as allocation sign)
    ((struct BLOCK *)pAllocating)->pNextFree = (void *)((struct BLOCK *)pAllocating)->block;
    return pAllocating;
}

/**
 * @brief Releasing memory block
 * 
 * @param pBlock - PTR to realising block
 * @return true - releasing success
 * @return false - no allocated block at this PTR
 */
bool Allocator_FreeBlock(void *pBlock) {
    // check is releasing block PTR inside pool
    if (pBlock < (void *)pool[0].block || pBlock > (void *)pool[BLOCKS_QTY - 1].block)
        return false;
    // check is released block PTR points to block start
    if (((size_t)pBlock - (size_t)pool[0].block) % sizeof(struct BLOCK))
        return false;
    // check is releasing block was not allocated before
    // (block PTR = PTR to next free block for allocated block as allocation sign)
    if (((struct BLOCK *)pBlock)->pNextFree != pBlock)
        return false;
    // release block
    ((struct BLOCK *)pBlock)->pNextFree = pFirstFree;
    pFirstFree = (void *)((struct BLOCK *)pBlock)->block;
    return true;
}