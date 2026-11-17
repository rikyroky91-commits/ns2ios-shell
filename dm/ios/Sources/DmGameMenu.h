// The in-game menu: GameMenu.swift builds it, the gamepad's menu button at the top centre opens it (DmGamepad.m). It holds the controller layout and the launcher
// settings the running game takes at once (front_ios.m dm_setting_live); the other settings stay on the settings screen before the game starts.
#pragma once
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif
void *dm_game_menu(void);   // GameMenu.swift: a retained UIMenu, rebuilt each time it opens
int dm_pad_layout(void);   // DmGamepad.m: 0 = 2D, 1 = 3D, 2 = Tap (DM_GAME_PAD_LAYOUT's numbers)
bool dm_pad_layout_offered(int layout);   // Tap only in handheld mode
void dm_pad_layout_set(int layout);   // releases every touch first, and is saved for the next start
void dm_gamepad_touch_feedback(bool on);   // DM_TOUCH_HAPTICS
void dm_gamepad_set_opacity(double k);   // DM_PAD_OPACITY: how opaque the touch controls are, times the shell's own look (0 invisible, 1 as shipped)
void dm_gamepad_set_size(double k);   // DM_PAD_SIZE: how large the touch controls are, times the shell's own size
bool dm_pad_edit_offered(void);   // the controls can be moved now (a drawn layout)
void dm_pad_edit_begin(void);   // the in-game menu's Move controls: drag each group of keys, Done saves it (per layout)
bool dm_setting_live(const char *env, const char *value);   // front_ios.m: value NULL asks whether the running game takes env at once; otherwise applies it
#ifdef __cplusplus
}
#endif
