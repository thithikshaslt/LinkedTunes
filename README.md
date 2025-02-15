# LinkedTunes

A simple **C++** console-based music playlist manager that allows you to add, delete, search, and play `.wav` songs. The program uses **Windows Multimedia API** (`PlaySound`) for audio playback.

---

## Features
- Add songs to a playlist.
- Delete songs from the playlist.
- Display all songs in the playlist.
- Search for a song.
- Play `.wav` audio files.
- Show recently played songs.

---

## IDE & Tools Used
- **Dev-C++**
- **GCC Compiler**
- **Windows API (winmm.lib)**

---

## Project Structure
```
Project1/
│── Project1.dev         # Dev-C++ project file
│── main.cpp             # Main source code
│── songs.txt            # Stores playlist songs
│── Project1.exe         # Compiled executable (generated after build)
```

---

## 🔗 Setting Up & Linking Library
1. **Open the Project in Dev-C++**
   - Open **Dev-C++**.
   - Click **File → Open Project or File**.
   - Select **`Project1.dev`**.

2. **Link Windows Multimedia Library** (for `PlaySound` function)
   - Go to **"Tools" → "Compiler Options"**.
   - Select the **"Linker"** tab.
   - Add the following in the linker box:
     ```
     -lwinmm
     ```
   - Click **OK**.

---

##  Running the Program
### **Method 1: From Dev-C++**
- Press **`F9`** (Compile & Run) or go to **"Execute" → "Compile & Run"**.
- The console window will open, allowing you to interact with the playlist.

### **Method 2: Manually Running Executable**
- Navigate to the project folder.
- Find **`Project1.exe`**.
- Double-click to run it.

---

## Placing Audio Files
- `.wav` files should be placed **in the same directory as `Project1.exe`**.
- If the songs do not play, check if the filenames in `main.cpp` match exactly.

---
## Note
- Ensure `-lwinmm` is linked in the compiler options.
