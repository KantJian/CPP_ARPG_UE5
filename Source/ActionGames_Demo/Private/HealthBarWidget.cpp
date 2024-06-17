// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidget.h"

#include "Components/ProgressBar.h"
#include "BaseCharacter.h"

bool UHealthBarWidget::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}
	HealthProgress->PercentDelegate.BindUFunction(this,FName("GetHealthProgress"));
	return true;
}

float UHealthBarWidget::GetHealthProgress()
{
	return ownerCharacter->GetHealthProgress();
}
