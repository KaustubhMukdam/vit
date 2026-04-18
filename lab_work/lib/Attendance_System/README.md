# Login, Signup, and Attendance System

## What Lab Assignments It Covers
- **Lab-5:** Login/Signup screen + Attendance system

## What Files Are Inside
- `main.dart`: Contains the Login and Signup flow.
- `Content.dart`: Displays the attendance list and handles toggling user status.
- `register_page.dart`: The signup screen.
- `utility.dart`: Regex validation for emails and passwords.
- `configurations.dart`: Provides the static data (Lists) used to store registered users and the hardcoded attendance record dates.

## Topics Covered (Detailed Breakdown)
This app introduces rendering large lists of data dynamically and passing navigation correctly to new screens after a successful login.

* **StatelessWidget with ValueNotifier (Advanced State Replacement):**
  - In `main.dart`, the **`MyHomePage`** class is actually a `StatelessWidget`. Instead of using `setState()` to update the UI like previous labs, it uses a smarter approach using `ValueNotifier` and `ValueListenableBuilder`. This is an optimized way to listen for text input changes (like typing a password) and redraw *only* the specific text box that needs to show an error, instead of redrawing the entire screen.
* **StatefulWidget (List Views and Toggles):**
  - In `Content.dart`, the **`Content`** class is a `StatefulWidget`. It holds the state for `_currentMode` (switching between Direct tap mode or Dialog mode) using a Dropdown.
  - Also in `Content.dart`, we created a custom **`AttendanceItem`** widget which is a `StatefulWidget`. This is crucial. Every single date row in the list maintains its *own* independent State (`isPresent` variable). When you tap a specific row's 'P' or 'A', it hits `setState()` to instantly change colors, and silently saves that modification to `Configurations.attendance` list so the change is temporarily saved.
* **ListView.builder:**
  - Inside `Content.dart`, we use `ListView.builder` to loop through the raw dates found in `configurations.dart` and automatically generate rows (`AttendanceItem`) for them dynamically.

## How to Run in Android Studio
1. Open Android Studio and connect your phone.
2. In the top toolbar next to the green Play button, click the dropdown and select **Edit Configurations...**.
3. Click the `+` icon and choose **Flutter**.
4. Set the **Dart entrypoint** explicitly to `lib/Attendance_System/main.dart`.
5. Give it a name like "Attendance App" and press **OK**.
6. Make sure "Attendance App" and your phone are selected, then hit the green Play button to run the code.
