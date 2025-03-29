#include "SystemTreePlugin.h"
#include <PluginServices.h>

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
