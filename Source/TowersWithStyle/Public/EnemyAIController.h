#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

UCLASS()
class TOWERSWITHSTYLE_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	void StartMoveToTarget();

	FTimerHandle MoveDelayHandle;
};
