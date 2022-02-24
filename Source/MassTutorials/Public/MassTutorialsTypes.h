// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MassEntityTypes.h"
#include "MassTutorialsTypes.generated.h"

namespace UE::Mass::Signals
{
	const FName PlayTaunt = FName(TEXT("PlayTaunt"));
	const FName SwitchTaunt = FName(TEXT("SwitchTaunt"));
}

USTRUCT(BlueprintType)
struct MASSTUTORIALS_API FEntityHandleWrapper
{
	GENERATED_BODY()

public:
	UPROPERTY()
		FMassEntityHandle EntityHandle;

	FEntityHandleWrapper()
	{
		EntityHandle = FMassEntityHandle();
	}

};