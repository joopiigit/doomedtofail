#pragma once

#include <ultra64.h>

#include "crash_types.h"

#include "address_select.h"
#include "crash_controls.h"
#include "crash_draw.h"
#include "crash_print.h"
#include "insn_disasm.h"
#include "map_parser.h"
#include "memory_read.h"


enum CrashScreenMessageIDs {
    CRASH_SCREEN_MSG_NONE,
    CRASH_SCREEN_MSG_VI_VBLANK,
    CRASH_SCREEN_MSG_CPU_BREAK = OS_EVENT_CPU_BREAK,
    CRASH_SCREEN_MSG_SP_BREAK  = OS_EVENT_SP_BREAK,
    CRASH_SCREEN_MSG_FAULT     = OS_EVENT_FAULT,
};

enum CrashScreenPages {
    FIRST_PAGE,
    PAGE_CONTEXT = FIRST_PAGE,
    PAGE_ASSERTS,
#ifdef PUPPYPRINT_DEBUG
    PAGE_LOG,
#endif
#ifdef INCLUDE_DEBUG_MAP
    PAGE_MAP_VIEWER,
#endif
    PAGE_STACK_TRACE,
    PAGE_RAM_VIEWER,
    PAGE_DISASM,

    NUM_PAGES,
    MAX_PAGES = 255U,
};


extern struct CSPage gCSPages[NUM_PAGES];
extern enum CrashScreenPages gCSPageID;

extern struct CSThreadInfo* gActiveCSThreadInfo;
extern OSThread* gCrashedThread;

extern Address gSelectedAddress;


void create_crash_screen_thread(void);