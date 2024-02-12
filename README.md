# CRC_calculation

### CRC (Cyclic Redundancy Check) is a technique used to detect errors in digital data, commonly used in communication networks and storage systems. It involves generating a checksum based on the data being transmitted or stored, which is then appended to the data. When the data is received or read, the checksum is recalculated, and if it doesn't match the received checksum, it indicates that the data has been corrupted or altered in some way.

## CRC-16 & CRC-32
CRC16 and CRC32 are specific types of CRC algorithms, each using a different polynomial and resulting in a checksum of different lengths. CRC16 produces a 16-bit checksum, while CRC32 produces a 32-bit checksum. These checksums are more robust than simpler error-checking methods like parity bits because they can detect a wider range of errors.

## Here's a brief description of the C code:

This C program calculates both CRC-16 and CRC-32 checksums for a given input message. It prompts the user to enter a message, calculates the checksums using the respective algorithms, and then displays the original message along with the calculated CRC-16 and CRC-32 checksums.

### Notes:
This program assumes a maximum message length of 100 characters. You can modify the userMessage array size to accommodate longer messages if needed.
The CRC-16 and CRC-32 algorithms used in this program employ specific polynomials (CRC16_POLYNOMIAL and CRC32_POLYNOMIAL, respectively) to generate the checksums.
Understanding CRC checksums can be beneficial in various fields, including networking, data storage, and error detection in digital communication.
