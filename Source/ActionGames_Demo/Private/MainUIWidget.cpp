// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUIWidget.h"
#include "Components/ProgressBar.h"
#include "Components/VerticalBox.h"
#include "PlayerBaseCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/WidgetAnimation.h"
#include "BossCharacter.h"


bool UMainUIWidget::Initialize()
{

	if (!Super::Initialize()) {
		return false;
	}
	PlayerCharacter = Cast<APlayerBaseCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	PlayerHealthBar->PercentDelegate.BindUFunction(this,FName("GetPlayerHealthProgress"));
	BossHealthBar->PercentDelegate.BindUFunction(this, FName("GetBossHealthProgress"));//绑定boss血条

	return false;
}

float UMainUIWidget::GetPlayerHealthProgress()
{
	if (PlayerCharacter) {
		return PlayerCharacter->GetHealthProgress();
	}


	return 0.0f;
}


void UMainUIWidget::PlayBloodAnimation()
{
	PlayAnimation(BloodScreenAnim);
}

void UMainUIWidget::SetBoss(ABossCharacter* Boss)
{
	BossCharacter = Boss;

	if (Boss) {
		BossHealthBarPanel->SetVisibility(ESlateVisibility::Visible);//显示boss血条
	}

}

void UMainUIWidget::HideBossHealthBar()
{
	BossHealthBarPanel->SetVisibility(ESlateVisibility::Hidden);
}


float UMainUIWidget::GetBossHealthProgress()
{
	if (BossCharacter) {
		return BossCharacter->GetHealthProgress();
	}

	return 0.0f;
}