// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageExecutionCalculation.h"
#include "../AttributeSets/MagicAttributeSet.h"
#include "../GasMagicCharacter.h"

struct DamageCapture
{
    DECLARE_ATTRIBUTE_CAPTUREDEF(Health);
    DECLARE_ATTRIBUTE_CAPTUREDEF(MaxHealth);

    DamageCapture()
    {
        DEFINE_ATTRIBUTE_CAPTUREDEF(UMagicAttributeSet, Health, Target, false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UMagicAttributeSet, MaxHealth, Target, false);
    }
};

static DamageCapture& GetDamageCapture()
{
    static DamageCapture DamageCapture;
    return DamageCapture;
}

UDamageExecutionCalculation::UDamageExecutionCalculation()
{
    RelevantAttributesToCapture.Add(GetDamageCapture().HealthDef);
    RelevantAttributesToCapture.Add(GetDamageCapture().MaxHealthDef);
}

void UDamageExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters &ExecutionParams, FGameplayEffectCustomExecutionOutput &OutExecutionOutput) const
{
    UAbilitySystemComponent* TargetAbilitySystemComponent = ExecutionParams.GetTargetAbilitySystemComponent();
    AActor* TargetActor = TargetAbilitySystemComponent->GetAvatarActor();

    UAbilitySystemComponent* SourceAbilitySystemComponent = ExecutionParams.GetTargetAbilitySystemComponent();
    AActor* SourceActor = SourceAbilitySystemComponent->GetAvatarActor();

    const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
    const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
    const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

    FAggregatorEvaluateParameters EvaluationParameters;
    EvaluationParameters.SourceTags = SourceTags;
    EvaluationParameters.TargetTags = TargetTags;

    //float Health = 0.0f;
    //ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().HealthDef, EvaluationParameters, Health);

    //float MaxHealth = 0.0f;
    //ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().MaxHealthDef, EvaluationParameters, MaxHealth);

    //float HealthToAdd = FMath::Clamp(MaxHealth - Health, 0.0f, 1.0f);

    float DamageMultiplier = 0.0f;
    if(Cast<AGasMagicCharacter>(TargetActor))
    {
        //GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, FString::Printf(TEXT("CAST TRUE")));
        DamageMultiplier = -1.0f;
    }

    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().HealthProperty, EGameplayModOp::Additive, DamageMultiplier));
}
