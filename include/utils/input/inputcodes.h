//
// Created by nate on 1/16/25.
//

#pragma once

#define NWT_KEY_SPACE              32
#define NWT_KEY_APOSTROPHE         39  /* ' */
#define NWT_KEY_COMMA              44  /* , */
#define NWT_KEY_MINUS              45  /* - */
#define NWT_KEY_PERIOD             46  /* . */
#define NWT_KEY_SLASH              47  /* / */
#define NWT_KEY_0                  48
#define NWT_KEY_1                  49
#define NWT_KEY_2                  50
#define NWT_KEY_3                  51
#define NWT_KEY_4                  52
#define NWT_KEY_5                  53
#define NWT_KEY_6                  54
#define NWT_KEY_7                  55
#define NWT_KEY_8                  56
#define NWT_KEY_9                  57
#define NWT_KEY_SEMICOLON          59  /* ; */
#define NWT_KEY_EQUAL              61  /* = */
#define NWT_KEY_A                  65
#define NWT_KEY_B                  66
#define NWT_KEY_C                  67
#define NWT_KEY_D                  68
#define NWT_KEY_E                  69
#define NWT_KEY_F                  70
#define NWT_KEY_G                  71
#define NWT_KEY_H                  72
#define NWT_KEY_I                  73
#define NWT_KEY_J                  74
#define NWT_KEY_K                  75
#define NWT_KEY_L                  76
#define NWT_KEY_M                  77
#define NWT_KEY_N                  78
#define NWT_KEY_O                  79
#define NWT_KEY_P                  80
#define NWT_KEY_Q                  81
#define NWT_KEY_R                  82
#define NWT_KEY_S                  83
#define NWT_KEY_T                  84
#define NWT_KEY_U                  85
#define NWT_KEY_V                  86
#define NWT_KEY_W                  87
#define NWT_KEY_X                  88
#define NWT_KEY_Y                  89
#define NWT_KEY_Z                  90
#define NWT_KEY_LEFT_BRACKET       91  /* [ */
#define NWT_KEY_BACKSLASH          92  /* \ */
#define NWT_KEY_RIGHT_BRACKET      93  /* ] */
#define NWT_KEY_GRAVE_ACCENT       96  /* ` */
#define NWT_KEY_WORLD_1            161 /* non-US #1 */
#define NWT_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define NWT_KEY_ESCAPE             256
#define NWT_KEY_ENTER              257
#define NWT_KEY_TAB                258
#define NWT_KEY_BACKSPACE          259
#define NWT_KEY_INSERT             260
#define NWT_KEY_DELETE             261
#define NWT_KEY_RIGHT              262
#define NWT_KEY_LEFT               263
#define NWT_KEY_DOWN               264
#define NWT_KEY_UP                 265
#define NWT_KEY_PAGE_UP            266
#define NWT_KEY_PAGE_DOWN          267
#define NWT_KEY_HOME               268
#define NWT_KEY_END                269
#define NWT_KEY_CAPS_LOCK          280
#define NWT_KEY_SCROLL_LOCK        281
#define NWT_KEY_NUM_LOCK           282
#define NWT_KEY_PRINT_SCREEN       283
#define NWT_KEY_PAUSE              284
#define NWT_KEY_F1                 290
#define NWT_KEY_F2                 291
#define NWT_KEY_F3                 292
#define NWT_KEY_F4                 293
#define NWT_KEY_F5                 294
#define NWT_KEY_F6                 295
#define NWT_KEY_F7                 296
#define NWT_KEY_F8                 297
#define NWT_KEY_F9                 298
#define NWT_KEY_F10                299
#define NWT_KEY_F11                300
#define NWT_KEY_F12                301
#define NWT_KEY_F13                302
#define NWT_KEY_F14                303
#define NWT_KEY_F15                304
#define NWT_KEY_F16                305
#define NWT_KEY_F17                306
#define NWT_KEY_F18                307
#define NWT_KEY_F19                308
#define NWT_KEY_F20                309
#define NWT_KEY_F21                310
#define NWT_KEY_F22                311
#define NWT_KEY_F23                312
#define NWT_KEY_F24                313
#define NWT_KEY_F25                314
#define NWT_KEY_KP_0               320
#define NWT_KEY_KP_1               321
#define NWT_KEY_KP_2               322
#define NWT_KEY_KP_3               323
#define NWT_KEY_KP_4               324
#define NWT_KEY_KP_5               325
#define NWT_KEY_KP_6               326
#define NWT_KEY_KP_7               327
#define NWT_KEY_KP_8               328
#define NWT_KEY_KP_9               329
#define NWT_KEY_KP_DECIMAL         330
#define NWT_KEY_KP_DIVIDE          331
#define NWT_KEY_KP_MULTIPLY        332
#define NWT_KEY_KP_SUBTRACT        333
#define NWT_KEY_KP_ADD             334
#define NWT_KEY_KP_ENTER           335
#define NWT_KEY_KP_EQUAL           336
#define NWT_KEY_LEFT_SHIFT         340
#define NWT_KEY_LEFT_CONTROL       341
#define NWT_KEY_LEFT_ALT           342
#define NWT_KEY_LEFT_SUPER         343
#define NWT_KEY_RIGHT_SHIFT        344
#define NWT_KEY_RIGHT_CONTROL      345
#define NWT_KEY_RIGHT_ALT          346
#define NWT_KEY_RIGHT_SUPER        347
#define NWT_KEY_MENU               348

#define NWT_MOUSE_BUTTON_1         0
#define NWT_MOUSE_BUTTON_2         1
#define NWT_MOUSE_BUTTON_3         2
#define NWT_MOUSE_BUTTON_4         3
#define NWT_MOUSE_BUTTON_5         4
#define NWT_MOUSE_BUTTON_6         5
#define NWT_MOUSE_BUTTON_7         6
#define NWT_MOUSE_BUTTON_8         7
#define NWT_MOUSE_BUTTON_LAST      NWT_MOUSE_BUTTON_8
#define NWT_MOUSE_BUTTON_LEFT      NWT_MOUSE_BUTTON_1
#define NWT_MOUSE_BUTTON_RIGHT     NWT_MOUSE_BUTTON_2
#define NWT_MOUSE_BUTTON_MIDDLE    NWT_MOUSE_BUTTON_3
#define NWT_MOUSE_BUTTON_MIDDLE    NWT_MOUSE_BUTTON_3

#if defined(_WIN32) || defined(_WIN64) || defined(__linux__) || defined(__unix__)
    #define NWT_PRESS GLFW_PRESS
#else
    #define NWT_PRESS 0
#endif
