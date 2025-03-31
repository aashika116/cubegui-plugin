#include "SystemTreePlugin.h"
#include "PluginServices.h"
#include <QMessageBox>

// Sets the version of the plugin
void SystemTreePlugin::version(int& major, int& minor, int& bugfix) const
{
    major = 1;
    minor = 0;
    bugfix = 0;
}

// Returns the name of the plugin
QString SystemTreePlugin::name() const
{
    return "SystemTreePlugin";
}

// Provides a brief description of the plugin's functionality
QString SystemTreePlugin::getHelpText() const
{
    return "This plugin visualizes system tree data in json.";
}

// Constructor: Initializes the tree widget
SystemTreePlugin::SystemTreePlugin()
{
    treeWidget = new QTreeWidget();
    treeWidget->setHeaderLabel("System Tree");

    // Set json file path
    QString rootDir = QDir(QCoreApplication::applicationDirPath()).filePath("..");
    jsonFilePath = rootDir + "data/dummy_test.json";
}

// Destructor: Cleans up allocated resources
SystemTreePlugin::~SystemTreePlugin()
{
    delete treeWidget;
}

// Called when a cube file is opened; sets up the plugin's tab and loads example JSON data
bool SystemTreePlugin::cubeOpened(cubepluginapi::PluginServices* service)
{
    // Add the plugin's tab to the system view
    service->addTab(cubepluginapi::SYSTEM, this);

    QString jsonContent = readCustomJson();
    if (!jsonContent.isEmpty()) {
        loadJson(jsonContent);
    }

    return true;
}

// Called when a cube file is closed; clears the tree widget
void SystemTreePlugin::cubeClosed()
{
    treeWidget->clear();
}

// Reads JSON content from the file
QString SystemTreePlugin::readCustomJson()
{
    QFile file(jsonFilePath);
    if (!file.exists()) {
        QMessageBox::warning(nullptr, "Error", "The JSON file does not exist: " + jsonFilePath);
        return QString();
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open the JSON file: " + jsonFilePath);
        return QString();
    }

    QString jsonStr = file.readAll();
    file.close();
    return jsonStr;
}

// Parses and loads JSON data into the tree widget
void SystemTreePlugin::loadJson(const QString& jsonStr)
{
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8(), &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        QMessageBox::warning(nullptr, "Error", "Failed to parse JSON: " + parseError.errorString());
        return;
    }

    if (!jsonDoc.isObject()) {
        QMessageBox::warning(nullptr, "Error", "The JSON root is not an object.");
        return;
    }

    treeWidget->clear();
    parseJson(jsonDoc.object(), nullptr);
}

// Recursively parses a JSON object and populates the tree widget
void SystemTreePlugin::parseJson(const QJsonObject& jsonObject, QTreeWidgetItem* parentItem)
{
    for (const QString& key : jsonObject.keys()) {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, key);

        // Add the item to the parent or as a top-level item
        if (parentItem) {
            parentItem->addChild(item);
        } else {
            treeWidget->addTopLevelItem(item);
        }

        // Nested Object handling
        if (jsonObject[key].isObject()) {
            parseJson(jsonObject[key].toObject(), item);
        }

        // Array handling
        else if (jsonObject[key].isArray()) {
            QJsonArray array = jsonObject[key].toArray();
            for (int i = 0; i < array.size(); ++i) {
                QTreeWidgetItem* arrayItem = new QTreeWidgetItem();
                arrayItem->setText(0, QString("[%1]").arg(i));
                item->addChild(arrayItem);

                if (array[i].isObject()) {
                    parseJson(array[i].toObject(), arrayItem);
                } else {
                    arrayItem->setText(1, array[i].toVariant().toString());
                }
            }
        }

        // Primitive value handling
        else {
            item->setText(1, jsonObject[key].toVariant().toString());
        }
    }
}
