// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerScoreSorter.h"

using namespace std;

#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x));}

UPlayerScoreSorter::UPlayerScoreSorter()
{
    scoreInfo = TArray<FPlayerScoreInfo>();
}

UPlayerScoreSorter::~UPlayerScoreSorter()
{
    //delete(scoreInfo);
}
/**
 * When a player's score changes, update the sorted scores list
 **/
void UPlayerScoreSorter::UpdateScores(FString playerName, int score) {
    int playerIndex = GetPlayerIndex(playerName);
    //If player wasn't found, add the player and run again
    if (playerIndex < 0) {
        AddPlayer(playerName);
        UpdateScores(playerName, score);
        return;
    }
    int direction = scoreInfo[playerIndex].score > score ? 1 : -1;
    scoreInfo[playerIndex].score = score;
    int swapIndex = playerIndex;
    //after changing the player's score, find their new index to keep scores sorted
    while(swapIndex > 0 && scoreInfo[swapIndex-1].score < scoreInfo[swapIndex].score) {
		//swap the player with their new index
		FPlayerScoreInfo temp = scoreInfo[swapIndex];
		scoreInfo[swapIndex] = scoreInfo[swapIndex-1];
		scoreInfo[swapIndex-1] = temp;
		swapIndex--;
    }
}

TArray<FPlayerScoreInfo> UPlayerScoreSorter::GetPlayerScores() {
    return scoreInfo;
}

void UPlayerScoreSorter::AddPlayer(FString playerName) {
    if (GetPlayerIndex(playerName) >= 0) {
        return;
    }
    D("Adding " + playerName + " to scores list");
    scoreInfo.Add({playerName, 0});
}

int UPlayerScoreSorter::GetPlayerIndex(FString playerName) {
    for (int i = 0; i < scoreInfo.Num(); i++) {
        if (scoreInfo[i].playerName.Equals(playerName)) {
            return i;
        }
    }
    return -1;
}



