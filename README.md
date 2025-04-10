# ParseToJSON CubeGUI Plugin
A plugin for CubeGUI that visualizes system tree data in JSON format.

## Build Instructions
To build the plugin, make sure you have **Qt 5.15.18** installed, as cubegui-4.8.2 is not compatible with Qt 6.

To build the plugin, simply run the `build.sh` script located in the project directory:
```bash
bash ./build.sh
```

## How it works
The `ParseToJSONPlugin` provides functionality to parse and display system tree data from `.cubex` files in JSON format within the CubeGUI application. Key features:

1. **Plugin Initialization**:
    - The plugin sets up a `QPlainTextEdit` widget to display the indented JSON data.
    - It initializes the widget with a fixed-width font and disables word wrapping for better readability.

2. **System Tree Parsing**:
    - When a `.cubex` file is opened, the plugin reads the file and parses the system tree using the Cube library.
    - It recursively traverses the `SystemTreeNode` structure, extracting properties (e.g., name, ID, description, class), child nodes, and location groups.
    - The parsed data is converted into a structured JSON format using `QJsonObject` and `QJsonArray`.

3. **Integration with CubeGUI**:
    - The plugin adds a tab to the CubeGUI interface when a `.cubex` file is opened.
    - It displays the JSON representation of the system tree in the `QPlainTextEdit` widget.
    - When the file is closed, the displayed JSON is cleared.

## Future Enhancements
- Better testing to identify and fix existing bugs. Plugin works with all the tested `.cubex` files, however this testing was not comprehensive.
- Add more visualization options to enhance user experience.
- Add features to download, collapse, expand and sort the json.
