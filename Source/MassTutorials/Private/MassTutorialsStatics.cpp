// Fill out your copyright notice in the Description page of Project Settings.

#include "MassTutorialsStatics.h"
#include "MassAgentComponent.h"

TArray<FMassTutorialsSoundWrapperFragment> 
UMassTutorialsStatics::GetSoundWrapperFragmentsFromEntities(
	UObject* ContextObject, 
	const TArray<FEntityHandleWrapper>& Entities)
{
	UMassEntitySubsystem* entitysubsystem = 
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return TArray<FMassTutorialsSoundWrapperFragment>();
	}
	return UMassTutorialsStatics::
		GetFragmentsFromEntities<FMassTutorialsSoundWrapperFragment>(
			entitysubsystem, Entities); 
}

FMassTutorialsSoundWrapperFragment 
UMassTutorialsStatics::GetSoundWrapperFragmentFromEntity(
	UObject* ContextObject, 
	const FEntityHandleWrapper& Entity)
{
	UMassEntitySubsystem* entitysubsystem = 
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return FMassTutorialsSoundWrapperFragment();
	}
	return UMassTutorialsStatics::
		GetFragmentFromEntity<FMassTutorialsSoundWrapperFragment>(
			entitysubsystem, Entity); 
}

void UMassTutorialsStatics::SetSoundWrapperFragmentsForEntities(
	UObject* ContextObject, 
	const TArray<FEntityHandleWrapper>& Entities, 
	const TArray<FMassTutorialsSoundWrapperFragment>& Fragments)
{
	UMassEntitySubsystem* entitysubsystem = 
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if ((Entities.Num() != Fragments.Num()) || 
		(entitysubsystem == nullptr))
	{
		return;
	}
	return UMassTutorialsStatics::
		SetFragmentsForEntities<FMassTutorialsSoundWrapperFragment>(
			entitysubsystem, Entities, Fragments);
}

void UMassTutorialsStatics::SetSoundWrapperFragmentForEntity(
	UObject* ContextObject, 
	const FEntityHandleWrapper& Entity, 
	const FMassTutorialsSoundWrapperFragment& Fragment)
{
	UMassEntitySubsystem* entitysubsystem = 
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return;
	}
	UMassTutorialsStatics::
		SetFragmentForEntity<FMassTutorialsSoundWrapperFragment>(
			entitysubsystem, Entity, Fragment);
}

FEntityHandleWrapper 
UMassTutorialsStatics::GetEntityHandleFromMassAgentComponent(
	UMassAgentComponent* AgentComponent)
{
	FEntityHandleWrapper result;
	result.EntityHandle = AgentComponent->GetEntityHandle();
	return result;
}

void UMassTutorialsStatics::RaiseSignalOnEntity(const FEntityHandleWrapper& Entity)
{
}

void UMassTutorialsStatics::RaiseSignalOnEntities(const TArray<FEntityHandleWrapper>& Entity)
{
}

TArray<FMassTutorialsDefaultTauntSoundsFragment> UMassTutorialsStatics::GetDefaultTauntSoundsFragmentFromEntities(UObject* ContextObject, const TArray<FEntityHandleWrapper>& Entities)
{
	UMassEntitySubsystem* entitysubsystem =
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return TArray<FMassTutorialsDefaultTauntSoundsFragment>();
	}
	return UMassTutorialsStatics::GetFragmentsFromEntities<FMassTutorialsDefaultTauntSoundsFragment>(
		entitysubsystem, 
		Entities);
}

FMassTutorialsDefaultTauntSoundsFragment UMassTutorialsStatics::GetDefaultTauntSoundsFragmentFromEntity(UObject* ContextObject, const FEntityHandleWrapper& Entity)
{
	UMassEntitySubsystem* entitysubsystem =
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return FMassTutorialsDefaultTauntSoundsFragment();
	}
	return UMassTutorialsStatics::GetSharedFragmentFromEntity<FMassTutorialsDefaultTauntSoundsFragment>(
		entitysubsystem,
		Entity);
}

void UMassTutorialsStatics::SetDefaultTauntSoundsFragmentsForEntities(UObject* ContextObject, const TArray<FEntityHandleWrapper>& Entities, const TArray<FMassTutorialsDefaultTauntSoundsFragment>& Fragments)
{
	UMassEntitySubsystem* entitysubsystem =
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return;
	}
	UMassTutorialsStatics::
		SetFragmentsForEntities<FMassTutorialsDefaultTauntSoundsFragment>(
			entitysubsystem, Entities, Fragments);
}

void UMassTutorialsStatics::SetDefaultTauntSoundsFragmentForEntity(UObject* ContextObject, const FEntityHandleWrapper& Entity, const FMassTutorialsDefaultTauntSoundsFragment& Fragment)
{
	UMassEntitySubsystem* entitysubsystem =
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return;
	}
	UMassTutorialsStatics::
		SetSharedFragmentForEntity<FMassTutorialsDefaultTauntSoundsFragment>(
			entitysubsystem, Entity, Fragment);
}

bool UMassTutorialsStatics::GetEntityHasMatureTag(UObject* ContextObject, const FEntityHandleWrapper& Entity)
{
	UMassEntitySubsystem* entitysubsystem =
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return false;
	}
	return UMassTutorialsStatics::GetEntityHasTag<FMassTutorialsMatureTag>(entitysubsystem, Entity);
}

TArray<bool> UMassTutorialsStatics::GetEntitiesHaveMatureTag(UObject* ContextObject, const TArray<FEntityHandleWrapper>& Entities)
{
	UMassEntitySubsystem* entitysubsystem =
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return TArray<bool>();
	}
	return UMassTutorialsStatics::GetEntitiesHaveTag<FMassTutorialsMatureTag>(entitysubsystem, Entities);
}

void UMassTutorialsStatics::SetEntityHasMatureTag(UObject* ContextObject, const FEntityHandleWrapper& Entity, bool NewHasTag)
{
	UMassEntitySubsystem* entitysubsystem =
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return;
	}
	UMassTutorialsStatics::SetEntityHasTag<FMassTutorialsMatureTag>(
		entitysubsystem, 
		Entity, 
		NewHasTag);
}

void UMassTutorialsStatics::SetEntitiesHaveMatureTag(UObject* ContextObject, const TArray<FEntityHandleWrapper>& Entities, TArray<bool> NewHaveTags)
{
	UMassEntitySubsystem* entitysubsystem =
		UMassTutorialsStatics::GetMassEntitySubsystem(ContextObject);
	if (entitysubsystem == nullptr)
	{
		return;
	}
	UMassTutorialsStatics::SetEntitiesHaveTag<FMassTutorialsMatureTag>(
		entitysubsystem, 
		Entities, 
		NewHaveTags);
}
