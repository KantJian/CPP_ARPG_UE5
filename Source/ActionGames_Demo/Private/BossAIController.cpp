// Fill out your copyright notice in the Description page of Project Settings.


#include "BossAIController.h"

#include "BossCharacter.h"
#include "Kismet/GameplayStatics.h"
//#include "PlayerBaseCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"


void ABossAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	ABossCharacter* boss = Cast<ABossCharacter>(InPawn);
	if (boss) {
		RunBehaviorTree(boss->BehaviorTree);
		ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		UBlackboardComponent* blackboard = GetBlackboardComponent();
		if (player&&blackboard) {
			SetFocus(player);
			blackboard->SetValueAsObject(FName("PlayerActor"), player);
		}
	}
}
