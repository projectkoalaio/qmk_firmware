#ifndef LETS_SPLIT_H
#define LETS_SPLIT_H

#include "quantum.h"

void promicro_bootloader_jmp(bool program);

#define KEYMAP( \
	k00, k01, k02, k03, k04, k40, k41, k42, k43, k44, \
	k10, k11, k12, k13, k14, k50, k51, k52, k53, k54, \
	k20, k21, k22, k23, k24, k60, k61, k62, k63, k64, \
	          k32, k33, k34, k70, k71, k72  \
	) \
	{ \
		{ k00, k01, k02, k03, k04, }, \
		{ k10, k11, k12, k13, k14, }, \
		{ k20, k21, k22, k23, k24, }, \
		{ KC_NO, KC_NO, k32, k33, k34, }, \
		{ k40, k41, k42, k43, k44, }, \
		{ k50, k51, k52, k53, k54, }, \
		{ k60, k61, k62, k63, k64, }, \
		{ k70, k71, k72, KC_NO, KC_NO, } \
	}

#endif
