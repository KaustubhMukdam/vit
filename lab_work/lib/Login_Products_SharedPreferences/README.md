# Login and Products App (with Shared Preferences)

## What Lab Assignments It Covers
- **Lab-9:** Login/Signup (with shared preference) + Products app

## What Files Are Inside
- `main.dart`: The brain of the app that checks device memory before launching to see if the user is already logged in.
- `products_page.dart`: The store page to view products and log out.
- `register_page.dart`: The signup screen.
- `utility.dart`: Password and Email complex validations.
- `configurations.dart`: Stores the backend static registered users list.
- `models/Product.dart`: Model used to display product structures.

## Topics Covered (Detailed Breakdown)
This unites authentication and APIs into one cohesive App architecture. The main concept here is **Shared Preferences** which permanently saves data to the physical phone.

* **StatelessWidget:**
  - In `main.dart`, the **`MyApp`** class is a `StatelessWidget`. It receives a variable from the terminal (`isLoggedIn`). Based on that variable, it either opens the Login screen or directly opens the Products screen.
* **StatefulWidget:**
  - In `main.dart`, the **`MyHomePage`** (Login Screen) is a `StatefulWidget`. Here, upon a successful login, the app opens the local device storage using `await SharedPreferences.getInstance()`, and writes `isLoggedIn = true` to save state. After this, it routes out.
  - In `products_page.dart`, the **`ProductsPage`** is a `StatefulWidget`. In the top right corner of the `AppBar`, there is a Log Out icon. Clicking this icon triggers code to overwrite the `SharedPreferences` memory to `false`, effectively logging you out before kicking you back to the login screen.
* **Asynchronous `main()` Execution:**
  - In standard apps, `void main()` just runs `runApp()`. But in `main.dart` for this layout, we made `main()` asynchronous: `void main() async`. We initialize Flutter early using `WidgetsFlutterBinding.ensureInitialized();` so that we have time to read the phone's native storage file BEFORE deciding which screen the app should permanently open. 

## How to Run in Android Studio
1. Launch Android Studio with your phone plugged into your PC via the C to C cable.
2. Near the topmost part of your screen, click the run configurations dropdown and hit **Edit Configurations...**.
3. Press the `+` icon on the upper left, then choose **Flutter** from the menu.
4. Set the **Dart entrypoint** file path explicitly to `lib/Login_Products_SharedPreferences/main.dart`.
5. Name this configuration "Login SharedPrefs App", then click **OK**.
6. At the top of Android Studio, make sure your phone and "Login SharedPrefs App" are selected, and then simply click the green triangular Run button.
