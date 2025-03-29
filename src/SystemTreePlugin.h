#ifndef SYSTEMTREEPLUGIN_H
#define SYSTEMTREEPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QWidget>
#include <QTreeWidget>
#include <CubePlugin.h>
#include <PluginInterface.h>

class SystemTreePlugin : public QObject, public cubepluginapi::CubePlugin, public cubegui::TabInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "SystemTreePlugin")
    Q_INTERFACES(CubePlugin)

public:
    explicit SystemTreePlugin();
    ~SystemTreePlugin();
    bool cubeOpened( cubepluginapi::PluginServices* service ) override;
    void cubeClosed() override;

private:
    QTreeWidget* treeWidget;
};

#endif
