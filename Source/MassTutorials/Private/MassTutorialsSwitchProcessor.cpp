// Fill out your copyright notice in the Description page of Project Settings.


#include "MassTutorialsSwitchProcessor.h"
#include "MassTutorialsTypes.h"
#include "MassTutorialsFragments.h"
#include "MassCommonFragments.h"

UMassTutorialsSwitchProcessor::UMassTutorialsSwitchProcessor()
{
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
}

void UMassTutorialsSwitchProcessor::Initialize(UObject& Owner)
{
	Super::Initialize(Owner);
	SubscribeToSignal(UE::Mass::Signals::SwitchTaunt);
}

void UMassTutorialsSwitchProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddSharedRequirement<FMassTutorialsTauntSoundsFragment>(EMassFragmentAccess::ReadOnly);

	FartersQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	FartersQuery.AddSharedRequirement<FMassTutorialsTauntSoundsFragment>(EMassFragmentAccess::ReadOnly);
	FartersQuery.AddTagRequirement<FMassTutorialsMatureTag>(EMassFragmentPresence::None);

	YawnersQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	YawnersQuery.AddSharedRequirement<FMassTutorialsTauntSoundsFragment>(EMassFragmentAccess::ReadOnly);
	YawnersQuery.AddTagRequirement<FMassTutorialsMatureTag>(EMassFragmentPresence::All);

}

void UMassTutorialsSwitchProcessor::SignalEntities(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context, FMassSignalNameLookup& EntitySignals)
{
	TArray<FMassEntityHandle> newfarters;
	TArray<FMassEntityHandle> newyawners;
	
	FartersQuery.ForEachEntityChunk(
		EntitySubsystem, 
		Context,
		[this, &newyawners](FMassExecutionContext& Context)
		{
			TConstArrayView<FMassEntityHandle> entities = Context.GetEntities();
			newyawners.Append(entities.GetData(), entities.Num());
		}
	);
	YawnersQuery.ForEachEntityChunk(
		EntitySubsystem,
		Context,
		[this, &newfarters](FMassExecutionContext& Context)
		{
			TConstArrayView<FMassEntityHandle> entities = Context.GetEntities();
			newfarters.Append(entities.GetData(), entities.Num());
		}
	);
	
	for (int32 i = 0; i < newfarters.Num(); ++i)
	{
		EntitySubsystem.RemoveTagFromEntity(newfarters[i], FMassTutorialsMatureTag::StaticStruct());
	}

	for (int32 i = 0; i < newyawners.Num(); ++i)
	{
		EntitySubsystem.AddTagToEntity(newyawners[i], FMassTutorialsMatureTag::StaticStruct());
	}
}
