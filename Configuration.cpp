 
//Configuration.cpp
#include "Configuration.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;


Configuration::Configuration() { 
	
}


/* Trim values */
string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void Configuration::Init() {

    // emulator config (to define the theme first)
    string configEmulatorfile = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/emulator.cfg";
    ifstream cFileEmu (configEmulatorfile);
    if (cFileEmu.is_open())
    {
        string line;
        while(getline(cFileEmu, line)){
            if(line[0] == '#' || line.empty()) continue;
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);

            AddConfigVariable(name, trim(value));
        }
        
    }
    else {
        std::cerr << "Couldn't open config file for reading - " << configEmulatorfile << "\n";
    }       

	// basic config
    string configBasicfile = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/basic.cfg";
    ifstream cFileBasic (configBasicfile);
    if (cFileBasic.is_open())
    {
        string line;
        while(getline(cFileBasic, line)){
            if(line[0] == '#' || line.empty()) continue;
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            AddConfigVariable(name, trim(value));
        }
        
    }
    else {
        std::cerr << "Couldn't open config file for reading - " << configBasicfile << "\n";
    }

    // advance config
    string configAdvancefile = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + "/config/advance.cfg";
    ifstream cFileAdv (configAdvancefile);
    if (cFileAdv.is_open())
    {
        string line;
        while(getline(cFileAdv, line)){
            if(line[0] == '#' || line.empty()) continue;
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);

            AddConfigVariable(name, trim(value));
        }
        
    }
    else {
        std::cerr << "Couldn't open config file for reading - " << configAdvancefile << "\n";
    }  


}




void Configuration::AddConfigVariable(auto name, auto value) {

    if(name == "theme") {
        _cfg.theme = value;
    }

    /* Paths */
    if(name == "emulatorPath"){
        _cfg.emulatorPath = value;
    }
    if(name == "emulatorExec"){
        _cfg.emulatorExec = value;
    }
    if(name == "emulatorParams"){
        _cfg.emulatorParams = value;
    }
    if(name == "emulatorExtensions"){
        _cfg.emulatorExtensions = value;
    }

    if(name == "romPath"){
        _cfg.romPath = value;   
    }
    if(name == "boxartPath"){
        _cfg.boxartPath = value;
    }
    if(name == "screenshotsPath"){
        _cfg.screenshotsPath = value;
    }
    if(name == "favSave"){
        _cfg.favSave = value;
    }


    /* Logging */  
    if(name == "logging"){
        _cfg.logging = atof(value.c_str());
    }
    if(name == "switchToEmu"){
        _cfg.switchToEmu = atof(value.c_str());
    }    

    /* Images */
    //Console
    if(name == "imgConsoleBackground"){
        _cfg.imgConsoleBackground = value;
    }
    if(name == "imgConsoleBar"){
        _cfg.imgConsoleBar = value;
    }
    if(name == "imgConsolePanel"){
        _cfg.imgConsolePanel = value;
    }             


    //Emulator
    if(name == "imgBackground"){
        _cfg.imgBackground = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgDefaultBoxart"){
        _cfg.imgDefaultBoxart = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }         
    if(name == "imgShadow"){
        _cfg.imgShadow = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgBookIcon"){
        _cfg.imgBookIcon = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgGameIcon"){
        _cfg.imgGameIcon = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgConsoleIcon"){
        _cfg.imgConsoleIcon = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgFavOff"){
        _cfg.imgFavOff = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgFavOn"){
        _cfg.imgFavOn = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonY"){
        _cfg.imgUrlButtonY = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonX"){
        _cfg.imgUrlButtonX = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonB"){
        _cfg.imgUrlButtonB = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonA"){
        _cfg.imgUrlButtonA = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonL"){
        _cfg.imgUrlButtonL = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonR"){
        _cfg.imgUrlButtonR = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonStart"){
        _cfg.imgUrlButtonStart = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonSelect"){
        _cfg.imgUrlButtonSelect = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonHome"){
        _cfg.imgUrlButtonHome = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonUp"){
       _cfg.imgUrlButtonUp = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonDown"){
        _cfg.imgUrlButtonDown = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonLeft"){
        _cfg.imgUrlButtonLeft = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonRight"){
        _cfg.imgUrlButtonRight = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "imgUrlButtonAll"){
        _cfg.imgUrlButtonAll = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }

    /* Fonts */
    //Console
    if(name == "fontConsole"){
        _cfg.fontConsole = value;
    }            

    //Emulator
    if(name == "fontCharacter"){
        _cfg.fontCharacter = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "fontGameList"){
        _cfg.fontGameList = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "fontFilename"){
        _cfg.fontFilename = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }
    if(name == "fontConsolename"){
        _cfg.fontConsolename = "/home/retrofw/apps/coverflow/themes/" + _cfg.emulatorType + "/" + _cfg.theme + value;
    }      

    /* Configuration */
    //# boxart settings
    if(name == "boxartZoomStrX"){
        _cfg.boxartZoomStrX = atof(value.c_str());
    }
    if(name == "boxartZoomStrY"){
        _cfg.boxartZoomStrY = atof(value.c_str());
    }      
    if(name == "boxartZoomStrSmallX"){
        _cfg.boxartZoomStrSmallX = atof(value.c_str());
    }  
    if(name == "boxartZoomStrSmallY"){
        _cfg.boxartZoomStrSmallY = atof(value.c_str());
    }
    if(name == "bortartOffsetY"){
        _cfg.bortartOffsetY = atof(value.c_str());
    }
    if(name == "bortartOffsetSmallY"){
        _cfg.bortartOffsetSmallY = atof(value.c_str());
    }      
    if(name == "bortartFilenamePosY"){
        _cfg.bortartFilenamePosY = atof(value.c_str());
    }  
    if(name == "boxartDistance"){
        _cfg.boxartDistance = atof(value.c_str());
    }

    //# screenshot settings
    if(name == "screenZoomStrX"){
        _cfg.screenZoomStrX = atof(value.c_str());
    }
    if(name == "screenZoomStrY"){
        _cfg.screenZoomStrY = atof(value.c_str());
    }      
    if(name == "screenZoomStrSmallX"){
        _cfg.screenZoomStrSmallX = atof(value.c_str());
    }  
    if(name == "screenZoomStrSmallY"){
        _cfg.screenZoomStrSmallY = atof(value.c_str());
    }
    if(name == "screenFilenamePosY"){
        _cfg.screenFilenamePosY = atof(value.c_str());
    }
    if(name == "screenOffsetY"){
        _cfg.screenOffsetY = atof(value.c_str());
    }      
    if(name == "screenOffsetSmallY"){
        _cfg.screenOffsetSmallY = atof(value.c_str());
    }  
    if(name == "screenDistance"){
        _cfg.screenDistance = atof(value.c_str());
    }
}
