#ifndef CUTPLUGIN_H
#define CUTPLUGIN_H

#include "Plugin.h"
#include "Tool.h"
#include "PluginProxy.h"
#include <string>

class CutPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "Cut";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::vector<std::string> counts;
};

#endif
