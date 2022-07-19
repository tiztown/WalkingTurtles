// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WalkingTurtles : ModuleRules
{
	public WalkingTurtles(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "Niagara", "PhysicsCore", "GameplayTasks", "NavigationSystem",
			"UMG",
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[]
		{
			"WalkingTurtles/Public/Player",
			"WalkingTurtles/Public/AI",
			"WalkingTurtles/Public/Misc",
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}