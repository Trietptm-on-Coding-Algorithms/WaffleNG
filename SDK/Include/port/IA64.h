#ifndef __SDK_WAFFLE_PORT_IA64_H_
#define __SDK_WAFFLE_PORT_IA64_H_

#define WAFFLE_PORT_DEBUG_INSTRUCTION                       0xCC //int 3
#define WAFFLE_PORT_OPTIONAL_INSTRUCTION                    0xF4 //hlt
#define WAFFLE_PORT_OPTIONAL_EXCEPTION_CODE                 EXCEPTION_PRIV_INSTRUCTION
#define WAFFLE_PORT_EXCEPTION_INSTRUCTION                   WAFFLE_PORT_OPTIONAL_INSTRUCTION
#define WAFFLE_PORT_EXCEPTION_INSTRUCTION_DATA              BYTE
#define WAFFLE_PORT_WRITE_EXCEPTION_INSTRUCTION(lpAddress)  (*(WAFFLE_PORT_EXCEPTION_INSTRUCTION_DATA *)(lpAddress) = WAFFLE_PORT_EXCEPTION_INSTRUCTION)

#define WAFFLE_PORT_PROGRAM_COUNTER_TO_PHYSICAL_ADDRESS(lpFunction)         (lpFunction)
#define WAFFLE_PORT_EXCEPTION_ADDRESS_TO_PHYSICAL_ADDRESS(ExceptionInfo)    (ExceptionInfo->ExceptionRecord->ExceptionAddress)

#define WAFFLE_PORT_PROGRAM_POINTER                         StIIP
#define WAFFLE_PORT_STACK_POINTER                           IntSp
//#define WAFFLE_PORT_FRAME_POINTER                           
#define WAFFLE_PORT_EXCEPTION_GET_CALLER(ExceptionInfo)     (*(SIZE_T *)(ExceptionInfo->ContextRecord->WAFFLE_PORT_STACK_POINTER))

//#define WAFFLE_PORT_ENTRY_POINT_LOOP_INSTRUCTION            ""

#define WAFFLE_PORT_MACHINE             WAFFLE_PORT_MACHINE_IA64
#define WAFFLE_PORT_MACHINE_STRING      WAFFLE_PORT_MACHINE_STRING_IA64

#endif /* __SDK_WAFFLE_PORT_IA64_H_ */