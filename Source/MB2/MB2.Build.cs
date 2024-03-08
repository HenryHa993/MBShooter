// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MB2 : ModuleRules
{
	public MB2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
		PublicDependencyModuleNames.AddRange(new string[] { "AIModule", "NavigationSystem", "GameplayTasks"});
        PublicDependencyModuleNames.AddRange(new string[] { "UMG" });

    }
}
