// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTypes.h"

#include "MassTutorialsFragments.generated.h"

/**
* Fragment wrapping a sound asset
*/
USTRUCT(BlueprintType)
struct MASSTUTORIALS_API FMassTutorialsSoundWrapperFragment : public FMassFragment
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TWeakObjectPtr<USoundBase> SoundToUse;
};