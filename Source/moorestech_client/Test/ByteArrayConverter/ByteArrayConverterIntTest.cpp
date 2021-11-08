#include "moorestech_client/Network/Util/ByteArrayConverter.h"
#include "moorestech_client/Util/StringSplit.h"
IMPLEMENT_COMPLEX_AUTOMATION_TEST(FByteArrayConverterIntTest, "moorestech.ByteArrayConverterIntTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

void FByteArrayConverterIntTest::GetTests(TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const
{
	//フォーマット　答え,byte値1,byte値2,byte値3....
	OutBeautifiedNames.Add("Test_0"); OutTestCommands.Add("0,0,0,0,0");
	OutBeautifiedNames.Add("Test_5"); OutTestCommands.Add("5,0,0,0,5");
	OutBeautifiedNames.Add("Test_500"); OutTestCommands.Add("500,0,0,1,244");
	OutBeautifiedNames.Add("Test_1546"); OutTestCommands.Add("1546,0,0,6,10");
}

bool FByteArrayConverterIntTest::RunTest(const FString& Parameters)
{
	TArray<FString> Strings;
	Strings = StringSplit::split(Parameters,',');
	TArray<uint8> actual;
	actual = ByteArrayConverter::ToByteArray(FCString::Atoi(*Strings[0]));
	
	TArray<uint8> expected;
	expected.Add((uint8)FCString::Atoi(*Strings[1]));
	expected.Add((uint8)FCString::Atoi(*Strings[2]));
	expected.Add((uint8)FCString::Atoi(*Strings[3]));
	expected.Add((uint8)FCString::Atoi(*Strings[4]));

	int ansCnt = 0;
	for (int i = 0;i < 4 ; i++)
	{
		if(actual[i] == expected[i])
		{
			ansCnt++;
		}
	}
	
	return ansCnt == 4;
}
