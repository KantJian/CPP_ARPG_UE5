// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskAttackPlayer.h"

#include "AIController.h"
#include "BaseCharacter.h"

UTaskAttackPlayer::UTaskAttackPlayer()
{
	NodeName = FString("AttackPlayer");
	bNotifyTick = true;
}

EBTNodeResult::Type UTaskAttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* controller = OwnerComp.GetAIOwner();
	if (!controller)return EBTNodeResult::Failed;
	ABaseCharacter* enemy = Cast<ABaseCharacter>(controller->GetPawn());
	if(!enemy)return EBTNodeResult::Failed;
	enemy->PlayAttack();
	return EBTNodeResult::InProgress;
}

void UTaskAttackPlayer::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* controller = OwnerComp.GetAIOwner();
	if (controller) {
		ABaseCharacter* enemy = Cast<ABaseCharacter>(controller->GetPawn());
		if (enemy&&!enemy->isAttacking) {
			FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
		}
	}
}
