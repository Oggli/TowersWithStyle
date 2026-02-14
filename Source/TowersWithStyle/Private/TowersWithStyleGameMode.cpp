#include "TowersWithStyleGameMode.h"
#include "TowersWithStyleHUD.h"
#include "TowersWithStyleCharacter.h"

ATowersWithStyleGameMode::ATowersWithStyleGameMode()
{
	HUDClass = ATowersWithStyleHUD::StaticClass();
	DefaultPawnClass = ATowersWithStyleCharacter::StaticClass();
}
