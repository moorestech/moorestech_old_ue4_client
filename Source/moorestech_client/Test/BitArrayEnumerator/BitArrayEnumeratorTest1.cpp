#include "moorestech_client/Network/Util/BitArrayEnumerator.h"
#include "moorestech_client/Util/StringSplit.h"

IMPLEMENT_COMPLEX_AUTOMATION_TEST(FBitArrayEnumeratorTest, "moorestech.BitArrayEnumeratorTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void FBitArrayEnumeratorTest::GetTests(TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
{
	OutBeautifiedNames.Add("Test"); OutTestCommands.Add("");
}

bool FBitArrayEnumeratorTest::RunTest(const FString& Parameters)
{
	TArray<uint8> actual;
	actual.Add(5);
	actual.Add(130);
	actual.Add(179);
	actual.Add(94);
	actual.Add(0);
	actual.Add(0);
	actual.Add(32);
	actual.Add(94);
	actual.Add(13);
	actual.Add(72);
	actual.Add(9);
	actual.Add(56);
	actual.Add(106);
	actual.Add(64);
	actual.Add(185);
	actual.Add(64);

	BitArrayEnumerator* bits;
	bits = new BitArrayEnumerator(actual);
	
	TArray<bool> ans;
	ans.Add(bits->MoveNextToByte() == 5);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToBit() == false);
	ans.Add(bits->MoveNextToShort() == 5530);
	ans.Add(bits->MoveNextToByte() == 240);
	ans.Add(bits->MoveNextToBit() == false);
	ans.Add(bits->MoveNextToShort() == 132576);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToBit() == false);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToFloat() == 140513.6513);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToBit() == false);
	ans.Add(bits->MoveNextToShort() == 741);

	for (int i = 0; i < ans.Num(); ++i)
	{
		if(!ans[i])
		{
            UE_LOG(LogTemp, Error, TEXT("Failed at %d"), i);
			return false;
		}
	}
	return true;
}

