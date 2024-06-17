// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerBaseCharacter.h"
#include "EnemyBaseCharacter.h"
#include "DebugHelper.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	ownerCharacter = Cast<ABaseCharacter>(TryGetPawnOwner());
}

void UCharacterAnimInstance::NativeUpdateAnimation(float daltaTime)
{
	if (ownerCharacter) {
		//获取动画蓝图对应角色的速度
		FVector velocity = ownerCharacter->GetVelocity();

		speed = velocity.Length();
		//获取移动方向
		FRotator rotation = ownerCharacter->GetActorRotation();

		direction = CalculateDirection(velocity, rotation);//？？貌似被Kismet替换掉了，暂时能用会警告而已，但我也没被警告，暂定
		//判断是否正在掉落
		UCharacterMovementComponent* movement = ownerCharacter->GetCharacterMovement();

		isFalling = movement->IsFalling();
		//将当前角色转换为player
		APlayerBaseCharacter* player = Cast<APlayerBaseCharacter>(ownerCharacter);
		if (player) {
			isAttackAnim = player->isAttackAnim;//转换成功则赋值当前的动画状态
		}
		if (ownerCharacter->GetHealthProgress()<= 0)isDeath = true;
	}
}

void UCharacterAnimInstance::AnimNotify_WeaponToHand(UAnimNotify* Notify)
{
	//Debug::Print("RunWeapon To Hand");
	SwitchWeaponPont(FName("WeaponToHand"));
}

void UCharacterAnimInstance::AnimNotify_SwitchWeaponPose(UAnimNotify* Notify)
{
	//Debug::Print("RunSwitchWeaponPose");
	SwitchWeaponPont(FName("WeaponAttackPoint"));
}

void UCharacterAnimInstance::AnimNotify_UnEquipWeapon(UAnimNotify* Notify)
{
	SwitchWeaponPont(FName("NormalWeaponPoint"));
}
//装备完成的动画通知方法
void UCharacterAnimInstance::AnimNotify_EquipEnd(UAnimNotify* Notify)
{
	APlayerBaseCharacter* playerCharacter = Cast<APlayerBaseCharacter>(ownerCharacter);
	if (playerCharacter) {
		playerCharacter->SetCharacterMovement(EMovementMode::MOVE_Walking);
	}
}

//切换武器挂点方法
void UCharacterAnimInstance::SwitchWeaponPont(FName pointName)
{
	APlayerBaseCharacter* playerCharacter = Cast<APlayerBaseCharacter>(ownerCharacter);
	if (playerCharacter) {
		playerCharacter->SwitchWeaponPoint(pointName);
	}
}

//敌人攻击结束
void UCharacterAnimInstance::AnimNotify_AttackEnd(UAnimNotify* Notify)
{
	ABaseCharacter* enemyCharacter= Cast<ABaseCharacter>(ownerCharacter);
	if (enemyCharacter) {
		enemyCharacter->isAttacking = false;
	}
}

void UCharacterAnimInstance::AnimNotify_AttackDamage(UAnimNotify* Notify)
{
	if (ownerCharacter) {
		ownerCharacter->AttackDamage();
	}
}
