#include <gtest/gtest.h>
#include "application/uart_frame.hpp"

static bool isDataReceivedCalled = false;

static void onDataReceived(uint8_t* data, size_t length) {
     // Check if the received data is correct
    EXPECT_EQ(data[0], 0x01);
    EXPECT_EQ(data[1], 0x02);
    EXPECT_EQ(data[2], 0x03);
    EXPECT_EQ(length, 3);

    isDataReceivedCalled = true;
}

TEST(UART_FrameTest, DataReception) {
    UART_Frame uartFrame(onDataReceived);
    uint8_t testData[] = {0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x02, 0x03, 0xFF};
    
    isDataReceivedCalled = false;
    uartFrame.deserialize(testData, sizeof(testData));
    EXPECT_TRUE(isDataReceivedCalled);
}

TEST(UART_FrameTest, UnalignedDataReception) {
    UART_Frame uartFrame(onDataReceived);
    uint8_t testData0[] = {0xFF, 0xFF, 0xFF, 0x01, 0x02, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x02, 0x03, 0xFF};
    
    isDataReceivedCalled = false;
    uartFrame.deserialize(testData0, sizeof(testData0));
    EXPECT_TRUE(isDataReceivedCalled);
    
    uint8_t testData1[] = {0xFF, 0xFF, 0x01, 0x02, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x02, 0x03, 0xFF};
    
    isDataReceivedCalled = false;
    uartFrame.deserialize(testData1, sizeof(testData1));
    EXPECT_TRUE(isDataReceivedCalled);

    uint8_t testData2[] = {0xFF,  0x01, 0x02, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x02, 0x03, 0xFF};
    
    isDataReceivedCalled = false;
    uartFrame.deserialize(testData2, sizeof(testData2));
    EXPECT_TRUE(isDataReceivedCalled);
}