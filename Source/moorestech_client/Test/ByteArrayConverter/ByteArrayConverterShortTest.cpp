#include "moorestech_client/Network/Util/ByteArrayConverter.h"
#include "moorestech_client/Util/StringSplit.h"
IMPLEMENT_COMPLEX_AUTOMATION_TEST(FMyComplexTest, "moorestech.ByteArrayConverterShortTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void FMyComplexTest::GetTests(TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
{
	//フォーマット　答え,byte値1,byte値2,byte値3....
	OutBeautifiedNames.Add("Test_0"); OutTestCommands.Add("0,0,0");
	OutBeautifiedNames.Add("Test_5"); OutTestCommands.Add("5,0,5");
	OutBeautifiedNames.Add("Test_500"); OutTestCommands.Add("500,1,244");
	OutBeautifiedNames.Add("Test_1546"); OutTestCommands.Add("1546,6,10");
}

bool FMyComplexTest::RunTest(const FString& Parameters)
{
	TArray<FString> Strings;
	Strings = StringSplit::split(Parameters,',');
	TArray<uint8> actual;
	actual = ByteArrayConverter::ToByteArray((int16)FCString::Atoi(*Strings[0]));
	
	TArray<uint8> expected;
	expected.Add((uint8)FCString::Atoi(*Strings[1]));
	expected.Add((uint8)FCString::Atoi(*Strings[2]));

	int ansCnt = 0;
	for (int i = 0;i < 2 ; i++)
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
