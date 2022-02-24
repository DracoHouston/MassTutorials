// Fill out your copyright notice in the Description page of Project Settings.

#include "MassTutorialsTraits.h"
#include "MassTutorialsFragments.h"
#include "MassEntityTemplateRegistry.h"
#include "MassEntityView.h"

void UMassTutorialsTaunterTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const
{
	BuildContext.AddChunkFragment<FMassTutorialsTauntSoundFragment>();
	FMassTutorialsDefaultTauntSoundsFragment defaultsounds;
	defaultsounds.FarterTauntSound = FarterTauntSound;
	defaultsounds.YawnerTauntSound = YawnerTauntSound;
	uint32 defaultsoundshash = UE::StructUtils::GetStructCrc32(FConstStructView::Make(defaultsounds));
	FSharedStruct shareddefaultsounds = World.GetSubsystem<UMassEntitySubsystem>()->GetOrCreateSharedFragment<FMassTutorialsDefaultTauntSoundsFragment>(defaultsoundshash, defaultsounds);
	BuildContext.AddSharedFragment(shareddefaultsounds);
	if (StartMature)
	{
		BuildContext.AddTag<FMassTutorialsMatureTag>();
	}
}