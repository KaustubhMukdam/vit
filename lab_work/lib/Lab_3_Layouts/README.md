# Layouts and Styling - Login Screen

## What Lab Assignments It Covers
- **Lab-3:** Layouts and Styling
  - Using layout widgets: Stack, SizedBox
  - Styling UI elements with themes, colors, and fonts
  - Designing a basic login screen with professional appearance

## What Files Are Inside
- `main.dart`: A complete login screen application demonstrating various layout and styling techniques.

## Topics Covered (Detailed Breakdown)
This project focuses on building a polished UI using advanced layouts and custom styling.

* **StatefulWidget:**
  - **`LayoutsAndStylingPage`**: A `StatefulWidget` that manages the state of two `TextEditingController` objects for user input (User ID and Password fields).
  - The reason it's "stateful" is that it needs to handle user interactions and potentially manage form state changes.

* **Advanced Layout Widgets:**
  - **Stack Widget:** Layers multiple widgets on top of each other. Used for the gradient header background with centered text overlay.
  - **SingleChildScrollView:** Allows vertical scrolling when content exceeds screen height, preventing overflow errors.
  - **SizedBox:** Used for both spacing between widgets and setting fixed dimensions (button height).
  - **Column:** Vertical arrangement of all major UI sections with `crossAxisAlignment: CrossAxisAlignment.stretch` to fill width.

* **Styling & Theming:**
  - **Gradient Backgrounds:** Uses `LinearGradient` with multiple colors and directions for visual appeal
  - **Custom Borders:** `OutlineInputBorder` with custom colors and border radius for TextField styling
  - **Box Shadows:** `BoxShadow` for depth and elevation effects
  - **Color Scheme:** Uses custom color palettes with indigo as the primary color
  - **Border Radius:** Rounded corners on containers and input fields using `BorderRadius.circular()`
  - **Theme Integration:** `ThemeData` with `ColorScheme.fromSeed()` for consistent theming

* **Input Widgets:**
  - **TextField:** Custom-styled text input fields with:
    - `prefixIcon` and `suffixIcon` for visual indicators
    - `InputDecoration` for borders, hints, and fills
    - Different styling for enabled vs. focused states
  - **ElevatedButton:** Styled button with custom backgroundColor, shape, and elevation
  - **GestureDetector:** For handling user interactions (like the Sign Up link)

* **User Interaction & Feedback:**
  - **ScaffoldMessenger & SnackBar:** Shows brief feedback messages to the user
  - **onPressed callbacks:** Handles button and link taps

## How to Run in Android Studio
1. Open Android Studio and ensure your device/emulator is connected.
2. Click on the Run Configurations dropdown at the top and select **Edit Configurations...**.
3. Click the `+` button and select **Flutter**.
4. Set the **Dart entrypoint** to `lib/Lab_3_Layouts/main.dart`.
5. Name this configuration "Lab 3 - Layouts" and click **OK**.
6. Select this configuration and click the green Play button to run the app.

## Learning Outcomes
After completing this lab, you should understand:
- How to use Stack for layering widgets
- The importance of SizedBox for spacing and sizing
- How to create custom-styled input fields and buttons
- How to implement gradients and shadows for depth
- How to design a professional-looking login interface
- How to handle user input with TextEditingController
