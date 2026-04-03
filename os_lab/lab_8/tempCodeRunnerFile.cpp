#include<iostream>
#include<fstream>
#include<cstring>
#include<cctype>

using namespace std;

// ==========================================
// GLOBAL VARIABLES (Machine Architecture)
// ==========================================
char M[100][4];  // Main Memory (RAM)
char IR[4];      // Instruction Register
char R[4];       // General Purpose Register
int IC;          // Instruction Counter
bool C;          // Toggle (Condition Code)
char Buffer[41]; // Input Buffer (40 chars + null terminator)
int m;           // Memory pointer for LOAD

// ==========================================
// FUNCTION DECLARATIONS
// ==========================================
void INIT();
void LOAD(ifstream &infile);
void EXECUTE(ifstream &infile);
void print_memory();

// ==========================================
// MAIN FUNCTION
// ==========================================
int main() {
    cout << "\n[STEP 1] Starting OS Phase-I Loader...\n";
    cout << "[STEP 2] Attempting to open 'input.txt'...\n";
    
    ifstream infile("input.txt");

    if (!infile.is_open()) {
        cerr << "[ERROR] Cannot open 'input.txt' file. Verification failed.\n";
        return 1;
    }
    
    cout << "[SUCCESS] File opened.\n";
    cout << "[STEP 3] Initiating LOAD process...\n";

    LOAD(infile);
    EXECUTE(infile);

    cout << "\n[STEP 7] Executing final memory dump...\n";
    print_memory();

    cout << "[STEP 8] Terminating simulator.\n";
    infile.close();
    return 0;
}

// ==========================================
// INIT FUNCTION
// ==========================================
void INIT() {
    cout << "\n  -> [INIT] Wiping Main Memory and CPU Registers...\n";
    
    for(int i = 0; i < 4; i++) {
        IR[i] = '*';
        R[i] = '*';
    }
    IC = 0;
    C = false;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 4; j++) M[i][j] = '*';
    }
    cout << "  -> [SUCCESS] INIT() completed. State is fresh.\n";
}

// ==========================================
// LOAD FUNCTION (With Corrected Block Allocation)
// ==========================================
void LOAD(ifstream &infile) {
    while (infile.getline(Buffer, 41)) {
        if (strncmp(Buffer, "$AMJ", 4) == 0) {
            cout << "\n[LOAD] Found $AMJ. Starting new job.\n";
            INIT();
            m = 0;
        }
        else if (strncmp(Buffer, "$DTA", 4) == 0) {
            cout << "\n[LOAD] Found $DTA. Program loading finished.\n";
            cout << "[STEP 4] Transitioning to Execution phase...\n";
            break; 
        }
        else if (strncmp(Buffer, "$END", 4) == 0) {
            continue;
        }
        else {
            cout << "[LOAD] Parsing Program Card at block M[" << m << "]...\n";
            int buffer_len = strlen(Buffer);
            int buffer_index = 0;
            int limit = m + 10; // Max 10 words per card

            // Load the instruction words into memory
            while (m < limit && buffer_index < buffer_len && m < 100) {
                for (int j = 0; j < 4; j++) {
                    if (buffer_index < buffer_len) M[m][j] = Buffer[buffer_index++];
                    else M[m][j] = '*'; 
                }
                m++;
            }

            // ==========================================
            // STRICT BLOCK ALLOCATION LOGIC
            // ==========================================
            // If the card was shorter than 40 characters, 'm' will not have 
            // reached the next multiple of 10. We force it to the next boundary.
            if (m % 10 != 0) {
                m = ((m / 10) + 1) * 10;
                cout << "  -> [ALLOCATION] Short card detected. Pointer 'm' advanced to block boundary " << m << "\n";
            } else {
                cout << "  -> [ALLOCATION] Full card loaded. Pointer 'm' naturally resting at boundary " << m << "\n";
            }
        }
    }
}

// ==========================================
// EXECUTE FUNCTION
// ==========================================
void EXECUTE(ifstream &infile) {
    cout << "\n[STEP 5] Starting EXECUTE Cycle...\n";
    
    while (true) {
        for (int i = 0; i < 4; i++) {
            IR[i] = M[IC][i];
        }
        cout << "\n  [CPU] Fetched Instruction at IC=" << (IC < 10 ? "0" : "") << IC << ": " 
             << IR[0] << IR[1] << IR[2] << IR[3] << "\n";
        
        IC++; 

        char op1 = IR[0];
        char op2 = IR[1];
        
        if (op1 == 'H') {
            cout << "  -> [EXEC] Halt (H) encountered. Terminating execution.\n";
            break;
        }

        int operand = 0;
        if (isdigit(IR[2]) && isdigit(IR[3])) {
            operand = (IR[2] - '0') * 10 + (IR[3] - '0');
        } else {
            cerr << "  -> [CRITICAL] Invalid operand in instruction. Crashing CPU.\n";
            break;
        }

        if (op1 == 'G' && op2 == 'D') {
            cout << "  -> [EXEC] GD" << operand << " : Reading Data Card to M[" << operand << "]\n";
            if(infile.getline(Buffer, 41)) {
                int len = strlen(Buffer);
                int b_idx = 0;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (b_idx < len) M[operand + i][j] = Buffer[b_idx++];
                        else M[operand + i][j] = '*';
                    }
                }
            }
        }
        else if (op1 == 'P' && op2 == 'D') {
            cout << "  -> [EXEC] PD" << operand << " : Printing to Output\n";
            cout << "\n    ================ OUTPUT ================\n    ";
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 4; j++) {
                    if (M[operand + i][j] != '*') cout << M[operand + i][j];
                }
            }
            cout << "\n    ========================================\n";
        }
        else if (op1 == 'L' && op2 == 'R') {
            cout << "  -> [EXEC] LR" << operand << " : Loading M[" << operand << "] into Register R\n";
            for (int i = 0; i < 4; i++) R[i] = M[operand][i];
        }
        else if (op1 == 'C' && op2 == 'R') {
            cout << "  -> [EXEC] CR" << operand << " : Comparing Register R with M[" << operand << "]\n";
            C = true;
            for (int i = 0; i < 4; i++) {
                if (R[i] != M[operand][i]) {
                    C = false;
                    break;
                }
            }
            cout << "     [STATE] Toggle C is now " << (C ? "TRUE" : "FALSE") << "\n";
        }
        else if (op1 == 'B' && op2 == 'T') {
            cout << "  -> [EXEC] BT" << operand << " : Branch if Toggle is TRUE\n";
            if (C) {
                IC = operand;
                cout << "     [STATE] Branch taken. IC updated to " << IC << "\n";
            } else {
                cout << "     [STATE] Branch ignored. Proceeding to next instruction.\n";
            }
        }
        else {
            cerr << "  -> [ERROR] Unrecognized Opcode. Crashing CPU.\n";
            break;
        }
    }
}

// ==========================================
// PRINT MEMORY FUNCTION
// ==========================================
void print_memory() {
    cout << "\n=========================================\n";
    cout << "          MAIN MEMORY DUMP (RAM)         \n";
    cout << "=========================================\n";
    
    for (int i = 0; i < 100; i++) {
        if (i < 10) cout << "M[0" << i << "]: ";
        else cout << "M[" << i << "]: ";

        for (int j = 0; j < 4; j++) cout << M[i][j];
        
        if ((i + 1) % 10 == 0) cout << "\n-------------------------";
        cout << "\n";
    }
}