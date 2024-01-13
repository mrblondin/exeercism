#include "circular_buffer.h"
#include <string.h>
#include <errno.h>

circular_buffer_t buffer;

circular_buffer_t *new_circular_buffer(size_t length){
  if (!length)
    return NULL;

  buffer.buf = (buffer_value_t *) malloc((length + 1) * sizeof(buffer.buf));

  if (buffer.buf == NULL) return NULL;

  buffer.length = length;
  clear_buffer(&buffer);
  return &buffer;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value){
  if (!buffer || !value) {errno = EINVAL; return EXIT_FAILURE;}

  if (buffer->buf[buffer->wrIndex]) { errno = ENOBUFS; return EXIT_FAILURE; }

  buffer->buf[buffer->wrIndex] = value;
  buffer->wrIndex = (buffer->wrIndex + 1) % buffer -> length;

  return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value){
  if (!buffer || !value) {errno = EINVAL; return EXIT_FAILURE;}

  if (!buffer->buf[buffer->wrIndex])
    return write(buffer, value);

  buffer->buf[buffer->wrIndex] = value;

  buffer->wrIndex = (buffer->wrIndex + 1) % buffer -> length;
  buffer->rdIndex = (buffer->rdIndex + 1) % buffer -> length;

  return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t * value){
  if (!buffer || !value) {errno = EINVAL; return EXIT_FAILURE;}

  if (!buffer->buf[buffer->rdIndex]) { errno = ENODATA; return EXIT_FAILURE; }

  *value = buffer->buf[buffer->rdIndex];
  buffer->buf[buffer->rdIndex] = 0;
  buffer->rdIndex = (buffer->rdIndex + 1) % buffer -> length;

  return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer){
  if (!buffer)
    return;

  memset(buffer->buf, 0, buffer->length * sizeof(buffer->buf));
  buffer->wrIndex = 0;
  buffer->rdIndex = 0;
}

void delete_buffer(circular_buffer_t *buffer){
  if (buffer)
    free(buffer->buf);
}
