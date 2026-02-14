#include "EnemyAIController.h"
#include "AIEnemyCharacter.h"
#include "GameFramework/Actor.h"
#include "Logging/LogMacros.h"
#include "Navigation/PathFollowingComponent.h"
#include "TimerManager.h"

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	const AAIEnemyCharacter* EnemyCharacter = Cast<AAIEnemyCharacter>(InPawn);
	if (!EnemyCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("EnemyAIController: Possessed non-enemy pawn."));
		return;
	}

	// Store the target on the pawn and delay the move to allow nav data to be ready.
	GetWorldTimerManager().SetTimer(MoveDelayHandle, this, &AEnemyAIController::StartMoveToTarget, 0.2f, false);
}

void AEnemyAIController::StartMoveToTarget()
{
	const AAIEnemyCharacter* EnemyCharacter = Cast<AAIEnemyCharacter>(GetPawn());
	if (!EnemyCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("EnemyAIController: StartMoveToTarget with no pawn."));
		return;
	}

	AActor* TargetActor = EnemyCharacter->GetTargetPoint();
	if (!TargetActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("EnemyAIController: TargetPoint is not set on enemy."));
		return;
	}

	const EPathFollowingRequestResult::Type MoveResult = MoveToActor(TargetActor, 5.0f);
	UE_LOG(LogTemp, Warning, TEXT("EnemyAIController: MoveToActor result = %d"), static_cast<int32>(MoveResult));

	if (MoveResult != EPathFollowingRequestResult::Type::RequestSuccessful)
	{
		const EPathFollowingRequestResult::Type FallbackResult = MoveToLocation(TargetActor->GetActorLocation(), 5.0f);
		UE_LOG(LogTemp, Warning, TEXT("EnemyAIController: MoveToLocation fallback result = %d"), static_cast<int32>(FallbackResult));
	}
}
