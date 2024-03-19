#pragma once

#include <ultra64.h>

#include "types.h"



// -- COP0 -- 

// $Index
typedef union Reg_CP0_Index {
    struct PACKED {
        u32 P     :  1; // Probe success or failure. Set to 1 when the previous TLBProbe (TLBP) instruction was unsuccessful; set to 0 when successful.
        u32       : 25; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 Index :  6; // Index to the TLB entry affected by the TLBRead and TLBWrite instructions.
    };
    u32 raw;
} Reg_CP0_Index;
// $Random
typedef union Reg_CP0_Random {
    struct PACKED {
        u32        : 26; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 Random :  6; // TLB Random Index.
    };
    u32 raw;
} Reg_CP0_Random;
// $EntryLo0
// $EntryLo1
// $Context
typedef union Reg_CP0_Context_32 {
    struct PACKED {
        u32 PTEBase :  9; // Base address of page table entry.
        u32 BadVPN2 : 19; // Page number of virtual address whose translation is invalid divided by 2.
        u32         :  4; // RFU. Must be written zeroes; returns zeroes when read.
    };
    u32 raw;
} Reg_CP0_Context_32;
typedef union Reg_CP0_Context_64 {
    struct PACKED {
        u64 PTEBase : 41; // Base address of page table entry.
        u64 BadVPN2 : 19; // Page number of virtual address whose translation is invalid divided by 2.
        u64         :  4; // RFU. Must be written zeroes; returns zeroes when read.
    };
    u64 raw;
} Reg_CP0_Context_64;
// $PageMask
typedef union Reg_CP0_PageMask {
    struct PACKED {
        u32      :  9;
        u32 mask : 12; // [0b000000000000:4KB, 0b000000000011:16KB, 0b000000001111:64KB, 0b000000111111:256KB, 0b000011111111:1MB, 0b001111111111:4MB, 0b111111111111:16MB]
        u32      : 21;
    };
    u32 raw;
} Reg_CP0_PageMask;
// $Wired
typedef union Reg_CP0_Wired {
    struct PACKED {
        u32       : 26; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 Wired :  6; // TLB Wired boundary.
    };
    u32 raw;
} Reg_CP0_Wired;
// $BadVAddr
// $Count
// $EntryHi
// $Compare
// $Status
typedef union Reg_CP0_Status {
    struct PACKED {
        u32 CU   : 4; // Controls the usability of each of the four coprocessor unit numbers. [1:usable, 0:unusable]
        u32 RP   : 1; // Enables low-power operation by reducing the internal clock frequency and the system interface clock frequency to one-quarter speed. [0:normal, 1:low power mode (1/4th CPU clock speed)]
        u32 FR   : 1; // Enables additional floating-point registers. [0:16 registers, 1:32 registers]
        u32 RE   : 1; // Reverse-Endian bit, enables reverse of system endianness in User mode. [0:disabled (big endian), 1:reversed (little endian)]
        u32 DS   : 9; // Diagnostic status field.
        u32 IM   : 8; // Interrupt Mask field, enables external, internal, coprocessors or software interrupts (&’d against interrupt pending in $Cause). [0:disabled, 1:enabled]
        u32 KX   : 1; // Enables 64-bit addressing in Kernel mode. When this bit is set, XTLB miss exception is generated on TLB misses in Kernel mode addresses space (64-bit operation is always valid in Kernel mode). [0:32-bit, 1:64-bit]
        u32 SX   : 1; // Enables 64-bit addressing and operations in Supervisor mode. When this bit is set, XTLB miss exception is generated on TLB misses in Supervisor mode addresses space. [0:32-bit, 1:64-bit]
        u32 UX   : 1; // Enables 64-bit addressing and operations in User mode. When this bit is set, XTLB miss exception is generated on TLB misses in User mode addresses space. [0:32-bit, 1:64-bit]
        u32 KSU  : 1; // Specifies and indicates execution mode bits [10:User, 01:Supervisor, 00:Kernel]
        u32 ERL  : 1; // Specifies and indicates error level (are we currently handling an error?). [0:normal, 1:error]
        u32 EXL  : 1; // Specifies and indicates exception level (are we currently handling an exception?). [0:normal, 1:exception]
        u32 IE   : 1; // Specifies and indicates global interrupt enable (should interrupts be handled?). [0:disable interrupts, 1:enable interrupts]
    };
    struct PACKED {
        u32     :  7;
        u32 ITS :  1; // Enables Instruction Trace Support.
        u32     :  1; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 BEV :  1; // Controls the location of TLB miss and general purpose exception vectors. [0:normal, 1:bootstrap]
        u32 TS  :  1; // Indicates TLB shutdown has occurred (read-only); used to avoid damage to the TLB if more than one TLB entry matches a single virtual address. [0:does not occur, 1:occur] After TLB shutdown, the processor must be reset to restart. TLB shutdown can occur even when a TLB entry with which the virtual address has matched is set to be invalid (V bit of the entry is cleared).
        u32 SR  :  1; // Indicates whether a Soft Reset or NMI has occured. [0:has not occured, 1:has occured]
        u32     :  1; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 CH  :  1; // CP0 condition bit. Read/write access by software only; not accessible by hardware. [0:false, 1:true]
        u32 CE  :  1; // These bits are defined to maintain compatibility with the VR4200, and is not used by the hardware of the VR4300.
        u32 DE  :  1; // These bits are defined to maintain compatibility with the VR4200, and is not used by the hardware of the VR4300.
        u32     : 16;
    } DS_;
    struct PACKED {
        u32          : 16;
        u32 Timer    :  1; // Mask bit for timer interrupt.
        u32 External :  5; // Mask bits for external interrupts Int[4:0], or external write requests.
        u32 Software :  2; // Mask bits for software interrupts and IP(1:0) of the $Cause register.
        u32          :  8;
    } IM_;
    struct PACKED {
        u32 : 28;
        u32 CU_3 : 1; // Coprocessor 3 enabled This bit is ignored by the N64, there is no COP3!
        u32 CU_2 : 1; // Coprocessor 2 enabled This bit is ignored by the N64, there is no COP2!
        u32 CU_1 : 1; // Coprocessor 1 enabled If this bit is 0, all COP1 instructions throw exceptions.
        u32 CU_0 : 1; // Coprocessor 0 enabled This bit is ignored by the N64, COP0 is always enabled!
    } CU_;
    u32 raw;
} Reg_CP0_Status;
// $Cause
typedef union Reg_CP0_Cause {
    struct PACKED {
        u32 BD          :  1; // Indicates whether the last exception occurred has been executed in a branch delay slot. [1:delay, 0:normal]
        u32             :  1; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 CE          :  2; // Coprocessor unit number referenced when a Coprocessor Unusable exception has occurred. If this exception does not occur, undefined.
        u32             : 12; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 IP          :  8; // Indicates an interrupt is pending. [1:interrupt pending, 0:no interrupt]
        u32             :  1; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 Exc_Code    :  5; // Exception code field.
        u32             :  2; // RFU. Must be written as zeroes, and returns zeroes when read.
    };
    struct PACKED {
        u32          : 16;
        u32 Timer    :  1; // Timer interrupt. This is connected to the $Count/$Compare interrupt mechanism inside COP0.
        u32 External :  5; // External normal interrupts. Controlled by Int[4:0], or external write requests.
        u32 Software :  2; // Software interrupts. Only these bits can cause interrupt exception when they are set to 1 by software. This is writable by MTC0, and is used as a “software interrupt”.
        u32          :  8;
    } IP_;
    struct PACKED {
        u32           : 17;
        u32 Indy_W    :  1; // Connected to the Indy dev kit’s RDB port. Set to 1 when a value is written.
        u32 Indy_R    :  1; // Connected to the Indy dev kit’s RDB port. Set to 1 when a value is read.
        u32 Reset     :  1; // This is connected to the Reset button on the top of the console. When pressed, this becomes 1.
        u32 Cartridge :  1; //This is connected to the cartridge slot. Cartridges with special hardware can trigger this interrupt. Unsure how common this is in practice.
        u32 MI        :  1; // This is connected to the MI interrupt process described above. It is set to 1 when ((MI_INTR_REG & MI_INTR_MASK_REG) != 0).
        u32           :  8;
    } IP_External_;
    u32 raw;
} Reg_CP0_Cause;
// $EPC
// $PRId
typedef union Reg_CP0_PRId {
    struct PACKED {
        u32     : 16; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 Imp :  8; // Processor ID number (0x0B for the VR4300 seriesTM).
        u32 Rev :  8; // Processor revision number.
    };
    u32 raw;
} Reg_CP0_PRId;
// $Config
typedef union Reg_CP0_Config {
    struct PACKED { //! TODO: return to this to add more documentation.
        u32    :  1; // 0b0
        u32 EC :  3; // Operating frequency ratio (read-only). The value displayed corresponds to the frequency ratio set by the DivMode pins on power application.
        u32 EP :  3; // Sets transfer data pattern (single/block write request). [0:D (default on cold reset), 6:DxxDxx:2 doublewords/6 cycles, others:RFU]
        u32    :  8; // 0b00000110
        u32 BE :  1; // Sets BigEndianMem (endianness). [0:Little endian, 1:Big endian (default on cold reset)]
        u32    : 11; // 0b11001000110
        u32 CU :  1; // RFU. However, can be read or written by software.
        u32 K0 :  3; // Sets coherency algorithm of kseg0. [0b10:Cache is not used, others:Cache is used]
    };
    u32 raw;
} Reg_CP0_Config;
// $LLAddr
// $WatchLo
typedef union Reg_CP0_WatchLo {
    struct PACKED {
        u32 PAddr0 : 29; // Bits 31:3 of the physical address.
        u32        :  1; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 R      :  1; // Exception occurs when load instruction is executed if set to 1.
        u32 W      :  1; // Exception occurs when store instruction is executed if set to 1.
    };
    u32 raw;
} Reg_CP0_WatchLo;
// $WatchHi
typedef union Reg_CP0_WatchHi {
    struct PACKED {
        u32        : 28; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 PAddr1 :  4; // Bits 35:32 of a physical address.
    };
    u32 raw;
} Reg_CP0_WatchHi;
// $XContext
typedef union Reg_CP0_XContext {
    struct PACKED {
        u64 PTEBase : 31; // Base address of page table entry
        u64 R       :  2; // Space identifier (bits 63 and 62 of virtual address). [0b00:User, 0b01:Supervisor, 0b11:Kernel]
        u64 BadVPN2 : 27; // Virtual address whose translation is invalid (bits 39:13).
        u64         :  4; // Must be written as zeroes, and returns zeroes when read.
    };
    u64 raw;
} Reg_CP0_XContext;
// $ParityErr
typedef union Reg_CP0_PErr {
    struct PACKED {
        u32            : 24; // RFU. Must be written as zeroes, and returns zeroes when read.
        u32 Diagnostic :  8; // 8-bit self-diagnosis area.
    };
    u32 Raw;
} Reg_CP0_PErr;
// $CacheErr
// $TagLo
typedef union Reg_CP0_TagLo {
    struct PACKED {
        u32        :  4; // RFU. Must be written as zeroes; returns zeroes when read.
        u32 PTagLo : 20; // Physical address bits 31:12.
        u32 PState :  2; //! Specifies the primary cache state. [Data cache:[0b11:Valid, 0b00:invalid], Instruction cache:[0b10:Valid, 0b00:Invalid]]
        u32        :  6; // RFU. Must be written as zeroes; returns zeroes when read.
    };
    u32 raw;
} Reg_CP0_TagLo;
// $TagHi
// $ErrorEPC


