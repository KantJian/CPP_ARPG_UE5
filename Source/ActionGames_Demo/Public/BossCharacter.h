// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "BossCharacter.generated.h"

class UBehaviorTree;
class UAnimMontage;
/**
 * 
 */
UCLASS()
class ACTIONGAMES_DEMO_API ABossCharacter : public ABaseCharacter
{
	GENERATED_BODY()


protected:
	

	//两次随机攻击，一次大招
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontage")
	TArray<TObjectPtr<UAnimMontage>> AttackAnimList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontage")
	TObjectPtr<UAnimMontage> BigAttackAnim;

	UFUNCTION()
	APlayerBaseCharacter* GertAttackRangePlayer(const TArray<FHitResult> hitList);

	int32 attackNum = 0;

	virtual void DeathRepose() override;

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	TObjectPtr<UBehaviorTree>BehaviorTree;
	virtual void PlayAttack() override;
	virtual void AttackDamage() override;
};
