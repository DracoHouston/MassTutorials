// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MassTutorialsFragments.h"
#include "MassTutorialsTypes.h"
#include "MassEntityView.h"
#include "MassEntitySubsystem.h"
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
  
  UFUNCTION(BlueprintCallable)
		static void RaiseSignalOnEntity(
			const FEntityHandleWrapper& Entity);

	UFUNCTION(BlueprintCallable)
		static void RaiseSignalOnEntities(
			const TArray<FEntityHandleWrapper>& Entity);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static TArray<FMassTutorialsDefaultTauntSoundsFragment> GetDefaultTauntSoundsFragmentFromEntities(
		UObject* ContextObject,
		const TArray<FEntityHandleWrapper>& Entities);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FMassTutorialsDefaultTauntSoundsFragment GetDefaultTauntSoundsFragmentFromEntity(
		UObject* ContextObject,
		const FEntityHandleWrapper& Entity);

	UFUNCTION(BlueprintCallable)
	static void SetDefaultTauntSoundsFragmentsForEntities(
		UObject* ContextObject,
		const TArray<FEntityHandleWrapper>& Entities,
		const TArray<FMassTutorialsDefaultTauntSoundsFragment>& Fragments);

	UFUNCTION(BlueprintCallable)
	static void SetDefaultTauntSoundsFragmentForEntity(
		UObject* ContextObject,
		const FEntityHandleWrapper& Entity,
		const FMassTutorialsDefaultTauntSoundsFragment& Fragment);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool GetEntityHasMatureTag(
		UObject* ContextObject,
		const FEntityHandleWrapper& Entity);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static TArray<bool> GetEntitiesHaveMatureTag(
			UObject* ContextObject,
			const TArray<FEntityHandleWrapper>& Entities);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static void SetEntityHasMatureTag(
			UObject* ContextObject,
			const FEntityHandleWrapper& Entity,
			bool NewHasTag);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static void SetEntitiesHaveMatureTag(
		UObject* ContextObject,
		const TArray<FEntityHandleWrapper>& Entities,
		TArray<bool> NewHaveTags);
    
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

	template <typename T>
	static T GetSharedFragmentFromEntity(
		UMassEntitySubsystem* EntitySubsystem,
		const FEntityHandleWrapper& Entity)
	{
		FMassEntityView view(*EntitySubsystem, Entity.EntityHandle);
		T& sharedfragment = view.GetSharedFragmentData<T>();
		return T(sharedfragment);
	}

	template <typename T>
	static void SetSharedFragmentForEntity(
		UMassEntitySubsystem* EntitySubsystem,
		const FEntityHandleWrapper& Entity,
		const T& Fragment)
	{
		FMassEntityView view(*EntitySubsystem, Entity.EntityHandle);
		UScriptStruct* scriptstruct = T::StaticStruct();
		T& oldfragment = view.GetSharedFragmentData<T>();
		if (scriptstruct->CompareScriptStruct(&Fragment, &oldfragment, 0))
		{
			return;
		}
		oldfragment = Fragment;
	}

	template <typename T>
	static TArray<bool> GetEntitiesHaveTag(
		UMassEntitySubsystem* EntitySubsystem,
		const TArray<FEntityHandleWrapper>& Entities)
	{
		TArray<bool> results;

		for (int32 i = 0; i < Entities.Num(); ++i)
		{
			FMassEntityView View(*EntitySubsystem, Entities[i].EntityHandle);
			results.Add(View.HasTag<T>());
		}
		return results;
	}

	template <typename T>
	static bool GetEntityHasTag(
		UMassEntitySubsystem* EntitySubsystem,
		const FEntityHandleWrapper& Entity)
	{
		FMassEntityView View(*EntitySubsystem, Entity.EntityHandle);
		return View.HasTag<T>();
	}

	template <typename T>
	static void SetEntitiesHaveTag(
		UMassEntitySubsystem* EntitySubsystem,
		const TArray<FEntityHandleWrapper>& Entities,
		TArray<bool> NewHaveTags)
	{
		for (int32 i = 0; i < Entities.Num(); ++i)
		{
			if (NewHaveTags[i])
			{
				EntitySubsystem->AddTagToEntity(Entities[i].EntityHandle, T::StaticStruct());
			}
			else
			{
				EntitySubsystem->RemoveTagFromEntity(Entities[i].EntityHandle, T::StaticStruct());
			}
		}
	}

	template <typename T>
	static void SetEntityHasTag(
		UMassEntitySubsystem* EntitySubsystem,
		const FEntityHandleWrapper& Entity,
		bool NewHasTag)
	{
		if (NewHasTag)
		{
			EntitySubsystem->AddTagToEntity(Entity.EntityHandle, T::StaticStruct());
		}
		else
		{
			EntitySubsystem->RemoveTagFromEntity(Entity.EntityHandle, T::StaticStruct());
		}
	}
};

