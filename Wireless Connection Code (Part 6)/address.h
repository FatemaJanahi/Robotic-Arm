/*
 * @file address.h
 * @Author Fatema Janahi & Julia Gangemi
 * @date December 2018
 * @brief hold address of GPIO & mapped IO window
 *     
 */
 
 #ifndef ADDRESS_H
#define ADDRESS_H

// Physical base address of GPIO
const unsigned gpio_address = 0x400d0000;

// Length of memory-mapped IO window
const unsigned gpio_size = 0xff;
#endif
