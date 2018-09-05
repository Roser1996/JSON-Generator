/*
	test.cpp
	Simple demo to show how to use the json_writer
*/

#include <iostream>
#include <cmath>
#include "json_writer.h"

using namespace std;

int main() {
	auto writer = new JsonWriter();
	writer->ConfigureCompressOutput();
	writer->StartArray();

	writer->StartShortObject();
	writer->KeyValue("name", "Roser");
	writer->KeyValue("age", 22);
	writer->EndObject();

	writer->StartObject();
	writer->KeyValue("skills", "C++");
	writer->KeyValue("skills", "Python");
	writer->KeyValue("skills", "Swift");
	writer->KeyValue("skills", "objective C");
	writer->KeyValue("website", "www.github.com");

	writer->Key("path");
	writer->StartArray();
	writer->Value("back end");
	writer->Value("algorithm");
	writer->Value("ios");
	writer->Value("linux");
	writer->EndArray();

	writer->Key("short-array");
	writer->StartShortArray();
	writer->Value(1);
	writer->Value((uint64_t)0xabcdef123456);
	writer->Value(M_PI);
	writer->EndArray();

	writer->EndObject();
	writer->Value(false);
	writer->EndArray();

	return 0;
}