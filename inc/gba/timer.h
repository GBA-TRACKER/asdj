//
// inc/gba/timer.h
//
// GBA Timer Control Flags
//

#ifndef GBA_HEAD_TIMER
#define GBA_HEAD_TIMER

#define TIMF_PRESCALE_SYS 0x0000
#define TIMF_PRESCALE_64 0x0001
#define TIMF_PRESCALE_256 0x0002
#define TIMF_PRESCALE_1024 0x0003

#define TIMF_OVERFLOW 0x0004

#define TIMF_IRQ 0x0040

#define TIMF_ENABLE 0x0080

#define TIMF_MASK 0x00C7

#endif

// EOF
