// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class WhoseWarServerTarget : TargetRules
{
	public WhoseWarServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
        bUsesSteam = true;
		ExtraModuleNames.AddRange( new string[] { "WhoseWar" } );
	}
}
