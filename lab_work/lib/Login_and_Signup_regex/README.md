# Login and Signup with Regex

## What Lab Assignments It Covers
- **Lab-3:** Login Screen
- **Lab-4:** Login/Signup screen with regex

## What Files Are Inside
- `main.dart`: Your main entry file that contains the Login Screen user interface and logic.
- `register_page.dart`: The screen where new users can sign up.
- `utility.dart`: A helper file that contains the regular expression (Regex) logic to check if emails and passwords are valid.
- `configurations.dart`: A simple storage file that holds a list of registered users and hardcoded credentials.

## Topics Covered (Detailed Breakdown)
This project focuses heavily on how to take text typed by the user, validate it instantly, and show errors on the screen if they made a mistake.

* **StatelessWidget:**
  - In `main.dart`, the **`MyApp`** class is a `StatelessWidget` that sets up the overall MaterialApp and launches `MyHomePage`.
* **StatefulWidget:**
  - In `main.dart`, the **`MyHomePage`** (Login Screen) is a `StatefulWidget`. It uses `TextEditingController` objects to constantly read what the user types. The reason it is "stateful" is that it needs to run a `validate()` function and call `setState()` so that red error text like "Please enter a valid email ID" instantly appears on the screen without restarting the app.
  - In `register_page.dart`, the **`RegisterPage`** is also a `StatefulWidget`. It holds state for three things: the user ID, password, and confirm password fields. It uses `setState()` to show alerts if passwords do not match or if the email is already in the hardcoded system.
* **Regex (Regular Expressions) & Static Helpers:**
  - In `utility.dart`, we don't use any widgets. Instead, we use a basic class with `static bool` functions. Inside these functions, we use **`RegExp(r"...").hasMatch(text)`** to create strict mathematical rules for emails and password strength (capital letter, symbol, length >= 8). We call these functions from inside our StatefulWidgets.

## How to Run in Android Studio
1. Open Android Studio and verify your device is connected.
2. At the top of the window, open the Run Configurations dropdown and click **Edit Configurations...**.
3. Click the `+` button in the top left corner and select **Flutter**.
4. Important: Set the **Dart entrypoint** file path to `lib/Login_and_Signup_regex/main.dart`.
5. Name this configuration "Login Regex" and click **OK**.
6. Select your device and click on the green Play button to install and run the app.
