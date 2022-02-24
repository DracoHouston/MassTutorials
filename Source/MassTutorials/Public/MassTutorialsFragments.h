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

/**
* Tag indicating the player is very mature.
*/
USTRUCT(BlueprintType)
struct MASSTUTORIALS_API FMassTutorialsMatureTag : public FMassTag
{
	GENERATED_BODY()
};

/**
* Shared fragment storing default taunt sounds for Farters and Yawners
*/
USTRUCT(BlueprintType)
struct MASSTUTORIALS_API FMassTutorialsTauntSoundsFragment : public FMassSharedFragment
{
	GENERATED_BODY()

	//Sound all Farters use for their taunt
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TWeakObjectPtr<USoundBase> FarterTauntSound;

	//Sound all Yawners use for their taunt
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TWeakObjectPtr<USoundBase> YawnerTauntSound;
};