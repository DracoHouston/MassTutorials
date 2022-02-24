// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassSignalProcessorBase.h"
#include "MassTutorialsSwitchProcessor.generated.h"

/**
 * 
 */
UCLASS()
class MASSTUTORIALS_API UMassTutorialsSwitchProcessor : public UMassSignalProcessorBase
{
	GENERATED_BODY()
public:
	UMassTutorialsSwitchProcessor();

	virtual void Initialize(UObject& Owner) override;
protected:
	virtual void ConfigureQueries() override;
	virtual void SignalEntities(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context, FMassSignalNameLookup& EntitySignals) override;

	FMassEntityQuery FartersQuery;
	FMassEntityQuery YawnersQuery;
};
