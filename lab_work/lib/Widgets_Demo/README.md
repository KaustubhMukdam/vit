# Flutter Widgets & Project Structure

## What Lab Assignments It Covers
- **Lab-2:** Flutter Project Structure & Widgets
  - Exploring project folders and key files (`pubspec.yaml`, `main.dart`)
  - Understanding Stateless and Stateful widgets
  - Building a basic UI with common widgets (Text, Container, Row, Column)

## What Files Are Inside
- `main.dart`: A comprehensive Flutter app demonstrating core widgets and their usage patterns.

## Topics Covered (Detailed Breakdown)
This project introduces the fundamental Flutter widgets used in most applications.

* **Project Structure Understanding:**
  - `pubspec.yaml`: Contains project metadata and dependencies (though not explicitly shown, it's the core config file)
  - `main.dart`: The entry point containing all the app logic and UI

* **StatelessWidget:**
  - **`MyApp`**: A `StatelessWidget` that sets up the MaterialApp with theme configuration and launches the main content page.
  - **`WidgetsDemoPage`**: A `StatelessWidget` that demonstrates various widgets without internal state changes.

* **Key Widgets Demonstrated:**
  - **Text Widget:** Basic text display with styling (fontSize, fontWeight, color)
  - **Container Widget:** A box model widget for layout and styling (padding, color, border, borderRadius)
  - **Row Widget:** Horizontal layout widget with children arranged left to right (mainAxisAlignment: spaceEvenly)
  - **Column Widget:** Vertical layout widget with children arranged top to bottom (crossAxisAlignment: stretch)
  - **SizedBox Widget:** A widget with fixed dimensions used for spacing and sizing other widgets
  - **ListView Widget:** A scrollable list of widgets, preventing overflow on smaller screens

* **Layout Principles:**
  - MainAxisAlignment: Controls alignment along the primary direction (horizontal for Row, vertical for Column)
  - CrossAxisAlignment: Controls alignment perpendicular to the primary direction
  - Padding & Margin: Used through Container and SizedBox for spacing

* **Styling & Theming:**
  - Uses `ThemeData` with `colorScheme` to define app colors
  - Custom widget styling with `BoxDecoration`, `BorderRadius`, and direct style properties

## How to Run in Android Studio
1. Open Android Studio and connect your phone/emulator.
2. Click on the Run Configurations dropdown and select **Edit Configurations...**.
3. Click the `+` button and select **Flutter**.
4. Set the **Dart entrypoint** to `lib/Widgets_Demo/main.dart`.
5. Name this configuration "Widgets Demo" and click **OK**.
6. Select this configuration and click the green Play button to run the app.

## Learning Outcomes
After completing this lab, you should understand:
- The basic project structure of a Flutter app
- The difference between layout and display widgets
- How to use Text, Container, Row, Column, and SizedBox
- How to create responsive layouts using these widgets
- Basic styling and theming in Flutter
