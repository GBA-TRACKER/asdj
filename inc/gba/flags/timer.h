//
// inc/gba/flags/timer.h
//
// GBA Timer Control Flags
//

#ifndef GBA_HEAD_FLAGS_TIMER
#define GBA_HEAD_FLAGS_TIMER

// Flags for REG_TMxCNT:
#define TIMF_PRESCALE_SYS 0x0000 // Increment every clock cycle.
#define TIMF_PRESCALE_64 0x0001 // Increment every 64th cycle.
#define TIMF_PRESCALE_256 0x0002 // Increment every 256th cycle.
#define TIMF_PRESCALE_1024 0x0003 // Increment every 1024th cycle.

#define TIMF_OVERFLOW 0x0004 // Increment on overflow from previous timer.

#define TIMF_IRQ 0x0040 // Enable timer IRQ.
#define TIMF_ENABLE 0x0080 // Enable timer.

#define TIMF_MASK 0x00C7 // Flag mask.

#endif /* GBA_HEAD_FLAGS_TIMER */

// EOF
