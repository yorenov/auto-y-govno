/******************************************************************************
 Header: SecureEngineCustomVMsMacros.h
 Description: Definition of CustomVM macros

 Author/s: Oreans Technologies 
 (c) 2021 Oreans Technologies

 --- File generated automatically from Oreans VM Generator (14/5/2021) ---
******************************************************************************/


// ****************************************************************************
// Declaration of Custom VM macros
// ****************************************************************************

#ifdef __cplusplus
 extern "C" {
#endif

#if defined(PLATFORM_X32)

void __stdcall VM_TIGER_WHITE_START_ASM32();
void __stdcall VM_TIGER_WHITE_END_ASM32();
void __stdcall VM_TIGER_RED_START_ASM32();
void __stdcall VM_TIGER_RED_END_ASM32();
void __stdcall VM_TIGER_BLACK_START_ASM32();
void __stdcall VM_TIGER_BLACK_END_ASM32();
void __stdcall VM_FISH_WHITE_START_ASM32();
void __stdcall VM_FISH_WHITE_END_ASM32();
void __stdcall VM_FISH_RED_START_ASM32();
void __stdcall VM_FISH_RED_END_ASM32();
void __stdcall VM_FISH_BLACK_START_ASM32();
void __stdcall VM_FISH_BLACK_END_ASM32();
void __stdcall VM_PUMA_WHITE_START_ASM32();
void __stdcall VM_PUMA_WHITE_END_ASM32();
void __stdcall VM_PUMA_RED_START_ASM32();
void __stdcall VM_PUMA_RED_END_ASM32();
void __stdcall VM_PUMA_BLACK_START_ASM32();
void __stdcall VM_PUMA_BLACK_END_ASM32();
void __stdcall VM_SHARK_WHITE_START_ASM32();
void __stdcall VM_SHARK_WHITE_END_ASM32();
void __stdcall VM_SHARK_RED_START_ASM32();
void __stdcall VM_SHARK_RED_END_ASM32();
void __stdcall VM_SHARK_BLACK_START_ASM32();
void __stdcall VM_SHARK_BLACK_END_ASM32();
void __stdcall VM_DOLPHIN_WHITE_START_ASM32();
void __stdcall VM_DOLPHIN_WHITE_END_ASM32();
void __stdcall VM_DOLPHIN_RED_START_ASM32();
void __stdcall VM_DOLPHIN_RED_END_ASM32();
void __stdcall VM_DOLPHIN_BLACK_START_ASM32();
void __stdcall VM_DOLPHIN_BLACK_END_ASM32();
void __stdcall VM_EAGLE_WHITE_START_ASM32();
void __stdcall VM_EAGLE_WHITE_END_ASM32();
void __stdcall VM_EAGLE_RED_START_ASM32();
void __stdcall VM_EAGLE_RED_END_ASM32();
void __stdcall VM_EAGLE_BLACK_START_ASM32();
void __stdcall VM_EAGLE_BLACK_END_ASM32();
void __stdcall VM_LION_WHITE_START_ASM32();
void __stdcall VM_LION_WHITE_END_ASM32();
void __stdcall VM_LION_RED_START_ASM32();
void __stdcall VM_LION_RED_END_ASM32();
void __stdcall VM_LION_BLACK_START_ASM32();
void __stdcall VM_LION_BLACK_END_ASM32();
void __stdcall VM_MUTATE_ONLY_START_ASM32();
void __stdcall VM_MUTATE_ONLY_END_ASM32();

#define VM_TIGER_WHITE_START VM_TIGER_WHITE_START_ASM32();
#define VM_TIGER_WHITE_END VM_TIGER_WHITE_END_ASM32();
#define VM_TIGER_RED_START VM_TIGER_RED_START_ASM32();
#define VM_TIGER_RED_END VM_TIGER_RED_END_ASM32();
#define VM_TIGER_BLACK_START VM_TIGER_BLACK_START_ASM32();
#define VM_TIGER_BLACK_END VM_TIGER_BLACK_END_ASM32();
#define VM_FISH_WHITE_START VM_FISH_WHITE_START_ASM32();
#define VM_FISH_WHITE_END VM_FISH_WHITE_END_ASM32();
#define VM_FISH_RED_START VM_FISH_RED_START_ASM32();
#define VM_FISH_RED_END VM_FISH_RED_END_ASM32();
#define VM_FISH_BLACK_START VM_FISH_BLACK_START_ASM32();
#define VM_FISH_BLACK_END VM_FISH_BLACK_END_ASM32();
#define VM_PUMA_WHITE_START VM_PUMA_WHITE_START_ASM32();
#define VM_PUMA_WHITE_END VM_PUMA_WHITE_END_ASM32();
#define VM_PUMA_RED_START VM_PUMA_RED_START_ASM32();
#define VM_PUMA_RED_END VM_PUMA_RED_END_ASM32();
#define VM_PUMA_BLACK_START VM_PUMA_BLACK_START_ASM32();
#define VM_PUMA_BLACK_END VM_PUMA_BLACK_END_ASM32();
#define VM_SHARK_WHITE_START VM_SHARK_WHITE_START_ASM32();
#define VM_SHARK_WHITE_END VM_SHARK_WHITE_END_ASM32();
#define VM_SHARK_RED_START VM_SHARK_RED_START_ASM32();
#define VM_SHARK_RED_END VM_SHARK_RED_END_ASM32();
#define VM_SHARK_BLACK_START VM_SHARK_BLACK_START_ASM32();
#define VM_SHARK_BLACK_END VM_SHARK_BLACK_END_ASM32();
#define VM_DOLPHIN_WHITE_START VM_DOLPHIN_WHITE_START_ASM32();
#define VM_DOLPHIN_WHITE_END VM_DOLPHIN_WHITE_END_ASM32();
#define VM_DOLPHIN_RED_START VM_DOLPHIN_RED_START_ASM32();
#define VM_DOLPHIN_RED_END VM_DOLPHIN_RED_END_ASM32();
#define VM_DOLPHIN_BLACK_START VM_DOLPHIN_BLACK_START_ASM32();
#define VM_DOLPHIN_BLACK_END VM_DOLPHIN_BLACK_END_ASM32();
#define VM_EAGLE_WHITE_START VM_EAGLE_WHITE_START_ASM32();
#define VM_EAGLE_WHITE_END VM_EAGLE_WHITE_END_ASM32();
#define VM_EAGLE_RED_START VM_EAGLE_RED_START_ASM32();
#define VM_EAGLE_RED_END VM_EAGLE_RED_END_ASM32();
#define VM_EAGLE_BLACK_START VM_EAGLE_BLACK_START_ASM32();
#define VM_EAGLE_BLACK_END VM_EAGLE_BLACK_END_ASM32();
#define VM_LION_WHITE_START VM_LION_WHITE_START_ASM32();
#define VM_LION_WHITE_END VM_LION_WHITE_END_ASM32();
#define VM_LION_RED_START VM_LION_RED_START_ASM32();
#define VM_LION_RED_END VM_LION_RED_END_ASM32();
#define VM_LION_BLACK_START VM_LION_BLACK_START_ASM32();
#define VM_LION_BLACK_END VM_LION_BLACK_END_ASM32();
#define VM_MUTATE_ONLY_START VM_MUTATE_ONLY_START_ASM32();
#define VM_MUTATE_ONLY_END VM_MUTATE_ONLY_END_ASM32();

#endif

#if defined(PLATFORM_X64)

void __stdcall VM_TIGER_WHITE_START_ASM64();
void __stdcall VM_TIGER_WHITE_END_ASM64();
void __stdcall VM_TIGER_RED_START_ASM64();
void __stdcall VM_TIGER_RED_END_ASM64();
void __stdcall VM_TIGER_BLACK_START_ASM64();
void __stdcall VM_TIGER_BLACK_END_ASM64();
void __stdcall VM_FISH_WHITE_START_ASM64();
void __stdcall VM_FISH_WHITE_END_ASM64();
void __stdcall VM_FISH_RED_START_ASM64();
void __stdcall VM_FISH_RED_END_ASM64();
void __stdcall VM_FISH_BLACK_START_ASM64();
void __stdcall VM_FISH_BLACK_END_ASM64();
void __stdcall VM_PUMA_WHITE_START_ASM64();
void __stdcall VM_PUMA_WHITE_END_ASM64();
void __stdcall VM_PUMA_RED_START_ASM64();
void __stdcall VM_PUMA_RED_END_ASM64();
void __stdcall VM_PUMA_BLACK_START_ASM64();
void __stdcall VM_PUMA_BLACK_END_ASM64();
void __stdcall VM_SHARK_WHITE_START_ASM64();
void __stdcall VM_SHARK_WHITE_END_ASM64();
void __stdcall VM_SHARK_RED_START_ASM64();
void __stdcall VM_SHARK_RED_END_ASM64();
void __stdcall VM_SHARK_BLACK_START_ASM64();
void __stdcall VM_SHARK_BLACK_END_ASM64();
void __stdcall VM_DOLPHIN_WHITE_START_ASM64();
void __stdcall VM_DOLPHIN_WHITE_END_ASM64();
void __stdcall VM_DOLPHIN_RED_START_ASM64();
void __stdcall VM_DOLPHIN_RED_END_ASM64();
void __stdcall VM_DOLPHIN_BLACK_START_ASM64();
void __stdcall VM_DOLPHIN_BLACK_END_ASM64();
void __stdcall VM_EAGLE_WHITE_START_ASM64();
void __stdcall VM_EAGLE_WHITE_END_ASM64();
void __stdcall VM_EAGLE_RED_START_ASM64();
void __stdcall VM_EAGLE_RED_END_ASM64();
void __stdcall VM_EAGLE_BLACK_START_ASM64();
void __stdcall VM_EAGLE_BLACK_END_ASM64();
void __stdcall VM_LION_WHITE_START_ASM64();
void __stdcall VM_LION_WHITE_END_ASM64();
void __stdcall VM_LION_RED_START_ASM64();
void __stdcall VM_LION_RED_END_ASM64();
void __stdcall VM_LION_BLACK_START_ASM64();
void __stdcall VM_LION_BLACK_END_ASM64();
void __stdcall VM_MUTATE_ONLY_START_ASM64();
void __stdcall VM_MUTATE_ONLY_END_ASM64();

#define VM_TIGER_WHITE_START VM_TIGER_WHITE_START_ASM64();
#define VM_TIGER_WHITE_END VM_TIGER_WHITE_END_ASM64();
#define VM_TIGER_RED_START VM_TIGER_RED_START_ASM64();
#define VM_TIGER_RED_END VM_TIGER_RED_END_ASM64();
#define VM_TIGER_BLACK_START VM_TIGER_BLACK_START_ASM64();
#define VM_TIGER_BLACK_END VM_TIGER_BLACK_END_ASM64();
#define VM_FISH_WHITE_START VM_FISH_WHITE_START_ASM64();
#define VM_FISH_WHITE_END VM_FISH_WHITE_END_ASM64();
#define VM_FISH_RED_START VM_FISH_RED_START_ASM64();
#define VM_FISH_RED_END VM_FISH_RED_END_ASM64();
#define VM_FISH_BLACK_START VM_FISH_BLACK_START_ASM64();
#define VM_FISH_BLACK_END VM_FISH_BLACK_END_ASM64();
#define VM_PUMA_WHITE_START VM_PUMA_WHITE_START_ASM64();
#define VM_PUMA_WHITE_END VM_PUMA_WHITE_END_ASM64();
#define VM_PUMA_RED_START VM_PUMA_RED_START_ASM64();
#define VM_PUMA_RED_END VM_PUMA_RED_END_ASM64();
#define VM_PUMA_BLACK_START VM_PUMA_BLACK_START_ASM64();
#define VM_PUMA_BLACK_END VM_PUMA_BLACK_END_ASM64();
#define VM_SHARK_WHITE_START VM_SHARK_WHITE_START_ASM64();
#define VM_SHARK_WHITE_END VM_SHARK_WHITE_END_ASM64();
#define VM_SHARK_RED_START VM_SHARK_RED_START_ASM64();
#define VM_SHARK_RED_END VM_SHARK_RED_END_ASM64();
#define VM_SHARK_BLACK_START VM_SHARK_BLACK_START_ASM64();
#define VM_SHARK_BLACK_END VM_SHARK_BLACK_END_ASM64();
#define VM_DOLPHIN_WHITE_START VM_DOLPHIN_WHITE_START_ASM64();
#define VM_DOLPHIN_WHITE_END VM_DOLPHIN_WHITE_END_ASM64();
#define VM_DOLPHIN_RED_START VM_DOLPHIN_RED_START_ASM64();
#define VM_DOLPHIN_RED_END VM_DOLPHIN_RED_END_ASM64();
#define VM_DOLPHIN_BLACK_START VM_DOLPHIN_BLACK_START_ASM64();
#define VM_DOLPHIN_BLACK_END VM_DOLPHIN_BLACK_END_ASM64();
#define VM_EAGLE_WHITE_START VM_EAGLE_WHITE_START_ASM64();
#define VM_EAGLE_WHITE_END VM_EAGLE_WHITE_END_ASM64();
#define VM_EAGLE_RED_START VM_EAGLE_RED_START_ASM64();
#define VM_EAGLE_RED_END VM_EAGLE_RED_END_ASM64();
#define VM_EAGLE_BLACK_START VM_EAGLE_BLACK_START_ASM64();
#define VM_EAGLE_BLACK_END VM_EAGLE_BLACK_END_ASM64();
#define VM_LION_WHITE_START VM_LION_WHITE_START_ASM64();
#define VM_LION_WHITE_END VM_LION_WHITE_END_ASM64();
#define VM_LION_RED_START VM_LION_RED_START_ASM64();
#define VM_LION_RED_END VM_LION_RED_END_ASM64();
#define VM_LION_BLACK_START VM_LION_BLACK_START_ASM64();
#define VM_LION_BLACK_END VM_LION_BLACK_END_ASM64();
#define VM_MUTATE_ONLY_START VM_MUTATE_ONLY_START_ASM64();
#define VM_MUTATE_ONLY_END VM_MUTATE_ONLY_END_ASM64();

#endif

#ifdef __cplusplus
}
#endif

