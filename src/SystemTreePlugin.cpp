#include "SystemTreePlugin.h"
#include "PluginServices.h"

void SystemTreePlugin::version(int& major, int& minor, int& bugfix) const
{
    major = 1;
    minor = 0;
    bugfix = 0;
}

QString SystemTreePlugin::name() const
{
    return "SystemTreePlugin";
}

QString SystemTreePlugin::getHelpText() const
{
    return "This plugin visualizes system tree data in json.";
}

SystemTreePlugin::SystemTreePlugin()
{
    treeWidget = new QTreeWidget();
    treeWidget->setHeaderLabel("System Tree");
}

SystemTreePlugin::~SystemTreePlugin()
{
    delete treeWidget;
}

bool SystemTreePlugin::cubeOpened(cubepluginapi::PluginServices* service)
{
    service->addTab(cubepluginapi::SYSTEM, this);
}

void SystemTreePlugin::cubeClosed()
{
    treeWidget->clear();
}
