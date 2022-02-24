// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MassTutorialsTraits.generated.h"

UCLASS()
class MASSTUTORIALS_API UMassTutorialsFarterTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

protected:

	virtual void BuildTemplate(
		FMassEntityTemplateBuildContext& BuildContext,
		UWorld& World) const override;

	UPROPERTY(EditAnywhere, Category = Mass)
		USoundBase* SoundToUse;
};