/**
 * @file unit_tests.cpp
 * @author Anton Khmelenko (akhmelenko@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "unit_tests.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

#include "allocator.h"
#include "config.h"

struct BLOCK_CONTEXT {
    void* pBlock;
    unsigned char value;
    bool operator<(const struct BLOCK_CONTEXT& rhs) {
        return (size_t)pBlock < (size_t)rhs.pBlock;
    }
};

/**
 * @brief Chack validation of all blocks
 * 
 * @param allocatedBlocksContext
 * @return true 
 * @return false 
 */
static bool ValidateAllBlocks(const std::vector<struct BLOCK_CONTEXT>& allocatedBlocksContext) {
    // iterate blocks
    std::cout << std::showbase;
    for (const auto& elem : allocatedBlocksContext) {
        // iterate and compare bytes in block with context value
        for (size_t i = 0; i < BLOCK_SIZE; ++i) {
            std::cout << std::showbase;
            std::cout
                << "correct value: " << std::dec << elem.value
                << " block data: " << std::dec << ((unsigned char*)elem.pBlock)[i]
                << std::endl;
            if (elem.value != ((unsigned char*)elem.pBlock)[i])
                return false;
        }
    }
    return true;
}

/**
 * @brief Allocate and Fill All Blocks
 * 
 * @param allocatedBlocksContext 
 * @param blocksQty 
 * @return true 
 * @return false 
 */
static bool AllocateAndFillAllBlocks(
    std::vector<struct BLOCK_CONTEXT>& allocatedBlocksContext,
    size_t blocksQty) {
    while (blocksQty--) {
        allocatedBlocksContext.push_back((struct BLOCK_CONTEXT){NULL, 0});
        // allocate block
        allocatedBlocksContext.back().pBlock = Allocator_GetBlock();
        if (allocatedBlocksContext.back().pBlock == NULL) {
            std::cout
                << "Allocator_GetBlock() Error: NULL PTR return "
                << "within valid number of blocks allocating"
                << std::endl;
            return false;
        }
        // get random data
        unsigned char randomByte = rand();
        // save value element to the block context
        allocatedBlocksContext.back().value = randomByte;
        // fill block by random data
        memset(allocatedBlocksContext.back().pBlock, randomByte, BLOCK_SIZE);
    }
    return true;
}

/**
 * @brief Release All Blocks With Validation
 * 
 * @param allocatedBlocksContext 
 * @return true 
 * @return false 
 */
static bool ReleaseAllBlocksWithValidation(
    std::vector<struct BLOCK_CONTEXT>& allocatedBlocksContext) {
    // Check left blocks data every time after each releasing block and free random by one block
    while (allocatedBlocksContext.size() > 0) {
        // validate all allocated blocks
        if (!ValidateAllBlocks(allocatedBlocksContext)) {
            std::cout << "Error: Blocks validation Fail" << std::endl;
            return false;
        }
        // get erasing element (block) number by random
        size_t eraseElemNumber =
            allocatedBlocksContext.size() > 1 ? rand() % (allocatedBlocksContext.size() - 1) : 0;
        // Release the block
        if (!Allocator_FreeBlock(allocatedBlocksContext[eraseElemNumber].pBlock)) {
            std::cout
                << "Error: Allocator_FreeBlock(void *pBlock) return coutor during"
                << std::endl;
            return false;
        }
        std::cout
            << "Block with address " << allocatedBlocksContext[eraseElemNumber].pBlock << " released"
            << std::endl;
        allocatedBlocksContext.erase(allocatedBlocksContext.begin() + eraseElemNumber);
    }
    return true;
}

/**
 * @brief Correct use test
 * 
 * @param passNum 
 * @return true 
 * @return false 
 */
bool CorrectUseTest(size_t passNum) {
    std::cout << "\n===========CorrectUseTest============\n";
    size_t blocksQty = POOL_SIZE / BLOCK_SIZE;

    // Allocator_Init() return check
    bool allocatorIninResult = Allocator_Init();
    if ((allocatorIninResult == true && blocksQty == 0) || (allocatorIninResult == false && blocksQty > 0)) {
        std::cout << "Allocator_Init() Error: return check FAILURE" << std::endl;
        return false;
    }

    // Allocate and fill blocks by randome data
    // and relase allocated blocks in random order and validate all left blocks every release
    // Repeat procedure +1 times (first allocating always by consequent order of free block list)
    size_t cnt = 0;
    while (cnt++ <= passNum) {
        if (cnt == 1)
            std::cout << "Pre Pass" << std::endl;
        else
            std::cout << "Pass #" << cnt - 1 << std::endl;
        std::vector<struct BLOCK_CONTEXT> allocatedBlocksContext;
        // Fill all blocks random data and check it every time after each releasing block
        if (!AllocateAndFillAllBlocks(allocatedBlocksContext, blocksQty))
            return false;
        if (!ReleaseAllBlocksWithValidation(allocatedBlocksContext))
            return false;
    }
    return true;
}

/**
 * @brief Incorrect use test
 * 
 * @return true 
 * @return false 
 */
bool IncorrectUseTest() {
    std::cout << "\n===========IncorrectUseTest============\n";
    bool result = true;
    size_t blocksQty = POOL_SIZE / BLOCK_SIZE;
    std::vector<struct BLOCK_CONTEXT> allocatedBlocksContext;

    // Allocator_Init() return check
    bool allocatorIninResult = Allocator_Init();
    if ((allocatorIninResult == true && blocksQty == 0) || (allocatorIninResult == false && blocksQty > 0)) {
        std::cout << "Allocator_Init() Error: return check FAILURE" << std::endl;
        return false;
    }

    // 1) Overflow allocation check
    std::cout << "==Allocation overflow==\n";
    AllocateAndFillAllBlocks(allocatedBlocksContext, blocksQty);
    if (Allocator_GetBlock() != NULL) {
        std::cout << "Error: Overflow allocation return not NULL" << std::endl;
        return false;
    }
    ReleaseAllBlocksWithValidation(allocatedBlocksContext);

    // 2) Release ptr outside the pool
    std::cout << "==Release ptr outside the pool==\n";
    AllocateAndFillAllBlocks(allocatedBlocksContext, blocksQty);
    std::sort(allocatedBlocksContext.begin(), allocatedBlocksContext.end());
    if (Allocator_FreeBlock((unsigned char*)allocatedBlocksContext.front().pBlock - 1) ||
        Allocator_FreeBlock((unsigned char*)allocatedBlocksContext.back().pBlock + 1)) {
        std::cout << "Error: Success release PTR outside the pool" << std::endl;
        return false;
    }
    ReleaseAllBlocksWithValidation(allocatedBlocksContext);

    // 3) Release ptr which is not begin of block
    if (BLOCK_SIZE > 1) {
        std::cout << "==Release ptr which is not begin of block==\n";
        AllocateAndFillAllBlocks(allocatedBlocksContext, blocksQty);
        if (Allocator_FreeBlock((unsigned char*)allocatedBlocksContext.front().pBlock + 1)) {
            std::cout << "Error: Success release PTR which is not start of block" << std::endl;
            return false;
        }
        ReleaseAllBlocksWithValidation(allocatedBlocksContext);
    }

    // 4) Release ptr of free block
    std::cout << "==Release ptr of free block==\n";
    void* pBlock = Allocator_GetBlock();
    Allocator_FreeBlock(pBlock);
    if (Allocator_FreeBlock(pBlock)) {
        std::cout << "Error: Success release of already released block" << std::endl;
        return false;
    }
    return result;
}