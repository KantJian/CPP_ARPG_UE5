// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseWidget.h"

#include "Components/Button.h"
#include "Components/Slider.h"
#include "Components/CheckBox.h"
#include "Kismet/GameplayStatics.h"
#include "CombatGameMode.h"

bool UPauseWidget::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}
	ResumeBtn->OnClicked.AddDynamic(this, &UPauseWidget::OnResumeBtnClick);
	RestartBtn->OnClicked.AddDynamic(this, &UPauseWidget::OnRestartBtnClick);
	BackBtn->OnClicked.AddDynamic(this, &UPauseWidget::OnBackBtnClick);

	VolumeSlider->OnValueChanged.AddDynamic(this, &UPauseWidget::OnVolumeSliderValueChange);

	MusicToggle->OnCheckStateChanged.AddDynamic(this, &UPauseWidget::OnCheckValueChange);

	GameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	return true;
}


void UPauseWidget::OnResumeBtnClick()
{
	GameMode->HidePausePanel();
}

void UPauseWidget::OnRestartBtnClick()
{
	GameMode->RestartGame();
	UGameplayStatics::OpenLevel(GetWorld(),FName("ElvenRuins"));
}

void UPauseWidget::OnBackBtnClick()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("StartMenu"));
}

void UPauseWidget::OnVolumeSliderValueChange(float value)
{
	GameMode->OnVolumeValueChange(value);
}
void UPauseWidget::OnCheckValueChange(bool isOn)
{
	GameMode->OnMusicPaused(isOn);
}

