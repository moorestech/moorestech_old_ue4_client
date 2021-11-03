#include "StringSplit.h"
#include "iostream"
#include "string"
#include "vector"

TArray<FString> StringSplit::split(FString str, char del) {
	TArray<FString> result;
	std::string subStr;
 
	for (const char c : str) {
		if (c == del) {
			result.Add(subStr.c_str());
			subStr.clear();
		}else {
			subStr += c;
		}
	}
 
	result.Add(subStr.c_str());
	return result;
}