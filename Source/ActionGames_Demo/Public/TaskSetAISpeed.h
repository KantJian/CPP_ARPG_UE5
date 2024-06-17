// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TaskSetAISpeed.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONGAMES_DEMO_API UTaskSetAISpeed : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UTaskSetAISpeed();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float speed = 175;
};
