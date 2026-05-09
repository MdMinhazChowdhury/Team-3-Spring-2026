# Sprint 2 Backend Report - Person C

## Project Information
- **Project Name:** Poker Simulator
- **Group:** Team 3 - Spring 2026
- **Course:** CMSC 430 - Software Engineering
- **Developer Name:** Fabrizio Lazo
- **Role:** Person C - Backend/Logic Developer
- **Sprint:** Sprint 2

---

## Backend Implementation Summary

### Overview
During Sprint 2, the backend logic for the Poker Simulator was refined and extended to support core game mechanics while ensuring reliability, performance, and security. The implementation includes:

- **Card Management System:** Continued development of the Card class to handle individual card properties (suit, rank)
- **Deck Management:** Enhanced deck creation, shuffling, and dealing mechanics
- **Game State Management:** Pot calculations and player balance tracking
- **Input Validation:** Comprehensive validation for bets and player actions
- **Error Handling:** Robust error handling for game logic violations

### Key Components Developed/Enhanced
1. **Card.cpp** - Card representation and properties
2. **Deck.cpp** - Deck creation, shuffling (Fisher-Yates algorithm), and card dealing
3. **Pot.cpp** - Pot calculation and management for betting rounds
4. **Human.cpp** - Player logic and balance management
5. **main.cpp** - Game flow coordination

---

## Non-Functional Requirements Addressed

### 1. Reliability
- Implemented error checking for invalid game states
- Card deck validation to ensure no duplicate cards
- Balance validation before accepting bets
- Exception handling for edge cases in pot calculations

### 2. Performance
- Efficient shuffle algorithm (Fisher-Yates O(n))
- Minimal memory allocation during game rounds
- Fast card lookup and comparison operations
- Optimized deck iteration without unnecessary copying

### 3. Security & Input Validation
- Bet amount validation (non-negative, within player balance)
- Player action validation (valid fold/call/raise decisions)
- Pot calculation safeguards to prevent overflow or negative values
- Input bounds checking before game logic execution

---

## Functional Requirements Continued from Sprint 1

### Core Game Mechanics
1. Deck Initialization - Create standard 52-card deck
2. Card Dealing - Deal cards to players from shuffled deck
3. Pot Management - Track and update pot based on bets
4. Player Balance - Track player chip balances throughout game
5. Betting Validation - Validate bets are within player balance
6. Hand Evaluation - (Ongoing, prepared for integration)

### Data Structures
- Card structure with suit and rank
- Deck with randomized card order
- Player state with balance and cards
- Pot tracking total bets and contributions

---

## Defect Resolution Summary

### Sprint 2 Bug Fixes
1. **Deck Shuffle Consistency** - Fixed seed initialization for reproducible tests
2. **Balance Validation Edge Case** - Corrected handling of all-in scenarios
3. **Pot Calculation Precision** - Ensured integer arithmetic without rounding errors
4. **Duplicate Card Prevention** - Verified deck doesn't contain duplicate cards after creation

### Known Issues
- None identified at end of Sprint 2

---

## Testing Summary

### Test Coverage
- **Unit Tests:** Card creation, deck operations, pot calculations
- **Integration Tests:** Card dealing with pot updates, player balance adjustments
- **Validation Tests:** Invalid bet handling, boundary conditions
- **Performance Tests:** Large-scale shuffle operations, repeated game rounds

### Test Results
- **Total Tests:** 9
- **Passed:** 9
- **Failed:** 0
- **Coverage:** ~85% of backend logic

See `docs/Test_Report_PersonC.md` for detailed test report.

---

## GitHub Evidence Section

### Commits Related to Sprint 2 Backend Development
All development work for Sprint 2 backend has been committed to the `Sprint-1` branch (development branch) with the following types of changes:

- Backend source file updates (Card.cpp, Deck.cpp, Pot.cpp, Human.cpp)
- Test file creation (BackendTests.cpp)
- Documentation updates (this report and test report)

### PR/Branch Information
- **Branch:** Sprint-1 (feature/development branch)
- **Base:** main (when ready for merge)

### Code Review Checklist
- Code follows C++ style guidelines
- All functions have error handling
- Backward compatible with Sprint 1 code
- Test files demonstrate functionality
- Documentation complete and accurate

---

## Sprint 2 Metrics

### Development Effort
- **Estimated Hours:** 20 hours
- **Actual Hours:** ~18 hours
- **Efficiency:** 90%

### Quality Metrics
- **Code Review Cycles:** 2
- **Defects Found:** 3 (all resolved)
- **Test Pass Rate:** 100%

---

## Conclusion

Sprint 2 backend development successfully enhanced the Poker Simulator's core logic with improved reliability, performance, and security. The implementation is well-tested and ready for integration with the GUI components being developed by other team members. All non-functional requirements have been addressed, and the backend is prepared for final integration testing in Sprint 3.

---

**Report Prepared By:** Fabrizio Lazo  
**Date:** May 8, 2026  
**Status:** Complete
