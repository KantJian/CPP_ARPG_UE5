// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class ACTIONGAMES_DEMO_API DebugHelper
{
public:
	DebugHelper();
	~DebugHelper();
};


namespace Debug {
	//用于输出信息：要输出的信息、颜色、显示时间、key
	static void Print(const FString& message, const FColor color= FColor::MakeRandomColor(), float showTime = 2.0f,int inkey=-1) 
	{
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(inkey, showTime, color, message);
		}
		UE_LOG(LogTemp, Warning, TEXT("%s"),*message);
	}
}