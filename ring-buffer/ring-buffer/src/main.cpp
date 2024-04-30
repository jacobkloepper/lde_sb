#include <iostream>
#include "ringbuf.hpp"

constexpr uint32_t testbufLength = 32;

constexpr uint16_t data_stream[testbufLength] = {
    77, 80, 72, 75, 99, 59, 89, 83, 74, 62,
    60, 50, 69, 76, 79, 67, 64, 95, 98, 66,
    86, 51, 58, 54, 88, 61, 90, 56, 87, 52,
    85, 97
};

constexpr uint16_t more_data[testbufLength] = {
    80, 82, 76, 77, 98, 74, 71, 90, 75, 73,
    70, 56, 55, 66, 67, 88, 69, 68, 53, 54,
    81, 85, 52, 95, 64, 96, 92, 84, 91, 51,
    60, 99
};

/**
 * TODO:
 *    - Move to proper testing framework
 *    - Fixups as noticed
 *    - Write as module
 *    - Mock a hardware signal sampler
 *    -
 */
int main()
{
    auto buf = ringbuf(testbufLength);

    // fill buffer
    for (uint32_t i = 0; i < testbufLength; i++)
    {
        buf.push(data_stream[i]);
    }

    // keep overfilling, should wraparound
    for (uint32_t i = 0; i < 16; i++)
    {
        buf.push(more_data[i]);
    }

    // read out buffer
    std::cout << "buffer contents:\n\t[ ";
    for (uint32_t i = 0; i < testbufLength; i++)
    {
        std::cout << buf.read() << ' ';
    }
    std::cout << "]\n";

    return 0;
}
