#include "moorestech_client/Network/Util/ByteArrayConverter.h"
#include "moorestech_client/Util/StringSplit.h"
IMPLEMENT_COMPLEX_AUTOMATION_TEST(FMyComplexTest, "moorestech.ByteArrayConverterStringTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void FMyComplexTest::GetTests(TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
{
	//フォーマット　答え,バイト数,byte値1,byte値2,byte値3....
	OutBeautifiedNames.Add("Test_abv-"); OutTestCommands.Add("abv-,4,97,98,118,43");
	OutBeautifiedNames.Add("Test_あ０"); OutTestCommands.Add("あ０,5,227,129,239,188,144");
	OutBeautifiedNames.Add("Test_(["); OutTestCommands.Add("([,2,40,91");
}

bool FMyComplexTest::RunTest(const FString& Parameters)
{
	TArray<FString> Strings;
	Strings = StringSplit::split(Parameters,',');
	TArray<uint8> actual;
	actual = ByteArrayConverter::ToByteArray(Strings[0]);
	
	TArray<uint8> expected;
	int cnt = FCString::Atoi(*Strings[1]);
	for (int i = 0;i<cnt;i++)
	{
		expected.Add(FCString::Atoi(*Strings[i+2]));
	}
	
	int ansCnt = 0;
	for (int i = 0;i < cnt ; i++)
	{
		UE_LOG(LogTemp, Log, TEXT("actual %d"), actual[i]);
		UE_LOG(LogTemp, Log, TEXT("expected %d"), expected[i]);
		if(actual[i] == expected[i])
		{
			ansCnt++;
		}
	}
	
	return ansCnt == 2;
}
