#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/TargetPoint.h"
#include "AIEnemyCharacter.generated.h"

class ATargetPoint;

UCLASS()
class TOWERSWITHSTYLE_API AAIEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAIEnemyCharacter();

	ATargetPoint* GetTargetPoint() const { return TargetPoint; }

protected:
	UPROPERTY(EditInstanceOnly, Category = "AI")
	ATargetPoint* TargetPoint = nullptr;
};
