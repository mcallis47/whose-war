// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class WhoseWarClientTarget : TargetRules
{
	public WhoseWarClientTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Client;
        bUsesSteam = true;
		ExtraModuleNames.AddRange( new string[] { "WhoseWar" } );
	}
}
