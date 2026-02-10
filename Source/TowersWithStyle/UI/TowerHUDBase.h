// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TowerHUDBase.generated.h"

class UUserWidget;

UENUM()
enum class EUILayout : uint8
{
	/** Bottom layer, for now. */
	Raycast		UMETA(DisplayName = "Raycast"),

	/** Where the main UI should go */
	Spherecast	UMETA(DisplayName = "Spherecast"),

	/** Use wheel collision shape to determine suspension length to ground - Slowest */
	Shapecast	UMETA(DisplayName = "Shapecast")
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
	UUserWidget* UILayout;

	UPROPERTY()
	UUserWidget* HUDWidget;
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
	UUserWidget* UILayout;

	UPROPERTY()
	UUserWidget* HUDWidget;
};
