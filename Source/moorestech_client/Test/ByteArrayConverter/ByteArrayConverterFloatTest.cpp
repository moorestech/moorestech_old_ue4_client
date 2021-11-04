#include "moorestech_client/Network/Util/ByteArrayConverter.h"
#include "moorestech_client/Util/StringSplit.h"
IMPLEMENT_COMPLEX_AUTOMATION_TEST(FByteArrayConverterFloatTest, "moorestech.ByteArrayConverterFloatTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void FByteArrayConverterFloatTest::GetTests(TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
{
	//フォーマット　答え,byte値1,byte値2,byte値3....
	OutBeautifiedNames.Add("Test_0"); OutTestCommands.Add("0,0,0,0,0");
	OutBeautifiedNames.Add("Test_5"); OutTestCommands.Add("5,64,160,0,0");
	OutBeautifiedNames.Add("Test_500"); OutTestCommands.Add("500,67,250,0,0");
	OutBeautifiedNames.Add("Test_35'19"); OutTestCommands.Add("35.19,66,12,194,143");
	OutBeautifiedNames.Add("Test_510231'56781"); OutTestCommands.Add("510231.56781,72,249,34,242");
}

bool FByteArrayConverterFloatTest::RunTest(const FString& Parameters)
{
	TArray<FString> Strings;
	Strings = StringSplit::split(Parameters,',');
	TArray<uint8> actual;
	actual = ByteArrayConverter::ToByteArray(FCString::Atof(*Strings[0]));
	
	TArray<uint8> expected;
	expected.Add((uint8)FCString::Atoi(*Strings[1]));
	expected.Add((uint8)FCString::Atoi(*Strings[2]));
	expected.Add((uint8)FCString::Atoi(*Strings[3]));
	expected.Add((uint8)FCString::Atoi(*Strings[4]));

	int ansCnt = 0;
	for (int i = 0;i < 4 ; i++)
	{
		UE_LOG(LogTemp, Log, TEXT("actual %d"), actual[i]);
		UE_LOG(LogTemp, Log, TEXT("expected %d"), expected[i]);
		if(actual[i] == expected[i])
		{
			ansCnt++;
		}
	}
	
	return ansCnt == 4;
}
