# Lab Work Code Mapping

Based on the analysis of the Dart files in `lib/`, here is the breakdown of which file contains the code for which project assignment:

| Project Description | Corresponding Files | Details |
| :--- | :--- | :--- |
| **Lab-1: Setup and Flutter Hello World program** | `main.dart` | The default Flutter starter code, which covers the initial setup and basic app structure. |
| **Lab-2: Project structure** | `main.dart` | Shares the base project structure with Lab-1. |
| **Lab-3: Login Screen** | `main2.dart` | A basic login screen with User ID and Password fields and standard conditional validation. |
| **Lab-4: Login/Signup screen with regex** | `main_3.dart`, `register_page.dart`, `utility.dart`, `configurations.dart` | Login/Signup with robust regex validations (email, password strength) in `utility.dart` and static credentials check. |
| **Lab-5: Login/Signup screen + Attendance system** | `main_4.dart`, `Content.dart`, `register_page.dart`, `utility.dart`, `configurations.dart` | Integrates the attendance list view where users can toggle Present/Absent via direct tap or dialog. |
| **Lab-6: Counter app** | `main.dart` | Uses the default increment counter logic found in flutter's default main application. |
| **Lab-7 / Lab-8: Products app (using fakestoreapi + CRUD operations)** | `main_5.dart`, `products_page.dart`, `models/Product.dart` | A store app interacting with FakeStore API featuring GET, POST, PUT, DELETE functionality. |
| **Lab-9: Login/Signup (with shared preference) + Products app** | `main_6.dart`, `products_page.dart`, `register_page.dart`, `utility.dart`, `configurations.dart` | Connects regex login/signup with shared preferences for logging in persistently and routing to the products page. |
