// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPack.h"

#include "Components/BoxComponent.h"
#include "DebugHelper.h"
#include "PlayerBaseCharacter.h"

// Sets default values
AHealthPack::AHealthPack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");

	BoxCollision->SetupAttachment(Root);
	BaseMesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AHealthPack::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this,&AHealthPack::BeginOverLap);
	
}

void AHealthPack::BeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Debug::Print("Player Overlap");
	APlayerBaseCharacter* player = Cast<APlayerBaseCharacter>(OtherActor);
	if (player) {
		player->AddHealth(30.0f);
		Destroy();
	}
}





