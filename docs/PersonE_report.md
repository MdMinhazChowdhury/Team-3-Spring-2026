# Sprint 2 – Person E Report
## GUI Usability Testing and Validation
### Team 3 – High Aces Poker Simulator

---

# Overview

During Sprint 2, my primary responsibility was supporting the GUI/usability portion of the High Aces Poker Simulator project through testing, validation, and user interaction verification.

My work focused on ensuring that the console-based GUI behaved correctly, handled invalid inputs properly, displayed accurate responses, and provided a usable interaction flow for the user.

This contribution supported the overall usability and stability of the poker simulator system.

---

# Responsibilities

The following responsibilities were completed during Sprint 2:

- Tested the functionality of the poker GUI system
- Verified menu navigation and usability flow
- Tested invalid input handling
- Verified backend responses displayed correctly through the GUI
- Assisted with GUI integration validation
- Validated user interaction workflow
- Verified pot updates and player actions
- Tested build execution using CMake and Visual Studio build tools
- Assisted with troubleshooting compilation and linking errors

---

# Files Contributed To

## src/PokerGUI.cpp

Used to verify:
- Menu interaction flow
- User action responses
- Backend integration behavior
- Input handling

## tests/GUITest.cpp

Created and updated to provide:
- GUI testing
- Usability testing
- Navigation validation
- Invalid input testing
- Workflow testing

---

# GUI Features Tested

The following GUI features were tested successfully:

| Feature | Status |
|----------|--------|
| Deal Cards | PASS |
| Bet | PASS |
| Raise | PASS |
| Fold | PASS |
| Check | PASS |
| Show Pot | PASS |
| Exit Program | PASS |
| Menu Navigation | PASS |
| Invalid Input Handling | PASS |

---

# Usability Testing

## Menu Readability

The menu system was tested to ensure:
- Options display clearly
- Navigation is understandable
- User prompts are readable

### Result
PASS

---

## Navigation Workflow

The workflow was tested to ensure users could:
1. Launch the program
2. Navigate menu options
3. Perform poker actions
4. Receive system responses
5. Exit the application safely

### Result
PASS

---

## Invalid Input Handling

The GUI was tested using invalid menu selections.

Examples tested:
- Numbers outside valid range
- Unsupported menu choices

The program correctly displayed:

Invalid selection. Try again.

### Result
PASS

---

# Backend Response Verification

The GUI responses were validated for the following backend interactions:

| Action | Expected Response | Result |
|--------|-------------------|--------|
| Deal Cards | Cards displayed | PASS |
| Bet | Pot updated | PASS |
| Raise | Pot updated | PASS |
| Fold | Fold confirmation shown | PASS |
| Check | Check confirmation shown | PASS |
| Show Pot | Pot amount displayed | PASS |

---

# GUITest.cpp Validation

The GUITest.cpp file was used to simulate and validate GUI behavior.

## Tests Included

### Menu Display Test
Verifies menu formatting and visibility.

### Invalid Input Test
Verifies incorrect inputs are rejected.

### Workflow Test
Verifies user interaction flow behaves correctly.

### Navigation Flow Test
Verifies menu organization and readability.

---

# Build and Execution Testing

The project was tested using:
- CMake
- Visual Studio Build Tools
- PowerShell terminal

### Build Commands

```powershell
cmake -S . -B build
cmake --build build

**creenshots to validate and verify GUI implementation and testing:**

