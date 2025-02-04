/*
** Odin 2 Synthesizer Plugin
** Copyright (C) 2020 - 2021 TheWaveWarden
**
** Odin 2 is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** Odin 2 is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
*/

#pragma once

#include "GlobalIncludes.h"

#define DEFAULT_TUNING_DIRECTORY                                                                                       \
	(File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory).getFullPathName())
#define DEFAULT_SOUNDBANK_IO_LOCATION_STRING (File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory).getFullPathName())
#define DEFAULT_PATCH_LOCATION_STRING (File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory).getFullPathName())


#define XML_ATTRIBUTE_ODIN_CONFIG ("odin_config")
#define XML_ATTRIBUTE_BIG_GUI ("big_gui")
#define XML_ATTRIBUTE_TUNING_DIR ("tuning_dir")
#define XML_ATTRIBUTE_SOUNDBANK_DIR ("soundbank_dir")
#define XML_ATTRIBUTE_PATCH_DIR ("patch_dir")

/**
 * This class manages the config file. Data is loaded from the file in constructor if possible. Then the individual 
 * attributes can be written and read. After writing, the state must be explicitly saved to file.
 */
class ConfigFileManager {
public:
	ConfigFileManager();
	void saveDataToFile();

	void setOptionBigGUI(bool p_GUI_big);
	bool getOptionBigGUI();
	void setOptionTuningDir(String p_dir);
	String getOptionTuningDir();
	void setOptionSoundbankDir(String p_dir);
	String getOptionSoundbankDir();
	void setOptionPatchDir(String p_dir);
	String getOptionPatchDir();

private:
	void createDirIfNeeded();
	void loadDataFromFile();
	//the actual config values with default values
	bool m_big_gui = true;
	String m_tuning_dir = DEFAULT_TUNING_DIRECTORY;
	String m_soundbank_dir = DEFAULT_SOUNDBANK_IO_LOCATION_STRING;
	String m_patch_dir = DEFAULT_PATCH_LOCATION_STRING;
};
