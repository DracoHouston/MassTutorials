// Fill out your copyright notice in the Description page of Project Settings.


#include "MassTutorialsTauntProcessor.h"
#include "MassTutorialsFragments.h"
#include "MassTutorialsTypes.h"
#include "MassCommonFragments.h"
#include "Kismet/GameplayStatics.h"

void UMassTutorialsTauntProcessor::Initialize(UObject& Owner)
{
	Super::Initialize(Owner);
	SubscribeToSignal(UE::Mass::Signals::PlayTaunt);
}

void UMassTutorialsTauntProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddSharedRequirement<FMassTutorialsTauntSoundsFragment>(EMassFragmentAccess::ReadOnly);
	FartersQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	FartersQuery.AddSharedRequirement<FMassTutorialsTauntSoundsFragment>(EMassFragmentAccess::ReadOnly, EMassFragmentPresence::All);
	FartersQuery.AddTagRequirement<FMassTutorialsMatureTag>(EMassFragmentPresence::None);
	YawnersQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	YawnersQuery.AddSharedRequirement<FMassTutorialsTauntSoundsFragment>(EMassFragmentAccess::ReadOnly, EMassFragmentPresence::All);
	YawnersQuery.AddTagRequirement<FMassTutorialsMatureTag>(EMassFragmentPresence::All);
}

void UMassTutorialsTauntProcessor::SignalEntities(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context, FMassSignalNameLookup& EntitySignals)
{
	FartersQuery.ForEachEntityChunk(
		EntitySubsystem,
		Context,
		[this](FMassExecutionContext& Context)
		{
			const FMassTutorialsTauntSoundsFragment& tauntsound = Context.GetSharedFragment<FMassTutorialsTauntSoundsFragment>();
			USoundBase* soundtouse = tauntsound.FarterTauntSound.Get();
			TConstArrayView<FTransformFragment> transforms = Context.GetFragmentView<FTransformFragment>();
			int32 entcount = Context.GetNumEntities();
			for (int32 i = 0; i < entcount; i++)
			{
				UGameplayStatics::PlaySoundAtLocation(this, soundtouse, transforms[i].GetTransform().GetLocation());
			}
		}
	);
	YawnersQuery.ForEachEntityChunk(
		EntitySubsystem,
		Context,
		[this](FMassExecutionContext& Context)
		{
			const FMassTutorialsTauntSoundsFragment& tauntsound = Context.GetSharedFragment<FMassTutorialsTauntSoundsFragment>();
			USoundBase* soundtouse = tauntsound.YawnerTauntSound.Get();
			TConstArrayView<FTransformFragment> transforms = Context.GetFragmentView<FTransformFragment>();
			int32 entcount = Context.GetNumEntities();
			for (int32 i = 0; i < entcount; i++)
			{
				UGameplayStatics::PlaySoundAtLocation(this, soundtouse, transforms[i].GetTransform().GetLocation());
			}
		}
	);
}
