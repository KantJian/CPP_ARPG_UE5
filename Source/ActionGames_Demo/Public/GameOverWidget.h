// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

class UTextBlock;
class UButton;
/**
 * 
 */
UCLASS()
class ACTIONGAMES_DEMO_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override;
protected:
	UPROPERTY(meta = (BindWidget))
	UButton* RestartBtn;

	UPROPERTY(meta = (BindWidget))
	UButton* BackBtn;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* GameOverDesText;

	UFUNCTION()
	void RestartBtnClick();
	UFUNCTION()
	void BackBtnClick();

public:
	UFUNCTION()
	void UpdateGameOverDesText(FText desText);

};
