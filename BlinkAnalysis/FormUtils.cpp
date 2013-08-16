#include "stdafx.h"

#include "FormUtils.h"

namespace FormUtils
{
	int worldExtractID(System::String^ str) {
		array<System::String^>^ split = str->Split(gcnew array<wchar_t> {'(', ')'});

		int result;
		// id contained in second to last element
		if (System::Int32::TryParse(split[split->Length - 2], result))
			return result;
		else
			return -1;
	}

	const char* managedStringToChar(System::String^ str) {
		return (const char*) (System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str)).ToPointer();
	}

	System::String^ setPoint(osg::Vec3* pos) {
		System::String^ str = System::Convert::ToString(pos->x());
		str += ", ";
		str += System::Convert::ToString(pos->y());
		str += ", ";
		str += System::Convert::ToString(pos->z());
		return str;
	}

	bool isFloat(System::String^ str) {
		System::String^ regs = "^\\s*-?\\d+(.\\d+)?\\s*$";
		System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(regs);
		return regex->IsMatch(str);
	}

	bool isPositiveFloat(System::String^ str) {
		System::String^ regs = "^\\s*\\d+(.\\d+)?\\s*$";
		System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(regs);
		return regex->IsMatch(str);
	}

	bool isPositiveNumber(System::String^ str) {
		System::String^ regs = "^\\s*\\d+\\s*$";
		System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(regs);
		return regex->IsMatch(str);
	}
};
