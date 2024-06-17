// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskGetRandomPosition.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "NavigationSystem.h"


UTaskGetRandomPosition::UTaskGetRandomPosition()
{
	NodeName = FString("GetRandomPosition");
}

EBTNodeResult::Type UTaskGetRandomPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//拿到黑板与AIController
	AAIController* controller = OwnerComp.GetAIOwner();
	UBlackboardComponent* blackboard = OwnerComp.GetBlackboardComponent();
	if (!controller||!blackboard) return EBTNodeResult::Failed;
	//拿到AIController对应的Pawn
	APawn* pawn = controller->GetPawn();
	if (!pawn)return EBTNodeResult::Failed;
	FVector location = pawn->GetActorLocation();
	//拿到导航系统，记得在Build.cs中添加导航模块儿，不然导不进来（导完重启VS）
	UNavigationSystemV1* navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	if(!navSystem)return EBTNodeResult::Failed;
	//根据导航网格随机位置
	FNavLocation navLocation;
	bool isFound=navSystem->GetRandomReachablePointInRadius(location,Radius,navLocation);
	if(!isFound)return EBTNodeResult::Failed;
	//将随机到的位置赋值给黑板键
	blackboard->SetValueAsVector(MovePositionKey.SelectedKeyName,navLocation.Location);
	return EBTNodeResult::Succeeded;
}
