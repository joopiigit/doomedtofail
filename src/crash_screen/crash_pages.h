#pragma once

#include <ultra64.h>

#include "types.h"

#include "pages/page_context.h"
#include "pages/page_logs.h"
#include "pages/page_stack.h"
#include "pages/page_map.h"
#include "pages/page_memory.h"
#include "pages/page_disasm.h"
#include "pages/page_settings.h"


#define CRASH_SCREEN_START_PAGE PAGE_CONTEXT


enum CSPages {
    FIRST_PAGE,
    PAGE_CONTEXT = FIRST_PAGE,
    PAGE_LOG,
    PAGE_STACK_TRACE,
#ifdef INCLUDE_DEBUG_MAP
    PAGE_MAP_VIEWER,
#endif
    PAGE_RAM_VIEWER,
    PAGE_DISASM,
    PAGE_SETTINGS,
    NUM_PAGES,
    MAX_PAGES = 255U,
};


typedef struct CSPage {
    /*0x00*/ const char* name;
    /*0x04*/ void (*initFunc)(void);
    /*0x08*/ void (*drawFunc)(void);
    /*0x0C*/ void (*inputFunc)(void);
    /*0x10*/ const enum ControlTypes* contList;
    /*0x14*/ struct CSSetting* settingsList; //! TODO: Allow page settings to be changed on the page via help popup.
    /*0x18*/ union {
                struct PACKED {
                    /*0x00*/ u32             : 29;
                    /*0x03*/ u32 printName   :  1;
                    /*0x03*/ u32 crashed     :  1;
                    /*0x03*/ u32 initialized :  1;
                }; /*0x04*/
                u32 raw;
            } flags; /*0x04*/
} CSPage; /*0x1C*/


extern struct CSPage* gCSPages[NUM_PAGES];
extern enum CSPages gCSPageID;
extern _Bool gCSSwitchedPage;


enum CSPopups {
    CS_POPUP_NONE,
    CS_POPUP_CONTROLS,
    CS_POPUP_ADDRESS_SELECT,
    NUM_CS_POPUPS,
};

typedef struct CSPopup {
    /*0x00*/ const char* name;
    /*0x04*/ void (*initFunc)(void);
    /*0x08*/ void (*drawFunc)(void);
    /*0x0C*/ void (*inputFunc)(void);
} CSPopup; /*0x10*/

extern struct CSPopup* gCSPopups[NUM_CS_POPUPS];
extern enum CSPopups gCSPopupID;
extern _Bool gCSSwitchedPopup;

void cs_set_page(enum CSPages page);
void cs_open_popup(enum CSPopups popupID);