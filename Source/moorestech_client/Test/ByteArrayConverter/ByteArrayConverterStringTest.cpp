#include "moorestech_client/Network/Util/ByteArrayConverter.h"
#include "moorestech_client/Util/StringSplit.h"
IMPLEMENT_COMPLEX_AUTOMATION_TEST(FByteArrayConverterStringTest, "moorestech.ByteArrayConverterStringTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void FByteArrayConverterStringTest::GetTests(TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
{
	//フォーマット　答え,バイト数,byte値1,byte値2,byte値3....
	OutBeautifiedNames.Add("Test_a"); OutTestCommands.Add("a,1,97");
	OutBeautifiedNames.Add("Test_abv-"); OutTestCommands.Add("abv-,4,97,98,118,45");
	OutBeautifiedNames.Add("Test_(["); OutTestCommands.Add("([,2,40,91");
}

bool FByteArrayConverterStringTest::RunTest(const FString& Parameters)
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
	
	return ansCnt == cnt;
}
