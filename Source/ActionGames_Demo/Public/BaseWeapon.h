// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class ACTIONGAMES_DEMO_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyComponent")
	USkinnedMeshComponent* MainMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "MyComponent")
	USceneComponent* RootComp;


public:	
	

};
