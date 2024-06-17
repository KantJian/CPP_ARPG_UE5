// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMenuGameModeBase.h"

#include "StartMenuWidget.h"
#include "Kismet/GameplayStatics.h"

void AStartMenuGameModeBase::BeginPlay()
{
	if (StartMenuClass) {
		UStartMenuWidget* widget=CreateWidget<UStartMenuWidget>(GetWorld(), StartMenuClass);
		widget->AddToViewport();
		APlayerController* pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		FInputModeUIOnly uiOnly;
		pController->SetInputMode(uiOnly);
		pController->bShowMouseCursor = true;
	}
}
