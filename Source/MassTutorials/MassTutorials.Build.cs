// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MassTutorials : ModuleRules
{
	public MassTutorials(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"MassEntity",
			"MassActors",
			"MassCommon",
			"MassSpawner",
			"StructUtils",
		});
	}
}
