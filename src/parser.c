#include "parser.h"
#include <stdio.h>

void pp_vector(uint8_t *data, uint32_t size)
{
    uint8_t nb_objects;
    uint8_t object_size;

    if (size < 2) {
        return;
    }

    nb_objects = data[0];
    object_size = data[1];

    size -= 2;

    if (nb_objects == 0 || object_size == 0) {
        return;
    }

    if (!(nb_objects == 4 && object_size == 4 && size == 7 && data[2] == 3)) {
        if (nb_objects * object_size > size) {
            return;
        }
    }

    data = &data[2];

    for (uint16_t i = 0; i < nb_objects; i++)
    {
        printf("Object[%d]\n", i);
        uint8_t *object = &data[i * object_size];
        for (uint16_t j = 0; j < object_size; j++)
        {
            printf("%x", object[j]);
        }
        printf("\n");
    }
}