// -- COP1 --

// $FPCSR
typedef union Reg_FPCSR {
    struct PACKED {
        u32                   :  7;
        u32 flushDenormToZero :  1; // Flush denorm to zero.
        u32 cond              :  1; // Condition bit.
        u32                   :  5;
        u32 cause_bits        :  6; // See Reg_FPCSR.cause.
        u32 enable_bits       :  5; // See Reg_FPCSR.enable.
        u32 flag_bits         :  5; // See Reg_FPCSR.flag.
        u32 rounding_mode     :  2; // Round to: (1:zero, 2:+inf, 3:-inf).
    };
    struct PACKED {
        u32               : 14;
        u32 unimplemented :  1; // cause: unimplemented operation
        u32 invalid       :  1; // cause: invalid operation
        u32 div0          :  1; // cause: division by zero
        u32 overflow      :  1; // cause: overflow
        u32 underflow     :  1; // cause: underflow
        u32 inexact       :  1; // cause: inexact operation
        u32               : 12;
    } cause;
    struct PACKED {
        u32               : 20;
        u32 invalid       :  1; // enable: invalid operation
        u32 div0          :  1; // enable: division by zero
        u32 overflow      :  1; // enable: overflow
        u32 underflow     :  1; // enable: underflow
        u32 inexact       :  1; // enable: inexact operation
        u32               :  7;
    } enable;
    struct PACKED {
        u32               : 25;
        u32 invalid       :  1; // flag: invalid operation
        u32 div0          :  1; // flag: division by zero
        u32 overflow      :  1; // flag: overflow
        u32 underflow     :  1; // flag: underflow
        u32 inexact       :  1; // flag: inexact operation
        u32               :  2;
    } flag;
    u32 raw;
} Reg_FPCSR;
