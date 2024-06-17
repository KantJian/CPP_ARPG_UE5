// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TaskGetRandomPosition.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONGAMES_DEMO_API UTaskGetRandomPosition : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UTaskGetRandomPosition();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	FBlackboardKeySelector MovePositionKey;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	float Radius = 1000;
};
