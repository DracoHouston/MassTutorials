// Fill out your copyright notice in the Description page of Project Settings.

#include "MassTutorialsStatics.h"
#include "MassSignalSubsystem.h"
#include "MassAgentComponent.h"

FEntityHandleWrapper UMassTutorialsStatics::
GetEntityHandleFromMassAgentComponent(
	UMassAgentComponent* AgentComponent)
{
	FEntityHandleWrapper result;
	result.EntityHandle = AgentComponent->GetEntityHandle();
	return result;
}

TArray<FMassTutorialsSoundWrapperFragment> UMassTutorialsStatics::
GetSoundWrapperFragmentsFromEntities(
	UObject* ContextObject, 
	const TArray<FEntityHandleWrapper>& Entities)
{
	return UMassTutorialsStatics::GetFragmentsFromEntities
		<FMassTutorialsSoundWrapperFragment>(
			ContextObject, Entities);
}

FMassTutorialsSoundWrapperFragment UMassTutorialsStatics::
GetSoundWrapperFragmentFromEntity(
	UObject* ContextObject, 
	const FEntityHandleWrapper& Entity)
{
	return UMassTutorialsStatics::GetFragmentFromEntity
		<FMassTutorialsSoundWrapperFragment>(
			ContextObject, Entity);
}

void UMassTutorialsStatics::
SetSoundWrapperFragmentsForEntities(
	UObject* ContextObject, 
	const TArray<FEntityHandleWrapper>& Entities, 
	const TArray<FMassTutorialsSoundWrapperFragment>& Fragments)
{
	return UMassTutorialsStatics::SetFragmentsForEntities
		<FMassTutorialsSoundWrapperFragment>(
			ContextObject, Entities, Fragments);
}

void UMassTutorialsStatics::
SetSoundWrapperFragmentForEntity(
	UObject* ContextObject, 
	const FEntityHandleWrapper& Entity, 
	const FMassTutorialsSoundWrapperFragment& Fragment)
{
	return UMassTutorialsStatics::SetFragmentForEntity
		<FMassTutorialsSoundWrapperFragment>(
			ContextObject, Entity, Fragment);
}

void UMassTutorialsStatics::
RaiseSignalOnEntity(
	UObject* ContextObject,
	const FEntityHandleWrapper& Entity,
	FName SignalName)
{
	if (ContextObject == nullptr)
	{
		return;
	}
	UMassSignalSubsystem* masssignals = ContextObject->GetWorld()->GetSubsystem<UMassSignalSubsystem>();
	if (masssignals == nullptr)
	{
		return;
	}
	masssignals->SignalEntity(SignalName, Entity.EntityHandle);
}

void UMassTutorialsStatics::
RaiseSignalOnEntities(
	UObject* ContextObject,
	const TArray<FEntityHandleWrapper>& Entities,
	FName SignalName)
{
	if (ContextObject == nullptr)
	{
		return;
	}
	UMassSignalSubsystem* masssignals = ContextObject->GetWorld()->GetSubsystem<UMassSignalSubsystem>();
	if (masssignals == nullptr)
	{
		return;
	}
	TArray<FMassEntityHandle> handles;
	for (int32 i = 0; i < Entities.Num(); i++)
	{
		handles.Add(Entities[i].EntityHandle);
	}
	masssignals->SignalEntities(SignalName, handles);
}

FMassTutorialsTauntSoundsFragment UMassTutorialsStatics::GetDefaultTauntSoundsFragmentFromEntity(UObject* ContextObject, const FEntityHandleWrapper& Entity)
{
	return UMassTutorialsStatics::GetSharedFragmentFromEntity<FMassTutorialsTauntSoundsFragment>(
		ContextObject,
		Entity);
}

void UMassTutorialsStatics::SetDefaultTauntSoundsFragmentForEntity(UObject* ContextObject, const FEntityHandleWrapper& Entity, const FMassTutorialsTauntSoundsFragment& Fragment)
{
	UMassTutorialsStatics::
		SetSharedFragmentForEntity<FMassTutorialsTauntSoundsFragment>(
			ContextObject, Entity, Fragment);
}

bool UMassTutorialsStatics::GetEntityHasMatureTag(UObject* ContextObject, const FEntityHandleWrapper& Entity)
{
	return UMassTutorialsStatics::GetEntityHasTag<FMassTutorialsMatureTag>(ContextObject, Entity);
}

TArray<bool> UMassTutorialsStatics::GetEntitiesHaveMatureTag(UObject* ContextObject, const TArray<FEntityHandleWrapper>& Entities)
{
	return UMassTutorialsStatics::GetEntitiesHaveTag<FMassTutorialsMatureTag>(ContextObject, Entities);
}

void UMassTutorialsStatics::SetEntityHasMatureTag(UObject* ContextObject, const FEntityHandleWrapper& Entity, bool NewHasTag)
{
	UMassTutorialsStatics::SetEntityHasTag<FMassTutorialsMatureTag>(
		ContextObject,
		Entity, 
		NewHasTag);
}

void UMassTutorialsStatics::SetEntitiesHaveMatureTag(UObject* ContextObject, const TArray<FEntityHandleWrapper>& Entities, TArray<bool> NewHaveTags)
{
	UMassTutorialsStatics::SetEntitiesHaveTag<FMassTutorialsMatureTag>(
		ContextObject,
		Entities, 
		NewHaveTags);
}
