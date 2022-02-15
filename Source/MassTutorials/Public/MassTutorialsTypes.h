// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MassEntityTypes.h"
#include "MassTutorialsTypes.generated.h"

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