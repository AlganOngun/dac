#ifndef DAC_H
#define DAC_H

#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include <stddef.h>
#include <stdlib.h>

// ==========================
//    Header Structure
// ==========================

struct DacHeader {
	size_t size;
	size_t capacity;
};

// ==========================
//      Helper Macros
// ==========================

#define dac_header(arr) \
	((struct DacHeader *)((char *)(arr) - sizeof(struct DacHeader)))

#define dac_len(arr) ((arr) ? dac_header(arr)->size : 0)

#define dac_capacity(arr) ((arr) ? dac_header(arr)->capacity : 0)

// ==========================
//     Array Operations
// ==========================

#define dac_grow(arr, new_capacity)                                          \
	do {                                                                 \
		if (arr == NULL) {                                           \
			size_t total_size = sizeof(struct DacHeader) +       \
					    (new_capacity) * sizeof(*(arr)); \
			struct DacHeader *header =                           \
				(struct DacHeader *)malloc(total_size);      \
			header->size = 0;                                    \
			header->capacity = (new_capacity);                   \
			arr = (void *)(header + 1);                          \
		} else {                                                     \
			size_t total_size = sizeof(struct DacHeader) +       \
					    (new_capacity) * sizeof(*(arr)); \
			struct DacHeader *header =                           \
				realloc(dac_header(arr), total_size);        \
			header->capacity = (new_capacity);                   \
			arr = (void *)(header + 1);                          \
		}                                                            \
	} while (0)

#define dac_push(arr, value)                                          \
	do {                                                          \
		if (dac_len(arr) == dac_capacity(arr)) {              \
			dac_grow(arr, dac_capacity(arr) ?             \
					      dac_capacity(arr) * 2 : \
					      4);                     \
		}                                                     \
		arr[dac_header(arr)->size++] = (value);               \
	} while (0)

#define dac_free(arr)                          \
	do {                                   \
		if (arr) {                     \
			free(dac_header(arr)); \
			arr = NULL;            \
		}                              \
	} while (0)

#ifdef __cplusplus
}
#endif

#endif
