// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseWidget.generated.h"


class UButton;
class USlider;
class UCheckBox;
class ACombatGameMode;
/**
 * 
 */
UCLASS()
class ACTIONGAMES_DEMO_API UPauseWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget));
	TObjectPtr<UButton> ResumeBtn;

	UPROPERTY(meta = (BindWidget));
	TObjectPtr<UButton> RestartBtn;

	UPROPERTY(meta = (BindWidget));
	TObjectPtr<UButton> BackBtn;

	UPROPERTY(meta = (BindWidget));
	TObjectPtr<USlider> VolumeSlider;

	UPROPERTY(meta = (BindWidget));
	TObjectPtr<UCheckBox> MusicToggle;

	UPROPERTY(BlueprintReadOnly, Category = "GameMode")
	TObjectPtr<ACombatGameMode> GameMode;

	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void OnResumeBtnClick();
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void OnRestartBtnClick();
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void OnBackBtnClick();

	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void OnVolumeSliderValueChange(float value);
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void OnCheckValueChange(bool isOn);

public:
	virtual	bool Initialize() override;
};
