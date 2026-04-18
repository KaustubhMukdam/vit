# Restructure Flutter Codebase

The goal is to analyze the user's Flutter `lab_work` repository and map the implementations of multiple assignment versions into distinct, organized project directories. Each directory will reflect a "small project" and contain corresponding documentation that identifies the Labs it covers.

## Proposed Project Mapping and Directory Structure

Based on your request to organize by project name since multiple labs cover the same code, we will create the following separate feature folders inside a new directory named `projects/` (or we can root them in the main directory if preferred, but organizing them into `projects/` makes the workspace cleaner). Inside each project folder, we will place the `lib/` files needed for that specific app and create a `README.md`.

We've identified the following projects and the standard lab mappings:

1. **`Counter_App`** (Covers Lab-1, Lab-2, and Lab-6)
   - Code: `main.dart`
   - Purpose: Basic Setup, Project Structure, and the Flutter Counter logic.

2. **`Login_and_Signup_regex`** (Covers Lab-3 and Lab-4)
   - Code: `main_3.dart` (as `main.dart`), `register_page.dart`, `utility.dart`, `configurations.dart`
   - (Note: We won't copy `main2.dart` since `main_3.dart` is the evolved Lab-4 version with regex that encapsulates Lab-3 logic, unless you want an intermediate folder).
   - Purpose: Regex validation for Authentication forms.

3. **`Attendance_System`** (Covers Lab-5)
   - Code: `main_4.dart` (as `main.dart`), `Content.dart`, `register_page.dart`, `utility.dart`, `configurations.dart`
   - Purpose: Integrates Login/Signup + Attendance list toggling.

4. **`Products_App_CRUD`** (Covers Lab-7 and Lab-8)
   - Code: `main_5.dart` (as `main.dart`), `products_page.dart`, `models/Product.dart`
   - Purpose: Utilizing fakestoreapi for a Products page featuring network actions.

5. **`Login_Products_SharedPreferences`** (Covers Lab-9)
   - Code: `main_6.dart` (as `main.dart`), `products_page.dart`, `register_page.dart`, `utility.dart`, `configurations.dart`
   - Purpose: Linking authentication state storage with the Products App.

## Open Questions

> [!WARNING]
> Since this involves moving existing code into sub-directories or duplicating files, it will break the existing `lab_work/lib` structure and you will get many dart files named `main.dart` in different folders.
> 
> How would you prefer these to be structured?
> **Option A:** I create standalone Flutter applications for each project (using `flutter create`) so that each folder can be run independently using `flutter run`. This creates whole new flutter projects.
> **Option B:** I just create normal subfolders inside `./lib` (e.g., `./lib/Counter_App`, `./lib/Attendance_System`) and move your files into them, renaming your `main_X.dart` to `main.dart` within those folders. (This means they share the same `pubspec.yaml`, but standard Flutter requires `lib/main.dart` to execute. You'd have to specify the target file like `flutter run lib/Counter_App/main.dart`).
> 
> *Please confirm if Option B approach is okay, or if you prefer a different structure!*

## Proposed Changes

### 1. Create Subfolders within `lib/` (Assuming Option B)
We will create folders and copy the required files into them.

#### `lib/Counter_App/`
- [NEW] `lib/Counter_App/main.dart` (from `main.dart`)
- [NEW] `lib/Counter_App/README.md` 

#### `lib/Login_and_Signup_regex/`
- [NEW] `lib/Login_and_Signup_regex/main.dart` (from `main_3.dart`)
- [NEW] `.../register_page.dart`, `.../utility.dart`, `.../configurations.dart`
- [NEW] `lib/Login_and_Signup_regex/README.md`

#### `lib/Attendance_System/`
- [NEW] `lib/Attendance_System/main.dart` (from `main_4.dart`)
- [NEW] `.../Content.dart`, `.../register_page.dart`, `.../utility.dart`, `.../configurations.dart`
- [NEW] `lib/Attendance_System/README.md`

#### `lib/Products_App_CRUD/`
- [NEW] `lib/Products_App_CRUD/main.dart` (from `main_5.dart`)
- [NEW] `.../products_page.dart`, `.../models/Product.dart`
- [NEW] `lib/Products_App_CRUD/README.md`

#### `lib/Login_Products_SharedPreferences/`
- [NEW] `lib/Login_Products_SharedPreferences/main.dart` (from `main_6.dart`)
- [NEW] `.../products_page.dart`, `.../register_page.dart`, `.../utility.dart`, `.../configurations.dart`
- [NEW] `lib/Login_Products_SharedPreferences/README.md`

### 2. Cleanup `lib/`
- Once safely copied, we can delete the loose `main_X.dart`, etc from the root `lib/` directory or move them to a backup folder if preferred.

## Verification Plan
1. Check that all files exist in their respective project folders.
2. Read the `README.md` files to ensure they document the corresponding covered labs clearly and provide correct run instructions (e.g., `flutter run lib/Attendance_System/main.dart`).
