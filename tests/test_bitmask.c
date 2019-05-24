#include "../bitmask.h"
#include <assert.h>

int main(void) {
    assert(MASK_RANGE(2, 4) == 0b00001100);
    assert(MASK_RANGE(3, 7) == 0b01111000);
    assert(MASK_RANGE(0, 8) == 0b11111111);
    return 0;
}
