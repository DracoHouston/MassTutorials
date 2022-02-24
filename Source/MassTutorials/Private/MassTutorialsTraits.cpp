// Fill out your copyright notice in the Description page of Project Settings.

#include "MassTutorialsTraits.h"
#include "MassTutorialsFragments.h"
#include "MassEntityTemplateRegistry.h"
#include "MassEntityView.h"

void UMassTutorialsFarterTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const
{
	BuildContext.AddFragment<FMassTutorialsSoundWrapperFragment>();
	BuildContext.GetMutableObjectFragmentInitializers().Add(
		[=](UObject& Owner, FMassEntityView& EntityView, const EMassTranslationDirection CurrentDirection)
		{
			FMassTutorialsSoundWrapperFragment& fartfragment = EntityView.GetFragmentData<FMassTutorialsSoundWrapperFragment>();
			fartfragment.SoundToUse = SoundToUse;
		}
	);
}