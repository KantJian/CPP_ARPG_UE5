// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"


/**
 * 
 */
UCLASS()
class ACTIONGAMES_DEMO_API UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	virtual bool Initialize() override;

protected:
	UPROPERTY(meta = (BindWidget))//绑定用户界面
	class UProgressBar* HealthProgress;

	UFUNCTION()
	float GetHealthProgress();
public:
	UPROPERTY(BlueprintReadWrite, Category = "BaseCharacter")
	class ABaseCharacter* ownerCharacter;
};
