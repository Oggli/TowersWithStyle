// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerHUDBase.h"

void ATowerHUDBase::ShowHUD()
{
	Super::ShowHUD();

	if (IsValid(UILayout))
	{
		UILayout->SetVisibility(bShowHUD ? ESlateVisibility::HitTestInvisible : ESlateVisibility::Collapsed);
	}
}
