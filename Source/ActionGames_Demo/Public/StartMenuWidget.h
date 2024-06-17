// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartMenuWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class ACTIONGAMES_DEMO_API UStartMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override;
protected:
	UPROPERTY(meta = (BingWidget))
	TObjectPtr<UButton> StartGameBtn;
	UPROPERTY(meta = (BingWidget))
	TObjectPtr<UButton> QuitBtn;
	UFUNCTION()
	void OnStartGameBtnClick();
	UFUNCTION()
	void QuitBtnClick();
};
