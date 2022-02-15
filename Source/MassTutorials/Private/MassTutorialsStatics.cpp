// Fill out your copyright notice in the Description page of Project Settings.

#include "MassTutorialsStatics.h"
#include "MassAgentComponent.h"

TArray<FMassTutorialsSoundWrapperFragment> UMassTutorialsStatics::GetSoundWrapperFragmentsFromEntities(UObject* ContextObject, const TArray<FEntityHandleWrapper>& Entities)
{
	TArray<FMassTutorialsSoundWrapperFragment> results;
	if (ContextObject == nullptr)
	{
		return results;
	}
	UMassEntitySubsystem* entitysubsystem = ContextObject->GetWorld()->GetSubsystem<UMassEntitySubsystem>();
	if (entitysubsystem == nullptr)
	{
		return results;
	}
	for (int32 i = 0; i < Entities.Num(); ++i)
	{
		results.Add(entitysubsystem->GetFragmentDataChecked<FMassTutorialsSoundWrapperFragment>(Entities[i].EntityHandle));
	}
	return results;
}

FMassTutorialsSoundWrapperFragment UMassTutorialsStatics::GetSoundWrapperFragmentFromEntity(UObject* ContextObject, const FEntityHandleWrapper& Entity)
{
	if (ContextObject == nullptr)
	{
		return FMassTutorialsSoundWrapperFragment();
	}
	UMassEntitySubsystem* entitysubsystem = ContextObject->GetWorld()->GetSubsystem<UMassEntitySubsystem>();
	if (entitysubsystem == nullptr)
	{
		return FMassTutorialsSoundWrapperFragment();
	}
	return entitysubsystem->GetFragmentDataChecked <FMassTutorialsSoundWrapperFragment>(Entity.EntityHandle);
}

void UMassTutorialsStatics::SetSoundWrapperFragmentsForEntities(UObject* ContextObject, const TArray<FEntityHandleWrapper>& Entities, const TArray<FMassTutorialsSoundWrapperFragment>& Fragments)
{
	if ((Entities.Num() != Fragments.Num()) || (ContextObject == nullptr))
	{
		return;
	}
	UMassEntitySubsystem* entitysubsystem = ContextObject->GetWorld()->GetSubsystem<UMassEntitySubsystem>();

	if (entitysubsystem == nullptr)
	{
		return;
	}
	TMap<FMassArchetypeHandle, FMassTutorialsHandleAndFragmentArray> archetypemap;
	for (int32 i = 0; i < Entities.Num(); ++i)
	{
		FMassTutorialsHandleAndFragmentArray& handleandfragmentarray = archetypemap.FindOrAdd(entitysubsystem->GetArchetypeForEntity(Entities[i].EntityHandle));
		handleandfragmentarray.Handles.Add(Entities[i].EntityHandle);
		handleandfragmentarray.Fragments.Add(FInstancedStruct::Make<FMassTutorialsSoundWrapperFragment>(Fragments[i]));
	}
	for (auto It = archetypemap.CreateIterator(); It; ++It)
	{
		FMassArchetypeSubChunks subchunks = FMassArchetypeSubChunks(It->Key, It->Value.Handles, FMassArchetypeSubChunks::EDuplicatesHandling::NoDuplicates);
		entitysubsystem->BatchSetEntityFragmentsValues(
			subchunks,
			It->Value.Fragments);
	}
}

void UMassTutorialsStatics::SetSoundWrapperFragmentForEntity(UObject* ContextObject, const FEntityHandleWrapper& Entity, const FMassTutorialsSoundWrapperFragment& Fragment)
{
	if (ContextObject == nullptr)
	{
		return;
	}
	UMassEntitySubsystem* entitysubsystem = ContextObject->GetWorld()->GetSubsystem<UMassEntitySubsystem>();
	if (entitysubsystem == nullptr)
	{
		return;
	}
	TArray<FInstancedStruct> structarray;
	structarray.Add(FInstancedStruct::Make<FMassTutorialsSoundWrapperFragment>(Fragment));
	entitysubsystem->SetEntityFragmentsValues(Entity.EntityHandle, structarray);
}

FEntityHandleWrapper UMassTutorialsStatics::GetEntityHandleFromMassAgentComponent(UMassAgentComponent* AgentComponent)
{
	FEntityHandleWrapper result;
	result.EntityHandle = AgentComponent->GetEntityHandle();
	return result;
}