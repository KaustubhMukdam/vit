# Counter App

## What Lab Assignments It Covers
- **Lab-1:** Setup and Flutter Hello World program
- **Lab-2:** Project structure
- **Lab-6:** Counter app

## What Files Are Inside
- `main.dart`: The main entry point of the Flutter application.

## Topics Covered (Detailed Breakdown)
This project introduces the very basics of Flutter and how the user interface is built using a tree of widgets.

* **StatelessWidget:** Used for UI that does not change on its own.
  - In `main.dart`, the **`MyApp`** class is a `StatelessWidget`. Its only job is to return the initial `MaterialApp` widget, set up the purple theme, and point to the Home Page. Since this setup doesn't change while you use the app, it remains "stateless".
* **StatefulWidget:** Used for UI that needs to update and redraw dynamically.
  - In `main.dart`, the **`MyHomePage`** class is a `StatefulWidget`. This is because the screen needs to update every time you press the button.
  - Attached to it is the **`_MyHomePageState`** class, which holds an integer variable called `_counter`.
  - When you click the floating increment or decrement buttons, the code calls `setState()`. This tells Flutter to redraw the `MyHomePage` widget to show the new `_counter` number on the screen.

## How to Run in Android Studio
1. Open Android Studio and ensure your phone is connected.
2. In the top toolbar, click on the run configuration dropdown (it usually says `<no device selected>` or has a file name like `main_5.dart`).
3. Select **Edit Configurations...**.
4. In the new window, click the `+` icon in the top left to add a new configuration, and choose **Flutter**.
5. Set the **Dart entrypoint** to point to this specific file: `lib/Counter_App/main.dart`.
6. Name the configuration something like "Counter App" and click **OK**.
7. Now, with "Counter App" selected in the dropdown, click the green Play button (Run) to start the app on your phone.
