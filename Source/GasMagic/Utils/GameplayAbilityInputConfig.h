// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "InputAction.h"
#include "Abilities/GameplayAbility.h"

#include "GameplayAbilityInputConfig.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FGameplayAbilityInputConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* AbilityInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<UGameplayAbility> GameplayAbility;
};
