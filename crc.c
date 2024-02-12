#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// CRC-16 parameters
#define CRC16_POLYNOMIAL 0x1021

// CRC-32 parameters
#define CRC32_POLYNOMIAL 0x04C11DB7

// Function to calculate CRC-16 checksum
uint16_t calculateCRC16(const char *message, size_t length) {
    uint16_t crc = 0xFFFF;

    for (size_t i = 0; i < length; i++) {
        crc ^= (uint16_t)message[i] << 8;

        for (int j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ CRC16_POLYNOMIAL;
            } else {
                crc = crc << 1;
            }
        }
    }

    return crc;
}

// Function to calculate CRC-32 checksum
uint32_t calculateCRC32(const char *message, size_t length) {
    uint32_t crc = 0xFFFFFFFF;

    for (size_t i = 0; i < length; i++) {
        crc ^= (uint32_t)message[i] << 24;

        for (int j = 0; j < 8; j++) {
            if (crc & 0x80000000) {
                crc = (crc << 1) ^ CRC32_POLYNOMIAL;
            } else {
                crc = crc << 1;
            }
        }
    }

    return crc;
}

int main() {
    char userMessage[100]; // Assuming a maximum message length of 100 characters

    // Prompt the user to enter a message
    printf("Enter a message: ");
    fflush(stdout);
    fgets(userMessage, sizeof(userMessage), stdin);


    // Remove the newline character from the input
    userMessage[strcspn(userMessage, "\n")] = '\0';

    // Calculate CRC-16 and CRC-32 checksums
    uint16_t crc16 = calculateCRC16(userMessage, strlen(userMessage));
    uint32_t crc32 = calculateCRC32(userMessage, strlen(userMessage));

    // Display the results
    printf("Message: %s\n", userMessage);
    printf("CRC-16: %04X\n", crc16);
    printf("CRC-32: %08X\n", crc32);

    return 0;
}
