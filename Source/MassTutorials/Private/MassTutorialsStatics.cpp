// Fill out your copyright notice in the Description page of Project Settings.

#include "MassTutorialsStatics.h"
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