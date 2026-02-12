// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "TowerHUDBase.generated.h"

UENUM(BLueprintType)
enum class EUILayout : uint8
{
	/** Bottom layer, for now. */
	HUD	,

	/** Where the main UI should go */
	Game,

	/** Use wheel collision shape to determine suspension length to ground - Slowest */
	Notification
};

UENUM(BLueprintType)
enum class EUILayer : uint8
{
	/** Bottom layer, for now. */
	HUD,

	/** Where the main UI should go */
	Game,

	/** Use wheel collision shape to determine suspension length to ground - Slowest */
	Notification
};

/**
 * 
 */
UCLASS()
class TOWERSWITHSTYLE_API ATowerHUDBase : public AHUD
{
	GENERATED_BODY()

public: 
	virtual void ShowHUD() override;

protected:
	UPROPERTY()
	UUILayoutWidgetBase* UILayout;

	UPROPERTY()
	UHUDWidgetBase* HUDWidget;
};

/**
 *
 */
UCLASS()
class TOWERSWITHSTYLE_API UHUDWidgetBase : public UUserWidget
{
	GENERATED_BODY()
};

/**
 *
 */
UCLASS()
class TOWERSWITHSTYLE_API UUILayoutWidgetBase : public UUserWidget
{
	GENERATED_BODY()
};

