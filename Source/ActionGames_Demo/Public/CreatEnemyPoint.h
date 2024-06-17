// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CreatEnemyPoint.generated.h"

UCLASS()
class ACTIONGAMES_DEMO_API ACreatEnemyPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACreatEnemyPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boss")
	bool IsBoss = false;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
