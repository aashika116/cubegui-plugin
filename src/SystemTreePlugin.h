#ifndef SYSTEMTREEPLUGIN_H
#define SYSTEMTREEPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QWidget>
#include <QTreeWidget>

#include "PluginServices.h"
#include "CubePlugin.h"
#include "TabInterface.h"

class SystemTreePlugin : public QObject, public cubepluginapi::CubePlugin, public cubepluginapi::TabInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "SystemTreePlugin")
    Q_INTERFACES( cubepluginapi::CubePlugin )

public:
    explicit SystemTreePlugin();
    ~SystemTreePlugin();
    bool cubeOpened( cubepluginapi::PluginServices* service ) override;
    void cubeClosed() override;
    void version(int& major, int& minor, int& bugfix) const override;
    QString name() const override;
    QString getHelpText() const override;

    QWidget* widget() override { return treeWidget; }
    QString label() const override { return "System Tree"; }

    void loadJson(const QString& jsonStr);

private:
    QTreeWidget* treeWidget;
    QString jsonFilePath;

    QString readCustomJson();
    void parseJson(const QJsonObject& jsonObject, QTreeWidgetItem* parentItem);
};

#endif
