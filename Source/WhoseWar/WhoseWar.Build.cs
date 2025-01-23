// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class WhoseWar : ModuleRules
{
	public WhoseWar(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "OnlineSubsystem", "OnlineSubsystemUtils", "MoviePlayer" });

        PrivateDependencyModuleNames.AddRange(new string[] { "OnlineSubsystem" });


        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
    }
}
