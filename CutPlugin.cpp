#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "CutPlugin.h"



void CutPlugin::input(std::string file) {
 inputfile = file;
readParameterFile(file);
std::ifstream countfile(std::string(PluginManager::prefix())+"/"+myParameters["counts"], std::ios::in);

std::string count;
while (!countfile.eof()) {
   countfile >> count;
   counts.push_back(count);
}

}

void CutPlugin::run() {}

void CutPlugin::output(std::string file) {
 std::string outputfile = file;
myCommand += "cut";
myCommand += " -f";
for (int i = 0; i < counts.size(); i++) {
    myCommand += counts[i];
    if (i != counts.size()-1)
	    myCommand += ",";
    else
	    myCommand += " ";
}
myCommand += std::string(PluginManager::prefix())+"/"+myParameters["txtfile"];
myCommand += " > ";
myCommand += outputfile;
 system(myCommand.c_str());
}

PluginProxy<CutPlugin> CutPluginProxy = PluginProxy<CutPlugin>("Cut", PluginManager::getInstance());
