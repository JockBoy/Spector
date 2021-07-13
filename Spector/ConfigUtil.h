#pragma once
#include "Config.h"

using namespace System::IO;
using namespace System::Xml::Serialization;
using namespace System::Runtime::InteropServices;

ref class ConfigUtil {
	private: System::String^ configFile;
	public: ConfigUtil(System::String^ filename) {
		auto dir = Directory::GetCurrentDirectory();
		this->configFile = dir + "\\" + filename;
	}

	public: Config^ Load(void) {
		Config^ ret = gcnew Config;
		bool isDone = false;
		FileInfo^ fileinfo = gcnew FileInfo(this->configFile);
		XmlSerializer^ serializer = nullptr;
		FileStream^ filestream = nullptr;
		try {
			if (fileinfo->Exists == true)
			{
				serializer = gcnew XmlSerializer(Config::typeid);
				filestream = fileinfo->OpenRead();
				ret = (Config^)serializer->Deserialize(filestream);
				isDone = true;
			}
		}
		catch (Exception^ ex) {}
		finally {
			if (filestream != nullptr) filestream->Close();
			ret->isLoadError = !isDone;
		}
		return ret;
	}

	public: bool Save(Config^ conf) {
		bool isDone = false;
		XmlSerializer^ serializer = nullptr;
		StreamWriter^ writer = nullptr;
		try {
			serializer = gcnew XmlSerializer(Config::typeid);
			writer = gcnew StreamWriter(this->configFile, false);
			serializer->Serialize(writer, conf);
			isDone = true;
		}
		catch (Exception^ ex) {}
		finally {
			if (writer != nullptr) writer->Close();
		}

		return isDone;
	}

};