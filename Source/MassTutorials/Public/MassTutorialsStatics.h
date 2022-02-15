// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MassTutorialsFragments.h"
#include "MassTutorialsTypes.h"
#include "MassTutorialsStatics.generated.h"

class UMassAgentComponent;

UCLASS()
class MASSTUTORIALS_API UMassTutorialsStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<FMassTutorialsSoundWrapperFragment> GetSoundWrapperFragmentsFromEntities(
			UObject* ContextObject,
			const TArray<FEntityHandleWrapper>& Entities);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FMassTutorialsSoundWrapperFragment GetSoundWrapperFragmentFromEntity(
			UObject* ContextObject,
			const FEntityHandleWrapper& Entity);

	UFUNCTION(BlueprintCallable)
		static void SetSoundWrapperFragmentsForEntities(
			UObject* ContextObject,
			const TArray<FEntityHandleWrapper>& Entities,
			const TArray<FMassTutorialsSoundWrapperFragment>& Fragments);

	UFUNCTION(BlueprintCallable)
		static void SetSoundWrapperFragmentForEntity(
			UObject* ContextObject,
			const FEntityHandleWrapper& Entity,
			const FMassTutorialsSoundWrapperFragment& Fragment);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FEntityHandleWrapper GetEntityHandleFromMassAgentComponent(UMassAgentComponent* AgentComponent);

};


USTRUCT()
struct MASSTUTORIALS_API FMassTutorialsHandleAndFragmentArray
{
	GENERATED_BODY()

public:
	TArray<FMassEntityHandle> Handles;
	TArray<FInstancedStruct> Fragments;
};