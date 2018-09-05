#include "json_writer.h"

void JsonWriter::Indent() {

	for (int i = 0, s = initialIndentDepth + depth.size(); i < s; i++) {
		Write() << indent;
	}
}

void JsonWriter::StartContainer(ContainerType type, ContainerLayout layout) {

	if (forceDefaultContainerLayout) {
		layout = defaultContainerLayout;
	}
	else if (layout == CONTAINER_LAYOUT_INHERIT) {
		if (depth.size() > 0) {
			layout = depth.top()->layout;
		}
		else {
			layout = defaultContainerLayout;
		}
	}

	StartChild();
	depth.push( new Container(type, layout) );
	Write() << (type == CONTAINER_TYPE_OBJECT ? '{' : '[' );
}

void JsonWriter::EndContainer() {
	Container *container = depth.top();
	depth.pop();

	if (container->childCount > 0) {
		if (container->layout == CONTAINER_LAYOUT_MULTI_LINE) {
			Write() << std::endl;
			Indent();
		}
		else {
			Write() << containerPadding;
		}
	}

	Write() << (container->type == CONTAINER_TYPE_OBJECT ? '}' : ']');

	delete container;
	container = nullptr;
}

void JsonWriter::StartChild(bool isKey) {
	if (depth.size() == 0) {
		if (initialIndentDepth > 0) {
			Indent();
		}
		return;
	}

	Container *container = depth.top();
	if (container->childCount > 0 && (container->type == CONTAINER_TYPE_ARRAY || (container->type == CONTAINER_TYPE_OBJECT && !container->isKey))) {
		Write() << ",";
		if (container->layout == CONTAINER_LAYOUT_SINGLE_LINE) {
			Write() << containerPadding;
		}
		else {
			Write() << std::endl;
			Indent();
		}
	}
	else if (container->childCount == 0) {
		Write() << containerPadding;
		if (container->layout == CONTAINER_LAYOUT_MULTI_LINE) {
			Write() << std::endl;
			Indent();
		}
	}

	container->isKey = isKey;
	container->childCount ++;
}

void JsonWriter::WriteString(const char *str) {
	Write() << "\"";
	for (int i = 0; str[i] != 0; i++) {
		WriteEscapedChar(str[i]);
	}
	Write() << "\"";
}

void JsonWriter::WriteEscapedChar(char c) {
	switch (c) {
		case '"': {
			Write() << "\\\"";
			break;
		}
		case '\\': {
			Write() << "\\\\";
			break;
		}
		case '\b': {
			Write() << "\\b";
			break;
		}
		case '\f': {
			Write() << "\\f";
			break;
		}
		case '\n': {
			Write() << "\\n";
			break;
		}
		case '\r': {
			Write() << "\\r";
			break;
		}
		case '\t': {
			Write() << "\\t";
			break;
		}
		default: {
			Write() << c;
			break;
		}
	}
}

void JsonWriter::Value(const char *value) {
	StartChild();
	WriteString(value);
}

void JsonWriter::Value(std::string value) {
	StartChild();
	WriteString(value.c_str());
}

void JsonWriter::Value(bool value) {
	StartChild();
	Write() << (value ? "true" : "false");
}

void JsonWriter::Key(const char *key) {
	StartChild(true);
	WriteString(key);
	Write() << keyPaddingLeft << ":" << keyPaddingRight;
}

void JsonWriter::NullValue() {
	StartChild();
	Write() << "null";
}












