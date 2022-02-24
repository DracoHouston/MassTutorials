// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassSignalProcessorBase.h"
#include "MassTutorialsTauntProcessor.generated.h"

/**
 * 
 */
UCLASS()
class MASSTUTORIALS_API UMassTutorialsTauntProcessor : public UMassSignalProcessorBase
{
	GENERATED_BODY()
public:
	virtual void Initialize(UObject& Owner) override;
protected:
	virtual void ConfigureQueries() override;
	virtual void SignalEntities(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context, FMassSignalNameLookup& EntitySignals) override;

	FMassEntityQuery FartersQuery;
	FMassEntityQuery YawnersQuery;
};
