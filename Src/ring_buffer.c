#include "ring_buffer.h"

void ring_buffer_init(ring_buffer_t *rb, uint8_t *mem, size_t capacity) {
    rb->buffer = mem;
    rb->capacity = capacity;
    rb->head = 0;
    rb->tail = 0;
}

bool ring_buffer_push(ring_buffer_t *rb, uint8_t data) {
    size_t next_head = (rb->head + 1U) % rb->capacity;
    if (next_head == rb->tail) {
        return false; /* Buffer full */
    }
    rb->buffer[rb->head] = data;
    rb->head = next_head;
    return true;
}

bool ring_buffer_pop(ring_buffer_t *rb, uint8_t *data) {
    if (rb->head == rb->tail) {
        return false; /* Buffer empty */
    }
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1U) % rb->capacity;
    return true;
}

size_t ring_buffer_available(const ring_buffer_t *rb) {
    if (rb->head >= rb->tail) {
        return rb->head - rb->tail;
    }
    return rb->capacity - (rb->tail - rb->head);
}

bool ring_buffer_is_empty(const ring_buffer_t *rb) {
    return (rb->head == rb->tail);
}
