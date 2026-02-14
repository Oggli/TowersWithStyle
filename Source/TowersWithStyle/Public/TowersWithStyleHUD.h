#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TowersWithStyleHUD.generated.h"

UCLASS()
class TOWERSWITHSTYLE_API ATowersWithStyleHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATowersWithStyleHUD();

	/** Toggle the menu visibility */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ToggleMenu();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> MainHUDWidgetClass;

	UPROPERTY()
	class UUserWidget* MainHUDWidget;
};
