ATowersWithStyleCharacter function notes

File: Source/TowersWithStyle/Public/TowersWithStyleCharacter.h
File: Source/TowersWithStyle/Private/TowersWithStyleCharacter.cpp

ATowersWithStyleCharacter()
- Sets controller rotation flags for a top-down camera.
- Builds the spring arm and camera components and configures their defaults.

BeginPlay()
- Adds the default enhanced input mapping context for the local player, if available.

SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
- Binds enhanced input actions to movement, look, jump, and menu toggle handlers.

OnJump()
- Calls the built-in character jump function.

Move(const FInputActionValue& Value)
- Converts a 2D input vector into forward/right movement based on controller yaw.

Look(const FInputActionValue& Value)
- Applies yaw and pitch input to the controller for camera rotation.

OnToggleMenu()
- Gets the HUD instance and asks it to toggle the menu visibility.

GetCameraBoom() / GetTopDownCameraComponent()
- Accessors for the spring arm and camera components.
