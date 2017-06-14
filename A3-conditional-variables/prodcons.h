/* 
 * Operating Systems  (2INC0)  Practical Assignment
 * Condition Variable application
 *
 * Joris Geurts
 * j.geurts@fontys.nl
 *
 */

/* ITEM:
 * a 16-bit integer containing a 'destination' (i.e. the consumer which has to handle this item)
 * and a 'sequence number' (starting from 1 onwards)
 */
typedef    unsigned short int    ITEM;
 
 /* NROF_BITS_DEST
 * number of bits for the 'destination' field in an ITEM
 * (so the 'sequence number' field occupies 16-NROF_BITS_DEST bits)
 * 
 * When editing this file: ensure that 
 *        2^(   NROF_BITS_DEST) > NROF_CONSUMERS and
 *        2^(16-NROF_BITS_DEST) > NROF_ITEMS,
 * such that no overflow occurs during program execution
 */
#define NROF_BITS_DEST      1

/* NROF_CONSUMERS:
 * number of consumers
 *
 * When editing this file: ensure that NROF_CONSUMERS > 0
 */
#define NROF_CONSUMERS      (1<<(NROF_BITS_DEST))

/* NROF_ITEMS:
 * number of items to be generated by the producer
 */
#define NROF_ITEMS          ((1<<(16-NROF_BITS_DEST))-1)

/* BUFFER_SIZE
 * number of items that fit in the buffer
 *
 * When editing this file: ensure that BUFFER_SIZE > 1
 */
#define BUFFER_SIZE         4

/* PRODUCER_SLEEP_FACTOR
 * let the producer (on average) sleep longer or shorter such that cornercases
 * for a full buffer and an empty buffer can be tested
 *
 * PRODUCER_SLEEP_FACTOR = 100:  producer sleeps (on average) as long as
 *                               the consumers
 * PRODUCER_SLEEP_FACTOR > 100:  producer sleeps longer
 *                               so there is a higher probability for an EMPTY buffer
 * PRODUCER_SLEEP_FACTOR < 100:  producer sleeps shorter
 *                               so there is a higher probability for a FULL buffer
 */
#define PRODUCER_SLEEP_FACTOR   100
