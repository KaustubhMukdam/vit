# Hello World - Introduction to Flutter & Dart

## What Lab Assignments It Covers
- **Lab-1:** Introduction to Flutter & Dart
  - Setting up Flutter SDK and IDE (Android Studio / VS Code)
  - Running the first Flutter app: "Hello World"
  - Basic Dart syntax: variables, functions, control structures

## What Files Are Inside
- `main.dart`: A simple Flutter app that displays "Hello World" on the screen with basic app structure setup.

## Topics Covered (Detailed Breakdown)
This is the introductory Flutter project that teaches the fundamentals of Flutter app development.

* **Entry Point (`main()` function):**
  - The `main()` function is the starting point of every Dart/Flutter application. It calls `runApp()` which initializes the entire application.

* **StatelessWidget:**
  - **`MyApp`**: A `StatelessWidget` that sets up the MaterialApp with basic properties like `title`, `theme`, and `home` page.
  - **`HelloWorldPage`**: A `StatelessWidget` that builds the UI displaying "Hello World" text centered on the screen.

* **Basic Structure:**
  - **Scaffold:** Provides the visual structure (AppBar, body) for a Material Design app.
  - **AppBar:** The top bar displaying the app title.
  - **Center:** A layout widget that centers child widgets both horizontally and vertically.
  - **Text:** A basic widget to display text with styling options (fontSize, fontWeight, color).

* **Theme & Styling:**
  - Uses `ThemeData` with `colorScheme` to define the app's visual appearance.
  - Text styling with properties like `fontSize`, `fontWeight`, and `color`.

## How to Run in Android Studio
1. Open Android Studio and ensure your device/emulator is connected.
2. Click on the Run Configurations dropdown at the top and select **Edit Configurations...**.
3. Click the `+` button and select **Flutter**.
4. Set the **Dart entrypoint** to `lib/Hello_World/main.dart`.
5. Name this configuration "Hello World" and click **OK**.
6. Select this configuration and click the green Play button to run the app.

## Learning Outcomes
After completing this lab, you should understand:
- How to set up and create a Flutter project
- The basic structure of a Flutter application
- How to run a Flutter app on an emulator or physical device
- Basic Dart syntax and Flutter widgets
