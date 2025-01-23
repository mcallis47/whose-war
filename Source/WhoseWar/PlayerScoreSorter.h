// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerScoreInfo.h"
#include <vector>
#include <string>
#include "PlayerScoreSorter.generated.h"

/**
 * 
 */
using namespace std;
UCLASS(BlueprintType)
class WHOSEWAR_API UPlayerScoreSorter : public UObject
{
	GENERATED_BODY()
//private:
	TArray<FPlayerScoreInfo> scoreInfo;
//public:
	UPlayerScoreSorter();
	~UPlayerScoreSorter();

	UFUNCTION(BlueprintCallable, Category="Scoring")
	void UpdateScores(FString playerName, int score);

	UFUNCTION(BlueprintCallable, Category="Scoring")
	TArray<FPlayerScoreInfo> GetPlayerScores();

	UFUNCTION(BlueprintCallable, Category="Scoring")
	void AddPlayer(FString playerName);

	int GetPlayerIndex(FString playerName);

};


