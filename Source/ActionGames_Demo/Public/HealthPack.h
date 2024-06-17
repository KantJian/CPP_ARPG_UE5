// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthPack.generated.h"


class UBoxComponent;

UCLASS()
class ACTIONGAMES_DEMO_API AHealthPack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthPack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyComponent")
	TObjectPtr<UBoxComponent> BoxCollision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyComponent")
	TObjectPtr<UStaticMeshComponent> BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyComponent")
	TObjectPtr<USceneComponent> Root;//执行了生成不出来，添加该跟组件

	UFUNCTION()
	void BeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	



};
