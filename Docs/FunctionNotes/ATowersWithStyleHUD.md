ATowersWithStyleHUD function notes

File: Source/TowersWithStyle/Public/TowersWithStyleHUD.h
File: Source/TowersWithStyle/Private/TowersWithStyleHUD.cpp

ATowersWithStyleHUD()
- Default constructor for the HUD.

BeginPlay()
- Creates the main HUD widget for the owning player and adds it to the viewport.
- Sets game-only input mode and hides the mouse cursor.

ToggleMenu()
- Shows or hides the main HUD widget.
- Switches input mode and mouse cursor visibility to match the menu state.
