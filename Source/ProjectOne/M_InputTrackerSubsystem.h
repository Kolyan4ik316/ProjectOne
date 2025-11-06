// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Framework/Application/SlateApplication.h"
#include "M_InputTrackerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTONE_API UM_InputTrackerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	int32 GetLastInputDeviceId() const;

	//UFUNCTION(BlueprintCallable, Category = "Input")
	//bool WasLastInputGamepad() const;
	
};
