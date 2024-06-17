// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "DebugHelper.h"

bool UGameOverWidget::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}

	RestartBtn->OnClicked.AddDynamic(this, &UGameOverWidget::RestartBtnClick);
	BackBtn->OnClicked.AddDynamic(this, &UGameOverWidget::BackBtnClick);

	return true;
}

void UGameOverWidget::RestartBtnClick()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("ElvenRuins"));
}

void UGameOverWidget::BackBtnClick()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("StartMenu"));
}

void UGameOverWidget::UpdateGameOverDesText(FText desText)
{
	GameOverDesText->SetText(desText);
}
