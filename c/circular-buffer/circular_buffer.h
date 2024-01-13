#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include <stdlib.h>
#include <stdint.h>

typedef int16_t buffer_value_t;

typedef struct {
  size_t wrIndex;
  size_t rdIndex;
  size_t length;
  buffer_value_t * buf;
} circular_buffer_t;

/**
 * Create new ringbuffer
 * 
 * @param {size_t} length of the array
 * @returns {circular_buffer_t} pointer to ringbuffer
 */
circular_buffer_t *new_circular_buffer(size_t length);

/**
 * Write 1 byte to ringbuffer
 * 
 * @param {circular_buffer_t} buffer - pointer to buffer
 * @param {buffer_value_t} value - byte to write
 * @returns {int16_t} status 
 *        EXIT_SUCCESS, when the byte is successfuly
 *          written to the ringbuffer,
 *        EXIT_FAILURE, when the byte could not be written
 */
int16_t write(circular_buffer_t *buffer, buffer_value_t value);

/**
 * Overwrite 1 byte of ringbuffer, if it is full, otherwise just write
 * 
 * @param {circular_buffer_t} buffer - pointer to buffer
 * @param {buffer_value_t} value - byte to write
 * @returns {int16_t} status 
 *        EXIT_SUCCESS, when the byte is successfuly
 *          written/overwritten to the ringbuffer,
 *        EXIT_FAILURE, when the byte could not be written
 */
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);

/**
 * Write 1 byte to ringbuffer
 * 
 * @param {circular_buffer_t} buffer - pointer to buffer
 * @param {buffer_value_t} value - byte that was read
 * @returns {int16_t} status 
 *        EXIT_SUCCESS, when the byte is successfuly
 *          read,
 *        EXIT_FAILURE, when the byte could not be read
 */
int16_t read(circular_buffer_t *buffer, buffer_value_t * value);

/**
 * Clear the whole ringbuffer
 * 
 * @param {circular_buffer_t} buffer - pointer to buffer
 * @returns {void}
 */
void clear_buffer(circular_buffer_t *buffer);

/**
 * Remove the buffer
 * 
 * @param {circular_buffer_t} buffer - pointer to buffer
 * @returns {void}
 */
void delete_buffer(circular_buffer_t *buffer);


#endif
