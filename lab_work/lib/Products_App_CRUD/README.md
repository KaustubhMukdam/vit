# Products App (FakeStore API + CRUD)

## What Lab Assignments It Covers
- **Lab-7:** Products app
- **Lab-8:** Products app (using fakestoreapi)

## What Files Are Inside
- `main.dart`: Your app's entry block that starts the user directly on the Products page.
- `products_page.dart`: The core logic that talks to the internet to get, create, edit, and delete store products.
- `models/Product.dart`: Contains the `Root` and `Rating` data models, which help Flutter understand the JSON data coming back from the fake store.

## Topics Covered (Detailed Breakdown)
This project focuses on **Networking and HTTP**. It demonstrates how to communicate with the web using asynchronous Dart code.

* **StatelessWidget:**
  - In `main.dart`, the **`MyApp`** class is a `StatelessWidget`. It simply sets the title and launches the app directly into `ProductsPage`.
  - In `products_page.dart`, there is a custom **`ProductCard`** class at the bottom which is a `StatelessWidget`. It exists purely to draw the beautiful UI border, title, image, and price. It contains no changing variables, making it highly efficient. It receives the `onEdit` and `onDelete` functions as parameters from the parent. 
* **StatefulWidget (Network State Management):**
  - In `products_page.dart`, the main **`ProductsPage`** rests inside a `StatefulWidget`. It holds two critical pieces of State: `_products` (the literal array of Items downloaded from the internet) and `_isLoading` (a boolean that shows a spinning circle while downloading).
  - Every time an internet function completes (like `_fetchProducts()` finishing its GET request or `_deleteProduct()` successfully sending a DELETE request), it immediately calls `setState()`. This tells the flutter screen to remove the loading spinner and rebuild the list to show the downloaded items.
* **JSON Serialization:**
  - Inside `models/Product.dart`, we define simple classes `Root` and `Rating`. Whenever the raw text JSON comes down from fakestoreapi, we use the `Root.fromJson()` function to automatically convert text to a strictly typed Dart object.

## How to Run in Android Studio
1. Open up Android Studio and connect your phone via cable.
2. In the top run bar, find the dropdown menu that usually shows the current file being run and click **Edit Configurations...**.
3. Add a new configuration by clicking the `+` button and selecting **Flutter**.
4. In the settings, change the **Dart entrypoint** to `lib/Products_App_CRUD/main.dart`.
5. Enter a name like "Products CRUD" and click **OK**.
6. Select this configuration and click the Play icon to run the App.
