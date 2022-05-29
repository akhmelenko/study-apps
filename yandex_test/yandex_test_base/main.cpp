#include <iostream>

int testVar;
void TestFunc(volatile int funcVar) {
    return;
}

struct TEST {
    int intVar0;
    int intVar1;
    char charVar0;
};

// const size_t POOL_SIZE = 7;
// const size_t BLOCK_SIZE = 2;

struct BLOCK {
    char block[BLOCK_SIZE];
    void *pNextFree;
};
const size_t BLOCKS_QTY = POOL_SIZE / BLOCK_SIZE;
static struct BLOCK pool[BLOCKS_QTY];
static void *pFirstFree = (void *)&pool[0].block;

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
    // init forward directed linked list of free blocks PTRs
    for (size_t i = 0; i < BLOCKS_QTY - 1; ++i)
        pool[i].pNextFree = (void *)pool[i + 1].block;
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

int main() {
    TestFunc(testVar);

    // Allocator_Init();

    // void *pBlock1 = Allocator_GetBlock();
    // if (pBlock1 == NULL)
    //     std::cout << "Allocation failed - no free space" << std::endl;
    // else
    //     std::cout << "Allocated block PTR = " << pBlock1 << std::endl;
    // void *pBlock2 = Allocator_GetBlock();
    // if (pBlock2 == NULL)
    //     std::cout << "Allocation failed - no free space" << std::endl;
    // else
    //     std::cout << "Allocated block PTR = " << pBlock2 << std::endl;
    // void *pBlock3 = Allocator_GetBlock();
    // if (pBlock3 == NULL)
    //     std::cout << "Allocation failed - no free space" << std::endl;
    // else
    //     std::cout << "Allocated block PTR = " << pBlock3 << std::endl;
    // void *pBlock4 = Allocator_GetBlock();
    // if (pBlock4 == NULL)
    //     std::cout << "Allocation failed - no free space" << std::endl;
    // else
    //     std::cout << "Allocated block PTR = " << pBlock4 << std::endl;

    // if (Allocator_FreeBlock(pBlock2))
    //     std::cout << "Block " << pBlock2 << " released successfully" << std::endl;
    // else
    //     std::cout << "Released block " << pBlock2 << " is not allocated!" << std::endl;
    // if (Allocator_FreeBlock(pBlock2))
    //     std::cout << "Block " << pBlock2 << " released successfully" << std::endl;
    // else
    //     std::cout << "Released block " << pBlock2 << " is not allocated!" << std::endl;
    // void *pBlock10 = pBlock1 + 100;
    // if (Allocator_FreeBlock(pBlock10))
    //     std::cout << "Block " << pBlock10 << " released successfully" << std::endl;
    // else
    //     std::cout << "Released block " << pBlock10 << " is not allocated!" << std::endl;

    // void *pBlock5 = Allocator_GetBlock();
    // if (pBlock5 == NULL)
    //     std::cout << "Allocation failed - no free space" << std::endl;
    // else
    //     std::cout << "Allocated block PTR = " << pBlock5 << std::endl;
    // void *pBlock6 = Allocator_GetBlock();
    // if (pBlock6 == NULL)
    //     std::cout << "Allocation failed - no free space" << std::endl;
    // else
    //     std::cout << "Allocated block PTR = " << pBlock6 << std::endl;
    // void *pBlock7 = Allocator_GetBlock();
    // if (pBlock7 == NULL)
    //     std::cout << "Allocation failed - no free space" << std::endl;
    // else
    //     std::cout << "Allocated block PTR = " << pBlock7 << std::endl;

    return 0;
}