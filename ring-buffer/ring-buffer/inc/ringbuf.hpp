#pragma once

#include <cstdint>

class ringbuf
{
    private:
        uint16_t* mpData;
        uint32_t mWriteIdx = 0;
        uint32_t mReadIdx = 0;

        uint32_t mCount = 0;
        uint32_t mLength;

        void updateWriteIdx();
        void updateReadIdx();

        constexpr bool full() { return mCount == mLength; }
        constexpr bool empty() { return mCount == 0; }

    public:
        ringbuf(uint32_t length);
        ~ringbuf();

        void push(uint16_t item);
        uint16_t read();
        double average();
};
