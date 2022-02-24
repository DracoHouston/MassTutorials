// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MassTutorialsFragments.h"
#include "MassTutorialsTypes.h"
#include "MassTutorialsStatics.generated.h"

class UMassAgentComponent;

USTRUCT()
struct MASSTUTORIALS_API FHandleAndFragmentArray
{
	GENERATED_BODY()

public:
	TArray<FMassEntityHandle> Handles;
	TArray<FInstancedStruct> Fragments;
};

UCLASS()
class MASSTUTORIALS_API UMassTutorialsStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FEntityHandleWrapper GetEntityHandleFromMassAgentComponent(UMassAgentComponent* AgentComponent);

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
	
	template <typename T>
	static TArray<T> GetFragmentsFromEntities(
		UObject* ContextObject,
		const TArray<FEntityHandleWrapper>& Entities)
	{
		TArray<T> results;
		if (ContextObject == nullptr)
		{
			return results;
		}
		UMassEntitySubsystem* entitysubsystem =
			ContextObject->GetWorld()
			->GetSubsystem<UMassEntitySubsystem>();
		if (entitysubsystem == nullptr)
		{
			return results;
		}
		for (int32 i = 0; i < Entities.Num(); ++i)
		{
			results.Add(
				entitysubsystem->
				GetFragmentDataChecked<T>(
					Entities[i].EntityHandle));
		}
		return results;
	}

	template <typename T>
	static T GetFragmentFromEntity(
		UObject* ContextObject,
		const FEntityHandleWrapper& Entity)
	{
		if (ContextObject == nullptr)
		{
			return T();
		}
		UMassEntitySubsystem* entitysubsystem =
			ContextObject->GetWorld()
			->GetSubsystem<UMassEntitySubsystem>();
		if (entitysubsystem == nullptr)
		{
			return T();
		}
		return entitysubsystem->GetFragmentDataChecked
			<T>(Entity.EntityHandle);
	}

	template<typename T>
	static void SetFragmentsForEntities(
		UObject* ContextObject,
		const TArray<FEntityHandleWrapper>& Entities,
		const TArray<T>& Fragments)
	{
		if (ContextObject == nullptr)
		{
			return;
		}
		UMassEntitySubsystem* entitysubsystem =
			ContextObject->GetWorld()
			->GetSubsystem<UMassEntitySubsystem>();
		if (entitysubsystem == nullptr)
		{
			return;
		}
		TMap<FMassArchetypeHandle,
			FHandleAndFragmentArray> archetypemap;
		for (int32 i = 0; i < Entities.Num(); ++i)
		{
			FHandleAndFragmentArray& handleandfragmentarray
				= archetypemap.FindOrAdd(
					entitysubsystem->GetArchetypeForEntity(
						Entities[i].EntityHandle));
			handleandfragmentarray.Handles.Add(Entities[i].EntityHandle);
			handleandfragmentarray.Fragments.Add(
				FInstancedStruct::Make<T>(Fragments[i]));
		}
		for (auto It = archetypemap.CreateIterator(); It; ++It)
		{
			FMassArchetypeSubChunks subchunks(
				It->Key,
				It->Value.Handles,
				FMassArchetypeSubChunks::
				EDuplicatesHandling::NoDuplicates);
			entitysubsystem->BatchSetEntityFragmentsValues(
				subchunks,
				It->Value.Fragments);
		}
	}

	template<typename T>
	static void SetFragmentForEntity(
		UObject* ContextObject,
		const FEntityHandleWrapper& Entity,
		const T& Fragment)
	{
		if (ContextObject == nullptr)
		{
			return;
		}
		UMassEntitySubsystem* entitysubsystem =
			ContextObject->GetWorld()
			->GetSubsystem<UMassEntitySubsystem>();
		if (entitysubsystem == nullptr)
		{
			return;
		}
		TArray<FInstancedStruct> structarray;
		structarray.Add(
			FInstancedStruct::Make<T>(
				Fragment));
		entitysubsystem->SetEntityFragmentsValues(
			Entity.EntityHandle,
			structarray);
	}
};


