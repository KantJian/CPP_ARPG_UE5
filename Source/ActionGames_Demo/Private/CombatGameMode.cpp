// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatGameMode.h"

#include "PlayerBaseCharacter.h"
#include "Components/WidgetComponent.h"
#include "MainUIWidget.h"
#include "DebugHelper.h"
#include "EnemyBaseCharacter.h"
#include "AIController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BossCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameOverWidget.h"
#include "PauseWidget.h"
#include "AudioActor.h"

ACombatGameMode::ACombatGameMode()
{
	DefaultPawnClass = APlayerBaseCharacter::StaticClass();
}

void ACombatGameMode::BeginPlay()
{
	RestartGame();
	UUserWidget* widget = CreateWidget<UUserWidget>(GetWorld(),MainUIClass);
	if (widget) {
		widget->AddToViewport();
		MainUI = Cast<UMainUIWidget>(widget);
	}
	if (AudioActorClass) {
		AudioActor=GetWorld()->SpawnActor<AAudioActor>(AudioActorClass);
	}
}



void ACombatGameMode::PlayBloodAnimation()
{
	if (MainUI) {
		MainUI->PlayBloodAnimation();
	}
}

void ACombatGameMode::AddPointToList(AActor* point)
{
	CreatPointList.Add(point);
}

void ACombatGameMode::BeginCreateEnemy()
{
	

	if (EnemyClassList.Num()>0) {
		int32 rIndex = FMath::RandRange(0, EnemyClassList.Num() - 1);
		int32 pointIndex = FMath::RandRange(0, CreatPointList.Num() - 1);
		FTransform transform = CreatPointList[pointIndex]->GetActorTransform();
		 AEnemyBaseCharacter* enemy=GetWorld()->SpawnActor<AEnemyBaseCharacter>(EnemyClassList[rIndex],transform);
		 EnemyList.Add(enemy);
		 CreatNum++;
		 FLatentActionInfo actionInfo;
		 actionInfo.Linkage = 1;
		 actionInfo.UUID = 100;
		 actionInfo.CallbackTarget = this;
		 actionInfo.ExecutionFunction = FName("LoopCreatEnemy");
		 UKismetSystemLibrary::Delay(GetWorld(), 3.0f,actionInfo);
	}
}

//循环创建敌人（当敌人小于一定数值的时候）
void ACombatGameMode::LoopCreatEnemy()
{
	if (CreatNum<6) {
		BeginCreateEnemy();
	}
}

void ACombatGameMode::CreatBoss()
{
	if (BossClass) {
		//FTransform transform = BossCreatePoint->GetActorTransform();
		ABossCharacter*boss=GetWorld()->SpawnActor<ABossCharacter>(BossClass,BossCreatePoint->GetActorTransform());
		if (boss) {
			MainUI->SetBoss(boss);
		}
	}
}

void ACombatGameMode::RemoveEnemy(AEnemyBaseCharacter* enemy)
{
	if (enemy) {
		EnemyList.Remove(enemy);
		if (EnemyList.Num()==0) {//表示所有敌人都被消灭
			isCreatBoss = true;
		}
	}
}

void ACombatGameMode::HideBossHealthBar()
{
	MainUI->HideBossHealthBar();
	ShowGameOverPanel(FText::FromString("Victory!"));
}

void ACombatGameMode::ShowGameOverPanel(FText desText)
{
	MainUI->RemoveFromParent();
	UGameOverWidget* userWidget = CreateWidget<UGameOverWidget>(GetWorld(), GameOverUIClass);
	if (userWidget) {
		userWidget->AddToViewport();
		userWidget->UpdateGameOverDesText(desText);
		APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		FInputModeUIOnly uionly;
		controller->SetInputMode(uionly);
		controller->bShowMouseCursor = true;
	}
}

void ACombatGameMode::ShowPausePanel()
{
	if (!PauseUIClass) return;
	if (!PauseWidget) {
		PauseWidget = CreateWidget<UPauseWidget>(GetWorld(), PauseUIClass);
	}
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	APlayerController* pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	pController->bShowMouseCursor=true;
	FInputModeUIOnly UIOnly;
	pController->SetInputMode(UIOnly);
	MainUI->RemoveFromParent();//移除MainUI
	PauseWidget->AddToViewport();

}

void ACombatGameMode::HidePausePanel()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	PauseWidget->RemoveFromParent();
	MainUI->AddToViewport();
	RestartGame();
}

void ACombatGameMode::RestartGame()
{
	APlayerController* pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	pController->bShowMouseCursor = false;
	FInputModeGameOnly gameOnly;
	pController->SetInputMode(gameOnly);

}

void ACombatGameMode::OnVolumeValueChange(float value)
{
	AudioActor->SetAudioVolume(value);
}

void ACombatGameMode::OnMusicPaused(bool isOn)
{
	AudioActor->ToggleBGMusic(isOn);
}

