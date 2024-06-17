// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "PlayerBaseCharacter.generated.h"

class USpringArmComponent;//标识在这个类中要使用USpringArmComponent
class UCameraComponent;

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

class ABaseWeapon;


UCLASS()
class ACTIONGAMES_DEMO_API APlayerBaseCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	APlayerBaseCharacter();//构造函数

	virtual void Tick(float deltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* CameraBoom;//声明定义弹簧臂类型的变量
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Montage")
	TObjectPtr<UAnimMontage>UnequipAnim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Montage")
	TObjectPtr<UAnimMontage>EquipAnim;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Montage")
	TArray<UAnimMontage*>AttackAnimList;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WeaponClass")
	TSubclassOf<ABaseWeapon>WeaponClass;

	UPROPERTY(BlueprintReadOnly, Category = "WeaponClass")
	ABaseWeapon* weapon;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "AttackValue")
	float attackRadius=50.0f;

	UPROPERTY(BlueprintReadOnly, Category = "GameMode")
	class ACombatGameMode* GameMode;



	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void InputMove(const FInputActionValue& Value);
	//void InputMove(const FVector2D axis2D);

	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void LookRotation(const FInputActionValue& Value);
	//void LookRotation(const FVector2D axis2D);

	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void InputJump(const FInputActionValue& Value);
	//void InputJump(const bool isJump);

	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void ChangeAnim(const bool isChange);

	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void PlayAttackInPlayer(const int32 attackIndex);

	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	TArray<ABaseCharacter*>GetAttackRangeEnemy(const TArray<FHitResult>hitList);

	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void PauseGameInput();



	void RegisterInput();//注册输入
	void SpawnWeapon();



public:
	UPROPERTY(BlueprintReadWrite, Category = "MyVariable")
	bool isAttackAnim;


	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void SwitchWeaponPoint(FName pointName);


	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void SetCharacterMovement(const EMovementMode moveMentMode);

	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void AddHealth(const float addValue);

	virtual void AttackDamage() override;

	virtual void HitRepose() override;

	virtual void DeathRepose() override;

};


