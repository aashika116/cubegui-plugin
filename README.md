# JSON Tree CubeGUI Plugin
A plugin for CubeGUI that visualizes system tree data in JSON format.

## Build Instructions
To build the plugin, make sure you have **Qt 5.15.18** installed, as cubegui-4.8.2 is not compatible with Qt 6.

To build the plugin, simply run the `build.sh` script located in the project directory:
```bash
bash ./build.sh
```

## How it works
The SystemTreePlugin provides functionality to load and display JSON data in a tree structure within the CubeGUI application. Key features:

1. **Plugin Initialization**:
    - The plugin sets up a QTreeWidget to display the system tree.
    - It reads a JSON file (dummy_test.json) located in the data directory.

2. **JSON Parsing**:
    - The plugin reads the JSON file and parses its content using QJsonDocument.
    - It recursively processes JSON objects and arrays to populate the tree widget.

3. **Integration with CubeGUI**:
    - The plugin adds a tab to the CubeGUI interface when a cube file is opened.
    - It clears the tree widget when a cube file is closed.

## Caveats
- The code has not been thoroughly tested, so the plugin may contain bugs.
- The custom plugin feature in CubeGUI was not fully understood, which prevented proper testing of the plugin's functionality within the application.

*Note: The plugin is compilable, but may not be fully functional.* 

## Future Enhancements
- Better testing to identify and fix existing bugs.
- Improve integration with CubeGUI's custom plugin feature.
- Add more visualization options to enhance user experience.
- Add feature to load json with a file rather than pasting a json at build time.
