#include "CoreMinimal.h"
#include "PlayerScoreInfo.generated.h"

USTRUCT(BlueprintType)
struct FPlayerScoreInfo {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Score Info")
    FString playerName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Score Info")
    int score;
};