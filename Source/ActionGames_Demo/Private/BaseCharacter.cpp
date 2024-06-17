// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "DebugHelper.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	health = maxHealth;
	
}

void ABaseCharacter::MyDelay(float delayTime,FName functionName)
{
	FLatentActionInfo actionInfo;
	actionInfo.Linkage = 1;
	actionInfo.UUID = 100;
	actionInfo.CallbackTarget = this;
	actionInfo.ExecutionFunction = functionName;
	UKismetSystemLibrary::Delay(GetWorld(),delayTime,actionInfo);
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::AttackDamage()
{

}

void ABaseCharacter::TakeHitDamage(const float damageValue)
{
	//Debug::Print("demage -health");
	if (health > 0) {
		health -= damageValue;
		//Debug::Print("health");
		if (health<=0) {
			health = 0;
			DeathRepose();//ËÀÍöÏìÓ¦
		}
		else {
			HitRepose();//ÉËº¦ÏìÓ¦
		}
	}
}

void ABaseCharacter::HitRepose()
{
	GetMesh()->GetAnimInstance()->Montage_Play(HitMontage);
}

void ABaseCharacter::DeathRepose()
{

}

void ABaseCharacter::PlayAttack()
{

}

