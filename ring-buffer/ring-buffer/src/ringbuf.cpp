#include <cstdlib>
#include "ringbuf.hpp"

/**
 * Allocate a ring buffer given length
 *
 * @param[in] length Length of the buffer
 */
ringbuf::ringbuf(uint32_t length)
{
    mpData = new uint16_t[length];
    mLength = length;
}

/**
 * Free the allocated memory
 */
ringbuf::~ringbuf()
{
    delete[] mpData;
}

/**
 * Update the write index, wrapping on mLength
 */
void ringbuf::updateWriteIdx()
{
    mWriteIdx = mWriteIdx == (mLength - 1) ? 0 : mWriteIdx + 1;
    ++mCount;
}

/**
 * Update the read index, wrapping on mLength
 */
void ringbuf::updateReadIdx()
{
    mReadIdx = mReadIdx == (mLength - 1) ? 0 : mReadIdx + 1;
    --mCount;
}

/**
 * Push an item to the buffer
 *
 * @param[in] item Item to push
 */
void ringbuf::push(uint16_t item)
{
    mpData[mWriteIdx] = item;
    updateWriteIdx();
}

/**
 * Read an item from the buffer
 *
 * @return item at read index
 */
uint16_t ringbuf::read()
{
    uint16_t item = 0;
    if (mCount > 0)
    {
        item = mpData[mReadIdx];
        updateReadIdx();
    }
    return item;
}

/**
 * Obtain the average of the items in the buffer
 *
 * @return double average of the buffer items
 *
 * TODO: std::optional
 */
double ringbuf::average()
{
    const uint32_t currReadIdx = mReadIdx;
    double sum = 0;
    double divisor = 1.0;
    if (mCount > 0)
    {
        divisor = static_cast<double>(mCount);
        for (uint32_t i = 0; i < + mCount; i++)
        {
            if ((currReadIdx + i) < (mLength - 1))
            {
                sum += static_cast<double>(mpData[currReadIdx + i]);
            }
            else
            {
                sum += static_cast<double>(mpData[i]);
            }
        }
    }

    return sum/static_cast<double>(divisor);
}

