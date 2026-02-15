#include "TowersWithStyleHUD.h"
#include "Blueprint/UserWidget.h"

ATowersWithStyleHUD::ATowersWithStyleHUD()
{
}

void ATowersWithStyleHUD::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = GetOwningPlayerController();
	if (!PC || !MainHUDWidgetClass)
	{
		return;
	}

	MainHUDWidget = CreateWidget<UUserWidget>(PC, MainHUDWidgetClass);
	if (MainHUDWidget)
	{
		MainHUDWidget->AddToViewport();
		MainHUDWidget->SetVisibility(ESlateVisibility::Visible);
		PC->SetShowMouseCursor(false);
		PC->SetInputMode(FInputModeGameOnly());
	}
}

void ATowersWithStyleHUD::ToggleMenu()
{
	if (!MainHUDWidget)
	{
		return;
	}

	APlayerController* PC = GetOwningPlayerController();
	if (!PC)
	{
		return;
	}

	if (MainHUDWidget->GetVisibility() == ESlateVisibility::Visible)
	{
		MainHUDWidget->SetVisibility(ESlateVisibility::Hidden);
		PC->SetShowMouseCursor(false);
		PC->SetInputMode(FInputModeGameOnly());
	}
	else
	{
		MainHUDWidget->SetVisibility(ESlateVisibility::Visible);
		PC->SetShowMouseCursor(true);
		PC->SetInputMode(FInputModeGameAndUI().SetWidgetToFocus(MainHUDWidget->TakeWidget()));
	}
}
