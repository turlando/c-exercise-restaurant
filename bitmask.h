#ifndef __RESTAURANT_BITMASK__
#define __RESTAURANT_BITMASK__

#define MASK_BIT(n) \
    (1U << n)

/* Mask the bits from start (inclusive) to end (exclusive).
 * Return a 32 bit unsigned integer.
 */
#define MASK_RANGE(start, end)                 \
    (((~0U) >> (32 - (end - start))) << start)

#endif /* __RESTAURANT_BITMASK__ */
